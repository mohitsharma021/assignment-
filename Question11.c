#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
char pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        return '\0'; // return null character if stack is empty
    }
}

// Function to check the precedence of operators
int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to reverse a string
void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    int i = 0, k = 0;
    while (infix[i]) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i]; // Operand
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // pop '('
        } else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; // Null terminate the postfix string
}

// Function to convert infix to prefix
void infixToPrefix(char *infix, char *prefix) {
    reverse(infix); // Step 1: Reverse the infix expression

    // Step 2: Change '(' to ')' and vice versa
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char postfix[MAX];
    infixToPostfix(infix, postfix); // Convert the modified infix to postfix
    reverse(postfix); // Reverse postfix to get prefix

    strcpy(prefix, postfix); // Copy to prefix
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove newline character from input
    infix[strcspn(infix, "\n")] = '\0';

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

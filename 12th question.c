#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        exit(1); // Exit if stack is empty
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *postfix) {
    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            // Push operand (convert character to integer)
            push(postfix[i] - '0');
        } else {
            // Operator encountered
            int op2 = pop();
            int op1 = pop();
            switch (postfix[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    exit(1);
            }
        }
    }
    return pop(); // The result will be the last item in the stack
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    fgets(postfix, MAX, stdin);
    
    // Remove newline character from input
    postfix[strcspn(postfix, "\n")] = '\0';

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}

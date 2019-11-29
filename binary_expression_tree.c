#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    struct node * left;
    struct node * right;
    char data;
} Node;

typedef struct stack {
    Node *s[50];
    int size;
} Stack;

typedef struct stack_op {
    char s[50];
    int size;
} OperatorStack;

int isOperator(char e) {
    switch (e) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
            return 1;
        default:
            return 0;
    }
}

Node* createNode(char data) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}

Node* createExpressionTreeFromPostfix(char *postfix, int len) {
    Stack s;
    s.size = -1;
    Node *root = NULL;
    Node *temp = NULL;
    Node *op1 = NULL, *op2 = NULL;
    for(int i=0; i<len; ++i) {
        if(!isOperator(postfix[i])) {
            temp = createNode(postfix[i]);
            s.s[++s.size] = temp;
        }
        else {
            op1 = s.s[s.size--];
            op2 = s.s[s.size--];
            temp = createNode(postfix[i]);
            temp->right = op1;
            temp->left = op2;
            s.s[++s.size] = temp;
        }
    }
    return s.s[s.size--];
}

int precedence(char op1, char op2) {
    switch(op2) {
        case '+':
        case '-': if(op1 == '(') return 0;
                  return 1;
        case '*':
        case '/': if(op1 == '*' || op1 == '/') return 1;
                  return 0;
        case '(': return 0;
        case ')': if(op1 == '(') return 0;
                  return 1;
        default: return 1;
    }
}

Node* createExpressionTreeFromInfix(char *infix, int len) {
    OperatorStack s_op;
    s_op.size = -1;
    Stack s_tree;
    s_tree.size = -1;
    Node *temp = NULL;
    Node *op1 = NULL, *op2 = NULL;
    for(int i=0; i<len; ++i) {
        if(!isOperator(infix[i])) {
            temp = createNode(infix[i]);
            s_tree.s[++s_tree.size] = temp;
        }
        else {
            while(s_op.size!=-1 && precedence(s_op.s[s_op.size], infix[i])) {
                op1 = s_tree.s[s_tree.size--];
                op2 = s_tree.s[s_tree.size--];
                temp = createNode(s_op.s[s_op.size--]);
                temp->right = op1;
                temp->left = op2;
                s_tree.s[++s_tree.size] = temp;
            }
            if(infix[i]==')') s_op.size--;
            else {
                s_op.s[++s_op.size] = infix[i];
            }
        }
    }
    while(s_op.size != -1) {
        op1 = s_tree.s[s_tree.size--];
        op2 = s_tree.s[s_tree.size--];
        temp = createNode(s_op.s[s_op.size--]);
        temp->right = op1;
        temp->left = op2;
        s_tree.s[++s_tree.size] = temp;
    }
    return s_tree.s[s_tree.size--];
}


void postorder(Node* node) {
    if(!node) return;
    postorder(node->left);
    postorder(node->right);
    printf("%c ", node->data);
}

void inorder(Node* node) {
    if(!node) return;
    inorder(node->left);
    printf("%c ", node->data);
    inorder(node->right);
}

void preorder(Node* node) {
    if(!node) return;
    printf("%c ", node->data);
    preorder(node->left);
    preorder(node->right);
}

int evaluate(Node* node) {
    int data;
    switch(node->data) {
        case '+': return evaluate(node->left) + evaluate(node->right);
        case '-': return evaluate(node->left) - evaluate(node->right);
        case '*': return evaluate(node->left) * evaluate(node->right);
        case '/': return evaluate(node->left) / evaluate(node->right);
        default:printf("Enter the value for %c: ", node->data);
                scanf(" %d", &data);
                return data;
    }
}

int main(int argc, char const *argv[]) {
    char expression[50];
    int choice = 0;
    Node* root = NULL;
    printf("1. Postfix\n2. Infix\nEnter your choice: ");
    scanf(" %d", &choice);
    if (choice == 1) {
        printf("Enter postfix experession\n");
        scanf("%s", expression);
        root = createExpressionTreeFromPostfix(expression, strlen(expression));
    }
    else if(choice == 2) {
        printf("Enter infix experession\n");
        scanf("%s", expression);
        root = createExpressionTreeFromInfix(expression, strlen(expression));
    }
    else {
        printf("Wrong choice\n");
        return 0;
    }
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Evaluating expression\n");
    printf("Result: %d\n", evaluate(root));
    return 0;
}
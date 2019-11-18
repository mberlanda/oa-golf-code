#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem
struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
int max(int a, int b) { 
    if (a > b) { return a; }
    return b;
}

int getHeight(struct node* root) {
    // Write your code here
    if (root == NULL) return -1;
    int lHeight, rHeight;
    lHeight = getHeight(root->left);
    rHeight = getHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
	printf("%d",getHeight(root));
    return 0;
}
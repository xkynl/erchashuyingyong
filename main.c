#include "stdio.h"
#include "stdlib.h"

//二叉树的二叉链表存储结构
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//二叉树的先序遍历
void PreOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    printf("%d\t", T->data);//访问根结点
    PreOrderTraverse(T->lchild);//先序遍历左子树
    PreOrderTraverse(T->rchild);//先序遍历右子树
}

//二叉树的中序遍历
void InOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);//中序遍历左子树
    printf("%d\t", T->data);//访问根结点
    InOrderTraverse(T->rchild);//中序遍历右子树
}

//二叉树的后序遍历
void PostOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);//后序遍历左子树
    PostOrderTraverse(T->rchild);//后序遍历右子树
    printf("%d\t", T->data);//访问根结点
}

//求二叉树的结点个数
int BiTreeSize(BiTree T) {
    if (T == NULL)
        return 0;
    else
        return 1 + BiTreeSize(T->lchild) + BiTreeSize(T->rchild);//递归求左子树和右子树的结点个数
}

//求二叉树叶子节点的个数
int BiTreeLeafSize(BiTree T) {
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    else
        return BiTreeLeafSize(T->lchild) + BiTreeLeafSize(T->rchild);//递归求左子树和右子树的叶子结点个数
}

//主函数
int main() {
    BiTree T;
    T = (BiTree) malloc(sizeof(BiTNode));
    T->data = 1;
    T->lchild = (BiTree) malloc(sizeof(BiTNode));
    T->lchild->data = 2;
    T->rchild = (BiTree) malloc(sizeof(BiTNode));
    T->rchild->data = 3;
    T->lchild->lchild = (BiTree) malloc(sizeof(BiTNode));
    T->lchild->lchild->data = 4;
    T->lchild->rchild = (BiTree) malloc(sizeof(BiTNode));
    T->lchild->rchild->data = 5;
    T->rchild->lchild = (BiTree) malloc(sizeof(BiTNode));
    T->rchild->lchild->data = 6;
    T->rchild->rchild = (BiTree) malloc(sizeof(BiTNode));
    T->rchild->rchild->data = 7;
    T->lchild->lchild->lchild = NULL;
    T->lchild->lchild->rchild = NULL;
    T->lchild->rchild->lchild = NULL;
    T->lchild->rchild->rchild = NULL;
    T->rchild->lchild->lchild = NULL;
    T->rchild->lchild->rchild = NULL;
    T->rchild->rchild->lchild = NULL;
    T->rchild->rchild->rchild = NULL;
    printf("二叉树的先序遍历结果为：");
    PreOrderTraverse(T);
    printf("\n");
    printf("二叉树的中序遍历结果为：");
    InOrderTraverse(T);
    printf("\n");
    printf("二叉树的后序遍历结果为：");
    PostOrderTraverse(T);
    printf("\n");
    printf("二叉树的结点个数为：%d", BiTreeSize(T));
    printf("\n");
    printf("二叉树的叶子节点个数为：%d", BiTreeLeafSize(T));
    return 0;
}
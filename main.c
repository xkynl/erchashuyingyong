#include "stdio.h"
#include "stdlib.h"

//�������Ķ�������洢�ṹ
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//���������������
void PreOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    printf("%d\t", T->data);//���ʸ����
    PreOrderTraverse(T->lchild);//�������������
    PreOrderTraverse(T->rchild);//�������������
}

//���������������
void InOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);//�������������
    printf("%d\t", T->data);//���ʸ����
    InOrderTraverse(T->rchild);//�������������
}

//�������ĺ������
void PostOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);//�������������
    PostOrderTraverse(T->rchild);//�������������
    printf("%d\t", T->data);//���ʸ����
}

//��������Ľ�����
int BiTreeSize(BiTree T) {
    if (T == NULL)
        return 0;
    else
        return 1 + BiTreeSize(T->lchild) + BiTreeSize(T->rchild);//�ݹ������������������Ľ�����
}

//�������Ҷ�ӽڵ�ĸ���
int BiTreeLeafSize(BiTree T) {
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    else
        return BiTreeLeafSize(T->lchild) + BiTreeLeafSize(T->rchild);//�ݹ�������������������Ҷ�ӽ�����
}

//������
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
    printf("������������������Ϊ��");
    PreOrderTraverse(T);
    printf("\n");
    printf("������������������Ϊ��");
    InOrderTraverse(T);
    printf("\n");
    printf("�������ĺ���������Ϊ��");
    PostOrderTraverse(T);
    printf("\n");
    printf("�������Ľ�����Ϊ��%d", BiTreeSize(T));
    printf("\n");
    printf("��������Ҷ�ӽڵ����Ϊ��%d", BiTreeLeafSize(T));
    return 0;
}
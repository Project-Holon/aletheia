/*
 * file:     unit_021BAA1C_p02.c
 * unit:     yes
 * function: func_021BABF4, func_021BAC38, func_021BAC58
 * address:  0x021BABF4
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BAA1C  0x021BAA1C  arm  ov114
 *   func_021BA118 0x021BA118 arm ov114
 *   func_021BAB58 0x021BAB58 arm ov114
 */
struct Node;
typedef struct Node
{
    struct Node *next;
    struct Node *prev;
} Node;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct DataList {
    struct DataList *next;
    char pad[0xC];
    unsigned long length;
} DataList;

typedef struct {
    int f0;
    int f4;
    char pad[8];
    int f10;
    char pad2[0x20];
    DataList *list;
} Req;

extern int func_021BAA1C(struct Node **head, int b, int c, int d);
extern unsigned long func_021BA118(char *s);
extern int func_021BAB58(Req *req_p, char *value_p, unsigned long length);
Node *func_021BABF4(Node **head);
int func_021BAC38(u32 *p, int a, int b, int c);
int func_021BAC58(Req *req_p, void *bgnEndInfo_p, char *label_p, char *value_p);


Node *func_021BABF4(Node **head)
{
    Node *n = *head;

    if (n != 0)
    {
        if (n == n->next)
        {
            *head = 0;
        }
        else
        {
            n->next->prev = n->prev;
            n->prev->next = n->next;
            *head = n->prev;
        }
    }
    return n;
}


/*
 * Nodes a fresh record into the +0x30 list when the +0x04 field is free.
 */
int func_021BAC38(u32 *p, int a, int b, int c)
{
    if (p[1] != 0)
        return 0;
    return func_021BAA1C((struct Node **)((char *)p + 0x30), a, b, c);
}


int func_021BAC58(Req *req_p, void *bgnEndInfo_p, char *label_p, char *value_p)
{
    int rc = 0;
    unsigned long length = 0;

    if (req_p->f4 != 0) {
        return 0;
    }
    if (req_p->f10 != 0) {
        return 0;
    }
    if (value_p != 0) {
        length = func_021BA118(value_p);
    }
    if (func_021BAB58(req_p, value_p, length) != 0) {
        rc = func_021BAA1C((struct Node **)(&req_p->list), (int)bgnEndInfo_p, (int)label_p, (int)value_p);
        if (rc != 0) {
            req_p->list->next->length = length;
        }
    }
    return rc;
}

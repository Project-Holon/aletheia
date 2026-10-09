/*
 * file:     unit_021BAA1C.c
 * unit:     yes
 * function: func_021BAA1C, func_021BAB24, func_021BAB58, func_021BABF4, func_021BAC38, func_021BAC58
 * address:  0x021BAA1C
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
 *   func_021BA590  0x021BA590  arm  ov114
 *   func_021BA820  0x021BA820  arm  ov114
 *   func_021BA874  0x021BA874  arm  ov114
 *   func_021BA690 0x021BA690 arm ov114
 *   g_021CDFC8 0x021CDFC8 data
 *   func_021BA118 0x021BA118 arm ov114
 */
struct Node_021BABF4;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Node_021BAA1C {
    struct Node_021BAA1C *prev;      /* +0x00 */
    struct Node_021BAA1C *next;      /* +0x04 */
    const char *key;        /* +0x08 */
    int val;                /* +0x0c */
    int a;                  /* +0x10 */
    int b;                  /* +0x14 */
} Node_021BAA1C;

typedef struct {
    char pad[0x38];
    char tag[0x20];
} Req_021BAA1C;

typedef struct Node_021BABF4
{
    struct Node_021BABF4 *next;
    struct Node_021BABF4 *prev;
} Node_021BABF4;

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
} Req_021BABF4;

int func_021BA590(char *p1_p, char *p2_p);
int func_021BA820(int a, int b);
void func_021BA874(u8 *p, int v);
extern int func_021BA690(signed char *hay, int len1, signed char *needle, int len2);
extern unsigned long func_021BA118(char *s);
int func_021BAA1C(Node_021BAA1C **head, int b, int c, int d);
char func_021BAB24(u8 c);
int func_021BAB58(Req_021BAA1C *req_p, char *value_p, unsigned long length);
Node_021BABF4 *func_021BABF4(Node_021BABF4 **head);
int func_021BAC38(u32 *p, int a, int b, int c);
int func_021BAC58(Req_021BABF4 *req_p, void *bgnEndInfo_p, char *label_p, char *value_p);
extern char g_021CDFC8[];



int func_021BAA1C(Node_021BAA1C **head, int b, int c, int d)
{
    Node_021BAA1C *n = *head;
    int found = 0;
    Node_021BAA1C *q;
    Node_021BAA1C *p;

    if (n != 0) {
        q = n;
        if (func_021BA590((char *)c, (char *)q->key) != 0) {
            q = q->next;
            while (q != *head) {
                if (func_021BA590((char *)c, (char *)q->key) == 0) {
                    found = 1;
                    break;
                }
                q = q->next;
            }
        } else {
            found = 1;
        }
    }

    if (found != 0) {
        q->val = d;
    } else {
        p = (Node_021BAA1C *)func_021BA820(0x18, 4);
        if (p == 0) {
            func_021BA874((u8 *)b, 1);
            return 0;
        }
        p->key = (const char *)c;
        p->val = d;
        p->a = 0;
        p->b = 0;
        if (*head == 0) {
            p->next = p;
            p->prev = p;
            *head = p;
        } else {
            p->prev = (*head)->prev;
            p->next = *head;
            (*head)->prev->next = p;
            (*head)->prev = p;
        }
    }
    return 1;
}



/*
 * Successor of a character on the '0'..'z' wheel, wrapping at the gaps.
 * Returning 'signed char' is what puts the single shared sign-extending
 * epilogue at 0x021BAB4C after the value is assigned, not returned early.
 */
char func_021BAB24(u8 c)
{
    c = (c + 1) & 0xff;
    if (c == 0x7b)
        c = 0x30;
    else if (c == 0x5b)
        c = 0x61;
    else if (c == 0x3a)
        c = 0x41;
    return (signed char)c;
}



int func_021BAB58(Req_021BAA1C *req_p, char *value_p, unsigned long length)
{
    char c;
    int n;

    if (func_021BA690((signed char *)value_p, length, (signed char *)(&req_p->tag[2]), 0x12) < 0) {
        return 1;
    }
    for (n = 0x13; n >= 2; n--) {
        char *tp = (char *)req_p + n;
        char t;
        c = tp[0x38];
        t = g_021CDFC8[n];
        while (1) {
            c = func_021BAB24(c);
            tp[0x38] = c;
            if (c == t) {
                break;
            }
            if (func_021BA690((signed char *)value_p, length, (signed char *)(&req_p->tag[2]), 0x12) < 0) {
                return 1;
            }
        }
    }
    return 0;
}



Node_021BABF4 *func_021BABF4(Node_021BABF4 **head)
{
    Node_021BABF4 *n = *head;

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
    return func_021BAA1C((Node_021BAA1C * *)((struct Node_021BABF4 **)((char *)p + 0x30)), a, b, c);
}



int func_021BAC58(Req_021BABF4 *req_p, void *bgnEndInfo_p, char *label_p, char *value_p)
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
    if (func_021BAB58((Req_021BAA1C *)req_p, value_p, length) != 0) {
        rc = func_021BAA1C((Node_021BAA1C * *)((struct Node_021BABF4 **)(&req_p->list)), (int)bgnEndInfo_p, (int)label_p, (int)value_p);
        if (rc != 0) {
            req_p->list->next->length = length;
        }
    }
    return rc;
}

/*
 * file:     unit_021BAA1C_p01.c
 * unit:     yes
 * function: func_021BAA1C, func_021BAB24, func_021BAB58
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
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Node {
    struct Node *prev;      /* +0x00 */
    struct Node *next;      /* +0x04 */
    const char *key;        /* +0x08 */
    int val;                /* +0x0c */
    int a;                  /* +0x10 */
    int b;                  /* +0x14 */
} Node;

typedef struct {
    char pad[0x38];
    char tag[0x20];
} Req;

int func_021BA590(char *p1_p, char *p2_p);
int func_021BA820(int a, int b);
void func_021BA874(u8 *p, int v);
extern int func_021BA690(signed char *hay, int len1, signed char *needle, int len2);
int func_021BAA1C(Node **head, int b, int c, int d);
char func_021BAB24(u8 c);
int func_021BAB58(Req *req_p, char *value_p, unsigned long length);
extern char g_021CDFC8[];


int func_021BAA1C(Node **head, int b, int c, int d)
{
    Node *n = *head;
    int found = 0;
    Node *q;
    Node *p;

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
        p = (Node *)func_021BA820(0x18, 4);
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


int func_021BAB58(Req *req_p, char *value_p, unsigned long length)
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

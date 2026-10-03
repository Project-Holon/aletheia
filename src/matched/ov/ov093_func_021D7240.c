/*
 * function: func_021D7240
 * address: 0x021D7240
 * packet: pkt_ov093_021D7240
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   g_021F3CB0 0x021F3CB0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Node Node;
typedef int (*Callback)(Node *, void *, int, int, u16, u8);
struct Node {
    Node *prev, *next;
    void *table;
    Callback callback;
    int kind;
    u32 pad14;
    u32 low:24, b24:1, b25:1, b26:1, b27:1, b28:1, b29:1, b30:1, b31:1;
    u8 pad1c[0x1c];
    u16 h38;
    u8 b3a, b3b;
};
extern struct { u32 f0; Node *head; } g_021F3CB0;
struct Unk021D62A8;
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_021EF948(int);
int func_021D7240(void *a, Node *b, int c)
{
    void *q = 0;
    Node *n;
    if (b->b3b != 0x1f) q = func_021C7CF4(a, b->b3b);
    if (b->kind == 4 && q != 0 && func_021D62C4(q, 0x10)) return 1;
    if (b->kind == 5) {
        if (func_021EF948(7)) return 1;
        if (q != 0 && func_021D62C4(q, 0x13)) return 1;
        if (q != 0 && func_021D5BB0(q, 9)) return 1;
    }
    for (n = g_021F3CB0.head; n != 0; n = n->next) {
        if (n->callback == 0) continue;
        if (n->kind == 4) {
            q = func_021C7CF4(a, n->b3b);
            if (q != 0 && func_021D62C4(q, 0x10)) continue;
        }
        if (n->b30) continue;
        if (n->callback(n, a, b->kind, c, b->h38, b->b3a)) return 1;
    }
    return 0;
}

/*
 * function: BTL_EVENT_IsEventBlocked
 * address: 0x021D7240
 * packet: pkt_ov093_021D7240
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_FIELD_GetStaticSlotObject 0x021EF948 thumb ov093
 *   gBtlEventFactorList 0x021F3CB0 data a4
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
extern struct { u32 f0; Node *head; } gBtlEventFactorList;
struct Unk021D62A8;
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern int BTL_FIELD_GetStaticSlotObject(int);
int BTL_EVENT_IsEventBlocked(void *a, Node *b, int c)
{
    void *q = 0;
    Node *n;
    if (b->b3b != 0x1f) q = func_021C7CF4(a, b->b3b);
    if (b->kind == 4 && q != 0 && BTL_POKEPARAM_HasSick(q, 0x10)) return 1;
    if (b->kind == 5) {
        if (BTL_FIELD_GetStaticSlotObject(7)) return 1;
        if (q != 0 && BTL_POKEPARAM_HasSick(q, 0x13)) return 1;
        if (q != 0 && BTL_POKEPARAM_TestTurnFlag(q, 9)) return 1;
    }
    for (n = gBtlEventFactorList.head; n != 0; n = n->next) {
        if (n->callback == 0) continue;
        if (n->kind == 4) {
            q = func_021C7CF4(a, n->b3b);
            if (q != 0 && BTL_POKEPARAM_HasSick(q, 0x10)) continue;
        }
        if (n->b30) continue;
        if (n->callback(n, a, b->kind, c, b->h38, b->b3a)) return 1;
    }
    return 0;
}

/*
 * function: func_021D713C
 * address: 0x021D713C
 * packet: pkt_ov093_021D713C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7240 0x021D7240 thumb ov093
 *   func_021D7040 0x021D7040 thumb ov093
 *   g_021F3CB0 0x021F3CB0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Node Node;
typedef struct { int id; void (*callback)(Node *, void *, u8, void *); } Entry;
struct Node {
    Node *prev, *next;
    Entry *table;
    void *callback;
    int kind;
    u32 pad14;
    u32 low:16, count:8, b24:1, b25:1, b26:1, b27:1, b28:1, b29:1, b30:1, b31:1;
    u8 pad1c[0x1c];
    u16 h38;
    u8 b3a, b3b;
};
extern struct { u32 tick; Node *head; } g_021F3CB0;
extern int func_021D7240(void *, Node *, int);
extern void func_021D7040(Node *);
void func_021D713C(void *a, int id, int kind, int check)
{
    Node *n;
    Node *next;
    Entry *entry;
    const Entry *table;
    u32 i;
    int count;
    int tmp;
    u32 tmp1;
    for (n = g_021F3CB0.head; n != 0; ) {
        next = n->next;
        if (n->b24 && !n->b28) goto advance;
        if (n->b25 || n->b30) goto advance;
        tmp = (kind != 7) && (n->kind != kind);
        if (tmp) goto advance;
        if (n->low != 0 && n->low >= g_021F3CB0.tick) goto advance;
        if (!n->b29) goto advance;
        if (id == 0x73 && !n->b26) goto advance;
        count = n->count;
        table = n->table;
        i = 0;
        for (; i < count; i++) {
            entry = (Entry *)&table[i];
            if (id != entry->id) continue;
            if (check && func_021D7240(a, n, id)) break;
            n->b24 = 1;
            tmp1 = n->b3a;
            entry->callback(n, a, tmp1, n->pad1c);
            if (n->b28) *(u32 *)((u8 *)n + 0x18) &= 0xefffffff;
            else *(u32 *)((u8 *)n + 0x18) &= 0xfeffffff;
            if (n->b27) {
                if (next != 0 && !next->b29) next = n->next;
                func_021D7040(n);
            }
            break;
        }
advance:
        if (next == 0) break;
        if (next->b29) n = next;
        else n = n->next;
    }
}

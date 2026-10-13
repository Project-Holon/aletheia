/*
 * file:     unit_068982C0.c
 * function: func_068982C0
 * address: 0x068982C0
 * packet: pkt_ov095_068982C0
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: Two bytes of alignment padding follow the 42-byte function.
 * symbols:
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb
 *   func_021D732C  0x021D732C  thumb
 *   BTL_EVENT_FindNextFactor  0x021D7360  thumb
 */
struct Node;
extern struct Node *func_021D732C(int, int);
extern unsigned short BTL_EVENT_GetFactorKey(struct Node *);
extern struct Node *BTL_EVENT_FindNextFactor(struct Node *);
int func_068982C0(int a, int b)
{
    struct Node *p = func_021D732C(1, b);
    while (p != 0) {
        if (a == BTL_EVENT_GetFactorKey(p)) return 0;
        p = BTL_EVENT_FindNextFactor(p);
    }
    return 1;
}

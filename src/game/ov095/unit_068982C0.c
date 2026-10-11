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
 *   func_021D70A8  0x021D70A8  thumb
 *   func_021D732C  0x021D732C  thumb
 *   func_021D7360  0x021D7360  thumb
 */
struct Node;
extern struct Node *func_021D732C(int, int);
extern unsigned short func_021D70A8(struct Node *);
extern struct Node *func_021D7360(struct Node *);
int func_068982C0(int a, int b)
{
    struct Node *p = func_021D732C(1, b);
    while (p != 0) {
        if (a == func_021D70A8(p)) return 0;
        p = func_021D7360(p);
    }
    return 1;
}

/*
 * function: func_021D57B8
 * address:  0x021D57B8
 * packet:   pkt_021D57B8
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_021D56FC  0x021D56FC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021D56FC(char *, int);

void func_021D57B8(char *p, int a)
{
    func_02045CAC(*(void **)(p + 0x20), a, *(void **)(p + 0x2c));
    func_021D56FC(p, 0);
}

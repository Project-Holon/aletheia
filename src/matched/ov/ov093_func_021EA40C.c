/*
 * function: func_021EA40C
 * address:  0x021EA40C
 * packet:   pkt_ov093_021EA40C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021ED294  0x021ED294  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_021CD9E0(u8 *p);
extern void func_021ED294(char *p, int a, u32 b);

void func_021EA40C(char *ctx, int a)
{
    func_021ED294(*(char **)(ctx + 0x17c), a, func_021CD9E0(*(u8 **)(ctx + 4)));
}

/*
 * function: func_021EBFA0
 * address:  0x021EBFA0
 * packet:   pkt_ov093_021EBFA0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B904C  0x021B904C  thumb  ov093
 *   func_021EC0DC  0x021EC0DC  thumb  ov093
 *   func_021EBFDC  0x021EBFDC  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 func_021B904C(u8 *p, int k);
extern int func_021EC0DC(u8 *, int *, u16, u16);
extern int func_021EBFDC(u8 *, int *, u16);
int func_021EBFA0(u8 *p, int *state)
{
    u8 a = func_021B904C(*(void **)(p + 0x134), 0);
    u8 b = func_021B904C(*(void **)(p + 0x134), 1);
    if (a != b)
        return func_021EC0DC(p, state, a, b);
    return func_021EBFDC(p, state, a);
}

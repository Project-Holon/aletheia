/*
 * function: func_021EBF80
 * address:  0x021EBF80
 * packet:   pkt_ov093_021EBF80
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B904C  0x021B904C  thumb  ov093
 *   func_021EBFDC  0x021EBFDC  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 func_021B904C(void *, int);
extern int func_021EBFDC(u8 *, int *, u16);
int func_021EBF80(u8 *p, int *state)
{
    return func_021EBFDC(p, state, func_021B904C(*(void **)(p + 0x134), 0));
}

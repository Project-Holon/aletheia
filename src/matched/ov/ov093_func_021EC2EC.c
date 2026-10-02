/*
 * function: func_021EC2EC
 * address:  0x021EC2EC
 * packet:   pkt_ov093_021EC2EC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B904C  0x021B904C  thumb  ov093
 *   func_021EC478  0x021EC478  thumb  ov093
 *   func_021EC328  0x021EC328  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 func_021B904C(void *, int);
extern int func_021EC478(u8 *, int *, u16, u16);
extern int func_021EC328(u8 *, int *, u16);
int func_021EC2EC(u8 *p, int *state)
{
    u8 a = func_021B904C(*(void **)(p + 0x134), 0);
    u8 b = func_021B904C(*(void **)(p + 0x134), 1);
    if (a != b)
        return func_021EC478(p, state, a, b);
    return func_021EC328(p, state, a);
}

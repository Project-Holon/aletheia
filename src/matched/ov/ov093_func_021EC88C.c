/*
 * function: func_021EC88C
 * address:  0x021EC88C
 * packet:   pkt_ov093_021EC88C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B9000  0x021B9000  thumb  ov093
 *   func_021EC8C4  0x021EC8C4  thumb  ov093
 *   func_021ECA60  0x021ECA60  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021B8FF4(u8 *);
extern u8 func_021B9000(u8 *);
extern int func_021EC8C4(u8 *, int *, u8);
extern int func_021ECA60(u8 *, int *, u32, u8);
int func_021EC88C(u8 *p, int *state)
{
    u8 a = func_021B8FF4(*(u8 **)(p + 0x134));
    u8 b = func_021B9000(*(u8 **)(p + 0x134));
    if (b == 4)
        return func_021EC8C4(p, state, a);
    return func_021ECA60(p, state, a, b);
}

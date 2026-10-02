/*
 * function: func_021B190C
 * address: 0x021B190C
 * packet: pkt_ov013_021B190C
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021B4BAC 0x021B4BAC data a4
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 */
typedef unsigned int u32;
extern void *d_021B4BAC[];
extern u32 func_02087988(void);
extern void func_0208799C(u32);
void *func_021B190C(unsigned int i)
{
    u32 h = func_02087988();
    if (d_021B4BAC[i] != 0) {
        func_0208799C(h);
        return d_021B4BAC[i];
    }
    func_0208799C(h);
    return 0;
}

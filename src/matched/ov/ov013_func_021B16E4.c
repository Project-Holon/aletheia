/*
 * function: func_021B16E4
 * address: 0x021B16E4
 * packet: pkt_ov013_021B16E4
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021B4BC4 0x021B4BC4 data a4
 *   d_021B4BAC 0x021B4BAC data a4
 *   d_021B4BB8 0x021B4BB8 data a4
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 */
typedef unsigned int u32;
extern u32 d_021B4BC4[], d_021B4BAC[], d_021B4BB8[];
extern u32 func_02087988(void);
extern void func_0208799C(u32);
void func_021B16E4(unsigned int i)
{
    u32 h = func_02087988();
    d_021B4BC4[i] = 0;
    d_021B4BAC[i] = 0;
    d_021B4BB8[i] = 0;
    func_0208799C(h);
}

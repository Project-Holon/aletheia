/*
 * function: func_021B3250
 * address: 0x021B3250
 * packet: pkt_ov013_021B3250
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: enum count cast to short preserves the smulbb; short local folded 15*68.
 * symbols:
 *   d_021B3C50 0x021B3C50 data a4
 *   func_021B3018 0x021B3018 arm ov013
 */
extern int d_021B3C50[];
extern void func_021B3018(void);
typedef enum { CountZero } Count;
void func_021B3250(void)
{
    Count n=15;
    short stride=68;
    d_021B3C50[2]=n;
    d_021B3C50[3]=(short)n*stride;
    func_021B3018();
}

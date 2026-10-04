/*
 * function: func_021CDA14
 * address:  0x021CDA14
 * packet:   pkt_ov016_021CDA14
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDA14.c \n *       --func func_021CDA14 --addr 0x021CDA14 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021D157C  0x021D157C  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CDA48  0x021CDA48  arm  ov016
 */

extern int func_021D157C(void);
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021C0E40(unsigned int v);
extern void func_021CDA48(void);

void func_021CDA14(void)
{
    if (func_021D157C())
        return;
    func_021D55A4(3, 0, 20, 8);
    func_021C0E40((unsigned int)func_021CDA48);
}

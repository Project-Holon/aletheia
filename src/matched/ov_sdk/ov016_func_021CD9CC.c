/*
 * function: func_021CD9CC
 * address:  0x021CD9CC
 * packet:   pkt_ov016_021CD9CC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procScene (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD9CC.c \n *       --func func_021CD9CC --addr 0x021CD9CC --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021CDA0C  0x021CDA0C  arm  ov016
 *   func_021CDA10  0x021CDA10  arm  ov016
 *   func_021D1568  0x021D1568  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021D1524  0x021D1524  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CDA14  0x021CDA14  arm  ov016
 */

extern void func_021CDA0C(void);
extern void func_021CDA10(void);
extern int func_021D1568(void);
extern void func_021CFFAC(int no);
extern void func_021D1524(void);
extern void func_021C0E40(void (*scene)(void));
extern void func_021CDA14(void);

void func_021CD9CC(void)
{
    func_021CDA0C();
    func_021CDA10();
    if (func_021D1568())
        return;
    func_021CFFAC(6);
    func_021D1524();
    func_021CFFAC(6);
    func_021C0E40(func_021CDA14);
}

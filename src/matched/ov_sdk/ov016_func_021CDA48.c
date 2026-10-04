/*
 * function: func_021CDA48
 * address:  0x021CDA48
 * packet:   pkt_ov016_021CDA48
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDA48.c \n *       --func func_021CDA48 --addr 0x021CDA48 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CD160  0x021CD160  arm  ov016
 */

extern int func_021D5580(int lcd);
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern void func_021CD160(void);

void func_021CDA48(void)
{
    if (func_021D5580(0))
        return;
    func_021D6090(0, 20);
    func_021C0E50(0, (unsigned int)((void *)1));
    func_021C0E40((unsigned int)func_021CD160);
}

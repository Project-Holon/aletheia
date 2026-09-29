/*
 * function: func_021CCE58
 * address:  0x021CCE58
 * packet:   pkt_ov016_021CCE58
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE58.c \n *       --func func_021CCE58 --addr 0x021CCE58 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021BCB9C  0x021BCB9C  arm  ov016
 *   func_021D5790  0x021D5790  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CCE78  0x021CCE78  arm  ov016
 */

extern void func_021BCB9C(void);
extern int func_021D5790(int frame);
extern void func_021C0E40(void (*scene)(void));
extern void func_021CCE78(void);

void func_021CCE58(void)
{
    func_021BCB9C();
    func_021D5790(8);
    func_021C0E40(func_021CCE78);
}

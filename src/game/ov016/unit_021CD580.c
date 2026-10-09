/*
 * file:     unit_021CD580.c
 * function: func_021CD580
 * address:  0x021CD580
 * packet:   pkt_ov016_021CD580
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetTestCompletet (libdwcutil.TWL.HYB.a scenesettestcomp)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD580.c \n *       --func func_021CD580 --addr 0x021CD580 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   g_021DE620     0x021DE620  data
 *   func_021CD5B0  0x021CD5B0  arm  ov016
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CD61C  0x021CD61C  arm  ov016
 */

extern unsigned char g_021DE620;
extern void func_021CD5B0(void);
extern void func_021BD29C(int msgId);
extern void func_021C0E40(unsigned int v);
extern void func_021CD61C(void);

void func_021CD580(void)
{
    g_021DE620 = 0;
    func_021CD5B0();
    func_021BD29C(45);
    func_021C0E40((unsigned int)func_021CD61C);
}

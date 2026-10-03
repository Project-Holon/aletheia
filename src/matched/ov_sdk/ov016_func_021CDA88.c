/*
 * function: func_021CDA88
 * address:  0x021CDA88
 * packet:   pkt_ov016_021CDA88
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetUsbComplete (libdwcutil.TWL.HYB.a scenesetusbcompl)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDA88.c \n *       --func func_021CDA88 --addr 0x021CDA88 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   g_021DE624     0x021DE624  data
 *   func_021CDAC8  0x021CDAC8  arm  ov016
 *   func_021BD674  0x021BD674  arm  ov016
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CDB48  0x021CDB48  arm  ov016
 */

extern unsigned char g_021DE624;
extern void func_021CDAC8(void);
extern void func_021BD674(int idx);
extern void func_021BD29C(int msgId);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(void (*scene)(void));
extern void func_021CDB48(void);

void func_021CDA88(void)
{
    g_021DE624 = 0;
    func_021CDAC8();
    func_021BD674(8);
    func_021BD29C(41);
    func_021CFFAC(16);
    func_021C0E40(func_021CDB48);
}

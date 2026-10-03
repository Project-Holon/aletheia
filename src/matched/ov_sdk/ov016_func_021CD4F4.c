/*
 * function: func_021CD4F4
 * address:  0x021CD4F4
 * packet:   pkt_ov016_021CD4F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      taskAc (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD4F4.c \n *       --func func_021CD4F4 --addr 0x021CD4F4 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_0205BC78  0x0205BC78  arm
 *   func_021BD7F4  0x021BD7F4  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_0205BD64  0x0205BD64  arm
 *   func_021C82EC  0x021C82EC  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D7724  0x021D7724  arm  ov016
 *   g_021DE61C     0x021DE61C  data
 *   func_021CD40C  0x021CD40C  arm  ov016
 */

extern int func_0205BC78(void);
extern void func_021BD7F4(void);
extern void func_021D0014(void);
extern int func_0205BD64(void);
extern void func_021C82EC(unsigned int v);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(void (*scene)(void));
extern void func_021D7724(int kind, void *task);
extern unsigned char g_021DE61C;
extern void func_021CD40C(void);

void func_021CD4F4(void *task)
{
    int rs = func_0205BC78();
    if (rs == 0)
        return;
    func_021BD7F4();
    func_021D0014();
    if (rs > 0) {
        g_021DE61C = 1;
        func_021CFFAC(17);
    } else {
        func_021C82EC(func_0205BD64());
        func_021CFFAC(18);
    }
    func_021C0E40(func_021CD40C);
    func_021D7724(0, task);
}

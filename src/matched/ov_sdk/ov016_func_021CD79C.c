/*
 * function: func_021CD79C
 * address:  0x021CD79C
 * packet:   pkt_ov016_021CD79C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      wait (libdwcutil.TWL.HYB.a scenesettestcomp)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD79C.c \n *       --func func_021CD79C --addr 0x021CD79C --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   g_021DE620     0x021DE620  data
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021C0ED8  0x021C0ED8  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C1630  0x021C1630  arm  ov016
 *   func_021CD690  0x021CD690  arm  ov016
 */

extern unsigned char g_021DE620;
extern void func_021C0EA0(void **param2, void **param3);
extern int func_021C0ED8(void);
extern void func_021C0E40(void (*scene)(void));
extern void func_021C1630(void);
extern void func_021CD690(void);

void func_021CD79C(void)
{
    int scene;
    int r;
    if (++g_021DE620 < 180)
        return;
    func_021C0EA0(0, (void **)&scene);
    r = func_021C0ED8();
    if (r != 0 && r == 1 && scene != 0) {
        func_021C0E40(func_021C1630);
        return;
    }
    func_021C0E40(func_021CD690);
}

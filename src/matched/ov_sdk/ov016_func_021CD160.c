/*
 * function: func_021CD160
 * address:  0x021CD160
 * packet:   pkt_ov016_021CD160
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetTest (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD160.c \n *       --func func_021CD160 --addr 0x021CD160 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   g_021DE61C     0x021DE61C  data
 *   func_021CD1F8  0x021CD1F8  arm  ov016
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021BD060  0x021BD060  arm  ov016
 *   func_021BD214  0x021BD214  arm  ov016
 *   func_021BD6D4  0x021BD6D4  arm  ov016
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021BC820  0x021BC820  arm  ov016
 *   func_021CD2A0  0x021CD2A0  arm  ov016
 *   func_021BD744  0x021BD744  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CD338  0x021CD338  arm  ov016
 */

extern unsigned char g_021DE61C;
extern void func_021CD1F8(void);
extern void func_021C0EA0(void **param2, void **param3);
extern int func_021BD060(int messageId, int n, int num);
extern void func_021BD214(int step);
extern void func_021BD6D4(void);
extern void func_021BD29C(int msgId);
extern void func_021BC820(int color);
extern void func_021CD2A0(void);
extern void func_021BD744(int type);
extern void func_021CFFAC(int no);
extern void func_021C0E40(void (*scene)(void));
extern void func_021CD338(void);

void func_021CD160(void)
{
    int scene;
    g_021DE61C = 0;
    func_021CD1F8();
    func_021C0EA0(0, (void **)&scene);
    if (scene == 0)
        func_021BD060(49, -1, 0);
    func_021BD214(2);
    if (scene == 0)
        func_021BD6D4();
    func_021BD29C(44);
    func_021BC820(0);
    func_021CD2A0();
    func_021BD744(0);
    func_021CFFAC(12);
    func_021C0E40(func_021CD338);
}

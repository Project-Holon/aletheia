/*
 * function: func_021CD690
 * address:  0x021CD690
 * packet:   pkt_ov016_021CD690
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a scenesettestcomp)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD690.c \n *       --func func_021CD690 --addr 0x021CD690 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021D0580  0x021D0580  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CD6F0  0x021CD6F0  arm  ov016
 */

extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern void func_021D0580(void);
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021C0E40(unsigned int v);
extern void func_021CD6F0(void);

void func_021CD690(void)
{
    int scene;
    func_021C0EA0(0, (unsigned int *)((void **)&scene));
    if (scene != 0)
        func_021D0580();
    func_021D55A4(3, 1, 1, 8);
    func_021D55A4(3, 0, 21, 8);
    func_021C0E40((unsigned int)func_021CD6F0);
}

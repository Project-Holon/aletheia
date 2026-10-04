/*
 * function: func_021CD6F0
 * address:  0x021CD6F0
 * packet:   pkt_ov016_021CD6F0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettestcomp)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD6F0.c \n *       --func func_021CD6F0 --addr 0x021CD6F0 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021D0A84  0x021D0A84  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021C0E8C  0x021C0E8C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C82FC  0x021C82FC  arm  ov016
 *   func_021C1984  0x021C1984  arm  ov016
 */

extern int func_021D5580(int lcd);
extern int func_021D0A84(void);
extern void func_021D5CA8(int lcd);
extern int func_021BD138(void);
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0EA0(void **param2, void **param3);
extern void func_021C0E8C(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern void func_021C82FC(void);
extern void func_021C1984(void);

void func_021CD6F0(void)
{
    int scene;
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    if (!func_021D0A84())
        return;
    func_021D5CA8(0);
    func_021BD138();
    func_021D6090(1, 1);
    func_021D6090(0, 21);
    func_021C0E50((unsigned int)((void *)2), (unsigned int)((void *)1));
    func_021C0EA0(0, (void **)&scene);
    if (scene == 0) {
        func_021C0E8C(0, 0);
        func_021C0E40((unsigned int)func_021C82FC);
        return;
    }
    func_021C0E40((unsigned int)func_021C1984);
}

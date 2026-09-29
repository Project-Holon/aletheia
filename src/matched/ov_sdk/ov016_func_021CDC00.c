/*
 * function: func_021CDC00
 * address:  0x021CDC00
 * packet:   pkt_ov016_021CDC00
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesetusbcompl)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDC00.c \n *       --func func_021CDC00 --addr 0x021CDC00 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E8C  0x021C0E8C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CD80C  0x021CD80C  arm  ov016
 */

extern int func_021D5580(int lcd);
extern void func_021D5CA8(int lcd);
extern int func_021BD138(void);
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(void *param0, void *param1);
extern void func_021C0E8C(void *param2, void *param3);
extern void func_021C0E40(void (*scene)(void));
extern void func_021CD80C(void);

void func_021CDC00(void)
{
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    func_021D5CA8(0);
    func_021BD138();
    func_021D6090(1, 1);
    func_021D6090(0, 21);
    func_021C0E50(0, 0);
    func_021C0E8C(0, (void *)2);
    func_021C0E40(func_021CD80C);
}

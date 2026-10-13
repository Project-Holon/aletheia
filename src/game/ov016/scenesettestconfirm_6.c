/*
 * file:     scenesettestconfirm_6.c
 * unit:     yes
 * function: func_021CDA14, func_021CDA48
 * address:  0x021CDA14
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D157C  0x021D157C  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021CD160  0x021CD160  arm  ov016
 */
extern int func_021D157C(void);
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021C0E40(unsigned int v);
extern int func_021D5580(int lcd);
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021CD160(void);
void func_021CDA14(void);
void func_021CDA48(void);


/*
 * sdk:      endScene (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDA14.c \n *       --func func_021CDA14 --addr 0x021CDA14 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CDA14(void)
{
    if (func_021D157C())
        return;
    func_021D55A4(3, 0, 20, 8);
    func_021C0E40((unsigned int)func_021CDA48);
}


/*
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDA48.c \n *       --func func_021CDA48 --addr 0x021CDA48 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CDA48(void)
{
    if (func_021D5580(0))
        return;
    func_021D6090(0, 20);
    func_021C0E50(0, (unsigned int)((void *)1));
    func_021C0E40((unsigned int)func_021CD160);
}

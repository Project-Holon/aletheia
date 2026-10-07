/*
 * file:     unit_021C7768_p01.c
 * unit:     yes
 * function: func_021C7768, func_021C77F4
 * address:  0x021C7768
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
 *   func_021BF730  0x021BF730  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   g_021DE5E4     0x021DE5E4  data
 *   func_021C7C74  0x021C7C74  arm  ov016
 *   func_021C79B4  0x021C79B4  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6F38  0x021D6F38  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD1D4  0x021BD1D4  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E8C  0x021C0E8C  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DB550     0x021DB550  data
 *   func_0207E51C  0x0207E51C  arm
 *   func_021C82FC  0x021C82FC  arm  ov016
 */
#include "../../matched/include/G_MemSsea.h"

typedef struct MemSsea MemSsea;

extern int func_021BF730();
extern void func_021C0E40(unsigned int v);
extern void func_021D1208(int msg, int type, unsigned char dark, int n, int num);
extern void func_021C7C74();
extern void func_021C79B4();
extern void func_021BD138();
extern void func_021D6F38(unsigned int *obj);
extern void func_021D5CA8(int a);
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void func_021D6090(int lcd, int plane);
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E8C(unsigned int a, unsigned int b);
extern void func_021D6438(void **mem);
extern void func_0207E51C();
extern void func_021C82FC();
void func_021C7768(void);
void func_021C77F4(void);
extern struct MemSsea *g_021DE5E4;
extern unsigned char g_021DB550[];


/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 */
void func_021C7768(void)
{
    int r;

    if (func_021BF730())
        return;
    r = g_021DE5E4->result;
    if (r == 0) {
        func_021C0E40((unsigned int)func_021C77F4);
    } else if (r == 2) {
        func_021D1208(6, 3, 1, -1, 0);
        func_021C0E40((unsigned int)func_021C7C74);
    } else {
        func_021D1208(0x47, 2, 1, -1, 0);
        func_021C0E40((unsigned int)func_021C79B4);
    }
}


/*
 * sdk:      endScene3 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 */
void func_021C77F4(void)
{
    int prm;

    func_021BD138();
    func_021D6F38(g_021DE5E4->caret);
    func_021D5CA8(0);
    func_021BD1D4((char *)g_021DB550, func_0207E51C);
    func_021D6090(1, 1);
    func_021D6090(0, 0x15);
    func_021C0EA0((unsigned int *)(&prm), 0);
    if (prm >= 3)
        prm++;
    func_021C0E50(2, 1);
    func_021C0E8C(0, prm + 3);
    func_021C0E40((unsigned int)func_021C82FC);
    func_021D6438((void *)0x021DE5E4);
}

/*
 * file:     unit_021C7768_p02.c
 * unit:     yes
 * function: func_021C79B4, func_021C7A0C
 * address:  0x021C79B4
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
 *   func_021D1568  0x021D1568  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021D1524  0x021D1524  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5E4     0x021DE5E4  data
 *   func_021D157C  0x021D157C  arm  ov016
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   g_021DB4DC     0x021DB4DC  data
 *   func_021C7314  0x021C7314  arm  ov016
 *   func_021C77F4  0x021C77F4  arm  ov016
 */
#include "../../matched/include/G_MemSsea.h"

typedef struct MemSsea MemSsea;

typedef struct GXOamAttr {
    unsigned int attr01;
    unsigned short attr2;
    unsigned short attr3;
} GXOamAttr;

typedef struct FuncTable {
    void (*f[5])(char *);
} FuncTable;

extern signed char func_021D1568(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021D1524();
extern void func_021C0E40(unsigned int v);
extern int func_021D157C();
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern void func_021C7314();
extern void func_021C77F4();
void func_021C79B4(void);
void func_021C7A0C(void);
extern struct MemSsea *g_021DE5E4;
extern FuncTable g_021DB4DC;


/*
 * sdk:      procWin (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 */
void func_021C79B4(void)
{
    g_021DE5E4->result = func_021D1568();
    switch (g_021DE5E4->result) {
    case 0:
        func_021CFFAC(7);
        break;
    case 1:
        func_021CFFAC(0xE);
        break;
    default:
        return;
    }
    func_021D1524();
    func_021C0E40((unsigned int)func_021C7A0C);
}


/*
 * sdk:      procWin1 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 */
void func_021C7A0C(void)
{
    FuncTable FUNC = g_021DB4DC;
    int prm;

    if (func_021D157C())
        return;
    if (g_021DE5E4->result == 0) {
        ((GXOamAttr *)g_021DE5E4->caret)->attr01 &= 0xC1FFFCFF;
        func_021C0E40((unsigned int)func_021C7314);
        return;
    }
    func_021C0EA0((unsigned int *)(&prm), 0);
    FUNC.f[prm]((char *)g_021DE5E4 + 8);
    func_021C0E40((unsigned int)func_021C77F4);
}

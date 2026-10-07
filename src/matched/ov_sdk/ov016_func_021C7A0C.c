/*
 * function: func_021C7A0C
 * address:  0x021C7A0C
 * packet:   pkt_ov016_021C7A0C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procWin1 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   func_021D157C  0x021D157C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   g_021DB4DC     0x021DB4DC  data
 *   g_021DE5E4     0x021DE5E4  data
 *   func_021C7314  0x021C7314  arm  ov016
 *   func_021C77F4  0x021C77F4  arm  ov016
 */

#include "../include/G_MemSsea.h"

typedef struct GXOamAttr {
    unsigned int attr01;
    unsigned short attr2;
    unsigned short attr3;
} GXOamAttr;

typedef struct MemSsea MemSsea;

typedef struct FuncTable {
    void (*f[5])(char *);
} FuncTable;

extern int func_021D157C();
extern void func_021C0E40(unsigned int v);
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern void func_021C7314();
extern void func_021C77F4();
extern struct MemSsea *g_021DE5E4;
extern FuncTable g_021DB4DC;

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

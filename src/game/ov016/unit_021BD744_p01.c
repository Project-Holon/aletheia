/*
 * file:     unit_021BD744_p01.c
 * unit:     yes
 * function: func_021BD7F4, func_021BD834
 * address:  0x021BD7F4
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
 *   func_021D7744  0x021D7744  arm  ov016
 *   func_021D6F38  0x021D6F38  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE558  0x021DE558  data
 *   g_021DE558_b  0x021DE558  data
 *   func_0208EE60  0x0208EE60  arm
 *   func_0208EE9C  0x0208EE9C  arm
 *   func_021D52D4  0x021D52D4  arm  ov016
 *   g_021DA090     0x021DA090  data
 */
#include "../../matched/include/G_MemIcon.h"

typedef struct MemIcon MemIcon;

typedef struct GXOamAttr {
    union {
        struct {
            unsigned short attr0;
            unsigned short attr1;
        } h;
        unsigned int attr01;
    } u;
    unsigned short attr2;
    unsigned short attr3;
} GXOamAttr;

typedef enum { LV0, LV1, LV2, LV3 } WMLinkLevel;

extern void func_021D7744(unsigned int idx, void *r4);
extern void func_021D6F38(unsigned int *obj);
extern void func_021D6438(void **mem);
extern unsigned short func_0208EE60(void);
extern WMLinkLevel func_0208EE9C(void);
extern void func_021D52D4(int lcd, int idx, GXOamAttr *obj);
void func_021BD7F4(void);
void func_021BD834(void);
extern struct MemIcon *g_021DE558;
extern struct MemIcon *g_021DE558_b;
extern unsigned char g_021DA090[][4];


/*
 * sdk:      DWCi_ICONlEnd (libdwcutil.TWL.HYB.a(icon.o))
 */
void func_021BD7F4(void)
{
    if (g_021DE558 == 0)
        return;
    func_021D7744(0, g_021DE558->task);
    func_021D6F38(g_021DE558->obj);
    func_021D6438((void **)(&g_021DE558_b));
}


/*
 * sdk:      taskRenew (libdwcutil.TWL.HYB.a icon.o)
 */
void func_021BD834(void)
{
    WMLinkLevel lv = 0;
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short old = *ime;
    *ime = 0;
    if (func_0208EE60() != 0x8000)
        lv = func_0208EE9C();
    (void)*ime;
    *ime = old;
    func_021D52D4(0, g_021DA090[g_021DE558->type][lv], g_021DE558->obj);
    ((GXOamAttr *)g_021DE558->obj)->u.attr01 = (((GXOamAttr *)g_021DE558->obj)->u.attr01 & 0xFE00FF00) | 0x26 | (0xE5 << 16);
    ((GXOamAttr *)g_021DE558->obj)->attr2 = (((GXOamAttr *)g_021DE558->obj)->attr2 & ~0xC00) | 0x800;
}

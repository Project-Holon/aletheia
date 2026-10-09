/*
 * file:     unit_021BD744.c
 * unit:     yes
 * function: func_021BD744, func_021BD7F4, func_021BD834
 * address:  0x021BD744
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5368  0x021D5368  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   g_021DE558     0x021DE558  data
 *   g_021DA090     0x021DA090  data
 *   func_021D7744  0x021D7744  arm  ov016
 *   func_021D6F38  0x021D6F38  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE558_b  0x021DE558  data
 *   func_0208EE60  0x0208EE60  arm
 *   func_0208EE9C  0x0208EE9C  arm
 *   func_021D52D4  0x021D52D4  arm  ov016
 */
#include "../../matched/include/G_MemIcon.h"

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

typedef struct MemIcon MemIcon;

typedef enum { LV0, LV1, LV2, LV3 } WMLinkLevel;

extern void *func_021D6414(unsigned long size, int alignment);
extern GXOamAttr *func_021D5368(int lcd, int idx);
extern void *func_021D7680(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021D7744(unsigned int idx, void *r4);
extern void func_021D6F38(unsigned int *obj);
extern void func_021D6438(void **mem);
extern unsigned short func_0208EE60(void);
extern WMLinkLevel func_0208EE9C(void);
extern void func_021D52D4(int lcd, int idx, GXOamAttr *obj);
void func_021BD744(int type);
void func_021BD7F4(void);
void func_021BD834(void);
extern struct MemIcon *g_021DE558;
extern unsigned char g_021DA090[][4];
extern struct MemIcon *g_021DE558_b;


void func_021BD744(int type)
{
    int idx;
    if (g_021DE558 != 0)
        return;
    g_021DE558 = func_021D6414(12, 4);
    idx = *((unsigned char *)g_021DA090 + (type << 2));
    g_021DE558->type = type;
    g_021DE558->obj = func_021D5368(0, idx);
    ((GXOamAttr *)g_021DE558->obj)->u.attr01 = (((GXOamAttr *)g_021DE558->obj)->u.attr01 & 0xFE00FF00) | 0x26 | (0xE5 << 16);
    ((GXOamAttr *)g_021DE558->obj)->attr2 = (((GXOamAttr *)g_021DE558->obj)->attr2 & ~0xC00) | 0x800;
    g_021DE558->task = func_021D7680(0, (void (*)(void *, void *))func_021BD834, 0, 0x78);
}



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

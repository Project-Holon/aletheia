/*
 * function: func_021BD834
 * address:  0x021BD834
 * packet:   pkt_ov016_021BD834
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskRenew (libdwcutil.TWL.HYB.a icon.o)
 *
 * symbols:
 *   func_0208EE60  0x0208EE60  arm
 *   func_0208EE9C  0x0208EE9C  arm
 *   func_021D52D4  0x021D52D4  arm  ov016
 *   g_021DE558     0x021DE558  data
 *   g_021DA090     0x021DA090  data
 */

#include "../include/G_MemIcon.h"

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

extern unsigned short func_0208EE60(void);
extern WMLinkLevel func_0208EE9C(void);
extern void func_021D52D4(int lcd, int idx, GXOamAttr *obj);
extern struct MemIcon *g_021DE558;
extern unsigned char g_021DA090[][4];

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

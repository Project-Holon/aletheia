/*
 * function: DWCi_ICONlInit
 * address:  0x021BD744
 * packet:   pkt_ov016_021BD744
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ICONlInit (libdwcutil.TWL.HYB.a icon.o)
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_CEINlSetExObj  0x021D5368  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   gIconWork     0x021DE558  data
 *   sIconCellIds     0x021DA090  data
 *   func_021BD834  0x021BD834  arm  ov016
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

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021BD834(void);
extern struct MemIcon *gIconWork;
extern unsigned char sIconCellIds[4][2];

void DWCi_ICONlInit(int type)
{
    int idx;
    if (gIconWork != 0)
        return;
    gIconWork = DWCi_HEAPlAllocEx(12, 4);
    idx = *((unsigned char *)sIconCellIds + (type << 2));
    gIconWork->type = type;
    gIconWork->obj = DWCi_CEINlSetExObj(0, idx);
    ((GXOamAttr *)gIconWork->obj)->u.attr01 = (((GXOamAttr *)gIconWork->obj)->u.attr01 & 0xFE00FF00) | 0x26 | (0xE5 << 16);
    ((GXOamAttr *)gIconWork->obj)->attr2 = (((GXOamAttr *)gIconWork->obj)->attr2 & ~0xC00) | 0x800;
    gIconWork->task = DWCi_TSKlForm(0, (void (*)(void *, void *))func_021BD834, 0, 0x78);
}

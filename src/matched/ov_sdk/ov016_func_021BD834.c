/*
 * function: taskRenew
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
 *   WM_GetAllowedChannel  0x0208EE60  arm
 *   WM_GetLinkLevel  0x0208EE9C  arm
 *   DWCi_CEINlSet  0x021D52D4  arm  ov016
 *   gIconWork     0x021DE558  data
 *   sIconCellIds     0x021DA090  data
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

extern unsigned short WM_GetAllowedChannel(void);
extern WMLinkLevel WM_GetLinkLevel(void);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern struct MemIcon *gIconWork;
extern unsigned char sIconCellIds[][4];

void taskRenew(void)
{
    WMLinkLevel lv = 0;
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short old = *ime;
    *ime = 0;
    if (WM_GetAllowedChannel() != 0x8000)
        lv = WM_GetLinkLevel();
    (void)*ime;
    *ime = old;
    DWCi_CEINlSet(0, sIconCellIds[gIconWork->type][lv], gIconWork->obj);
    ((GXOamAttr *)gIconWork->obj)->u.attr01 = (((GXOamAttr *)gIconWork->obj)->u.attr01 & 0xFE00FF00) | 0x26 | (0xE5 << 16);
    ((GXOamAttr *)gIconWork->obj)->attr2 = (((GXOamAttr *)gIconWork->obj)->attr2 & ~0xC00) | 0x800;
}

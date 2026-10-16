/*
 * file:     icon.c
 * unit:     yes
 * function: DWCi_ICONlInit, DWCi_ICONlEnd, taskRenew
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
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_CEINlSetExObj  0x021D5368  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   gIconWork     0x021DE558  data
 *   sIconCellIds     0x021DA090  data
 *   DWCi_TSKlDeleteByIndex  0x021D7744  arm  ov016
 *   DWCi_OBJlDelete  0x021D6F38  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gMemIcon  0x021DE558  data
 *   WM_GetAllowedChannel  0x0208EE60  arm
 *   WM_GetLinkLevel  0x0208EE9C  arm
 *   DWCi_CEINlSet  0x021D52D4  arm  ov016
 */
#include "../../matched/include/G_MemIcon.h"

#include "gx_oam_types.h"

typedef struct MemIcon MemIcon;

typedef enum { LV0, LV1, LV2, LV3 } WMLinkLevel;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void DWCi_TSKlDeleteByIndex(unsigned int idx, void *r4);
extern void DWCi_OBJlDelete(unsigned int *obj);
extern void DWCi_HEAPlFree_(void **mem);
extern unsigned short WM_GetAllowedChannel(void);
extern WMLinkLevel WM_GetLinkLevel(void);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
void DWCi_ICONlInit(int type);
void DWCi_ICONlEnd(void);
extern struct MemIcon *gIconWork;
extern unsigned char sIconCellIds[][4];
extern struct MemIcon *gMemIcon;

static void taskRenew(void);


void DWCi_ICONlInit(int type)
{
    int idx;
    if (gIconWork != 0)
        return;
    gIconWork = DWCi_HEAPlAllocEx(12, 4);
    idx = *((unsigned char *)sIconCellIds + (type << 2));
    gIconWork->type = type;
    gIconWork->obj = DWCi_CEINlSetExObj(0, idx);
    ((GXOamAttr *)gIconWork->obj)->attr01 = (((GXOamAttr *)gIconWork->obj)->attr01 & 0xFE00FF00) | 0x26 | (0xE5 << 16);
    ((GXOamAttr *)gIconWork->obj)->attr2 = (((GXOamAttr *)gIconWork->obj)->attr2 & ~0xC00) | 0x800;
    gIconWork->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskRenew, 0, 0x78);
}


/*
 * sdk:      DWCi_ICONlEnd (libdwcutil.TWL.HYB.a(icon.o))
 */
void DWCi_ICONlEnd(void)
{
    if (gIconWork == 0)
        return;
    DWCi_TSKlDeleteByIndex(0, gIconWork->task);
    DWCi_OBJlDelete(gIconWork->obj);
    DWCi_HEAPlFree_((void **)(&gMemIcon));
}


/*
 * sdk:      taskRenew (libdwcutil.TWL.HYB.a icon.o)
 */
static void taskRenew(void)
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
    ((GXOamAttr *)gIconWork->obj)->attr01 = (((GXOamAttr *)gIconWork->obj)->attr01 & 0xFE00FF00) | 0x26 | (0xE5 << 16);
    ((GXOamAttr *)gIconWork->obj)->attr2 = (((GXOamAttr *)gIconWork->obj)->attr2 & ~0xC00) | 0x800;
}

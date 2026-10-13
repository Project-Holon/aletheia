/*
 * function: SCRCMD_PROC_FLD_CreateItemListMenu
 * address:  0x021B43EC
 * packet:   pkt_ov021_021B43EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a 0x34-byte list template on the stack (layout as read by
 * BMP_MENULIST_Create) and creates the list object from it.
 *
 * symbols:
 *   SCRCMD_PROC_FLD_OnListCursorMove 0x021B468C thumb ov021
 *   SCRCMD_PROC_FLD_PrintPriceEntry 0x021B4510 thumb ov021
 *   SCRCMD_PROC_FLD_PrintUniqueItemEntry 0x021B45A0 thumb ov021
 *   BMP_MENUWORK_CountItems 0x0201F91C thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 */
#include "../include/Obj00037.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *arr;
    void *cb04;
    void *cb08;
    u32 w0c;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
    void *w1c;
    u16 h20;
    u16 h22;
    u32 w24;
    void *w28;
    u32 w2c;
    u32 w30;
} Tmpl;

extern void SCRCMD_PROC_FLD_OnListCursorMove(u32 a, u32 idx);
struct Slot;
extern void SCRCMD_PROC_FLD_PrintPriceEntry(u8 *p, int a, u8 b);
extern void SCRCMD_PROC_FLD_PrintUniqueItemEntry(u32 unused, int a, u8 b);
extern u32 BMP_MENUWORK_CountItems(struct Slot *s);
struct Obj;
struct Src;
extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);

void SCRCMD_PROC_FLD_CreateItemListMenu(char *w)
{
    Tmpl t;

    t.arr = ((struct Obj00037 *)w)->f180;
    t.cb04 = (void *)SCRCMD_PROC_FLD_OnListCursorMove;
    if (((struct Obj00037 *)w)->f162 == 0) {
        t.cb08 = (void *)SCRCMD_PROC_FLD_PrintPriceEntry;
    } else {
        t.cb08 = (void *)SCRCMD_PROC_FLD_PrintUniqueItemEntry;
    }
    t.w0c = ((struct Obj00037 *)w)->f16C;
    t.count = BMP_MENUWORK_CountItems(((struct Obj00037 *)w)->f180);
    t.rows = 7;
    t.f14 = 0;
    t.f15 = 0;
    t.f16 = 0;
    t.f17lo = 8;
    t.f17hi = 0xC;
    t.f18lo = 0;
    t.f18hi = 0xD;
    t.f1Alo = 0;
    t.f1Amid = 0;
    t.f1Apad = 1;
    t.f1Amid2 = 0;
    t.f1Atop = 1;
    t.w1c = w;
    t.h20 = 0xC;
    t.h22 = 0x10;
    t.w24 = 0;
    t.w28 = w + 0x1A8;
    t.w2c = ((struct Obj00037 *)w)->f1B0;
    t.w30 = ((struct Obj00037 *)w)->f8;
    ((struct Obj00037 *)w)->f1A4 = (unsigned int)BMP_MENULIST_Create((struct Src *)(&t), 0, 0, ((struct Obj00037 *)w)->f4);
}

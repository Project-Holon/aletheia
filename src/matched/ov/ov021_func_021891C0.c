/*
 * function: FIELDMAP_SetupBbdColor
 * address:  0x021891C0
 * packet:   pkt_ov021_021891C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_GetAreaBillboardColor  0x020140E4  thumb
 *   FIELD_BBD_COLOR_Create  0x021CD1C8  thumb
 *   FIELD_BBD_COLOR_Load  0x021CD204  thumb
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   FIELD_BBD_COLOR_Apply  0x021CD214  thumb
 *   FIELD_BBD_COLOR_Delete  0x021CD1F0  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09442.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Sub020140BCObj;
extern u8 ZONEDATA_GetAreaBillboardColor(struct Sub020140BCObj *p);
extern u32 FIELD_BBD_COLOR_Create(u32 a);
extern void FIELD_BBD_COLOR_Load(u32 a, u32 b);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void FIELD_BBD_COLOR_Apply(u8 *s, void *o);
extern int FIELD_BBD_COLOR_Delete(void *a);

void FIELDMAP_SetupBbdColor(u8 *a)
{
    u16 v = (((struct Obj09442 *)a)->f0 & 0x7FFF) | 0x8000;
    u32 h;
    u32 t;

    t = ZONEDATA_GetAreaBillboardColor((struct Sub020140BCObj *)(((struct Obj09442 *)a)->fC));
    h = FIELD_BBD_COLOR_Create(v);
    FIELD_BBD_COLOR_Load(h, t);
    FIELD_BBD_COLOR_Apply((u8 *)h, (void *)BILLBOARD_ACT_GetBoard((u32 *)(((struct Obj09442 *)a)->fB0)));
    FIELD_BBD_COLOR_Delete((void *)h);
}

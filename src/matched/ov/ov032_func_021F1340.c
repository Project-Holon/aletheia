/*
 * function: BEACON_VIEW_StartSlide
 * address:  0x021F1340
 * packet:   pkt_ov032_021F1340
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_StartSlide 0x021F1340 thumb
 *   BEACON_VIEW_SetPrintQueueLimit 0x021F029C thumb
 *   BEACON_VIEW_SetActorAnim 0x021F0DF4 thumb
 *   BEACON_VIEW_SetArrowAnim 0x021F05E8 thumb
 *   BEACON_VIEW_ScrollList 0x021F12B8 thumb
 */
#include "../include/Obj00188.h"

typedef unsigned char u8;

extern void BEACON_VIEW_SetPrintQueueLimit(char *this, int a);
extern void BEACON_VIEW_SetActorAnim(void *p, unsigned short v);
typedef unsigned int   u32;
extern void BEACON_VIEW_SetArrowAnim(u8 *p, int a, u32 b);
extern void BEACON_VIEW_ScrollList(u8 *this, int dir);

void BEACON_VIEW_StartSlide(char *this, int a, u8 b)
{
    this[0x81] = 1;
    this[0x82] = 0;
    ((struct Obj00188 *)this)->f84 = a;
    this[0x83] = b;
    ((struct Obj00188 *)this)->f88 = 0;
    BEACON_VIEW_SetPrintQueueLimit(this, 1);
    if (((struct Obj00188 *)this)->f84 == 0)
        BEACON_VIEW_SetActorAnim((void *)(((struct Obj00188 *)this)->f2D0), 0x13);
    else
        BEACON_VIEW_SetActorAnim((void *)(((struct Obj00188 *)this)->f2CC), 0xf);
    BEACON_VIEW_SetArrowAnim((u8 *)this, 4, 2);
    BEACON_VIEW_ScrollList((u8 *)this, a);
}

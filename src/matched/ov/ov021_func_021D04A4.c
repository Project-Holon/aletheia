/*
 * function: FLDEFF_HIDE_RequestEnd
 * address:  0x021D04A4
 * packet:   pkt_ov021_021D04A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked: sHideEndSeIds (u32 table indexed by e->fC) is contested: another
 * overlay in the window starts an object at 0x021DB934 and this function has
 * no overlay_id site, so the ABS32 word stays wildcarded.
 *
 * symbols:
 *   sHideEndSeIds     0x021DB934  data  a4
 *   func_020061E4  0x020061E4  thumb
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb  ov021
 */
#include "../include/Obj13000.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELD_EFFECT_GetObjectWork(u32 a);
extern void func_020061E4(u32 a);
extern int sHideEndSeIds[];

void FLDEFF_HIDE_RequestEnd(void *a)
{
    u8 *e;

    if (a != 0) {
        e = (u8 *)FIELD_EFFECT_GetObjectWork((u32)a);
        ((struct Obj13000 *)e)->f1A = 1;
        func_020061E4(sHideEndSeIds[((struct Obj13000 *)e)->fC]);
    }
}

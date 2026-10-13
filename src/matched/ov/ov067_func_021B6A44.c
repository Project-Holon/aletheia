/*
 * function: TOUCHBAR_OnPressToggle
 * address:  0x021B6A44
 * packet:   pkt_ov067_021B6A44
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOUCHBAR_IsButtonDown  0x021B69F8  thumb
 *   TOUCHBAR_SetButtonToggle  0x021B69D8  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */
#include "../include/Obj13132.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 TOUCHBAR_IsButtonDown(u32 p);
struct S;
extern void TOUCHBAR_SetButtonToggle(struct S *p, u32 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void TOUCHBAR_OnPressToggle(u8 *p)
{
    u32 a = TOUCHBAR_IsButtonDown((u32)p);
    int b = 1;

    if (a != 0) {
        b = 0;
    }
    TOUCHBAR_SetButtonToggle((struct S *)p, b);
    if (((struct Obj13132 *)p)->f34 != 0) {
        GFL_USE_PlaySeDefaultVolume(((struct Obj13132 *)p)->f34);
    }
}

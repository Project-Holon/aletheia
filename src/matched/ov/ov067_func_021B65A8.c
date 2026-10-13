/*
 * unit: yes
 * function: TOUCHBAR_IsButtonToggled, TOUCHBAR_ResetAndEnableButton
 * address: 0x021B65A8
 * packet: pkt_ov067_021B65A8
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Extent includes the unlabelled tail-call follower at 0x021B65B4.
 * symbols:
 *   TOUCHBAR_GetButton 0x021B6600 thumb ov067
 *   TOUCHBAR_IsButtonDown 0x021B69F8 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 */
#include "../include/Obj07675.h"
extern void *TOUCHBAR_GetButton(unsigned char *p, unsigned int id);
typedef unsigned int   u32;
extern u32 TOUCHBAR_IsButtonDown(u32 p);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);

int TOUCHBAR_IsButtonToggled(unsigned char *p, int id)
{
    return TOUCHBAR_IsButtonDown((u32)TOUCHBAR_GetButton(p, id));
}

int TOUCHBAR_ResetAndEnableButton(unsigned char *p, unsigned int id)
{
    *(int *)&((struct Obj07675 *)p)->f8 = 0;
    *(int *)&((struct Obj07675 *)p)->f0 = -1;
    return TOUCHBAR_SetButtonEnabled(p, id, 1);
}

/*
 * function: REPORT_EVENT_EndAvatarAnim
 * address:  0x0216A1F8
 * packet:   pkt_0216A1F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_CheckNotWaterForm  0x021A3208  thumb
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb
 */
#include "../include/Obj17752.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FIELDMAP_GetFieldPlayer(unsigned char *p);
extern int FIELD_PLAYER_CheckNotWaterForm();
extern int FIELD_PLAYER_StartFormChange();
extern int FIELD_PLAYER_StepFormChange();

void REPORT_EVENT_EndAvatarAnim(int a0)
{
    int a1;
    void *v0;

a0 = ((struct Obj17752 *)a0)->f8;
    v0 = FIELDMAP_GetFieldPlayer((void *)a0);
loc_0216A200:
    a0 = FIELD_PLAYER_CheckNotWaterForm(v0);
loc_0216A206:
    if (a0 != 1) goto loc_0216A218;
loc_0216A20A:
a1 = 8;
    a0 = FIELD_PLAYER_StartFormChange(v0, a1);
loc_0216A212:
    a0 = FIELD_PLAYER_StepFormChange(v0);
loc_0216A218:
    return;}

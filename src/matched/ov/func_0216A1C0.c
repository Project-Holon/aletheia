/*
 * function: REPORT_EVENT_BeginAvatarAnim
 * address:  0x0216A1C0
 * packet:   pkt_0216A1C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_CheckNotWaterForm  0x021A3208  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb
 *   FLDMMDL_OffMoveBitMovePause  0x0216DB04  thumb  ov010
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb
 */
#include "../include/Obj17751.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FIELDMAP_GetFieldPlayer(unsigned char *p);
extern int FIELD_PLAYER_CheckNotWaterForm();
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FIELD_PLAYER_StartFormChange();
extern char *FLDMMDL_OffMoveBitMovePause(void *a0);
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);
extern int FIELD_PLAYER_StepFormChange();

int REPORT_EVENT_BeginAvatarAnim(int a0)
{
    int a1;
    void *v0;
    void *v1;

a0 = ((struct Obj17751 *)a0)->f8;
    v0 = FIELDMAP_GetFieldPlayer((void *)a0);
loc_0216A1C8:
    a0 = FIELD_PLAYER_CheckNotWaterForm(v0);
loc_0216A1CE:
    if (a0 != 1) goto loc_0216A1F6;
loc_0216A1D2:
    v1 = FIELD_PLAYER_GetMmdl(v0);
loc_0216A1D8:
a1 = 0x20;
    a0 = FIELD_PLAYER_StartFormChange(v0, a1);
loc_0216A1E2:
    a0 = (int)FLDMMDL_OffMoveBitMovePause(v1);
loc_0216A1E8:
a1 = 0x10;
    a0 = (int)FLDMMDL_ClearStatusBit(v1, a1);
loc_0216A1F0:
    a0 = FIELD_PLAYER_StepFormChange(v0);
loc_0216A1F6:
    return a0;}

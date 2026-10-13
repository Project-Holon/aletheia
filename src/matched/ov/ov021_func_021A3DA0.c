/*
 * function: FIELD_PLAYER_CORE_FormStepNormal
 * address:  0x021A3DA0
 * packet:   pkt_ov021_021A3DA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FIELD_PLAYER_CORE_ChangeModel  0x021A3AD8  thumb  ov021
 *   FIELD_PLAYER_CORE_GetSex  0x021A398C  thumb  ov021
 *   FIELD_PLAYER_GetFormObjCode  0x021A3190  thumb  ov021
 *   FIELD_PLAYER_CORE_SetFormCode  0x021A3980  thumb  ov021
 *   FIELD_PLAYER_CORE_PostZoneBgmChange  0x021A4114  thumb  ov021
 *   FIELD_PLAYER_CORE_GetRideEffect  0x021A3AD4  thumb  ov021
 *   FIELD_PLAYER_CORE_SetRideEffect  0x021A3AD0  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FLDMMDL_SetDrawOffsetOutside  0x0216D8E0  thumb  ov010
 */
#include "../include/Obj19780.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
extern u16 FLDMMDL_GetObjCode(void *p);
extern void FIELD_PLAYER_CORE_ChangeModel(u8 *p, int a);
extern u32 FIELD_PLAYER_CORE_GetSex(u8 *);
extern u16 FIELD_PLAYER_GetFormObjCode(int, int);
extern void FIELD_PLAYER_CORE_SetFormCode(u8 *p, u32 a1);
extern void FIELD_PLAYER_CORE_PostZoneBgmChange(u32 *p);
extern u32 FIELD_PLAYER_CORE_GetRideEffect(u8 *);
extern void FIELD_PLAYER_CORE_SetRideEffect(u8 *, u32);
extern void FIELD_EFFECT_DeleteObject(u32 a);
extern void FLDMMDL_SetDrawOffsetOutside(void *, u32 *);

int FIELD_PLAYER_CORE_FormStepNormal(u8 *p)
{
    u32 buf[3] = { 0, 0, 0 };
    u32 a;
    void *b;
    u32 o;

    a = FIELD_PLAYER_CORE_GetSex(p);
    b = FIELD_PLAYER_CORE_GetMmdl(p);
    a = FIELD_PLAYER_GetFormObjCode(a, 0);
    if (a != FLDMMDL_GetObjCode(b)) {
        FIELD_PLAYER_CORE_ChangeModel(p, a);
    }
    FIELD_PLAYER_CORE_SetFormCode(p, 0);
    FIELD_PLAYER_CORE_PostZoneBgmChange((u32 *)p);
    if ((o = FIELD_PLAYER_CORE_GetRideEffect(p)) != 0) {
        FIELD_EFFECT_DeleteObject(o);
        FIELD_PLAYER_CORE_SetRideEffect(p, 0);
    }
    FLDMMDL_SetDrawOffsetOutside(b, buf);
    ((struct Obj19780 *)p)->f32 = 1;
    return 0;
}

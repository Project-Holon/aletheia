/*
 * function: FIELD_PLAYER_CORE_FormStepDive
 * address:  0x021A3FE8
 * packet:   pkt_ov021_021A3FE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FIELD_PLAYER_CORE_ChangeModel  0x021A3AD8  thumb  ov021
 *   FIELD_PLAYER_CORE_GetSex  0x021A398C  thumb  ov021
 *   FIELD_PLAYER_GetFormObjCode  0x021A3190  thumb  ov021
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_CORE_SetFormCode  0x021A3980  thumb  ov021
 *   FIELD_PLAYER_CORE_GetRideEffect  0x021A3AD4  thumb  ov021
 *   FIELD_PLAYER_CORE_SetRideEffect  0x021A3AD0  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDEFF_NAMIPOKE_Start  0x021ACB38  thumb  ov021
 *   FLDEFF_BUBBLE_Start  0x021D05D8  thumb  ov021
 *   FLDEFF_NAMIPOKE_SetWakeEnabled  0x021ACBC8  thumb  ov021
 */
#include "../include/Obj05025.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
extern u16 FLDMMDL_GetObjCode(void *p);
extern void FIELD_PLAYER_CORE_ChangeModel(u8 *p, int a);
extern u32 FIELD_PLAYER_CORE_GetSex(u8 *);
extern u16 FIELD_PLAYER_GetFormObjCode(int, int);
extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
extern void FIELD_PLAYER_CORE_SetFormCode(u8 *p, u32 a1);
extern u32 FIELD_PLAYER_CORE_GetRideEffect(u8 *);
extern void FIELD_PLAYER_CORE_SetRideEffect(u8 *, u32);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern u32 FLDEFF_NAMIPOKE_Start(u32, u32, u32 *, void *, int);
extern void FLDEFF_BUBBLE_Start(void *a, void *b);
extern void FLDEFF_NAMIPOKE_SetWakeEnabled(u32, int);

int FIELD_PLAYER_CORE_FormStepDive(u8 *p)
{
    u32 buf[3];
    u32 a;
    void *b;
    u32 c;
    u32 d;
    u32 e;

    e = FIELDMAP_GetEffect((u8 *)(((struct Obj05025 *)p)->f8));
    a = FIELD_PLAYER_CORE_GetSex(p);
    b = FIELD_PLAYER_CORE_GetMmdl(p);
    a = FIELD_PLAYER_GetFormObjCode(a, 3);
    if (a != FLDMMDL_GetObjCode(b)) {
        FIELD_PLAYER_CORE_ChangeModel(p, a);
    }
    if (FIELD_PLAYER_CORE_GetFormCode(p) != 3) {
        FIELD_PLAYER_CORE_SetFormCode(p, 3);
    }
    if (FIELD_PLAYER_CORE_GetRideEffect(p) == 0) {
        c = FIELDMAP_GetEffect((u8 *)(((struct Obj05025 *)p)->f8));
        d = FLDMMDL_GetDirDisp(b);
        FLDMMDL_GetPos(b, (struct VecFx32 *)buf);
        FIELD_PLAYER_CORE_SetRideEffect(p, FLDEFF_NAMIPOKE_Start(c, d, buf, b, 1));
    }
    FLDEFF_BUBBLE_Start((void *)(((struct Obj05025 *)p)->f1C), (void *)e);
    if (((struct Obj05025 *)p)->f28 != 0) {
        FLDEFF_NAMIPOKE_SetWakeEnabled(((struct Obj05025 *)p)->f28, 0);
    }
    ((struct Obj05025 *)p)->f32 = 1;
    return 0;
}

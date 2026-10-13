/*
 * function: FIELD_PLAYER_CORE_FormStepSlot8Done
 * address:  0x021A40A8
 * packet:   pkt_ov021_021A40A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_FinishFormSlotChange  0x021A3D6C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_AddDirGrid  0x02164240  thumb  ov010
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   FLDMMDL_DRAW_SetState  0x0219F5C8  thumb  ov021
 */
#include "../include/Obj09563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void FIELD_PLAYER_CORE_FinishFormSlotChange(u8 *, int);
extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
extern void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_GetGridNowX(void *);
extern int FLDMMDL_GetGridNowZ(void *);
extern void FLDMMDL_MOVE_AddDirGrid(int dir, s16 *x, s16 *z, s16 amt);
extern void *FLDMMDL_SysSearchGridPos(u32 a, u32 b, u32 c, u32 d);
extern void FLDMMDL_DRAW_SetState(void *, int);

int FIELD_PLAYER_CORE_FormStepSlot8Done(u8 *p)
{
    s16 v[2];
    int f;
    void *a;
    u32 b;

    FIELD_PLAYER_CORE_FinishFormSlotChange(p, 8);
    if (((struct Obj09563 *)p)->f32 == 1 && FIELD_PLAYER_CORE_GetFormCode(p) == 2) {
        f = 0;
        a = FIELD_PLAYER_CORE_GetMmdl(p);
        b = (u32)FLDMMDL_GetMmdlSys(a);
        v[1] = FLDMMDL_GetGridNowX(a);
        v[0] = FLDMMDL_GetGridNowZ(a);
        FLDMMDL_MOVE_AddDirGrid(1, &v[1], &v[0], 1);
        if (FLDMMDL_SysSearchGridPos(b, v[1], v[0], 1) != 0) {
            f = 1;
        }
        FLDMMDL_DRAW_SetState(a, f);
    }
    return 0;
}

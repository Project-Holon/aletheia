/*
 * function: FIELD_PLAYER_GRID_EVENT_BoulderDropEvent
 * address:  0x021C0E98
 * packet:   pkt_ov021_021C0E98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GRID_StopTurnOrBlocked  0x021A5408  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SetStatusBitFellowHit  0x0216DAE0  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_SetDrawOffsetOutside  0x0216D8E0  thumb  ov010
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   FLDMMDL_StoreMovedPos  0x0216E57C  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00235.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_GRID_StopTurnOrBlocked(u8 *a);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(u32 o, u32 a);
extern void func_020061E4(u32 se);
extern int FLDMMDL_CheckEndAcmd(u32 o);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *o, struct VecFx32 *v);
extern int FLDMMDL_MOVE_GetMapHeight(u32 o, Vec3 *v, int *out);
extern u16 FLDMMDL_GetObjCode(void *p);
extern int FLDMMDL_SetStatusBitHeightGetOff(void *a0, int a1);
extern void FLDMMDL_SetStatusBitFellowHit(unsigned int *p, unsigned int v);
extern void FLDMMDL_SetPos(u32 o, Vec3 *v);
extern void FLDMMDL_SetDrawOffsetOutside(u32 o, void *p);
extern void FLDMMDL_InitPosition(void *a, int *p, int b);
extern void FLDMMDL_StoreMovedPos(void *a);

int FIELD_PLAYER_GRID_EVENT_BoulderDropEvent(u32 unused, int *st, u8 *p)
{
    Vec3 a;
    Vec3 b;
    Vec3 c;

    switch (*st) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(((struct Obj00235 *)p)->f1C) == 0)
            break;
        if (FLDMMDL_CheckPossibleAcmd(((struct Obj00235 *)p)->f20) == 0 && FIELD_PLAYER_GRID_StopTurnOrBlocked((u8 *)(((struct Obj00235 *)p)->f0)) == 0)
            break;
        FLDMMDL_SetAcmd(((struct Obj00235 *)p)->f1C, FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj00235 *)p)->f4, 8));
        FLDMMDL_SetAcmd(((struct Obj00235 *)p)->f20, FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj00235 *)p)->f4, 0x20));
        func_020061E4(0x674);
        (*st)++;
        break;
    case 1:
        if (FLDMMDL_CheckEndAcmd(((struct Obj00235 *)p)->f1C) == 0)
            break;
        if (FLDMMDL_CheckEndAcmd(((struct Obj00235 *)p)->f20) == 0)
            break;
        if (((struct Obj00235 *)p)->f6 == 0) {
            *st = 4;
            break;
        }
        FLDMMDL_GetPos((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&a);
        FLDMMDL_MOVE_GetMapHeight(((struct Obj00235 *)p)->f1C, &a, (int *)(p + 0xc));
        if (FLDMMDL_GetObjCode((void *)(((struct Obj00235 *)p)->f1C)) == 0x6d)
            ((struct Obj00235 *)p)->fC -= 14 << 12;
        else
            ((struct Obj00235 *)p)->fC -= 26 << 12;
        FLDMMDL_SetStatusBitHeightGetOff((void *)(((struct Obj00235 *)p)->f1C), 1);
        FLDMMDL_SetStatusBitFellowHit((unsigned int *)(((struct Obj00235 *)p)->f1C), 0);
        func_020061E4(0x675);
        (*st)++;
        break;
    case 2:
        FLDMMDL_GetPos((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&b);
        if (((struct Obj00235 *)p)->fC < b.y) {
            b.y -= 0x4000;
            if (((struct Obj00235 *)p)->fC > b.y)
                b.y = ((struct Obj00235 *)p)->fC;
        } else if (((struct Obj00235 *)p)->fC > b.y) {
            b.y += 0x4000;
            if (((struct Obj00235 *)p)->fC < b.y)
                b.y = ((struct Obj00235 *)p)->fC;
        }
        FLDMMDL_SetPos(((struct Obj00235 *)p)->f1C, &b);
        if (((struct Obj00235 *)p)->fC == b.y) {
            ((struct Obj00235 *)p)->f14 = 0x2000;
            (*st)++;
        }
        break;
    case 3:
        FLDMMDL_SetDrawOffsetOutside(((struct Obj00235 *)p)->f1C, p + 0x10);
        ((struct Obj00235 *)p)->f14 = -((struct Obj00235 *)p)->f14;
        ((struct Obj00235 *)p)->f8 = ((struct Obj00235 *)p)->f8 + 1;
        if (((struct Obj00235 *)p)->f8 & 4) {
            if (((struct Obj00235 *)p)->f14 < 0)
                ((struct Obj00235 *)p)->f14 += 0x1000;
            else if (((struct Obj00235 *)p)->f14 > 0)
                ((struct Obj00235 *)p)->f14 -= 0x1000;
        }
        if (((struct Obj00235 *)p)->f14 == 0) {
            FLDMMDL_GetPos((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&c);
            FLDMMDL_InitPosition((void *)(((struct Obj00235 *)p)->f1C), (int *)(&c), ((struct Obj00235 *)p)->f4);
            FLDMMDL_SetDrawOffsetOutside(((struct Obj00235 *)p)->f1C, p + 0x10);
            FLDMMDL_StoreMovedPos((void *)(((struct Obj00235 *)p)->f1C));
            (*st)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}

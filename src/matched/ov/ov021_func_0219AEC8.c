/*
 * function: FLDMMDL_MOVECODE_RoutePatrolSwapStepWalk
 * address:  0x0219AEC8
 * packet:   pkt_ov021_0219AEC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of FLDMMDL_MOVECODE_RoutePatrolStepWalk (same shape; the step field is signed and advanced
 * through FLDMMDL_MOVECODE_AdvanceRouteIndex).
 *
 * symbols:
 *   FLDMMDL_MOVECODE_UpdateTriggerWait  0x0219B2E8  thumb  ov021
 *   FLDMMDL_GetGridInitX  0x0216D7E8  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridInitZ  0x0216D7F8  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVECODE_AdvanceRouteIndex  0x0219ADEC  thumb  ov021
 *   FLDMMDL_MOVECODE_GetDirSet  0x0219B120  thumb  ov021
 *   FLDMMDL_SetDirMove  0x0216D600  thumb  ov010
 *   FLDMMDL_MOVECODE_IsMirrorEventType  0x0219B358  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_MOVE_HitCheckMoveDir  0x021639C0  thumb  ov010
 *   FLDMMDL_MOVECODE_IsDashEventType  0x0219B334  thumb  ov021
 *   FLDMMDL_MOVECODE_IsBButtonHeld  0x0219B060  thumb  ov021
 *   FLDMMDL_MOVE_IsNearPlayer  0x02164168  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 *   FLDMMDL_MOVECODE_StartMirrorTurn  0x0219B390  thumb  ov021
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct St {
    u8 f0;
    s8 step;
    u8 last;
    u8 axis;
    u8 id;
    u8 f5;
    u8 f6;
    u8 f7;
    s8 f8;
} St;

extern int FLDMMDL_MOVECODE_UpdateTriggerWait(int a, u8 *b);
extern int FLDMMDL_GetGridInitX(void *p);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridInitZ(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern void FLDMMDL_MOVECODE_AdvanceRouteIndex(St *b);
extern u32 *FLDMMDL_MOVECODE_GetDirSet(u32 id);
extern int FLDMMDL_SetDirMove(int a0, u16 a1);
extern int FLDMMDL_MOVECODE_IsMirrorEventType(u32 a);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern int FLDMMDL_MOVE_HitCheckMoveDir(int a, u16 b);
extern int FLDMMDL_MOVECODE_IsDashEventType(u32 a);
extern int FLDMMDL_MOVECODE_IsBButtonHeld(void);
extern int FLDMMDL_MOVE_IsNearPlayer(int a);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);
extern void FLDMMDL_MOVECODE_StartMirrorTurn(int a, s8 *b);
extern void FLDMMDL_OnMoveBitMove(int a);

int FLDMMDL_MOVECODE_RoutePatrolSwapStepWalk(char *a, St *b)
{
    u32 *tbl;
    u32 v;
    int x0;
    int y0;
    int x1;
    int y1;
    int f;
    int m;

    if (FLDMMDL_MOVECODE_UpdateTriggerWait((int)a, &b->f6) == 0) {
        return 0;
    }
    if (b->step == b->last) {
        if (b->axis == 0) {
            x0 = FLDMMDL_GetGridInitX((void *)a);
            if (x0 == FLDMMDL_GetGridNowX((void *)a)) {
                FLDMMDL_MOVECODE_AdvanceRouteIndex(b);
            }
        } else {
            x0 = FLDMMDL_GetGridInitZ((void *)a);
            if (x0 == FLDMMDL_GetGridNowZ((void *)a)) {
                FLDMMDL_MOVECODE_AdvanceRouteIndex(b);
            }
        }
    }
    if (b->step == 3) {
        x0 = FLDMMDL_GetGridInitX((void *)a);
        y0 = FLDMMDL_GetGridInitZ((void *)a);
        x1 = FLDMMDL_GetGridNowX((void *)a);
        y1 = FLDMMDL_GetGridNowZ((void *)a);
        if (x0 == x1 && y0 == y1) {
            b->step = 0;
        }
    }
    tbl = FLDMMDL_MOVECODE_GetDirSet(b->id);
    v = tbl[b->step];
    FLDMMDL_SetDirMove((int)a, (u16)v);
    if (FLDMMDL_MOVECODE_IsMirrorEventType((u32)a) == 0) {
        FLDMMDL_SetDirDispCheckPause((int)a, (u16)v);
    }
    f = FLDMMDL_MOVE_HitCheckMoveDir((int)a, (u16)v);
    if (1 & f) {
        FLDMMDL_MOVECODE_AdvanceRouteIndex(b);
        v = tbl[b->step];
        FLDMMDL_SetDirMove((int)a, (u16)v);
        if (FLDMMDL_MOVECODE_IsMirrorEventType((u32)a) == 0) {
            FLDMMDL_SetDirDispCheckPause((int)a, (u16)v);
        }
        f = FLDMMDL_MOVE_HitCheckMoveDir((int)a, (u16)v);
    }
    m = 12;
    if (FLDMMDL_MOVECODE_IsDashEventType((u32)a) != 0 && FLDMMDL_MOVECODE_IsBButtonHeld() == 1 && FLDMMDL_MOVE_IsNearPlayer((int)a) == 1) {
        m = 16;
    }
    if (f != 0) {
        m = 32;
    }
    FLDMMDL_SetLocalAcmd(a, (u16)FLDMMDL_ACMD_ConvertCodeByDir((u16)v, (u16)m));
    if (FLDMMDL_MOVECODE_IsMirrorEventType((u32)a) == 1) {
        FLDMMDL_MOVECODE_StartMirrorTurn((int)a, &b->f8);
    }
    FLDMMDL_OnMoveBitMove((int)a);
    b->f0 = 3;
    return 1;
}

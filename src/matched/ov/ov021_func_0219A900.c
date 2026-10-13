/*
 * function: FLDMMDL_MOVECODE_BackForthStepWalk
 * address:  0x0219A900
 * packet:   pkt_ov021_0219A900
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVECODE_UpdateTriggerWait  0x0219B2E8  thumb  ov021
 *   FLDMMDL_GetGridInitX  0x0216D7E8  thumb  ov010
 *   FLDMMDL_GetGridInitZ  0x0216D7F8  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
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
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int FLDMMDL_MOVECODE_UpdateTriggerWait(int a, u8 *b);
extern int FLDMMDL_GetGridInitX(void *p);
extern int FLDMMDL_GetGridInitZ(void *p);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern u16 FLDMMDL_GetDirMove(void *p);
typedef signed char    s8;
extern u16 FLDMMDL_MOVE_GetDirTableValue(int i);
extern int FLDMMDL_SetDirMove(int a0, u16 a1);
extern int FLDMMDL_MOVECODE_IsMirrorEventType(u32);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern int FLDMMDL_MOVE_HitCheckMoveDir(u32, u16);
extern int FLDMMDL_MOVECODE_IsDashEventType(u32);
extern int FLDMMDL_MOVECODE_IsBButtonHeld(void);
extern int FLDMMDL_MOVE_IsNearPlayer(int a);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);
extern void FLDMMDL_MOVECODE_StartMirrorTurn(int a, s8 *b);
extern void FLDMMDL_OnMoveBitMove(u32);

int FLDMMDL_MOVECODE_BackForthStepWalk(u32 a, u8 *b)
{
    int x;
    int y;
    int tx;
    int ty;
    u32 u;
    u32 d;
    int r;
    u32 k;

    if (FLDMMDL_MOVECODE_UpdateTriggerWait(a, b + 2) == 0)
        return 0;
    if (b[1] != 0) {
        x = FLDMMDL_GetGridInitX((void *)a);
        y = FLDMMDL_GetGridInitZ((void *)a);
        tx = FLDMMDL_GetGridNowX((void *)a);
        ty = FLDMMDL_GetGridNowZ((void *)a);
        if (x == tx && y == ty) {
            u = (u32)FLDMMDL_MOVE_GetDirTableValue((u16)FLDMMDL_GetDirMove((void *)a));
            FLDMMDL_SetDirMove(a, u);
            if (FLDMMDL_MOVECODE_IsMirrorEventType(a) == 0)
                FLDMMDL_SetDirDispCheckPause((u32)a, (u16)u);
            b[1] = 0;
        }
    }
    d = FLDMMDL_GetDirMove((void *)a);
    r = FLDMMDL_MOVE_HitCheckMoveDir(a, d);
    if (r & 1) {
        b[1] = 1;
        d = (u32)FLDMMDL_MOVE_GetDirTableValue((u16)d);
        r = FLDMMDL_MOVE_HitCheckMoveDir(a, d);
    }
    k = 12;
    if (FLDMMDL_MOVECODE_IsDashEventType(a) != 0 && FLDMMDL_MOVECODE_IsBButtonHeld() == 1 && FLDMMDL_MOVE_IsNearPlayer(a) == 1)
        k = 16;
    if (r != 0)
        k = 32;
    FLDMMDL_SetLocalAcmd((char *)a, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)d, (u16)k)));
    if (FLDMMDL_MOVECODE_IsMirrorEventType(a) == 1)
        FLDMMDL_MOVECODE_StartMirrorTurn((u32)a, (s8 *)(b + 4));
    FLDMMDL_OnMoveBitMove(a);
    b[0] = 2;
    return 1;
}

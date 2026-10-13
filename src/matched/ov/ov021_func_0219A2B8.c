/*
 * function: FLDMMDL_MOVECODE_MoveWalkRandom
 * address:  0x0219A2B8
 * packet:   pkt_ov021_0219A2B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 *   FLDMMDL_OffMoveBitMoveEnd  0x0216DA7C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 *   FLDMMDL_ACMD_Update  0x02197EDC  thumb  ov021
 *   FLDMMDL_MOVECODE_GetRandomTableEntry  0x0219B0F0  thumb  ov021
 *   FLDMMDL_MOVECODE_GetRandomDirFromSet  0x0219B104  thumb  ov021
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_MOVECODE_IsDirInsideMoveRect  0x0219A4CC  thumb  ov021
 *   FLDMMDL_MOVE_HitCheckMoveDir  0x021639C0  thumb  ov010
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb  ov010
 *   gMmdlRandomWaitFrames     0x021D4FA4  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef struct {
    s16 state;
    s16 timer;
    int mode;
    u32 arg;
    u32 v;
} St;
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern void FLDMMDL_OffMoveBitMove(u8 *p);
extern void FLDMMDL_OffMoveBitMoveEnd(u8 *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);
extern u32 FLDMMDL_ACMD_Update(u8 *p);
extern int FLDMMDL_MOVECODE_GetRandomTableEntry(u32 a, u32 b);
extern u32 FLDMMDL_MOVECODE_GetRandomDirFromSet(u32, u32);
extern void FLDMMDL_SetDirAll(u32, u16);
extern int FLDMMDL_MOVECODE_IsDirInsideMoveRect(u32, u32);
extern int FLDMMDL_MOVE_HitCheckMoveDir(u32, u16);
extern void FLDMMDL_OnMoveBitMove(u32);
extern u8 gMmdlRandomWaitFrames[];

void FLDMMDL_MOVECODE_MoveWalkRandom(u32 a)
{
    St *p;
    u32 r;
    int f;

    p = FLDMMDL_GetMoveProcWork((void *)a);
    switch (p->state) {
    case 0:
        FLDMMDL_OffMoveBitMove((u8 *)a);
        FLDMMDL_OffMoveBitMoveEnd((u8 *)a);
        FLDMMDL_SetLocalAcmd((char *)a, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)((u32)FLDMMDL_GetDirDisp((void *)a)), (u16)0)));
        p->state++;
        break;
    case 1:
        if (FLDMMDL_ACMD_Update((u8 *)a) == 0)
            break;
        p->timer = FLDMMDL_MOVECODE_GetRandomTableEntry((u32)gMmdlRandomWaitFrames, -1);
        p->state++;
    case 2:
        p->timer--;
        if (p->timer != 0)
            break;
        p->state++;
    case 3:
        r = FLDMMDL_MOVECODE_GetRandomDirFromSet(p->v, 9);
        FLDMMDL_SetDirAll(a, r);
        if (p->mode == 1 && FLDMMDL_MOVECODE_IsDirInsideMoveRect(a, r) == 0) {
            p->state = 0;
            return;
        }
        f = FLDMMDL_MOVE_HitCheckMoveDir(a, r);
        if (f != 0) {
            if (p->mode == 2) {
                if (f & 1) {
                    p->state = 0;
                    return;
                }
            } else {
                p->state = 0;
                return;
            }
        }
        FLDMMDL_SetLocalAcmd((char *)a, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)r, (u16)p->arg)));
        FLDMMDL_OnMoveBitMove(a);
        p->state++;
    case 4:
        if (FLDMMDL_ACMD_Update((u8 *)a) != 0) {
            FLDMMDL_OffMoveBitMove((u8 *)a);
            p->state = 0;
        }
        break;
    }
}

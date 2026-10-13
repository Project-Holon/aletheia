/*
 * function: FLDMMDL_MOVECODE_MoveTurnRandom
 * address:  0x0219A150
 * packet:   pkt_ov021_0219A150
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 *   FLDMMDL_MOVE_IsNearPlayer  0x02164168  thumb  ov010
 *   FLDMMDL_MOVECODE_IsBButtonPressed  0x0219B0C4  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_MOVECODE_GetNextDirInRotation  0x0219A1E8  thumb  ov021
 *   FLDMMDL_MOVECODE_GetDirTowardPlayerInSet  0x0219B200  thumb  ov021
 *   FLDMMDL_MOVECODE_GetRandomTableEntry  0x0219B0F0  thumb  ov021
 *   FLDMMDL_MOVECODE_GetRandomDirFromSet  0x0219B104  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   gMmdlRandomWaitFrames     0x021D4FA4  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef struct { u16 x; s16 n; u32 v; } St;
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern u16 FLDMMDL_GetEventType(u8 *p);
extern int FLDMMDL_MOVE_IsNearPlayer(int a);
extern int FLDMMDL_MOVECODE_IsBButtonPressed(void);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern u16 FLDMMDL_GetMoveCode(void *p);
extern u16 FLDMMDL_MOVECODE_GetNextDirInRotation(u32, u32);
extern int FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(int a, int id, int end);
extern int FLDMMDL_MOVECODE_GetRandomTableEntry(u32 a, u32 b);
extern u32 FLDMMDL_MOVECODE_GetRandomDirFromSet(u32, u32);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern u8 gMmdlRandomWaitFrames[];

void FLDMMDL_MOVECODE_MoveTurnRandom(u32 a)
{
    St *p;
    u32 r;
    u32 t;
    u16 q;
    p = FLDMMDL_GetMoveProcWork((void *)a);
    if (FLDMMDL_GetEventType((u8 *)a) == 11) {
        if (FLDMMDL_MOVE_IsNearPlayer(a) == 1 && FLDMMDL_MOVECODE_IsBButtonPressed() == 1) {
            t = FLDMMDL_GetDirDisp((void *)a);
            q = FLDMMDL_MOVECODE_GetNextDirInRotation(FLDMMDL_GetMoveCode((void *)a), t);
            if (q != 9)
                FLDMMDL_SetDirDispCheckPause((u32)a, (u16)q);
        }
    } else {
        r = FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(a, p->v, 9);
        if (r != 9) {
            FLDMMDL_SetDirDispCheckPause((u32)a, (u16)r);
        } else if (p->x == 0) {
            p->n = p->n - 1;
            if (p->n <= 0) {
                p->n = FLDMMDL_MOVECODE_GetRandomTableEntry((u32)gMmdlRandomWaitFrames, -1);
                r = FLDMMDL_MOVECODE_GetRandomDirFromSet(p->v, 9);
                FLDMMDL_SetDirDispCheckPause((u32)a, (u16)r);
            }
        }
    }
    FLDMMDL_MOVE_UpdateOldGridPos(a);
}

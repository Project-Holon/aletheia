/*
 * function: FLDMMDL_ACMD_WalkMove
 * address:  0x0219800C
 * packet:   pkt_ov021_0219800C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVectorPos  0x02163FC0  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05990.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern void FLDMMDL_MOVE_AddDirVectorPos(int a, int dir, int amt);
extern int FLDMMDL_MOVE_UpdateHeight(int a);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_IncAcmdSeq(u8 *);

u32 FLDMMDL_ACMD_WalkMove(u8 *p)
{
    u8 *h;

    h = FLDMMDL_GetMoveCmdWork(p);
    FLDMMDL_MOVE_AddDirVectorPos((int)p, (u16)(((struct Obj05990 *)h)->f4), (u32)(((struct Obj05990 *)h)->f8));
    FLDMMDL_MOVE_UpdateHeight((int)p);
    ((struct Obj05990 *)h)->f2 = ((struct Obj05990 *)h)->f2 - 1;
    if (((struct Obj05990 *)h)->f2 > 0) {
        return 0;
    }
    FLDMMDL_SetMoveBit(p, 0x440);
    FLDMMDL_MOVE_UpdateOldGridPos((int)p);
    FLDMMDL_SetDrawStatus(p, 0);
    FLDMMDL_IncAcmdSeq(p);
    return 0;
}

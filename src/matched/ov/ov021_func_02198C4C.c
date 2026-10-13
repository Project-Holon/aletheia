/*
 * function: func_02198C4C
 * address:  0x02198C4C
 * packet:   pkt_ov021_02198C4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVectorPos  0x02163FC0  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05005.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern void FLDMMDL_MOVE_AddDirVectorPos(int a, int dir, int amt);
extern int FLDMMDL_MOVE_UpdateHeight(int a);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int func_02198C4C(u32 a, u32 *b)
{
    s16 *p;

    p = FLDMMDL_GetMoveCmdWork((void *)a);
    FLDMMDL_MOVE_AddDirVectorPos(a, ((struct Obj05005 *)p)->f0, b[p[3]]);
    FLDMMDL_MOVE_UpdateHeight(a);
    p[3] = p[3] + 1;
    if (p[3] < p[2]) {
        return 0;
    }
    FLDMMDL_SetMoveBit((void *)a, 1088);
    FLDMMDL_MOVE_UpdateOldGridPos(a);
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}

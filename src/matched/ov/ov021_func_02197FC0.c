/*
 * function: FLDMMDL_ACMD_WalkInit
 * address:  0x02197FC0
 * packet:   pkt_ov021_02197FC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_MOVE_UpdateGridPosDir  0x02163E7C  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07465.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FLDMMDL_InitMoveCmdWork(int a0, int a1, int a2);
extern void FLDMMDL_MOVE_UpdateGridPosDir(int a, int b);
extern void FLDMMDL_SetDirAll(u8 *, u16);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern void FLDMMDL_IncAcmdSeq(u8 *);

void FLDMMDL_ACMD_WalkInit(u8 *a, u32 b, u32 c, u16 d, u16 e)
{
    u16 *r;

    r = FLDMMDL_InitMoveCmdWork((int)a, (u32)12, c);
    r[0] = e;
    r[1] = d;
    ((struct Obj07465 *)r)->f4 = b;
    ((struct Obj07465 *)r)->f8 = c;
    FLDMMDL_MOVE_UpdateGridPosDir((int)a, (u16)b);
    FLDMMDL_SetDirAll(a, b);
    FLDMMDL_SetDrawStatus(a, e);
    FLDMMDL_SetMoveBit(a, 0x20);
    FLDMMDL_IncAcmdSeq(a);
}

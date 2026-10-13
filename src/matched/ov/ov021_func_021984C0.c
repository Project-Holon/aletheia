/*
 * function: FLDMMDL_ACMD_JumpInit
 * address:  0x021984C0
 * packet:   pkt_ov021_021984C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_MOVE_UpdateGridPosDir  0x02163E7C  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05004.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *FLDMMDL_InitMoveCmdWork(int a0, int a1, int a2);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern void FLDMMDL_MOVE_UpdateGridPosDir(int a, int b);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int FLDMMDL_SetDirAll(int a0, int a1);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_IncAcmdSeq(u8 *);
extern void func_020061E4(void);

void FLDMMDL_ACMD_JumpInit(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g, u32 h)
{
    u8 *r;

    r = FLDMMDL_InitMoveCmdWork((int)a, (u32)16, c);
    r[12] = b;
    ((struct Obj05004 *)r)->f0 = c;
    r[13] = d;
    r[14] = e;
    r[15] = f;
    ((struct Obj05004 *)r)->f8 = g;
    if (c == 0) {
        FLDMMDL_MOVE_UpdateOldGridPos((int)a);
    } else {
        FLDMMDL_MOVE_UpdateGridPosDir((int)a, (u16)b);
    }
    FLDMMDL_SetMoveBit(a, 0xa0);
    FLDMMDL_SetDirAll((int)a, (u16)b);
    FLDMMDL_SetDrawStatus(a, e);
    FLDMMDL_IncAcmdSeq(a);
    if (h != 0) {
        func_020061E4();
    }
}

/*
 * function: FLDMMDL_RAIL_MOVE_AcJumpSetSe
 * address:  0x0219E00C
 * packet:   pkt_ov021_0219E00C
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
 *   FLDMMDL_RAIL_SetMoveRequest  0x0219E370  thumb  ov021
 *   FLDMMDL_RAIL_SetGridPosByDir  0x0219E6C8  thumb  ov021
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05013.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u16 a;
    u16 b;
    s16 c;
    u16 d;
    u16 e;
    u16 f;
} S;

extern void *FLDMMDL_InitMoveCmdWork(int a0, int a1, int a2);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern void FLDMMDL_RAIL_SetMoveRequest(u32 a, u32 b, u32 c);
extern void FLDMMDL_RAIL_SetGridPosByDir(u32, u16);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int FLDMMDL_SetDirAll(int a0, int a1);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_IncAcmdSeq(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void FLDMMDL_RAIL_MOVE_AcJumpSetSe(u32 o, u32 id, u32 p, u8 q, S s, u32 fn)
{
    u8 *e;

    e = FLDMMDL_InitMoveCmdWork(o, 0x10, p);
    e[0xc] = id;
    ((struct Obj05013 *)e)->f0 = p;
    e[0xd] = q;
    e[0xe] = s.a;
    e[0xf] = s.c;
    ((struct Obj05013 *)e)->f8 = s.e;
    if (p == 0) {
        FLDMMDL_MOVE_UpdateOldGridPos(o);
    } else {
        FLDMMDL_RAIL_SetMoveRequest(o, (u16)id, 8);
        FLDMMDL_RAIL_SetGridPosByDir(o, id);
    }
    FLDMMDL_SetMoveBit((void *)o, 0xa0);
    FLDMMDL_SetDirAll((u32)o, (u16)id);
    FLDMMDL_SetDrawStatus((void *)o, s.a);
    FLDMMDL_IncAcmdSeq((u8 *)o);
    if (fn) {
        GFL_USE_PlaySeDefaultVolume(fn);
    }
}

/*
 * function: FLDMMDL_RAIL_MOVE_AcStayWalkSet
 * address:  0x0219DE64
 * packet:   pkt_ov021_0219DE64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FLDMMDL_InitMoveCmdWork(int a0, int a1, int a2);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern void FLDMMDL_IncAcmdSeq(u8 *p);

void FLDMMDL_RAIL_MOVE_AcStayWalkSet(u32 a, u32 b, u16 c, u16 d)
{
    u16 *q = FLDMMDL_InitMoveCmdWork((u32)a, (u32)4, c);
    q[0] = d;
    q[1] = c;
    FLDMMDL_SetDirDispCheckPause((u32)a, (u16)b);
    FLDMMDL_SetDrawStatus((void *)a, d);
    FLDMMDL_MOVE_UpdateOldGridPos(a);
    FLDMMDL_IncAcmdSeq((u8 *)a);
}

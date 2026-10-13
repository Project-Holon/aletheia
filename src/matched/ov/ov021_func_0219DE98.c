/*
 * function: FLDMMDL_RAIL_MOVE_AcStayWalk1
 * address:  0x0219DE98
 * packet:   pkt_ov021_0219DE98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_IncAcmdSeq(u8 *p);

int FLDMMDL_RAIL_MOVE_AcStayWalk1(u32 a)
{
    s16 *q = FLDMMDL_GetMoveCmdWork((void *)a);
    q[1]--;
    if (q[1] > 0)
        return 0;
    FLDMMDL_SetMoveBit((void *)a, 0x400);
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_IncAcmdSeq((u8 *)a);
    return 1;
}

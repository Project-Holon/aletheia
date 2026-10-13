/*
 * function: FLDMMDL_ACMD_Dash2FMove
 * address:  0x02199D4C
 * packet:   pkt_ov021_02199D4C
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
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern void FLDMMDL_MOVE_AddDirVectorPos(int a, int dir, int amt);
extern int FLDMMDL_MOVE_UpdateHeight(int a);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_Dash2FMove(u32 a)
{
    s16 *p;

    p = FLDMMDL_GetMoveCmdWork((void *)a);
    FLDMMDL_MOVE_AddDirVectorPos(a, (u16)((u32 *)p)[1], ((u32 *)p)[2]);
    FLDMMDL_MOVE_UpdateHeight(a);
    p[1] = p[1] - 1;
    if (p[1] > 0) {
        return 0;
    }
    FLDMMDL_MOVE_UpdateOldGridPos(a);
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}

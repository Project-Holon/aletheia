/*
 * function: FLDMMDL_ACMD_StayWalk22FMove
 * address:  0x02199CE4
 * packet:   pkt_ov021_02199CE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern void FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_StayWalk22FMove(u32 a)
{
    int *p = FLDMMDL_GetMoveCmdWork((void *)a);
    if (++*p >= 22) {
        FLDMMDL_IncAcmdSeq(a);
    }
    return 0;
}

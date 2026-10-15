/*
 * function: FLDMMDL_ACMD_StayMove
 * address:  0x02199050
 * packet:   pkt_ov021_02199050
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern void FLDMMDL_IncAcmdSeq(u8 *p);

int FLDMMDL_ACMD_StayMove(u32 a)
{
    u16 *p;

    p = FLDMMDL_GetMoveCmdWork((void *)a);
    p[0]++;
    if (p[0] >= p[1]) {
        FLDMMDL_IncAcmdSeq((u8 *)a);
    }
    return 0;
}

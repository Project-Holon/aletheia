/*
 * function: FIELD_PLAYER_CORE_CheckAcmdPossible
 * address:  0x021A3AA0
 * packet:   pkt_021A3AA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);

int FIELD_PLAYER_CORE_CheckAcmdPossible(u32 a)
{
if (FLDMMDL_CheckPossibleAcmd((int)FIELD_PLAYER_CORE_GetMmdl((u8 *)a)) == 1) {
    return 1;
}
return 0;
}


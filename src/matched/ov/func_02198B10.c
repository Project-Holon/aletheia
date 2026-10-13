/*
 * function: FLDMMDL_ACMD_DirPauseOff
 * address:  0x02198B10
 * packet:   pkt_02198B10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FLDMMDL_IncAcmdSeq (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_DirPauseOff(u32 a, u32 b, u32 c, u32 d)
{
FLDMMDL_ClearStatusBit((u32 *)a, 8);
FLDMMDL_IncAcmdSeq(a);
return 1;
}


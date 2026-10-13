/*
 * function: FLDMMDL_RAIL_MOVE_AcNextStep
 * address:  0x0219DC28
 * packet:   pkt_0219DC28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FLDMMDL_IncAcmdSeq (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_IncAcmdSeq(u32, u32, u32, u32);

int FLDMMDL_RAIL_MOVE_AcNextStep(u32 a, u32 b, u32 c, u32 d)
{
FLDMMDL_IncAcmdSeq(a, b, c, d);
return 1;
}


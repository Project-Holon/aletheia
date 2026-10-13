/*
 * function: FLDMMDL_ACMD_StepDownFaceUp8F
 * address:  0x021993FC
 * packet:   pkt_ov021_021993FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the const
 * Vec initialiser is an ov021 data start that another overlay mapped over the
 * same window also starts an object at, so the symbols hint is contested and
 * no single-reference witness exists.  No C change needed to promote.
 *
 * 2026-10-01: the own-overlay data hint is dropped from symbols: so the
 *   own-window rule (code running in ov021 can only see ov021's bytes in its
 *   window) fixes the overlay; with the hint the tool refused it as contested.
 *
 * symbols:
 *   FLDMMDL_ACMD_StepInit  0x0219912C  thumb  ov021
 *   d_021D4BE0     0x021D4BE0  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021D4BE0;
extern void FLDMMDL_ACMD_StepInit(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);

int FLDMMDL_ACMD_StepDownFaceUp8F(u32 a)
{
    Vec t = d_021D4BE0;
    FLDMMDL_ACMD_StepInit(a, &t, 0, 1, 8, 3);
    return 1;
}

/*
 * function: FLDMMDL_ACMD_StepUpFaceLeft8F
 * address:  0x02199234
 * packet:   pkt_ov021_02199234
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_ACMD_StepInit  0x0219912C  thumb  ov021
 *   d_021D4B44     0x021D4B44  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021D4B44;
extern void FLDMMDL_ACMD_StepInit(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);

int FLDMMDL_ACMD_StepUpFaceLeft8F(u32 a)
{
    Vec t = d_021D4B44;
    FLDMMDL_ACMD_StepInit(a, &t, 2, 0, 8, 3);
    return 1;
}

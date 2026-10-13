/*
 * function: FLDMMDL_ACMD_StepUpFaceDown2F
 * address:  0x02199550
 * packet:   pkt_ov021_02199550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_ACMD_StepInit  0x0219912C  thumb  ov021
 *   d_021D4B8C  0x021D4B8C  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021D4B8C;
extern void FLDMMDL_ACMD_StepInit(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);

int FLDMMDL_ACMD_StepUpFaceDown2F(u32 a)
{
    Vec t = d_021D4B8C;
    FLDMMDL_ACMD_StepInit(a, &t, 1, 0, 2, 5);
    return 1;
}

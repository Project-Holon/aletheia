/*
 * function: FLDMMDL_ACMD_ResetDrawOffset
 * address:  0x02199F30
 * packet:   pkt_ov021_02199F30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern void FLDMMDL_SetDrawOffset(u32, const Vec *);
extern void FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_ResetDrawOffset(u32 a)
{
    Vec t = {0, 0, 0};
    FLDMMDL_SetDrawOffset(a, &t);
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}

/*
 * function: FLDEFF_D06DENKI_FollowFreezeLoop
 * address:  0x021C909C
 * packet:   pkt_ov021_021C909C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
extern int FIELD_EFFECT_GetObjectWork(u32 a);
void FLDEFF_D06DENKI_FollowFreezeLoop(u32 a)
{
    if (a != 0)
        ((u8 *)FIELD_EFFECT_GetObjectWork(a))[0x14] = 1;
}

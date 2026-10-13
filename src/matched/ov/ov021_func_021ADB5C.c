/*
 * function: FLDEFF_ENCOUNT_SetDrawHidden
 * address:  0x021ADB5C
 * packet:   pkt_ov021_021ADB5C
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int FIELD_EFFECT_GetObjectWork(u32 a);

void FLDEFF_ENCOUNT_SetDrawHidden(int a, int v)
{
    if (a != 0)
        ((u8 *)FIELD_EFFECT_GetObjectWork(a))[3] = v;
}

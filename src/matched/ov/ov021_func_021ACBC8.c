/*
 * function: FLDEFF_NAMIPOKE_SetWakeEnabled
 * address:  0x021ACBC8
 * packet:   pkt_ov021_021ACBC8
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

void FLDEFF_NAMIPOKE_SetWakeEnabled(u32 a, int v)
{
    u8 *p;

    if (a != 0) {
        p = (u8 *)FIELD_EFFECT_GetObjectWork(a);
        if (v == 1)
            p[10] = 0;
        else
            p[10] = 1;
    }
}

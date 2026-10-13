/*
 * function: FLDEFF_FISHING_Init
 * address:  0x021AE030
 * packet:   pkt_ov021_021AE030
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern void FIELD_EFFECT_SetObjectPos(u32 a, u32 *b);

void FLDEFF_FISHING_Init(u32 a, u32 *out)
{
    u32 *p = (u32 *)FIELD_EFFECT_GetObjectParam(a);

    *out = p[0];
    FIELD_EFFECT_SetObjectPos(a, p + 1);
}

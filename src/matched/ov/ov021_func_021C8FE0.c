/*
 * function: FLDEFF_D06DENKI_SparkUpdate
 * address:  0x021C8FE0
 * packet:   pkt_ov021_021C8FE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
extern void FIELD_EFFECT_DeleteObject(u32 a);
void FLDEFF_D06DENKI_SparkUpdate(u32 a, u32 *p)
{
    if (p[2] == 1)
        FIELD_EFFECT_DeleteObject(a);
}

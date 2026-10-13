/*
 * function: FIELD_LIGHT_StepBlend
 * address:  0x021A0B14
 * packet:   pkt_ov021_021A0B14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0xF0];
    u16 cur;
    u16 max;
} Counter;

void FIELD_LIGHT_StepBlend(Counter *p)
{
    if (p->cur < p->max)
        p->cur++;
}

/*
 * function: func_0215F9C4
 * address:  0x0215F9C4
 * packet:   pkt_0215F9C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GPOWER_GetSpecialPowerId(void);

int func_0215F9C4(void)
{
    int a0;

    a0 = GPOWER_GetSpecialPowerId();
loc_0215F9CA:
    if (a0 == 0x14) goto loc_0215F9D2;
loc_0215F9CE:
    if (a0 == 0x15) goto loc_0215F9D6;
loc_0215F9D2:
a0 = 8;
    return a0;
loc_0215F9D6:
a0 = 7;
    return a0;}

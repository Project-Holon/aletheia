/*
 * function: PALETTE_ANIME_Bind
 * address:  0x021C29E8
 * packet:   pkt_ov217_021C29E8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALETTE_ANIME_BindImpl  0x021C2DE0  thumb  ov217
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void PALETTE_ANIME_BindImpl(char *p, unsigned short *dst, unsigned short *src, int count);

void PALETTE_ANIME_Bind(void *p, u32 b, u32 c, u32 d)
{
    PALETTE_ANIME_BindImpl(p, (short unsigned int *)b, (short unsigned int *)c, d);
}

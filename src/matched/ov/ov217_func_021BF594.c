/*
 * function: func_021BF594
 * address:  0x021BF594
 * packet:   pkt_ov217_021BF594
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALETTE_ANIME_Start 0x021C29F8 thumb ov217
 *   d_021C3A34 0x021C3A34 data a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct S { u32 a; u16 b; u8 pad[14]; } S;
extern S d_021C3A34[];
extern void PALETTE_ANIME_Start(u8 *p, u32 b, u16 c);
void func_021BF594(char *p, int i)
{
    PALETTE_ANIME_Start((u8 *)(*(u32 *)(p + i * 4 + 0x324)), d_021C3A34[i].a, d_021C3A34[i].b);
}

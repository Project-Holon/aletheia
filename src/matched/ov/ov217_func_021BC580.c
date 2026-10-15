/*
 * function: RESEARCH_LIST_StartListPaletteAnime
 * address: 0x021BC580
 * packet: pkt_ov217_021BC580
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   PALETTE_ANIME_Start 0x021C29F8 thumb ov217
 *   d_021C326C 0x021C326C data a4
 *   d_021C3270 0x021C3270 data a4
 */
struct Ent { unsigned int a; unsigned short b; unsigned short pad; unsigned int c[3]; };
extern const struct Ent d_021C326C[];
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void PALETTE_ANIME_Start(u8 *p, u32 b, u16 c);

void RESEARCH_LIST_StartListPaletteAnime(char *p, int i)
{
    PALETTE_ANIME_Start((u8 *)(*(int *)(p + 0x9c + i * 4)), d_021C326C[i].a, d_021C326C[i].b);
}

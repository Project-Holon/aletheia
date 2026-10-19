/*
 * function: RESEARCH_GRAPH_ShowBackground7
 * address:  0x021C0114
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) 7, 1, 0 to BG_SYS_FreeTiles.
 *
 * symbols:
 *   BG_SYS_FreeTiles  0x02040DA8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void BG_SYS_FreeTiles(u32, u32, u32);

void RESEARCH_GRAPH_ShowBackground7(void)
{
    BG_SYS_FreeTiles(7, 1, 0);
}


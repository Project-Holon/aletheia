/*
 * function: RESEARCH_LIST_ShowBackground3
 * address:  0x021BCC58
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) 3, 1, 0 to BG_SYS_FreeTiles.
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

void RESEARCH_LIST_ShowBackground3(u32 a0)
{
    BG_SYS_FreeTiles(3, 1, 0);
}


/*
 * function: RESEARCH_TOP_ShowBackground7
 * address:  0x021BA7D0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) 7, 1, 0 to BG_SYS_SetTileUnit.
 *
 * symbols:
 *   BG_SYS_SetTileUnit  0x02040DA8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void BG_SYS_SetTileUnit(u32, u32, u32);

void RESEARCH_TOP_ShowBackground7(u32 a0, u32 a1, u32 a2)
{
    BG_SYS_SetTileUnit(7, 1, 0);
}


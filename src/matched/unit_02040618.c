/*
 * unit:     yes
 * address:  0x020407E8
 * packet:   pkt_02040618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Screen / BG hardware layer configuration getters.
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

typedef struct BgLayer {
    u8  pad0[8];
    u8  sub0[12];
    u32 field14;
    u32 field18;
    u8  pad1C[16];
} BgLayer;

extern BgLayer *g_02146A44;

u32 func_020407E8(u32 idx)
{
    return g_02146A44[idx].field14;
}

u32 func_02040804(u32 idx)
{
    return g_02146A44[idx].field18;
}

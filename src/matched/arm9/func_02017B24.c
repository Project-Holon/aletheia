/*
 * function: POKE_TOOL_HatchEgg
 * address:  0x02017B24
 * packet:   pkt_0201756C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Verified with:
 *   python tools/match.py one --src src/pending/POKE_TOOL_HatchEgg.c \
 *       --func POKE_TOOL_HatchEgg --addr 0x02017B24 --cc 1.1p1 --thumb
 *
 * symbols:
 *   POKE_TOOL_HatchBoxEgg  0x02017B4C  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_HatchBoxEgg(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);

void POKE_TOOL_HatchEgg(void *p, u32 a, u32 b, u32 c)
{
    u8 v = (u8)POKE_TOOL_DecodePartyParam(p);

    POKE_TOOL_HatchBoxEgg(p, a, b, c);
    POKE_TOOL_EncodePartyParam(p, v);
}

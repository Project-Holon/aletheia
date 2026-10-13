/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201C1C8
 * packet:   pkt_0201BD28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WAZA_TOOL_GetType, WAZA_TOOL_GetPower
 *
 * Two truncating wrappers around sub_0201BD28 (0x0201BD28, still open, a
 * getter dispatched by a small id constant), one narrowing the result to a
 * byte for id 0, the other to a halfword for id 3.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C1C8.c \
 *       --addr 0x0201C1C8 --thumb
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 sub_0201BD28(void *p, u32 id);

u8 WAZA_TOOL_GetType(void *p)
{
    return (u8)sub_0201BD28(p, 0);
}

u16 WAZA_TOOL_GetPower(void *p)
{
    return (u16)sub_0201BD28(p, 3);
}

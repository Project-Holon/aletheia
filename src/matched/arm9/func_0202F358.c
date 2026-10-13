/*
 * function: func_0202F358
 * address:  0x0202F358
 * packet:   pkt_0202F30C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_SetBoxValue   0x02017E64  thumb
 *
 * Installs the four resource slots of one variant.  The base index is the
 * caller's u8 flag plus 0x95 for the first slot, then that same base times
 * three plus 0x8f/0x90/0x91 for the rest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F358.c \
 *       --func func_0202F358 --addr 0x0202F358 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);

void func_0202F358(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u8 base = (a5 == 1);

    POKE_TOOL_SetBoxValue(a0, base + 0x95, a1);
    base = (u8)(base * 3);
    POKE_TOOL_SetBoxValue(a0, base + 0x8F, a2);
    POKE_TOOL_SetBoxValue(a0, base + 0x90, a3);
    POKE_TOOL_SetBoxValue(a0, base + 0x91, a4);
}

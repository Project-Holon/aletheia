/*
 * function: POKE_REGULATION_CheckPokemon
 * address:  0x02019DA4
 * packet:   pkt_02019D58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue   0x02017E1C  thumb
 *   func_0200AE54   0x0200AE54  thumb
 *   func_0200AFD4   0x0200AFD4  thumb
 *
 * A stat comparison against a threshold picked by selector 4 of the first
 * argument: selector 5 (one over the limit) and 6 (under it) are both
 * rejected with 2, and the tail reports 0x20 for the presence flag, 4 or
 * 0x40 for the two range checks, and 1 when there is no object at all.  The
 * two comparisons are signed, which is what `ble`/`bge` says.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckPokemon.c \
 *       --func POKE_REGULATION_CheckPokemon --addr 0x02019DA4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
typedef signed int     s32;
struct Reg;
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern u32 func_0200AFD4(struct Reg *p, u32 id, s32 n);

int POKE_REGULATION_CheckPokemon(void *a0, void *a1)
{
    u16 v5 = (u16)POKE_TOOL_GetPartyValue(a1, 5, 0);
    u16 v6 = (u16)POKE_TOOL_GetPartyValue(a1, 6, 0);
    int m;
    int s;
    int t;
    int r;

    if (a0 == 0)
        return 1;

    m = func_0200AE54(a0, 4);
    s = func_0200AE54(a0, 5);
    t = POKE_TOOL_GetPartyValue(a1, 0x9E, 0);

    switch (s) {
    case 1:
        if (m > t)
            return 2;
        break;
    case 2:
        if (m < t)
            return 2;
        break;
    }

    r = 0;
    if (POKE_TOOL_GetPartyValue(a1, 0x4C, 0) != 0)
        return 0x20;
    if (func_0200AFD4(a0, 9, v5) != 0)
        return 4;
    if (func_0200AFD4(a0, 0xA, v6) != 0)
        r = 0x40;
    return r;
}

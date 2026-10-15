/*
 * function: POKE_REGULATION_AdjustLevel
 * address:  0x0201A26C
 * packet:   pkt_02019D58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   REGULATION_GetRuleValue   0x0200AE54  thumb
 *
 * Picks the smaller (or larger, per selector 5) of a value read from the
 * object and the caller's second argument, with the selector 3 / 4 / 5 arms
 * emitted as a compare chain and the default falling through to the caller's
 * value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_AdjustLevel.c \
 *       --func POKE_REGULATION_AdjustLevel --addr 0x0201A26C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Reg;
extern u32 REGULATION_GetRuleValue(struct Reg *p, u32 id);

u32 POKE_REGULATION_AdjustLevel(void *a0, u32 a1)
{
    u32 v = REGULATION_GetRuleValue(a0, 4);
    u32 w = REGULATION_GetRuleValue(a0, 5);

    switch (w) {
    case 3:
        if (a1 > v)
            return v;
        break;
    case 4:
        return v;
    case 5:
        if (a1 < v)
            return v;
        break;
    }
    return a1;
}

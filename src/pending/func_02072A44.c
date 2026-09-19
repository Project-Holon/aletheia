/*
 * function: func_02072A44
 * address:  0x02072A44
 * packet:   pkt_02072A44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * blocker:  +0040 ABS32 g_0214DECC             -> unresolved: 0214DECC (data, from header) has no witness outside 02072A44..02072A88
 *
 * symbols:
 *   func_0207292C    0x0207292C  arm
 *   g_0214DECC       0x0214DECC  data
 *
 * Claims one bit with func_0207292C and, on success, seeds the matching slot of
 * the stride-0x14 table and clears its +8 word; the slot address is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02072A44.c \
 *       --func func_02072A44 --addr 0x02072A44 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef struct {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
    u32 unk10;
} Slot02072A44;

extern u32   func_0207292C(u32 bit);
extern Slot02072A44 g_0214DECC[];

Slot02072A44 *func_02072A44(u32 idx)
{
    Slot02072A44 *s;

    if (func_0207292C(1 << idx) == 0) {
        return 0;
    }
    s = &g_0214DECC[idx];
    s->unk00 = idx;
    s->unk08 = 0;
    return s;
}

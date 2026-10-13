/*
 * function: VMAN_GetBankSetSize
 * address:  0x02034520
 * packet:   pkt_020339D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_FlagTable  0x020A07C8  data
 *
 * Sums the values of a nine-entry {flags, value} table for every entry
 * whose flag bit is set in the argument, then scales the total left by
 * 10 (`<< 0xa`).
 *
 * Every concrete byte matches; g_FlagTable has no witness anywhere else
 * in the ARM9 image, so its one ABS32 site stays unresolved under the
 * honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/VMAN_GetBankSetSize.c \
 *       --func VMAN_GetBankSetSize --addr 0x02034520 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct FlagEntry {
    u32 flag;
    u32 value;
};

extern const struct FlagEntry g_FlagTable[9];

u32 VMAN_GetBankSetSize(u32 flags)
{
    u32 i;
    u32 sum = 0;

    for (i = 0; i < 9; i++) {
        if (flags & g_FlagTable[i].flag) {
            sum += g_FlagTable[i].value;
        }
    }
    return sum << 0xa;
}

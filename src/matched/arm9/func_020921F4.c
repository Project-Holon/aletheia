/*
 * function: func_020921F4
 * address:  0x020921F4
 * packet:   pkt_02092144
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * note:     the trailing star is the unlabelled leaf at 0x02092264 (and the
 *           word-run of unlabelled leaves after it), not a byte difference:
 *           the listing extent runs to the next func_ label at 0x020922B0.
 *           Wants a seed at 0x02092264 in layout/function_starts.txt.
 */

typedef unsigned int u32;
typedef unsigned long long u64;

int func_020921F4(u64 v)
{
    if ((*(u32 *)((char *)&v + 4) & 0x7FF00000u) != 0) {
        if ((*(u32 *)((char *)&v + 4) & 0x7FF00000u) == 0x7FF00000u)
            return ((*(u32 *)((char *)&v + 4) & 0xFFFFFu) != 0 ||
                    *(u32 *)&v != 0) ? 1 : 2;
    } else {
        return ((*(u32 *)((char *)&v + 4) & 0xFFFFFu) != 0 ||
                *(u32 *)&v != 0) ? 5 : 3;
    }
    return 4;
}

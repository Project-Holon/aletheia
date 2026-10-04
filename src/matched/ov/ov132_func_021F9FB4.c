/*
 * function: func_021F9FB4
 * address:  0x021F9FB4
 * packet:   pkt_021F9FB4
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02051630  0x02051630  arm
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x02051630 now has an
 * EXACT arm9 shard entry (pkt_02051630), so the blx at +0012 resolves via
 * `matched`.  Verified EXACT.
 *
 * Addresses are Black-image addresses.
 */

extern void func_02051630(void **p, void *q);

void func_021F9FB4(char *p, int i)
{
    int v = *(int *)(p + i * 16 + 0x4808);

    if (v != 0)
        func_02051630(*(void **)(p + 0x4804), (void *)v);
}

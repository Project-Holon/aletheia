/*
 * function: func_021F9FB4
 * address:  0x021F9FB4
 * packet:   pkt_021F9FB4
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  func_02051630 is an unlabelled arm9 ARM leaf (no func_ label,
 *           not in symbols_sdk.json / runtime_arm9.txt), so the blx at +0012
 *           has no witness outside this range.  Byte-correct; caps at MATCH.
 *
 * symbols:
 *   func_02051630  0x02051630  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_02051630(void *, int);

void func_021F9FB4(char *p, int i)
{
    int v = *(int *)(p + i * 16 + 0x4808);

    if (v != 0)
        func_02051630(*(void **)(p + 0x4804), v);
}

/*
 * function: func_02012158
 * address:  0x02012158
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  02012BC8
 */

extern void func_02012BC8(int v);
void func_02012158(char *p)
{
    func_02012BC8(*(int *)(p + 0x1c));
}

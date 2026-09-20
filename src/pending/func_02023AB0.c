/*
 * function: func_02023AB0
 * address:  0x02023AB0
 * packet:   pkt_02023AB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 *
 * cap: the only call site of func_02023AF4 (0x02023AF4) inside the image is at
 *      0x02023ADA, which is inside this function, so the `label` class refuses
 *      it (no witness outside 02023AB0..02023AF2).  Every byte reproduces:
 *      the listing extent reads 68 only because of two bytes of 00 00 padding
 *      at 0x02023AF2; the code is 66.  Promotes to EXACT the moment
 *      func_02023AF4 has its own manifest entry.
 *
 * symbols:
 *   func_02023AF4  0x02023AF4  thumb
 */

typedef unsigned int u32;

extern void func_02023AF4(void *a0, void *a1, u32 a2, u32 a3);

void func_02023AB0(void *p)
{
    int i;

    for (i = 0; i < *(int *)((char *)p + 0x310); i++) {
        func_02023AF4((void *)(*(u32 *)((char *)p + 0x30C) + i * 4), p,
                      *(u32 *)((char *)p + 0x318),
                      *(u32 *)((char *)p + 0x314));
    }
}

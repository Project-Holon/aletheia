/*
 * function: func_021BC5C4
 * address:  0x021BC5C4
 * packet:   pkt_021BC52C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021BC5C4   0x021BC5C4  thumb
 *   func_021DCFD0   0x021DCFD0  data  ov016
 *
 * Forward the argument a to entry 3 of the function-pointer table at 0x021DCFD0.
 *
 * NOT EXACT.  MATCH: the pool word names 0x021DCFD0, a bss address of ov016 that nine overlays
 * share and that another overlay starts an object at, so the `ov016` hint is
 * contested and no class attests it.  It turns EXACT when an attestation
 * extension resolves a contested bss object, or when a second reference to
 * 0x021DCFD0 exists outside this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021BC5C4.c \
 *       --func func_021BC5C4 --addr 0x021BC5C4 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void (*func_021DCFD0[])(int);

void func_021BC5C4(int a)
{
    func_021DCFD0[3](a);
}

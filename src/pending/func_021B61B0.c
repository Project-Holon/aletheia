/*
 * function: func_021B61B0
 * address:  0x021B61B0
 * packet:   pkt_021B6178
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021B61B0   0x021B61B0  thumb
 *   func_021DCE20   0x021DCE20  data  ov016
 *
 * Forward the argument a to the handler in the global function pointer at 0x021DCE20.
 *
 * NOT EXACT.  MATCH: the pool word names 0x021DCE20, a bss address of ov016 that nine overlays
 * share and that another overlay starts an object at, so the `ov016` hint is
 * contested and no class attests it.  It turns EXACT when an attestation
 * extension resolves a contested bss object, or when a second reference to
 * 0x021DCE20 exists outside this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021B61B0.c \
 *       --func func_021B61B0 --addr 0x021B61B0 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void (*func_021DCE20)(int);

void func_021B61B0(int a)
{
    func_021DCE20(a);
}

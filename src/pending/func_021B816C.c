/*
 * function: func_021B816C
 * address:  0x021B816C
 * packet:   pkt_021B816C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021B816C   0x021B816C  thumb
 *   func_021DCE20   0x021DCE20  data  ov016
 *
 * Call the global sink at 0x021DCE20 with b when b is positive, else return 0.
 *
 * NOT EXACT.  MATCH: the pool word names 0x021DCE20, a bss address of ov016 that nine overlays
 * share and that another overlay starts an object at, so the `ov016` hint is
 * contested and no class attests it.  Every concrete byte matches.  It turns
 * EXACT when an attestation extension resolves a contested bss object, or when
 * a second reference to 0x021DCE20 exists outside this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021B816C.c \
 *       --func func_021B816C --addr 0x021B816C --region ov016 --cc dsi/1.1p1 --thumb
 */

extern int (*func_021DCE20)(int);

int func_021B816C(int a, int b)
{
    if (b > 0)
        return func_021DCE20(b);
    return 0;
}

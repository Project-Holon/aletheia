/*
 * function: func_021BDD40
 * address:  0x021BDD40
 * packet:   pkt_ov021_021BDD40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub onto func_021BE1C4.
 *
 * symbols:
 *   func_021BE1C4  0x021BE1C4  thumb  ov021
 */

typedef unsigned int   u32;
extern int func_021BE1C4(u32 a);

int func_021BDD40(void *a)
{
    return func_021BE1C4((u32)a);
}

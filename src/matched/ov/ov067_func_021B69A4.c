/*
 * function: func_021B69A4
 * address: 0x021B69A4
 * packet: pkt_ov067_021B69A4
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 */
typedef unsigned int   u32;
struct Actor;
extern u32 func_0204B98C(struct Actor *a);
int func_021B69A4(void **p)
{
    if (func_0204B98C(*p) == 0) return 1;
    return 0;
}

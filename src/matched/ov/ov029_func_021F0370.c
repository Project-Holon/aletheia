/*
 * function: func_021F0370
 * address: 0x021F0370
 * packet: pkt_ov029_021F0370
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F08BC 0x021F08BC thumb ov029
 */
struct W;
extern void func_021F08BC(struct W *p, int i, int j, int k);
void func_021F0370(void *p)
{
    int i;
    for (i = 0; i < 3; i++) func_021F08BC(p, i, 0, 31);
}

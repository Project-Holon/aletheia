/*
 * function: func_021F088C
 * address: 0x021F088C
 * packet: pkt_ov029_021F088C
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F0D08 0x021F0D08 thumb ov029
 *   func_021F08BC 0x021F08BC thumb ov029
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021F3204 0x021F3204 data ov029 a1
 */
struct W;
extern unsigned short func_021F0D08(unsigned short *p, int i);
extern void func_021F08BC(struct W *p, int i, int j, int k);
extern unsigned char d_021F3204[];
void func_021F088C(void *p, int i, unsigned short *q)
{
    unsigned int v = func_021F0D08(q, i);
    if (v > 15) return;
    v = (unsigned)(v * 12) / 15;
    v = d_021F3204[v];
    func_021F08BC(p, i, v, 31);
}

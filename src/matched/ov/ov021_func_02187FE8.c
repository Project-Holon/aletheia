/*
 * function: func_02187FE8
 * address:  0x02187FE8
 * packet:   pkt_ov021_02187FE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021880A4  0x021880A4  thumb  ov021
 *   func_02012110  0x02012110  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */

void func_021880A4(int x);
struct Ctx;
void func_02012110(struct Ctx *p, void *v);
void func_020315D4(int a);
void func_020306F0(int a);

int func_02187FE8(int a, int unused, int b, int *c)
{
    func_021880A4(*c);
    func_02012110((void *)b, 0);
    func_020315D4(a);
    func_020306F0(0x96);
    func_020306F0(0x92);
    func_020306F0(0x93);
    func_020306F0(0x89);
    func_020306F0(0x50);
    func_020306F0(0x70);
    func_020306F0(0x15);
    return 1;
}

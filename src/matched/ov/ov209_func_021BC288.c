/*
 * function: func_021BC288
 * address:  0x021BC288
 * packet:   pkt_021BC288
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */

struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);

int func_021BC288(void *p)
{
    func_020315D4(p);
    func_020306F0(0x6b);
    return 1;
}

/*
 * function: func_021BC9D0
 * address:  0x021BC9D0
 * packet:   pkt_021BC9D0
 * region:   ov210
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0202E940 0x0202E940 thumb
 *   func_0202E9AC 0x0202E9AC thumb
 *   func_02049238 0x02049238 arm
 */

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0202E940(int, int, int, int);
extern void func_0202E9AC(int, int, int, int, int);
extern void func_02049238(int);

void func_021BC9D0(int p)
{
    void *h = func_020490F4(0x9f, 0x807b);

    *(int *)(p + 0x2b4) = func_0202E940(0x30, 0x10, 1, 0x7b);
    func_0202E9AC(*(int *)(p + 0x2b4), h, 0x49, 0x20, 0x30);
    func_02049238(h);
}

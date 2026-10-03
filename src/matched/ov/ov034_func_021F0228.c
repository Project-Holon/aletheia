/*
 * function: func_021F0228
 * address:  0x021F0228
 * packet:   pkt_ov034_021F0228
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0228 0x021F0228 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02040EBC 0x02040EBC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 */

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *, int, int, int, int, int);
typedef unsigned int   u32;
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_02049658(void *, int, int, int, int, int, int);
extern void func_020498F4(void *, int, int, int, int, int, int);
extern void func_02049238(void *);

void func_021F0228(int a)
{
    void *h = func_020490F4(0xC4, a);

    func_02049B68(h, 2, 4, 0, 0x60, a);
    func_02040EBC(4, 0);
    func_02049658(h, 1, 4, 0, 0, 1, a);
    func_020498F4(h, 0, 4, 0, 0, 1, a);
    func_02049238(h);
}

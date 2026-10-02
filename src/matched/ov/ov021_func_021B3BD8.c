/*
 * function: func_021B3BD8
 * address:  0x021B3BD8
 * packet:   pkt_ov021_021B3BD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3BD8 0x021B3BD8 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_020414EC 0x020414EC arm
 *   func_0204047C 0x0204047C arm
 */

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *, int, int, int, int, int);
extern void func_02049658(void *, int, int, int, int, int, int);
extern void func_02049990(void *, int, int, int, int, int, int, int);
extern void func_02049238(void *);
extern void func_0201F5BC(int, int, int, int, int);
extern void func_020414EC(int);
extern void func_0204047C(int, int);

void func_021B3BD8(char *p)
{
    void *q;

    *(volatile u16 *)0x04000050 = 0;
    q = func_020490F4(54, *(u16 *)(p + 4));
    func_02049B68(q, 1, 0, 0, 96, *(u16 *)(p + 4));
    func_02049658(q, 0, 2, 100, 0, 0, *(u16 *)(p + 4));
    func_02049990(q, 2, 2, 0, 100, 0, 0, *(u16 *)(p + 4));
    func_02049238(q);
    func_0201F5BC(1, 228, 9, 0, *(u16 *)(p + 4));
    func_020414EC(1);
    func_0204047C(2, 1);
}

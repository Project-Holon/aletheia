/*
 * function: func_02073710
 * address:  0x02073710
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_0214E464  0x0214E464  data
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


struct A { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; };
struct E { u8 p0[0xc]; u8 f0c; u8 pad[0x24 - 0xd]; };
extern struct E g_0214E464[];
extern void func_02074758(void **a0);
extern void func_020605B4(void *tbl, void *p);
void func_02073710(struct A *a) {
    if (a->f8 == 0) return;
    func_02074758((void **)a->f8);
    if (a->fc != 0) { *(u32 *)(a->fc + 8) = 0; return; }
    func_020605B4(&g_0214E464[a->f10].f0c, a);
}

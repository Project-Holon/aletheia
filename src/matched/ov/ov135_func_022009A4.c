/*
 * function: func_022009A4
 * address: 0x022009A4
 * packet: pkt_ov135_022009A4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02202858 0x02202858 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02045CAC(u32, u32, void *);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32, u32);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(u32);
extern u32 func_02045730(u32);
extern void func_020409B4(u32);
extern void func_0201F73C(u32, u32, u32, u32);
extern void func_02202858(u32, u32, void *, u32, u32, void *);
void func_022009A4(u8 *p, u32 n)
{
    u32 w;
    func_02045CAC(*(u32 *)(p + 0xb6c), n, *(void **)(p + 0xb88));
    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0xd40)), 0xf);
    w = *(u32 *)(p + 0xd40);
    func_02045334((struct Descriptor *)w);
    func_02045374(w);
    func_020409B4(func_02045730(w));
    func_0201F73C(*(u32 *)(p + 0xd40), 0, 1, 0xe);
    func_02202858(*(u32 *)(p + 0xd40), 0, *(void **)(p + 0xb88), 0, 0, p + 0xfa0);
}

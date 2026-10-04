/*
 * function: func_021C5360
 * address: 0x021C5360
 * packet: pkt_ov136_021C5360
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-02 byte-exact; waiting on arm9 witness shard for func_02024450
 * symbols:
 *   func_021C5360 0x021C5360 thumb
 *   func_02024450 0x02024450 thumb
 *   func_0202DC48 0x0202DC48 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02024450(const u16 *p);
extern void func_0202DC48(u32, u32, void *, u8);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *, u32, short, short, void *, u32, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(u32 v);
extern u32 func_02045730(u32 v);
extern void func_020409B4(u32 v);

void func_021C5360(u8 *p)
{
    int i;
    u8 *q;
    u32 t;
    for (i = 0; i < 3; i++) {
        if (func_02024450((u16 *)(*(u8 **)(p + 0x1C) + 0x16 + i * 8))) {
            func_0202DC48(*(u32 *)(p + 0x148), *(u32 *)(p + i * 4 + 0x48), *(u8 **)(p + 0x1C) + 0x16 + i * 8, i);
        }
    }
    q = *(u8 **)(p + 0x1C);
    if (*(u16 *)(q + 0x32) != 0xFFFF) {
        *(u16 *)(p + 0x14C) = 6;
        *(u16 *)(p + 0x14E) = 0;
        *(u16 *)(p + 0x150) = *(u16 *)(q + 0x32);
        func_0202DC48(*(u32 *)(p + 0x148), *(u32 *)(p + 0x54), p + 0x14C, 3);
    }
    if (p[0xB] == 0) {
        u32 a = *(u32 *)(p + 0x98);
        func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x88)), 0, 2, *(void **)(*(u8 **)(p + 0x1C) + 0xC), *(u32 *)(p + 0x24), 0x440);
        p[0x8C] = 1;
        t = *(u32 *)(p + 0x58);
        func_02045334((struct Descriptor *)t);
        func_02045374(t);
        func_020409B4(func_02045730(t));
    }
}

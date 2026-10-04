/*
 * function: func_021C47C4
 * address: 0x021C47C4
 * packet: pkt_ov136_021C47C4
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0201F73C(void *, int, int, int);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
void func_021C47C4(u8 *p, int n)
{
    void *q;
    func_0201F73C(*(void **)(p + 0x5C), 2, 13, 4);
    func_02043B5C(func_02045770(*(void **)(p + 0x5C)), 255);
    func_02045CAC(*(void **)(p + 0x20), n, *(void **)(p + 0x34));
    *(u32 *)(p + 0x9C) = func_0201CCE4(*(u32 *)(p + 0x5C), 0, 0, *(u32 *)(p + 0x34), *(u32 *)(p + 0x24), *(s8 *)(p + 0x15), *(u32 *)(p + 0x100), 4, (u16)*(u32 *)p, 15);
    q = *(void **)(p + 0x5C);
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
}

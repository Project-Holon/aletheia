/*
 * function: func_021B67D4
 * address: 0x021B67D4
 * packet: pkt_ov098_021B67D4
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02008374's three unused legacy trailing inputs omitted: full getter reads only r0, no forwarding; caller supplies no new values.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02008374 0x02008374 thumb
 *   func_02013080 0x02013080 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02041300 0x02041300 arm
 *   func_02040C14 0x02040C14 arm
 *   func_020496E4 0x020496E4 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_020215EC 0x020215EC thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_020454E0 0x020454E0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_021B6C34 0x021B6C34 thumb ov098
 *   d_021B6E74 0x021B6E74 data a4
 *   d_021B6E24 0x021B6E24 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BgTemplate;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PalAnmSlot;
struct Cfg;
extern const char d_021B6E74[];
extern const struct BgTemplate d_021B6E24;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern struct MsgBank *func_02045B38(u32, u32, u32, u32);
extern u32 func_02008374(int);
extern signed char func_02013080(u32);
extern struct U16Vec *func_020457B0(u32, u32);
extern struct WordSet *func_0201EC64(u32);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02040C14(u32, u32, u32, u32);
extern u32 func_020496E4(u32, u32, u32, u32, u32, u16);
extern int func_021F86E0(void);
extern void func_020215EC(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16, u16);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void func_02045374(struct Cfg *);
extern void func_020454E0(struct Cfg *, u16, u32);
extern void func_020409B4(u32);
extern void func_02040588(u32, u32);
extern void func_021B6C34(char *, int);
u8 *func_021B67D4(void *a, void *b, void *c, u32 heap)
{
    u8 *p;
    u32 idx;
    p = func_02030734(heap, 0x48, 1, d_021B6E74, 0x82);
    func_0203FCA0(1, &d_021B6E24, 0);
    *(u16 *)(p + 0x44) = heap;
    *(void **)(p + 0x28) = c;
    *(struct MsgBank **)(p + 0x20) = func_02045B38(0, 2, 0x56, *(u16 *)(p + 0x44));
    *(void **)(p + 0x24) = a;
    *(int *)(p + 0x34) = func_02013080(func_02008374((int)b));
    *(struct U16Vec **)(p + 0x2c) = func_020457B0(0x100, heap);
    *(struct WordSet **)(p + 0x30) = func_0201EC64(heap);
    func_02041300(1, 0, 0, 0, 32, 32, 17);
    func_02040C14(1, 0, 1, 0);
    idx = func_020496E4(11, 89, 1, 0, 0, *(u16 *)(p + 0x44));
    func_020215EC((struct PalAnmSlot *)func_021F86E0(), 11, 90, *(u16 *)(p + 0x44), 0, 32, 0, 0);
    *(u32 *)(p + 0x1c) = func_020450F0(1, 1, 19, 30, 4, 0, 0);
    func_02045374(*(struct Cfg **)(p + 0x1c));
    func_020454E0(*(struct Cfg **)(p + 0x1c), idx, 0);
    func_020409B4(1);
    func_02040588(1, 0);
    func_021B6C34((char *)p + 4, *(int *)(p + 0x1c));
    return p;
}

/*
 * function: func_021D48D8
 * address: 0x021D48D8
 * packet: pkt_ov122_021D48D8
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 02049990 argument 5 is u16: original truncates the value at 021D49B4/49D2.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   func_021D4644 0x021D4644 thumb ov122
 *   func_021D46CC 0x021D46CC thumb ov122
 *   data_021D5870 0x021D5870 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020457B0(u32, u32);
extern void *func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void *func_0201D7EC(int, int, int, int, u32);
extern void *func_02045B38(u32, u32, u32, u32);
extern u32 func_020490F4(u32, u32);
extern void func_02049B68(u32, u32, u32, u32, u32, u16);
extern void *func_02049F78(u32, u32, u32, u32);
extern void func_02082D44(const void *, void *, u32);
extern u16 data_021D5870[];
extern void func_021D4644(u16 *, const u16 *, int);
extern void func_020307B0(void *);
extern u32 func_02049740(u32, u32, u32, u32, u32, u16);
extern u32 func_02049990(u32, u32, u32, u32, u16, u32, u32, u16);
extern int func_0204A6C8(u32, u32, u32, u32, u16);
extern int func_0204AC18(u32, u32, u32, u32, u16, u16, u16);
extern int func_0204AF28(u32, u32, u32, u32);
extern void func_02049238(u32);
extern void *func_0201F5DC(u32, u32, u32, u32);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void func_021D46CC(char *);
void func_021D48D8(char *p)
{
    u32 arc;
    void *resource;
    char *palette;
    *(void **)(p + 0x54) = func_020457B0(200, *(u16 *)(p + 0xc));
    *(void **)(p + 0x58) = func_020457B0(200, *(u16 *)(p + 0xc));
    *(void **)(p + 0x50) = func_020457B0(200, *(u16 *)(p + 0xc));
    *(void **)(p + 0x3c) = func_020450F0(5, 16, 10, 10, 2, 13, 0);
    *(void **)(p + 0x4c) = func_0201D7EC(23, 0, 0, 0, *(u16 *)(p + 0xc));
    *(void **)(p + 0x44) = func_02045B38(0, 2, 23, *(u16 *)(p + 0xc));
    arc = func_020490F4(29, *(u16 *)(p + 0xc));
    func_02049B68(arc, 0, 0, 0, 0, *(u16 *)(p + 0xc));
    func_02049B68(arc, 1, 4, 0, 0, *(u16 *)(p + 0xc));
    resource = func_02049F78(arc, 1, (u32)&palette, *(u16 *)(p + 0xc));
    func_02082D44(*(void **)(palette + 0xc), p + 0x12c, 0xe0);
    func_02082D44(*(void **)(palette + 0xc), p + 0x20c, 0xe0);
    func_021D4644((u16 *)(p + 0x20c), data_021D5870, 7);
    func_020307B0(resource);
    *(u32 *)(p + 0x60) = func_02049740(arc, 4, 4, 0, 0, *(u16 *)(p + 0xc));
    func_02049990(arc, 9, 4, 0, *(u32 *)(p + 0x60), 0, 0, *(u16 *)(p + 0xc));
    func_02049990(arc, 15, 6, 0, *(u32 *)(p + 0x60), 0, 0, *(u16 *)(p + 0xc));
    *(int *)(p + 0x37c) = func_0204A6C8(arc, 5, 0, 1, *(u16 *)(p + 0xc));
    *(int *)(p + 0x378) = func_0204AC18(arc, 3, 1, 0, 0, 10, *(u16 *)(p + 0xc));
    *(int *)(p + 0x380) = func_0204AF28(arc, 7, 16, *(u16 *)(p + 0xc));
    func_02049238(arc);
    *(void **)(p + 0x5c) = func_0201F5DC(5, 11, 0, *(u16 *)(p + 0xc));
    func_02049B40(23, 5, 4, 384, 32, *(u16 *)(p + 0xc));
    func_021D46CC(p);
}

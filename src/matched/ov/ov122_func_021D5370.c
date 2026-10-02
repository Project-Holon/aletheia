/*
 * function: func_021D5370
 * address: 0x021D5370
 * packet: pkt_ov122_021D5370
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 021D53BA reads hardware DISPCNT, 021D53C0 writes the update.
 * ABI: 0203159C leaves the allocator result in r0 (020315BC/15C0); caller uses it.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_021D5368 0x021D5368 thumb ov122
 *   func_021D424C 0x021D424C thumb ov122
 *   func_021D48D8 0x021D48D8 thumb ov122
 *   func_0203101C 0x0203101C arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021D4A64 0x021D4A64 thumb ov122
 *   func_021D4244 0x021D4244 thumb ov122
 *   func_0203D798 0x0203D798 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_021D5278 0x021D5278 thumb ov122
 *   func_02178118 0x02178118 thumb ov014
 *   func_020355D8 0x020355D8 arm
 *   data_021D58B0 0x021D58B0 data a4
 *   data_021D5770 0x021D5770 data a4
 *   data_021D5740 0x021D5740 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 v[4]; } Display;
extern u32 data_021D58B0[], data_021D5740[];
extern const Display data_021D5770;
extern void func_0203064C(void *, u32, u32);
extern void *func_0203159C(void *, u32, u32);
extern void func_02082BCC(void *, int, u32);
extern void func_0204363C(u32);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const void *);
extern void func_0203FC28(Display *);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204A48C(const void *, u32, u32);
extern void *func_0204B100(int, u8, u32);
extern void func_021D5368(void);
extern void *func_020056A0(u32, void *, u32);
extern void func_021D424C(void *);
extern void func_021D48D8(char *);
extern void *func_0201EC74(u32, u32, u32);
extern void *func_0203101C(u32, u16, u32, u32);
extern u32 func_0201C440(u32);
extern void *func_02027F60(u16, u16, u32, u32, u16);
extern void func_0207D63C(void *, u32, u32, u32, u32);
extern void func_0202208C(u32, u32, u32, u32, u32, u32, u32);
extern void func_021D4A64(char *);
extern void func_021D4244(char *, void *, int);
extern void func_0203D798(void);
extern void func_0203D34C(u32, u32);
extern int func_0203CD98(void);
extern void func_021D5278(void *, const char *, int, int);
extern void func_02178118(u32, u32);
extern void func_020355D8(u8);
int func_021D5370(void *owner, void *unused, char *args)
{
    char *p;
    Display display;
    func_0203064C((void *)1, 31, 0x18000);
    p = func_0203159C(owner, 0x3a8, 31);
    func_02082BCC(p, 0, 0x3a8);
    *(u16 *)(p + 0xc) = 31;
    *(u32 *)(p + 0x350) = *(u32 *)(args + 4);
    *(u32 *)(p + 0x354) = *(u32 *)(args + 0);
    func_0204363C(1);
    *(volatile u32 *)0x04001000 |= 0x10000;
    func_0207D46C();
    func_0203F8F4(*(u16 *)(p + 0xc));
    func_02045088(*(u16 *)(p + 0xc));
    func_0201DD60();
    func_020433E0(data_021D58B0);
    display = data_021D5770;
    func_0203FC28(&display);
    func_02043534(0);
    func_020435F4(0);
    func_0204A48C(data_021D5740, (u32)data_021D58B0, *(u16 *)(p + 0xc));
    *(void **)(p + 0x30c) = func_0204B100(40, 0, *(u16 *)(p + 0xc));
    *(void **)(p + 0x310) = func_020056A0((u32)func_021D5368, p, 0);
    func_021D424C(p);
    func_021D48D8(p);
    *(void **)(p + 0x48) = func_0201EC74(11, 200, *(u16 *)(p + 0xc));
    *(void **)(p + 0x31c) = func_0203101C(*(u16 *)(p + 0xc), *(u16 *)(p + 0xc), 1, 0);
    *(u32 *)(p + 0x320) = func_0201C440(*(u16 *)(p + 0xc));
    *(void **)(p + 0x340) = func_02027F60(5, 13, *(u32 *)(p + 0x4c), *(u32 *)(p + 0x320), *(u16 *)(p + 0xc));
    func_0207D63C((void *)0x04001050, 4, 1, 15, 4);
    func_0202208C(4, 1, 1, 0, 6, 1, *(u16 *)(p + 0xc));
    func_020435F4(31);
    func_021D4244(p, func_021D4A64, 0x6cb);
    *(char **)(p + 0x344) = args;
    func_0203D798();
    *(int *)(*(char **)(p + 0x344) + 0x10) = 1;
    *(u32 *)(*(char **)(p + 0x344) + 0xc) = *(u32 *)(p + 0x350);
    func_0203D34C(0, *(u16 *)(p + 0xc));
    if (func_0203CD98()) func_02178118((u32)func_021D5278, (u32)p);
    func_020355D8(1);
    return 1;
}

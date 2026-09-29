/*
 * function: func_021F000C
 * address:  0x021F000C
 * packet:   pkt_ov033_021F000C
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021F06AC 0x021F06AC thumb ov033
 *   func_021F0760 0x021F0760 thumb ov033
 *   func_021F07F4 0x021F07F4 thumb ov033
 *   func_021F0924 0x021F0924 thumb ov033
 *   func_0204A298 0x0204A298 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021F0674 0x021F0674 thumb ov033
 *   func_021F0B74 0x021F0B74 thumb ov033
 *   func_021F05A4 0x021F05A4 thumb ov033
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_021EFEC0 0x021EFEC0 thumb ov033
 *   func_0207D63C 0x0207D63C arm
 *   func_0203D34C 0x0203D34C arm
 *   d_021F0E60 0x021F0E60 data ov033 a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32, u32, u32, const char *, u32);
extern void func_021F06AC(void *);
extern void func_021F0760(void *);
extern void func_021F07F4(void *);
extern void func_021F0924(void *);
extern void *func_0204A298(u32, u32, u32, u32, u32 *);
extern void *func_020056A0(void *fn, void *ctx, u32 a);
extern void func_021F0674(void *, void *);
extern void func_021F0B74(void *);
extern void func_021F05A4(void *, int);
extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern u32 func_0201296C(u32);
extern u32 func_02012EBC(u32);
extern u32 func_0200BE48(u32);
extern void *func_021EFEC0(u32, u32, u32);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void func_0203D34C(u32, u32);
extern const char d_021F0E60[];

void *func_021F000C(u32 heap, u32 heap2, u32 a, u32 b)
{
    char *p;
    u32 size;
    u32 s;
    u32 v;

    p = func_02030734(heap, 0xD4, 1, d_021F0E60, 0x272);
    *(u16 *)p = heap;
    *(u16 *)(p + 2) = heap2;
    *(u32 *)(p + 4) = a;
    *(u32 *)(p + 8) = b;
    func_021F06AC(p);
    func_021F0760(p);
    func_021F07F4(p);
    func_021F0924(p);
    *(void **)(p + 0x60) = func_0204A298(0xC3, 0xD, 0, *(u16 *)p, &size);
    *(void **)(p + 0xA8) = func_020056A0(func_021F0674, p, 1);
    *(u8 *)(p + 0xAC) = 0;
    *(u32 *)(p + 0xB0) = 1;
    func_021F0B74(p);
    *(u32 *)(p + 0x64) = 10;
    *(u32 *)(p + 0x68) = 9;
    *(u32 *)(p + 0x6C) = 10;
    *(u32 *)(p + 0x70) = 0;
    *(u32 *)(p + 0x7C) = 0;
    *(u32 *)(p + 0x88) = 0;
    *(u32 *)(p + 0x8C) = 0;
    *(u32 *)(p + 0x90) = 0;
    *(u32 *)(p + 0x94) = 0;
    *(u32 *)(p + 0x9C) = 0;
    *(u32 *)(p + 0xA4) = 0;
    func_021F05A4(p, 1);
    *(u32 *)(p + 0xC8) = 1;
    *(u32 *)(p + 0xCC) = 1;
    s = func_020120F4(func_02188C80(*(u32 *)(p + 8)));
    v = func_0201296C(s);
    *(void **)(p + 0xD0) = func_021EFEC0(*(u16 *)p, v, func_0200BE48(func_02012EBC(s)));
    func_0207D63C(0x04001050, 0x10, 0x18, 1, 7);
    func_0203D34C(0, *(u16 *)p);
    return p;
}

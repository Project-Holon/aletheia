/*
 * function: func_021B7BA8
 * address: 0x021B7BA8
 * packet: pkt_ov172_021B7BA8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021B8614 0x021B8614 thumb ov172
 *   func_021BE0D8 0x021BE0D8 thumb ov172
 *   func_0203D7C8 0x0203D7C8 arm
 *   func_021C1A80 0x021C1A80 arm ov172
 *   func_021BE004 0x021BE004 thumb ov172
 *   func_02012944 0x02012944 thumb
 *   func_02008494 0x02008494 thumb
 *   func_021BE100 0x021BE100 thumb ov172
 *   func_0203E5F8 0x0203E5F8 arm
 *   d_021C71F4 0x021C71F4 data a4
 */
#include "../include/Obj00386.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Flags;
extern const char d_021C71F4[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021B8614(int unused, int unused2, void *p);
extern int func_021BE0D8(void *p);
extern void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
extern unsigned long func_021C1A80(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option);
extern u32 func_021BE004(void *p);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *src, void *dst);
extern int func_021BE100(void);
extern void func_0203E5F8(int a0, int a1);
char *func_021B7BA8(void *p, u16 heap)
{
    char *q;
    u8 i;
    u8 j;
    q = func_02030734(heap, 0x3e0, 1, d_021C71F4, 0xf4);
    ((struct Obj00386 *)q)->f3DC = p;
    ((struct Obj00386 *)q)->f8 = 0;
    ((struct Obj00386 *)q)->f4 = 1;
    ((struct Obj00386 *)q)->f183 = 0;
    ((struct Obj00386 *)q)->f174 = 0;
    ((struct Obj00386 *)q)->f178 = 0;
    ((struct Obj00386 *)q)->f3D0 = 0;
    for (i = 0; i < 4; i++)
        func_021B8614((int)p, (int)q, q + 0x64 + i * 0x40);
    for (i = 0; i < 3; i++) {
        if (func_021BE0D8(p) == 0 || i == 0)
            *(void **)(q + 0x164 + i * 4) = func_0203D7C8(heap, 3 << 14, d_021C71F4, 0x107);
    }
    ((struct Obj00386 *)q)->f188 = func_0203D7C8(heap, func_021C1A80(0x80, 0xc0, 1, 4), d_021C71F4, 0x10c);
    ((struct Obj00386 *)q)->f18C = func_0203D7C8(heap, 0xc000, d_021C71F4, 0x10e);
    ((struct Obj00386 *)q)->f190 = func_0203D7C8(heap, 0xc000, d_021C71F4, 0x10f);
    ((struct Obj00386 *)q)->f170 = 0;
    ((struct Obj00386 *)q)->f182 = 0;
    ((struct Obj00386 *)q)->f184 = 0;
    ((struct Obj00386 *)q)->f194 = 0;
    ((struct Obj00386 *)q)->f198 = 0;
    ((struct Obj00386 *)q)->f1A4 = func_02030734(heap, 0x208, 1, d_021C71F4, 0x116);
    ((struct Obj00386 *)q)->f1A8 = func_02030734(heap, 0xc800, 1, d_021C71F4, 0x117);
    ((struct Obj00386 *)q)->f1AC = 0;
    ((struct Obj00386 *)q)->f1AD = 0;
    ((struct Obj00386 *)q)->f3AE = 0xff;
    ((struct Obj00386 *)q)->f3B0 = 0;
    ((struct Obj00386 *)q)->f3B4 = 0;
    ((struct Obj00386 *)q)->f3B8 = 0;
    ((struct Obj00386 *)q)->f3BC = 0;
    ((struct Obj00386 *)q)->f3D4 = 0;
    ((struct Obj00386 *)q)->f3C0 = 1;
    ((struct Obj00386 *)q)->f3C4 = 0;
    ((struct Obj00386 *)q)->f3C8 = 1;
    ((struct Obj00386 *)q)->f3CC = 0;
    ((struct Obj00386 *)q)->f3D8 = 0xff;
    func_02008494(func_02012944((void *)(*((u32 *)func_021BE004(p)))), q + 0xc);
    ((struct Obj00386 *)q)->f2C = 1;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 6; j++)
            *(u8 *)(q + i * 6 + j + 0x2e) = 0xff;
    ((Flags *)(q + 0x2d))->b0 = func_021BE100();
    ((Flags *)(q + 0x2d))->b1 = 0;
    func_02008494(func_02012944((void *)(*((u32 *)func_021BE004(p)))), q + 0x40);
    ((struct Obj00386 *)q)->f60 = func_021BE100();
    ((struct Obj00386 *)q)->f0 = 1;
    func_0203E5F8(heap, 0);
    return q;
}

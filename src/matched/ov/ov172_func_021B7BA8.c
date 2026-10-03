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
extern u32 *func_021BE004(void *p);
extern void *func_02012944(u32 v);
extern void func_02008494(void *src, void *dst);
extern int func_021BE100(void);
extern void func_0203E5F8(int a0, int a1);
char *func_021B7BA8(void *p, u16 heap)
{
    char *q;
    u8 i;
    u8 j;
    q = func_02030734(heap, 0x3e0, 1, d_021C71F4, 0xf4);
    *(void **)(q + 0x3dc) = p;
    *(u32 *)(q + 8) = 0;
    *(u8 *)(q + 4) = 1;
    *(u8 *)(q + 0x183) = 0;
    *(u32 *)(q + 0x174) = 0;
    *(u32 *)(q + 0x178) = 0;
    *(u16 *)(q + 0x3d0) = 0;
    for (i = 0; i < 4; i++)
        func_021B8614((int)p, (int)q, q + 0x64 + i * 0x40);
    for (i = 0; i < 3; i++) {
        if (func_021BE0D8(p) == 0 || i == 0)
            *(void **)(q + 0x164 + i * 4) = func_0203D7C8(heap, 3 << 14, d_021C71F4, 0x107);
    }
    *(void **)(q + 0x188) = func_0203D7C8(heap, func_021C1A80(0x80, 0xc0, 1, 4), d_021C71F4, 0x10c);
    *(void **)(q + 0x18c) = func_0203D7C8(heap, 0xc000, d_021C71F4, 0x10e);
    *(void **)(q + 0x190) = func_0203D7C8(heap, 0xc000, d_021C71F4, 0x10f);
    *(u8 *)(q + 0x170) = 0;
    *(u8 *)(q + 0x182) = 0;
    *(u32 *)(q + 0x184) = 0;
    *(u32 *)(q + 0x194) = 0;
    *(u32 *)(q + 0x198) = 0;
    *(void **)(q + 0x1a4) = func_02030734(heap, 0x208, 1, d_021C71F4, 0x116);
    *(void **)(q + 0x1a8) = func_02030734(heap, 0xc800, 1, d_021C71F4, 0x117);
    *(u8 *)(q + 0x1ac) = 0;
    *(u8 *)(q + 0x1ad) = 0;
    *(u8 *)(q + 0x3ae) = 0xff;
    *(u32 *)(q + 0x3b0) = 0;
    *(u32 *)(q + 0x3b4) = 0;
    *(u32 *)(q + 0x3b8) = 0;
    *(u32 *)(q + 0x3bc) = 0;
    *(u32 *)(q + 0x3d4) = 0;
    *(u32 *)(q + 0x3c0) = 1;
    *(u32 *)(q + 0x3c4) = 0;
    *(u32 *)(q + 0x3c8) = 1;
    *(u32 *)(q + 0x3cc) = 0;
    *(u8 *)(q + 0x3d8) = 0xff;
    func_02008494(func_02012944(*func_021BE004(p)), q + 0xc);
    *(u8 *)(q + 0x2c) = 1;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 6; j++)
            *(u8 *)(q + i * 6 + j + 0x2e) = 0xff;
    ((Flags *)(q + 0x2d))->b0 = func_021BE100();
    ((Flags *)(q + 0x2d))->b1 = 0;
    func_02008494(func_02012944(*func_021BE004(p)), q + 0x40);
    *(u8 *)(q + 0x60) = func_021BE100();
    *(u32 *)q = 1;
    func_0203E5F8(heap, 0);
    return q;
}

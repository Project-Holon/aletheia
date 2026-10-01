/*
 * function: func_021B6A64
 * address: 0x021B6A64
 * packet: pkt_ov173_021B6A64
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027778 0x02027778 thumb
 *   func_021B81B0 0x021B81B0 thumb ov173
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 a,b,c,d; } Descriptor;
extern u32 func_02027778(Descriptor *, u32);
extern void func_021B81B0(int);
int func_021B6A64(u8 *p)
{
    Descriptor x;
    x.heap = 79;
    x.count = 2;
    x.items = p + 0x1fc;
    x.zero = 0;
    x.a = 21;
    x.b = 8;
    x.c = 10;
    x.d = 3;
    *(u32 *)(p + 0x1e0) = func_02027778(&x, *(u32 *)(p + 0x1dc));
    func_021B81B0(1);
    return 4;
}

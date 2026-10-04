/*
 * function: func_021F4284
 * address: 0x021F4284
 * packet: pkt_ov112_021F4284
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021F44F8 0x021F44F8 thumb ov112
 *   func_021F46A8 0x021F46A8 thumb ov112
 *   func_02027F60 0x02027F60 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_02043598 0x02043598 arm
 *   d_021F8394 0x021F8394 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021F8394[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021F44F8(void *);
extern void func_021F46A8(void *);
extern u32 func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02043598(u32 mask, u32 enable);
typedef struct { u16 v; u16 pad; } H16;
void *func_021F4284(u32 a, u32 b, u32 c, u32 d, H16 heap)
{
    u8 *p = func_02030734(*(u16 *)&heap, 0x5c, 1, d_021F8394, 0x8d);
    *(u16 *)p = *(u16 *)&heap;
    *(u32 *)(p + 0xc) = c;
    *(u32 *)(p + 0x10) = a;
    *(u32 *)(p + 0x14) = b;
    *(u32 *)(p + 0x44) = d;
    *(u32 *)(p + 0x2c) = 0;
    *(u8 *)(p + 8) = 0;
    if (c == 1) *(u32 *)(p + 4) = 0; else *(u32 *)(p + 4) = 1;
    func_021F44F8(p);
    func_021F46A8(p);
    *(u32 *)(p + 0x40) = func_02027F60(4, 12, *(u32 *)(p + 0x20), *(u32 *)(p + 0x38), *(u16 *)p);
    func_0203D34C(0, *(u16 *)&heap);
    func_02043598(16, 1);
    return p;
}

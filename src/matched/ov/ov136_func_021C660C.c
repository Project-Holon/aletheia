/*
 * function: func_021C660C
 * address: 0x021C660C
 * packet: pkt_ov136_021C660C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const descriptor input preserves load and stack-store scheduling.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { s16 x, y; u16 value; u8 flag, mode; } Descriptor;
extern void *func_0204B294(u32, u32, u32, u32, const Descriptor *, u16, u16);
void *func_021C660C(u8 *p, const u8 *cfg)
{
    Descriptor d;
    d.x = *(s16 *)(cfg + 0);
    d.y = *(s16 *)(cfg + 2);
    d.value = *(u16 *)(cfg + 6);
    d.flag = 0;
    d.mode = *(u32 *)(cfg + 0x2c);
    return func_0204B294(*(u32 *)(p + 0x1ec), *(u32 *)(p + 0x210 + *(u32 *)(cfg + 0x14) * 4), *(u32 *)(p + 0x230 + *(u32 *)(cfg + 0x18) * 4), *(u32 *)(p + 0x250 + *(u32 *)(cfg + 0x1c) * 4), &d, *(u32 *)(cfg + 0x10), 102);
}

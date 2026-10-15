/*
 * function: STA_ACT_LIGHT_AddBillboardImage
 * address: 0x021F709C
 * packet: pkt_ov112_021F709C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   BILLBOARD_AddImageFromArchive 0x0204EFC8 arm
 *   d_021F8464 0x021F8464 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021F8464[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Desc;
extern u32 BILLBOARD_AddImageFromArchive(struct Desc *desc, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6);
u8 *STA_ACT_LIGHT_AddBillboardImage(u16 heap, u32 b, u32 c, u32 d, u32 e)
{
    u8 i = 0;
    u8 *p;
    p = func_02030734(heap, 0x440, 0, d_021F8464, 0x93);
    *(u16 *)p = heap;
    *(u32 *)(p + 4) = b;
    *(u32 *)(p + 0xc) = c;
    *(u32 *)(p + 0x10) = d;
    *(u16 *)(p + 0x434) = i;
    *(u32 *)(p + 8) = e;
    *(u8 *)(p + 0x43c) = i;
    for (i = 0; i < 4; i++) {
        u8 *q = p + i * 0x108;
        *(u32 *)(q + 0x14) = 0;
        *(u32 *)(q + 0x18) = 0;
    }
    *(u32 *)(p + 0x438) = BILLBOARD_AddImageFromArchive((struct Desc *)(*(u32 *)(p + 8)), 0x2f, 0x1d, 3, 0x33, 0x40, 0x40);
    return p;
}

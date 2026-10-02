/*
 * function: func_021C59B8
 * address: 0x021C59B8
 * packet: pkt_ov136_021C59B8
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note: 2026-10-02 structure right (two 4 and 2 iteration u16 loops, raw offsets 0x314/0x344 records, pool 78C0 and 78B0 each reloaded per use); residue is spill layout (orig sp 0x1c, offsets 0x1D0,0x314,0x318,0x31C spilled as stack constants, counter r4, i*12 r6, table ptr r7) plus ordering of table pointer before i*12
 * symbols:
 *   func_021C59B8 0x021C59B8 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   g_78C0 0x021C78C0 data
 *   g_78B0 0x021C78B0 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair { u32 a; u32 b; };
extern const struct Pair g_78C0[];
extern const struct Pair g_78B0[];
extern void *func_02027F60(int, int, void *, void *, u16);
extern u32 func_02045EC0(void *, int);

void func_021C59B8(u8 *p)
{
    u16 i;
    const struct Pair *t;
    *(void **)(*(u8 **)(p + 8) + 0x30C) = func_02027F60(0, 5, *(void **)(p + 0x18), *(void **)(*(u8 **)(p + 8) + 0x1C4), 0x66);
    for (i = 0; i < 4; i++) {
        t = &g_78C0[i];
        *(u32 *)(*(u8 **)(p + 8) + i * 12 + 0x314) = func_02045EC0(*(void **)(*(u8 **)(p + 8) + 0x1D0), *(const u32 *)((const u8 *)g_78C0 + i * 8));
        *(u16 *)(*(u8 **)(p + 8) + i * 12 + 0x318) = 0x39E3;
        *(u32 *)(*(u8 **)(p + 8) + i * 12 + 0x31C) = t->b;
    }
    for (i = 0; i < 2; i++) {
        t = &g_78B0[i];
        *(u32 *)(*(u8 **)(p + 8) + i * 12 + 0x344) = func_02045EC0(*(void **)(*(u8 **)(p + 8) + 0x1D0), *(const u32 *)((const u8 *)g_78B0 + i * 8));
        *(u16 *)(*(u8 **)(p + 8) + i * 12 + 0x348) = 0x39E3;
        *(u32 *)(*(u8 **)(p + 8) + i * 12 + 0x34C) = t->b;
    }
}

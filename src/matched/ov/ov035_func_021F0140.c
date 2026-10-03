/*
 * function: func_021F0140
 * address: 0x021F0140
 * packet: pkt_ov035_021F0140
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding at 021F015A.
 * symbols:
 *   func_02027F60 0x02027F60 thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct R;
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
void func_021F0140(char *p, u16 heap)
{
    *(void **)(p + 0x40) = func_02027F60(4, 3, *(u32 *)(p + 0x34), *(u32 *)(p + 0x3c), heap);
}

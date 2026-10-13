/*
 * function: BTL_POKEPARAM_RestoreMovePP
 * address: 0x021D5674
 * packet: pkt_ov093_021D5674
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Entry { u16 id; u8 a; u8 b; u16 c; u16 other; u8 x; u8 y; u16 z; u8 flag; u8 rest; };
typedef unsigned int u32;
u16 BTL_POKEPARAM_RestoreMovePP(u8 *p, u32 i, u8 n)
{
    struct Entry *e = (struct Entry *)((u32)p + 0x104 + i * 14);
    e->x += n;
    if (e->x > e->y) e->x = e->y;
    if (e->flag) e->a = e->x;
    return e->other;
}

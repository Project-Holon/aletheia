/*
 * function: func_021D56A0
 * address: 0x021D56A0
 * packet: pkt_ov093_021D56A0
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
u16 func_021D56A0(u8 *p, u32 i, u8 n)
{
    struct Entry *e = (struct Entry *)((u32)p + 0x104 + i * 14);
    e->a += n;
    if (e->a > e->b) e->a = e->b;
    if (e->flag) e->x = e->a;
    return e->id;
}

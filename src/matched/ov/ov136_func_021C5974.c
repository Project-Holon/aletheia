/*
 * function: func_021C5974
 * address: 0x021C5974
 * packet: pkt_ov136_021C5974
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027778 0x02027778 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 x,y,w,h; } Template;
extern void *func_02027778(Template *, void *);
void func_021C5974(u8 *p)
{
    Template t;
    t.heap = 102;
    t.count = 2;
    t.items = *(u8 **)(p + 8) + 0x344;
    t.zero = 0;
    t.x = 21;
    t.y = 8;
    t.w = 10;
    t.h = 3;
    *(void **)(*(u8 **)(p + 8) + 0x310) = func_02027778(&t, *(void **)(*(u8 **)(p + 8) + 0x30c));
}

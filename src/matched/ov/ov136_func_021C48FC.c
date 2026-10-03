/*
 * function: func_021C48FC
 * address: 0x021C48FC
 * packet: pkt_ov136_021C48FC
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 x,y,w,h; } Template;
extern u32 func_02045EC0(void *, int);
extern void *func_02027778(Template *, void *);
struct Chan02021FD8;
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void func_0202843C(u8 *p);
void func_021C48FC(u8 *p)
{
    Template t;
    *(u32 *)(p + 0x110) = func_02045EC0(*(void **)(p + 0x20), 4);
    *(u16 *)(p + 0x114) = 0x39E3;
    *(u32 *)(p + 0x118) = 0;
    *(u32 *)(p + 0x11C) = func_02045EC0(*(void **)(p + 0x20), 5);
    *(u16 *)(p + 0x120) = 0x39E3;
    *(u32 *)(p + 0x124) = 0;
    t.heap = *(u32 *)p;
    t.count = 2;
    t.items = p + 0x110;
    t.zero = 0;
    t.x = 23;
    t.y = 6;
    t.w = 8;
    t.h = 3;
    *(void **)(p + 0x10C) = func_02027778(&t, *(void **)(p + 0x108));
    func_02021FD8(*(void **)(p + 0x38), 0, 0, 48, 10, 0);
    func_0202843C(*(void **)(p + 0x128));
    func_0202843C(*(void **)(p + 0x12C));
}

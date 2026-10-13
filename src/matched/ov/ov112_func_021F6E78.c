/*
 * function: func_021F6E78
 * address: 0x021F6E78
 * packet: pkt_ov112_021F6E78
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, unsigned int);
u8 *func_021F6E78(u8 *p, int v)
{
    u8 i = 0;
    u8 *q;
    Pos pos;
    struct Obj *o;
    do {
        if (*(u32 *)(p + i * 32 + 8) == 0) break;
        i++;
    } while (i < 4);
    *(u32 *)(p + 8 + i * 32) = v;
    q = p + 8 + i * 32;
    pos.x = 0x80;
    pos.y = 0x60;
    pos.z = 0;
    pos.a = 0;
    pos.b = 2;
    o = CLACT_CreateActor(*(void **)(p + 0xa8), *(u32 *)(p + 0xb0), *(u32 *)(p + 0xac), *(u32 *)(p + 0xb4), &pos, 0, *(u16 *)p);
    *(struct Obj **)(q + 0x1c) = o;
    func_0204B3DC(o, 1);
    return q;
}

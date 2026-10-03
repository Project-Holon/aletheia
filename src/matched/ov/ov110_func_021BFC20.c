/*
 * function: func_021BFC20
 * address: 0x021BFC20
 * packet: pkt_ov110_021BFC20
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BF734 0x021BF734 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern unsigned func_021BF734(u8 *);
void func_021BFC20(u8 *p, unsigned visible) {
    if (visible) {
        if (**(unsigned **)(p+0x9c)==0) func_0204B3DC(*(void **)(p+0x14),1);
        else func_0204B3DC(*(void **)(p+0x14),0);
        func_0204B3DC(*(void **)(p+0x1c), func_021BF734(*(u8 **)(p+4))>14 ? 1 : 0);
    } else {
        func_0204B3DC(*(void **)(p+0x14),visible);
        func_0204B3DC(*(void **)(p+0x1c),0);
    }
}

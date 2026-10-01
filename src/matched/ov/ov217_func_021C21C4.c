/*
 * function: func_021C21C4
 * address: 0x021C21C4
 * packet: pkt_ov217_021C21C4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero padding bytes at 0x021C224E, not a follower.
 * ABI: B8C4's own source omits the visible original r1=0; retain it.
 *      Palette is selected only for the original modes 0..3; original
 *      default branch retains entry r5 without initializing it.
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B9C4 0x0204B9C4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B954 0x0204B954 arm
 *   func_0204B95C 0x0204B95C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Vec2 { short x,y; };
struct Obj;
struct Actor;
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B8C4(struct Obj *,u32);
extern void func_0204B9C4(struct Actor *,u32);
extern void func_0204B92C(struct Obj *,u32);
extern void func_0204B954(struct Actor *,u32);
extern void func_0204B95C(struct Actor *);
extern void func_0204B3DC(struct Obj *,u32);
void func_021C21C4(u8 *p,int index)
{
    u8 *record=p+0x28+index*24;
    struct Obj *obj=*(struct Obj **)(record+0x14);
    struct Vec2 point;
    u16 palette;
    point.x=record[0xe];
    point.y=record[0xf];
    *(u32 *)record=1;
    switch (*(u32 *)(record+0x10)) {
    case 0: palette=*(u16 *)(p+0x16); break;
    case 1: palette=*(u16 *)(p+0x18); break;
    case 2: palette=*(u16 *)(p+0x1a); break;
    case 3: palette=*(u16 *)(p+0x1c); break;
    }
    func_0204B404(obj,&point,*(u16 *)(p+0x14));
    func_0204B878(obj,palette);
    func_0204B8C4(obj,0);
    func_0204B9C4((struct Actor *)obj,1);
    func_0204B92C(obj,1);
    func_0204B954((struct Actor *)obj,0x12000);
    func_0204B95C((struct Actor *)obj);
    func_0204B3DC(obj,1);
}

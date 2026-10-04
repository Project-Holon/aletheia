/*
 * function: func_021D67B4
 * address: 0x021D67B4
 * packet: pkt_ov123_021D67B4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6C90 0x021D6C90 thumb ov123
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B570 0x0204B570 arm
 *   d_021DA734 0x021DA734 data a2
 *   d_021DA740 0x021DA740 data a4
 */
#include "../include/Obj13980.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Pos { short x,y; };
struct Pair { int a,b; };
extern const struct Pos d_021DA734;
extern const struct Pair d_021DA740;
extern void func_021D6C90(u8 *, int, void *);
extern void func_0204B404(void *, struct Pos *, u16);
extern void func_0204B5AC(void *, struct Pair *);
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B570(struct Actor *actor, u32 value);
void func_021D67B4(u8 *p, int i)
{
    struct Pos pos;
    struct Pair pair;
    void *h;
    func_021D6C90(p,i,((struct Obj13980 *)p)->fB8);
    h = ((struct Obj13980 *)p)->fB8;
    pos = d_021DA734; pair = d_021DA740;
    func_0204B404(h,&pos,0); func_0204B5AC(h,&pair);
    func_0204B92C(h,0); func_0204B3DC(h,0);
    func_0204B688(h,1); func_0204B570(h,2);
    *(void **)(p+i*24+0x40f4) = h;
}

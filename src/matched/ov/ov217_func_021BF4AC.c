/*
 * function: func_021BF4AC
 * address: 0x021BF4AC
 * packet: pkt_ov217_021BF4AC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind table=d_021C3850 before the guards to retain its r7 base.
 * F910 preserves caller's visibly loaded r1; C11DC/C11FC index parameters are u8 from original truncations.
 * symbols:
 *   d_021C3850 0x021C3850 data a2
 *   func_021BF910 0x021BF910 thumb ov217
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_021C11DC 0x021C11DC thumb ov217
 *   func_021C11FC 0x021C11FC thumb ov217
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B9C4 0x0204B9C4 arm
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
struct Obj; struct Actor;
struct Vec2 { short x,y; };
extern const u16 d_021C3850[];
typedef unsigned int   u32;
extern u32 func_021BF910(u8 *p);
extern u8 *func_021BF76C(void *p);
extern u8 func_021C11DC(u8 *p, u8 key);
extern void func_021C11FC(u8 *h, u8 key, s32 *px, s32 *py);
extern void func_0204B3DC(struct Obj *,unsigned);
extern void func_0204B404(struct Obj *,const struct Vec2 *,unsigned);
extern void func_0204B92C(struct Obj *,unsigned);
extern void func_0204B9C4(struct Actor *,unsigned);
void func_021BF4AC(char *p)
{
    struct Obj *obj;
    unsigned index;
    s32 x,y;
    struct Vec2 pos;
    const u16 *table;
    obj=*(struct Obj * *)&((struct Obj00021 *)p)->f3A0;
    table=d_021C3850;
    if (((struct Obj00021 *)p)->f3C8==0) { func_0204B3DC(obj,0); return; }
    if (((struct Obj00021 *)p)->f34!=2) { func_0204B3DC(obj,0); return; }
    index=func_021BF910((u8 *)p);
    if (func_021C11DC(func_021BF76C(p),index)==0) { func_0204B3DC(obj,0); return; }
    if (index==0) { func_0204B3DC(obj,0); return; }
    func_021C11FC(func_021BF76C(p),index,&x,&y);

    pos.x=x;
    pos.y=y;
    func_0204B404(obj,&pos,table[12]);
    func_0204B3DC(obj,1);
    func_0204B92C(obj,1);
    func_0204B9C4((struct Actor *)obj,2);
}

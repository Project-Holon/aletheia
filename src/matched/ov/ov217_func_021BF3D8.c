/*
 * function: func_021BF3D8
 * address: 0x021BF3D8
 * packet: pkt_ov217_021BF3D8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C3AC8 0x021C3AC8 data a4
 *   func_021BFA08 0x021BFA08 thumb ov217
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B92C 0x0204B92C arm
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
struct Row { u8 x,y,w,h; int fields[8]; };
struct Vec2 { short x,y; };
struct Obj;
extern const struct Row d_021C3AC8[];
extern unsigned func_021BFA08(void *,unsigned);
extern void func_0204B3DC(struct Obj *,unsigned);
extern void func_0204B404(struct Obj *,const struct Vec2 *,unsigned);
extern void func_0204B92C(struct Obj *,unsigned);
void func_021BF3D8(char *p)
{
    const struct Row *row;
    struct Obj *a,*b;
    struct Vec2 pos;
    row=&d_021C3AC8[((struct Obj00021 *)p)->f34];
    a=(struct Obj *)func_021BFA08(p,0);
    b=(struct Obj *)func_021BFA08(p,1);
    if (((struct Obj00021 *)p)->f3D0==1 || ((struct Obj00021 *)p)->f34==2 || ((struct Obj00021 *)p)->f34==4) {
        func_0204B3DC(a,0);
        func_0204B3DC(b,0);
        return;
    }
    pos.x=row->fields[0]+row->fields[4];
    pos.y=row->fields[1]+row->fields[5];
    func_0204B404(a,&pos,0);
    pos.x=row->fields[0]+row->fields[6];
    pos.y=row->fields[1]+row->fields[7];
    func_0204B404(b,&pos,0);
    func_0204B3DC(a,1);
    func_0204B3DC(b,1);
    func_0204B92C(a,1);
    func_0204B92C(b,1);
}

/*
 * file:     p_sta_oam_p18.c
 * unit:     yes
 * function: func_021D7C38, func_021D7CAC
 * address:  0x021D7C38
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_020450F0 0x020450F0 arm
 *   d_021DC288 0x021DC288 data a1
 *   func_021D7F04 0x021D7F04 thumb ov131
 *   func_021D8288 0x021D8288 thumb ov131
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02017E88 0x02017E88 thumb
 *   func_0204AB84 0x0204AB84 arm
 *   func_0204B784 0x0204B784 arm
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B878 0x0204B878 arm
 */
#include "../../matched/include/Obj01547.h"
#include "../../matched/include/Obj01407.h"
#include "../../matched/include/Obj05391.h"
#include "../../matched/include/Obj23144.h"

struct Cfg;
struct Descriptor;
struct Obj;
struct Struct36;
struct Vec2;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short s16;

struct Rec { u32 w[9]; };

struct Point { s16 x,y; };

extern void *func_021D6064(unsigned char *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_021D7F04(u8 *p, u8 *q, void *mon);
extern void func_021D8288(u8 *a, u8 *p, void *mon);
extern void func_020410D0(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02041B6C(u32);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern u32 func_02017E88(void *,u32,u32);
extern void func_0204AB84(u32,struct Rec *);
extern void func_0204B784(char *dst, const struct Struct36 *src);
extern u8 func_020275EC(int i);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B84C(void *,u32);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021D7C38(void *a, unsigned char *p);
void func_021D7CAC(u8 *a,u8 *p);
extern const unsigned char d_021DC288[];

void func_021D7C38(void *a, unsigned char *p)
{
    void *arc=func_021D6064(a);
    unsigned char i;
    for(i=0;i<10;i++) {
        unsigned int offset=i*4;
        *(void **)(p+offset+0xc)=(void *)func_020450F0(1,d_021DC288[offset],d_021DC288[offset+1],d_021DC288[offset+2],d_021DC288[offset+3],14,1);
    }
    ((struct Obj01547 *)p)->f34=(void *)func_020450F0(4,4,5,24,20,14,1);
    func_021D7F04(a,p,arc);
    func_021D8288(a,p,arc);
    ((struct Obj01547 *)p)->f4=1;
}

void func_021D7CAC(u8 *a,u8 *p)
{
    struct Rec r1,r2;
    struct Point point;
    u8 i;
    void *object;
    void *cell;
    u32 first,second;
    object=func_021D6064(a);
    if(((struct Obj01407 *)a)->f38==0) func_020410D0(2,0,0,32,24,(u32)(*(u8 * *)&((struct Obj05391 *)p)->f4C+12),0,0,32,32);
    else func_020410D0(2,0,0,32,24,(u32)(*(u8 * *)&((struct Obj05391 *)p)->f54+12),0,0,32,32);
    func_02041B6C(2);
    func_02040AE0(6,*(u8 * *)&((struct Obj05391 *)p)->f5C+12,((struct Obj23144 *)(*(u8 * *)&((struct Obj05391 *)p)->f5C))->f8);
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,(u32)(*(u8 * *)&((struct Obj05391 *)p)->f64+12),0,0,32,32);
    func_02041B6C(5);
    for(i=0;i<10;i++) {
        cell=*(void **)((p+i*4)+0xc);
        func_02045334(cell);
        func_02045374(cell);
        func_020409B4(func_02045730(cell));
    }
    cell=((struct Obj05391 *)p)->f34;
    func_02045334(cell);
    func_02045374(cell);
    func_020409B4(func_02045730(cell));
    if(((struct Obj01407 *)a)->f38==0) {
        first=func_02017E88(object,174,0);
        second=func_02017E88(object,175,0);
        func_0204AB84(*(u32 *)((u32)a+first*4u+0x130u),&r1);
        func_0204B784(((struct Obj01407 *)a)->f198,(const struct Struct36 *)(&r1));
        func_0204B6F4(((struct Obj01407 *)a)->f198,func_020275EC((u8)first),1);
        point.x=96;
        point.y=48;
        func_0204B404(((struct Obj01407 *)a)->f198,(const struct Vec2 *)(&point),0);
        func_0204B3DC(((struct Obj01407 *)a)->f198,1);
        func_0204B84C(((struct Obj01407 *)a)->f198,1);
        if(first!=second) {
            func_0204AB84(*(u32 *)((u32)a+second*4u+0x130u),&r2);
            func_0204B784(((struct Obj01407 *)a)->f19C,(const struct Struct36 *)(&r2));
            func_0204B6F4(((struct Obj01407 *)a)->f19C,func_020275EC((u8)second),1);
            point.x=130;
            point.y=48;
            func_0204B404(((struct Obj01407 *)a)->f19C,(const struct Vec2 *)(&point),0);
            func_0204B3DC(((struct Obj01407 *)a)->f19C,1);
            func_0204B84C(((struct Obj01407 *)a)->f19C,1);
        } else func_0204B3DC(((struct Obj01407 *)a)->f19C,0);
    } else {
        func_0204B3DC(((struct Obj01407 *)a)->f198,0);
        func_0204B3DC(((struct Obj01407 *)a)->f19C,0);
    }
    func_0204B878(((struct Obj01407 *)a)->f178,3);
}

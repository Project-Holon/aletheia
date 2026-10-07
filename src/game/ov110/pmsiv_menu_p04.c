/*
 * file:     pmsiv_menu_p04.c
 * unit:     yes
 * function: func_021BC564, func_021BC578, func_021BC58C, func_021BC5BC, func_021BC69C, func_021BC6D0, func_021BC6DC
 * address:  0x021BC564
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_02024508 0x02024508 thumb
 *   func_02024520 0x02024520 thumb
 *   func_02045730 0x02045730 arm
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020416D4 0x020416D4 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_02024838 0x02024838 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 */
#include "../../matched/include/Obj10277.h"
#include "../../matched/include/Obj01393.h"
#include "../../matched/include/Obj22375.h"

struct Bmp;
struct Descriptor;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021BC564;

typedef unsigned int u32;

typedef signed short s16_021BC578;

typedef signed short s16_021BC58C;

typedef struct { s16_021BC58C x, y; } Vec2_021BC58C;

typedef signed short s16_021BC5BC;

typedef struct Vec2_021BC5BC { s16_021BC5BC x,y; } Vec2_021BC5BC;

typedef signed short s16_021BC69C;

typedef signed short s16_021BC6D0;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u32 func_021BAC44(u8 *);
extern u32 func_02024508(u32);
extern u32 func_02024520(u32);
extern u8 func_02045730(struct Descriptor *);
extern u8 func_02045758(struct Descriptor *);
extern u8 func_02045760(struct Descriptor *);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B404(struct Obj *p, const struct Vec2_021BC5BC *delta, u32 which);
extern void func_0204B3DC(struct Obj *,u32);
extern u8 func_020416D4(u32);
extern void func_0204B84C(struct Obj *,u32);
extern void func_02024838(u32,void *,u32);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,s16_021BC5BC,s16_021BC5BC,void *,void *);
void func_021BC564(s16_021BC564 *p,s16_021BC564 *out);
void func_021BC578(const s16_021BC578 *a, s16_021BC578 *b);
void func_021BC58C(void *p, const Vec2_021BC58C *a);
void func_021BC5BC(u8 *p,struct Descriptor *window,const Vec2_021BC5BC *input,u32 id,struct Obj *sprite);
void func_021BC69C(u8 *p, int flag);
u32 func_021BC6D0(u32 n);
unsigned int func_021BC6DC(void *p);


/*
 * extent: two bytes of zero alignment padding after return.
 */
void func_021BC564(s16_021BC564 *p,s16_021BC564 *out) { out[0]=p[0]-48; out[1]=p[1]-8; }


void func_021BC578(const s16_021BC578 *a, s16_021BC578 *b)
{
    b[0] = a[0] + 24;
    b[1] = a[1] + 8;
}

void func_021BC58C(void *p, const Vec2_021BC58C *a)
{
    Vec2_021BC58C pos;
    func_021BC564((s16_021BC58C *)a, (s16_021BC58C *)(&pos));
    func_02043AF4(func_02045770(p), pos.x, pos.y, 0x60, 16, 14);
}

void func_021BC5BC(u8 *p,struct Descriptor *window,const Vec2_021BC5BC *input,u32 id,struct Obj *sprite)
{
    Vec2_021BC5BC base;
    Vec2_021BC5BC pos;
    u32 font;
    u32 index;
    u32 layer;
    font=func_021BAC44(*(u8 * *)&((struct Obj10277 *)p)->f0);
    if(id==0xffff) return;
    func_021BC564((s16_021BC5BC *)input,(s16_021BC5BC *)(&base));
    if(func_02024508(id)!=0) {
        index=func_02024520(id)-1;
        layer=func_021BC6D0(func_02045730(window));
        pos.x=base.x+func_02045758(window)*8;
        pos.y=base.y+func_02045760(window)*8;
        if(layer==1) pos.y+=192;
        func_0204B878(sprite,index);
        func_0204B404(sprite,&pos,(u16)layer);
        func_0204B3DC(sprite,1);
        func_0204B84C(sprite,func_020416D4(func_02045730(window)));
    } else {
        func_02024838(id,((struct Obj10277 *)p)->f30,42);
        func_0201DD78(3,4,14);
        func_0201C7A4(func_02045770(window),base.x,base.y,((struct Obj10277 *)p)->f30,(void *)font);
    }
}

void func_021BC69C(u8 *p, int flag)
{
    if (((struct Obj01393 *)p)->f44 != 0) {
        if (flag != 0) func_0204B878(((struct Obj01393 *)p)->f14, 0);
        else func_0204B878(((struct Obj01393 *)p)->f14, 1);
    } else {
        if (flag != 0) func_0204B878(((struct Obj01393 *)p)->f14, 14);
        else func_0204B878(((struct Obj01393 *)p)->f14, 15);
    }
}


u32 func_021BC6D0(u32 n)
{
    if (n >= 4) return 1;
    return 0;
}


unsigned int func_021BC6DC(void *p)
{
    return ((struct Obj22375 *)p)->f44;
}

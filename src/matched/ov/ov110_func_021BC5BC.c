/*
 * function: func_021BC5BC
 * address: 0x021BC5BC
 * packet: pkt_ov110_021BC5BC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: C564 full body writes both signed-halfword base coordinates;
 *   position x/y initialized before sprite read. Descriptor getters return
 *   u8; all arithmetic uses promoted values and observed halfword wrapping.
 *   B404 third extern is u16 because original truncates just before call;
 *   own B404 full body forwards only that value as the selector. Font pointer
 *   preserves BAC44 full 32-bit payload. Sentinel returns before any local
 *   read. All other prototypes copied from full own matched bodies/units.
 * symbols:
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BC564 0x021BC564 thumb ov110
 *   func_02024508 0x02024508 thumb
 *   func_02024520 0x02024520 thumb
 *   func_02045730 0x02045730 arm
 *   func_021BC6D0 0x021BC6D0 thumb ov110
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020416D4 0x020416D4 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_02024838 0x02024838 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 */
#include "../include/Obj10277.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Vec2 { s16 x,y; } Vec2;
struct Descriptor;
struct Obj;
extern u32 func_021BAC44(u8 *);
extern void func_021BC564(s16 *p, s16 *out);
extern u32 func_02024508(u32);
extern u32 func_02024520(u32);
extern u8 func_02045730(struct Descriptor *);
extern u32 func_021BC6D0(u32);
extern u8 func_02045758(struct Descriptor *);
extern u8 func_02045760(struct Descriptor *);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *,u32);
extern u8 func_020416D4(u32);
extern void func_0204B84C(struct Obj *,u32);
extern void func_02024838(u32,void *,u32);
extern void func_0201DD78(u32,u32,u32);
extern void *func_02045770(struct Descriptor *);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
void func_021BC5BC(u8 *p,struct Descriptor *window,const Vec2 *input,u32 id,struct Obj *sprite)
{
    Vec2 base;
    Vec2 pos;
    u32 font;
    u32 index;
    u32 layer;
    font=func_021BAC44(*(u8 * *)&((struct Obj10277 *)p)->f0);
    if(id==0xffff) return;
    func_021BC564((s16 *)input,(s16 *)(&base));
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

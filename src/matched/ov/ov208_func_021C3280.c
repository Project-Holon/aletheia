/*
 * function: func_021C3280
 * address: 0x021C3280
 * packet: pkt_ov208_021C3280
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_020437DC 0x020437DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_021C3318 0x021C3318 thumb ov208
 *   data_020A7370 0x020A7370 data a4
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct MsgBank; struct StrObj; struct Descriptor; struct Bmp; struct U16Vec; struct Key;
extern u16 func_021BC3C0(struct Key *key);
extern void *func_02045EC0(struct MsgBank *bank,u32 index);
extern u32 func_0201D304(struct StrObj *s,u32 a,u32 b);
extern void *func_02045770(struct Descriptor *p);
extern u16 func_020437DC(const struct Bmp *p);
extern void func_0201C724(void *owner,u32 bitmap,s16 x,s16 y,u32 text,u32 font,u16 color);
extern void func_02045808(struct U16Vec *s);
extern void func_021C3318(u16 *heap, u8 *p, int key);
extern struct MsgBank *data_020A7370;
void func_021C3280(u16 *heap,u8 *p,struct Key *key)
{
    struct StrObj *text;
    u16 width;
    u16 available;
    text=func_02045EC0(data_020A7370,func_021BC3C0(key));
    width=func_0201D304(text,((struct Obj00146 *)p)->f4,0);
    available=func_020437DC(func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC));
    func_0201C724(((struct Obj00146 *)p)->f8,(u32)func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC),(u16)((available-width)/2),1,(u32)text,((struct Obj00146 *)p)->f4,0x3c40);
    func_02045808((struct U16Vec *)text);
    ((struct Obj00146 *)p)->f10=1;
    func_021C3318(heap,p,(int)key);
}

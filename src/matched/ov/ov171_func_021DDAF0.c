/*
 * function: func_021DDAF0
 * address: 0x021DDAF0
 * packet: pkt_ov171_021DDAF0
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_020257D0 0x020257D0 thumb
 */
#include "../include/Obj00210.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct CharBuf;
struct MsgBank;
struct Obj;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_020257D0(struct Obj *o);
void func_021DDAF0(u8 *p)
{
    void *s1,*s2,*font,*text;
    u8 width,x;
    u32 w;
    if(p[0xc5f]==1) return;
    func_02043B5C(((struct Obj00210 *)p)->fC58,0);
    s1=func_02045EC0(((struct Obj00210 *)p)->fB60,3);
    width=func_0201D304(s1,*(u32 *)&((struct Obj00210 *)p)->fB58,0);
    x=(40-width)/2;
    func_0201C7D0(((struct Obj00210 *)p)->fC58,x,4,s1,((struct Obj00210 *)p)->fB58,0x1900);
    func_02045808(s1);
    s2=func_02045EC0(((struct Obj00210 *)p)->fB60,4);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,0,((struct Obj00210 *)p)->fC5E + 1,2,0,1);
    func_0201F250(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s2);
    font=((struct Obj00210 *)p)->fB58;
    text=((struct Obj00210 *)p)->fB68;
    w=func_0201D304(text,(u32)font,0);
    func_0201C7D0(((struct Obj00210 *)p)->fC58,x-w,4,text,font,0x1900);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,0,p[0xc5f],2,0,1);
    func_0201F250(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s2);
    func_0201C7D0(((struct Obj00210 *)p)->fC58,x+width,4,((struct Obj00210 *)p)->fB68,((struct Obj00210 *)p)->fB58,0x1900);
    func_02045808(s2);
    func_020257D0(((struct Obj00210 *)p)->fC54);
}

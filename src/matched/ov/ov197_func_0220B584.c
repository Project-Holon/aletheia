/*
 * function: func_0220B584
 * address: 0x0220B584
 * packet: pkt_ov197_0220B584
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * matching: parenthesised byte-pointer plus page keeps the page load before the far-field add; a flat offset sum differs in two bytes.
 * Width: original narrows x to signed 16 bits before each 0201C724 call; s16 extern preserves those caller truncations despite owner u32 x.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045738 0x02045738 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 */
#include "../include/Obj00314.h"
#include "../include/Obj24999.h"
#include "../include/Obj25000.h"
#include "../include/Obj25001.h"
#include "../include/Obj25002.h"
#include "../include/Obj25003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *,void *,s16,s16,void *,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
void func_0220B584(char *p)
{
    void *handle=((struct Obj00314 *)p)->f118;
    void *surface=func_02045770(handle);
    void *text;
    u32 width;
    u32 x;
    void *font;
    void *lastSurface;
    func_02043B5C(surface,0);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,28);
    width=func_0201D304(text,((struct Obj24999 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0);
    x=(func_02045738(handle)*8-width)/2;
    func_0201C724(((struct Obj00314 *)p)->f18,surface,x,4,text,((struct Obj25000 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    func_02045808(text);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,29);
    func_0201EFA4(((struct Obj00314 *)p)->f10,0,((u8 *)p+((u8 *)p)[0x533])[0x539]+1,2,0,1);
    func_0201F250(((struct Obj00314 *)p)->f10,((struct Obj00314 *)p)->f14,text);
    func_0201C724(((struct Obj00314 *)p)->f18,surface,x+width,4,((struct Obj00314 *)p)->f14,((struct Obj25001 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    func_02045808(text);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,30);
    func_0201EFA4(((struct Obj00314 *)p)->f10,0,*(s16 *)(*(char * *)&((struct Obj00314 *)p)->f0+((u8 *)p)[0x533]*2+0x38)+1,2,0,1);
    func_0201F250(((struct Obj00314 *)p)->f10,((struct Obj00314 *)p)->f14,text);
    width=func_0201D304(((struct Obj00314 *)p)->f14,((struct Obj25002 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0);
    font=((struct Obj00314 *)p)->f18;
    lastSurface=func_02045770(((struct Obj00314 *)p)->f118);
    func_0201C724(font,lastSurface,x-width,4,((struct Obj00314 *)p)->f14,((struct Obj25003 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    ((u8 *)p)[0x11C]=1;
    func_02045808(text);
}

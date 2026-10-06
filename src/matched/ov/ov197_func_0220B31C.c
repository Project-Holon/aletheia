/*
 * function: func_0220B31C
 * address: 0x0220B31C
 * packet: pkt_ov197_0220B31C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Width: printer x truncates to signed halfword in original; extern keeps s16 despite owner u32.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_02045738 0x02045738 arm
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201D304 0x0201D304 thumb
 *   d_0220DA38 0x0220DA38 data a4
 */
#include "../include/Obj00845.h"
#include "../include/Obj24993.h"
#include "../include/Obj24994.h"
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
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern const char d_0220DA38[];
void func_0220B31C(char *p,u32 i,int id,int w,int unused,int unused2)
{
    char *windows=p+0x28;
    void *handle=*(void **)(windows+w*8);
    void *text;
    void *font;
    void *surface;
    u32 width;
    int page;
    func_02043B5C(func_02045770(handle),0);
    page=(u32)p+((u8 *)p)[0x533]*0x90;
    if(*(u16 *)(page+i*4+0x150)!=0){
        text=func_02045EC0(((struct Obj00845 *)p)->fC,*(u32 *)(d_0220DA38+id*8));
        page=(u32)p+((u8 *)p)[0x533]*0x90;
        func_0201EF40(((struct Obj00845 *)p)->f10,0,*(u16 *)(page+i*4+0x150));
        func_0201F250(((struct Obj00845 *)p)->f10,((struct Obj00845 *)p)->f14,text);
        width=func_0201D304(((struct Obj00845 *)p)->f14,((struct Obj24993 *)(*(char * *)&((struct Obj00845 *)p)->f0))->f4,0);
        width=func_02045738(handle)*8-width;
        font=((struct Obj00845 *)p)->f18;
        surface=func_02045770(*(void **)(windows+w*8));
        func_0201C724(font,(u32)surface,(s16)(width/2),(s16)7,(u32)(((struct Obj00845 *)p)->f14),((struct Obj24994 *)(*(char * *)&((struct Obj00845 *)p)->f0))->f4,0x3C40);
        (p+w*8)[0x2C]=1;
        func_02045808(text);
    }else{
        func_02045334(handle);
    }
}

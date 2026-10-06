/*
 * function: func_0220B248
 * address: 0x0220B248
 * packet: pkt_ov197_0220B248
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * matching: unsigned loop bound i<=4 preserves the original cmp4/bls; i<5 differs in two bytes.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0220B1D4 0x0220B1D4 thumb ov197
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   d_0220DA0D 0x0220DA0D data a1
 */
#include "../include/Obj03905.h"
#include "../include/Obj24992.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
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
extern void func_0220B1D4(char *,int,int,int,u16);
extern const char d_0220DA0D[];
void func_0220B248(char *p)
{
    unsigned i;
    void *text;
    void *font;
    void *surface;
    for(i=0;i<=4;i++)func_02043B5C(func_02045770(*(void **)(p+i*8+0x28)),0);
    func_0220B1D4(p,0,0,0,0x3C40);
    func_0220B1D4(p,0,1,16,0x3C40);
    func_0220B1D4(p,1,2,0,0x3C40);
    func_0220B1D4(p,1,3,16,0x3C40);
    func_0220B1D4(p,2,7,0,0x3C40);
    func_0220B1D4(p,3,6,0,0x3C40);
    if(((struct Obj03905 *)p)->f540!=0){
        text=func_02045EC0(((struct Obj03905 *)p)->fC,8);
        font=((struct Obj03905 *)p)->f18;
        surface=func_02045770(((struct Obj03905 *)p)->f48);
        func_0201C724(font,(u32)surface,0,0,(u32)text,((struct Obj24992 *)(*(char * *)&((struct Obj03905 *)p)->f0))->f4,0x3C40);
        p[0x4C]=1;
        func_02045808(text);
    }else{
        func_02045334(((struct Obj03905 *)p)->f48);
    }
    *(const char * *)&((struct Obj03905 *)p)->f59C=d_0220DA0D;
}

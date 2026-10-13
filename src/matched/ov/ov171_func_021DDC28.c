/*
 * function: func_021DDC28
 * address: 0x021DDC28
 * packet: pkt_ov171_021DDC28
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201EE60 0x0201EE60 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   func_021DD94C 0x021DD94C thumb ov171
 */
#include "../include/Obj00142.h"
#include "../include/Obj05441.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct RowBits { u8 pad[0x13]; unsigned char low:6; unsigned char kind:2; };
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void func_021DD94C(int *);
void func_021DDC28(u8 *p)
{
    u8 *row;
    void *s0,*s1,*s2,*s3,*s4,*s5,*s6,*s7;
    u32 width,i;
    row=p+0xc+((struct Obj00142 *)p)->fC5E*0xbc+((struct Obj00142 *)p)->fC5C*0x1c;
    BMP_Clear(func_02045770(((struct Obj00142 *)p)->fB50),0);
    s0=func_02045EC0(((struct Obj00142 *)p)->fB60,5);
    func_0201EE60(((struct Obj00142 *)p)->fB64,0,((struct Obj05441 *)row)->f10);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s0);
    TOUCHBAR_PrintAligned(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),0,0,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    STRBUF_Delete(s0);
    if(((struct RowBits *)row)->kind==0) {
      if(((struct Obj05441 *)row)->f10!=32) {
        s1=func_02045EC0(((struct Obj00142 *)p)->fB60,6);
        TOUCHBAR_PrintAligned(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),64,0,(u32)s1,((struct Obj00142 *)p)->fB58,0xc80,0);
        STRBUF_Delete(s1);
      }
    } else if(((struct RowBits *)row)->kind==1) {
      if(((struct Obj05441 *)row)->f10!=29) {
        s2=func_02045EC0(((struct Obj00142 *)p)->fB60,7);
        TOUCHBAR_PrintAligned(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),64,0,(u32)s2,((struct Obj00142 *)p)->fB58,0x14c0,0);
        STRBUF_Delete(s2);
      }
    }
    s3=func_02045EC0(((struct Obj00142 *)p)->fB60,11);
    width=func_0201D304(s3,((struct Obj00142 *)p)->fB5C,0);
    TOUCHBAR_PrintAligned(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),80,4,(u32)s3,((struct Obj00142 *)p)->fB5C,0x440,0);
    STRBUF_Delete(s3);
    s4=func_02045EC0(((struct Obj00142 *)p)->fB60,8);
    func_0201EFA4(((struct Obj00142 *)p)->fB64,0,row[0x12],3,0,1);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s4);
    TOUCHBAR_PrintAligned(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),width+80,0,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    STRBUF_Delete(s4);
    s5=func_02045EC0(((struct Obj00142 *)p)->fB60,9);
    func_0201EE0C(((struct Obj00142 *)p)->fB64,0,(const void *)(((struct Obj05441 *)row)->f0),0,1,2);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s5);
    TOUCHBAR_PrintAligned(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),0,24,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    STRBUF_Delete(s5);
    s6=func_02045EC0(((struct Obj00142 *)p)->fB60,10);
    func_0201EE0C(((struct Obj00142 *)p)->fB64,0,(const void *)(((struct Obj05441 *)row)->f4),0,1,2);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s6);
    TOUCHBAR_PrintAligned(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),0,48,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    STRBUF_Delete(s6);
    for(i=0;i<4;i++) {
        s7=func_02045EC0(((struct Obj00142 *)p)->fB60,i+12);
        func_0201EF34(((struct Obj00142 *)p)->fB64,0,*(u16 *)(row+i*2+0x14));
        func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s7);
        TOUCHBAR_PrintAligned(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),(i&1)*96,(i>>1)*16+88,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
        STRBUF_Delete(s7);
    }
    func_021DD94C((int *)(p+0xb50));
}

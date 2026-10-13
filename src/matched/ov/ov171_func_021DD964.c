/*
 * function: func_021DD964
 * address: 0x021DD964
 * packet: pkt_ov171_021DD964
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
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045748 0x02045748 arm
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   func_021DD94C 0x021DD94C thumb ov171
 */
#include "../include/Obj00210.h"
#include "../include/Obj24055.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u8 func_02045748(struct Descriptor *p);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void func_021DD94C(int *);
void func_021DD964(u8 *p)
{
    u32 offset;
    u8 *group;
    void *s0,*s1,*s2;
    u32 width;
    offset=((struct Obj00210 *)p)->fC5E*0xbc;
    group=p+0xc;
    BMP_Clear(func_02045770(((struct Obj00210 *)p)->fB48),0);
    if(((struct Obj24055 *)(*(u8 * *)&((struct Obj00210 *)p)->f0))->f4==0) {
        s0=func_02045EC0(((struct Obj00210 *)p)->fB60,0);
        TOUCHBAR_PrintAligned(p+0xb48,(void *)(((struct Obj00210 *)p)->fB6C),0,0,(u32)s0,*(u32 *)&((struct Obj00210 *)p)->fB58,0x440,0);
        STRBUF_Delete(s0);
    } else {
        s1=func_02045EC0(((struct Obj00210 *)p)->fB60,1);
        func_0201EFA4(((struct Obj00210 *)p)->fB64,0,*(u16 *)(group+offset+0xba),4,0,1);
        func_0201F250(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s1);
        TOUCHBAR_PrintAligned(p+0xb48,(void *)(((struct Obj00210 *)p)->fB6C),0,0,*(u32 *)&((struct Obj00210 *)p)->fB68,*(u32 *)&((struct Obj00210 *)p)->fB58,0x440,0);
        STRBUF_Delete(s1);
    }
    s2=func_02045EC0(((struct Obj00210 *)p)->fB60,2);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,0,*(u32 *)(group+offset+0xa8),2,2,1);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,1,*(u32 *)(group+offset+0xac),2,2,1);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,2,*(u32 *)(group+offset+0xb0),2,2,1);
    func_0201F250(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s2);
    width=func_02045748(((struct Obj00210 *)p)->fB48);
    TOUCHBAR_PrintAligned(p+0xb48,(void *)(((struct Obj00210 *)p)->fB6C),width<<3,0,*(u32 *)&((struct Obj00210 *)p)->fB68,*(u32 *)&((struct Obj00210 *)p)->fB58,0x14c0,1);
    STRBUF_Delete(s2);
    func_021DD94C((int *)(p+0xb48));
}

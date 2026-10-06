/*
 * function: func_021BBA10
 * address: 0x021BBA10
 * packet: pkt_ov110_021BBA10
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAC4C 0x021BAC4C thumb ov110
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BF814 0x021BF814 thumb ov110
 *   func_021BC78C 0x021BC78C thumb ov110
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045808 0x02045808 arm
 *   func_02040804 0x02040804 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 *   func_0201C724 0x0201C724 thumb
 */
#include "../include/Obj02460.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned u32;
extern u32 func_021BAC4C(u8 *);
extern u32 func_021BAC44(u8 *);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021BF814(u8 *p, u32 a, int b);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02040804(unsigned);
extern void func_021BC78C(u8 *,int,int,int,int);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(unsigned);
extern void func_02040588(u32 which, unsigned char enable);
void func_021BBA10(u8 *p,unsigned n)
{
    u32 owner,font;
    void *str;
    int i,x,height,base;
    owner=func_021BAC4C(*(u8 * *)&((struct Obj02460 *)p)->f0);
    font=func_021BAC44(*(u8 * *)&((struct Obj02460 *)p)->f0);
    str=func_020457B0(15,42);
    func_02043B5C(func_02045770(((struct Obj02460 *)p)->f98),15);
    ((struct Obj02460 *)p)->f9C=((struct Obj02460 *)p)->f98;
    p[0xa0]=0;
    for(i=0;i<n;i++) {
        if(i%2==0) x=8; else x=128;
        func_021BF814(*(u8 * *)&((struct Obj02460 *)p)->f4,i,(int)str);
        func_0201C724((void *)owner,(u32)func_02045770(((struct Obj02460 *)p)->f9C),(s16)x,(s16)((i/2)*16),(u32)str,font,1103);
        p[0xa0]=1;
    }
    func_02045808(str);
    base=func_02040804(6)+192;
    height=((n+1)/2)*16+8;
    if(height>192) height=192;
    else if(height<48) height=48;
    func_021BC78C(p+0x38,6,1,height-base,8);
    func_02045374(((struct Obj02460 *)p)->f98);
    func_02041B6C(6);
    func_02040588(6,1);
}

/*
 * file:     unit_021B7560_p06.c
 * unit:     yes
 * function: func_021B84B4, func_021B8598, func_021B85A4, func_021B8734, func_021B87E8, func_021B8840
 * address:  0x021B84B4
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02049F34 0x02049F34 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_020061E4 0x020061E4 thumb
 *   d_021B8984 0x021B8984 data a1
 */
#include "../../matched/include/Obj07990.h"
#include "../../matched/include/Obj22250.h"

#define W(off) (*(unsigned *)(p+(off)))
#define H(off) (*(u16 *)(p+(off)))
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32_021B84B4;

typedef unsigned int   u32;

typedef short s16;

typedef signed char s8;

typedef int s32_021B8598;

typedef struct { u8 index[2]; u8 count; } Row;

typedef signed int     s32_021B8734;

extern void func_02082BCC(void *,int,int);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049658(void *,int,int,int,int,int,int);
extern void func_020498F4(void *,int,int,int,int,int,int);
extern void func_02049238(void *);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *,void *,int);
extern u32 func_020307B0(void *p);
extern s32_021B84B4 func_02061CA4(void *p, u32 a, u32 b, s32_021B84B4 size);
extern void func_020061E4(u32 a);
void func_021B84B4(u8 *p,int id,int choice,int heap);
void func_021B8598(void *p);
void func_021B85A4(u8 *p);
void func_021B871C(u8 *p);
unsigned func_021B8730(u8 *p);
void func_021B8734(u16 *p,int n,u8 div,u8 offset,u8 index,u16 a,u16 b);
int func_021B87E8(unsigned a, int *p);
unsigned int func_021B8840(unsigned int x,int y);
extern const Row d_021B8984[];

void func_021B84B4(u8 *p,int id,int choice,int heap)
{
    void *archive, *data, *raw;
    u8 *pal;
    int i;
    func_02082BCC(p,0,0x60);
    ((struct Obj07990 *)p)->f0=id;
    ((struct Obj07990 *)p)->f54=func_021B87E8(choice,(int *)(p+0x5c));
    if (((struct Obj07990 *)p)->f5C) ++((struct Obj07990 *)p)->f54;
    archive=func_020490F4(0x5e,heap);
    func_02049658(archive,15,3,0,0,0,heap);
    func_020498F4(archive,17,3,0,0,0,heap);
    func_02049238(archive);
    data=func_02049F34(0x5e,16,(u32)(&raw),heap);
    pal=*(u8 * *)&((struct Obj22250 *)raw)->fC;
    func_02082D44(pal,p+8,32);
    func_02082D44(pal+0x100,p+8,32);
    func_020307B0(data);
    func_02082D44(p+8,p+0x28,32);
    for(i=0;i<13;++i) *(u16 *)(p+0x28+i*2)=0x7fff;
    for(i=0;i<16;++i) func_02061CA4((void *)15,0x100+i*2,(u32)(p+0x28+i*2),2);
}

void func_021B8598(void *p) { func_02082BCC(p, 0, 0x60); }

/*
 * extent: 376-byte lead,20-byte reset871C,4-byte getter8730; no tail data.
 * lever: 3-byte table rows unify index array and count field relocations.
 */
void func_021B85A4(u8 *p)
{
    int i;
    if (!W(0x50)) return;
    switch(W(0x58)) {
    case 0:
        if(H(0x56)>H(0x54)) {
            if(W(0x5c)) W(0x58)=1;
            else { W(0x4c)=1; W(0x50)=0; }
            return;
        }
        if(!W(0x48)) func_020061E4(2000+H(0x56));
        for(i=0;i<d_021B8984[H(0x56)].count;++i) {
            int index=d_021B8984[H(0x56)].index[i];
            func_021B8734((u16 *)(p+0x28)+index,(u16)W(0x48),40,8,index,0x7fff,((u16 *)(p+8))[index]);
        }
        if(W(0x48)++>=40) { W(0x48)=0; ++H(0x56); }
        break;
    case 1:
        if(W(0x48)++>=60) { W(0x48)=0; W(0x58)=2; }
        break;
    case 2:
        if(!W(0x48)) func_020061E4(1998+H(0x56));
        for(i=0;i<d_021B8984[H(0x56)-1].count;++i) {
            int index=d_021B8984[H(0x56)-1].index[i];
            func_021B8734((u16 *)(p+0x28)+index,(u16)W(0x48),40,8,index,((u16 *)(p+8))[index],0x7fff);
        }
        if(W(0x48)++>=40) { W(0x48)=0; W(0x4c)=1; W(0x50)=0; }
        break;
    }
}

void func_021B871C(u8 *p)
{
    W(0x50)=1; W(0x4c)=0; H(0x56)=1; W(0x58)=0; W(0x48)=0;
}

unsigned func_021B8730(u8 *p)
{
    return W(0x4c);
}

/*
 * extent: two-byte zero padding before func_021B87E8
 * lever: u8 div and offset pin their home stores to the prologue
 */
void func_021B8734(u16 *p,int n,u8 div,u8 offset,u8 index,u16 a,u16 b)
{
 u8 r,g,blue; int dr,dg,db;
 g=(a&0x3E0)>>5;
 r=a&31;
 blue=(a&0x7C00)>>10;
 db=((u8)((b&0x7C00)>>10)-blue)*n/div;
 dr=((u8)(b&31)-r)*n/div;
 dg=((u8)((b&0x3E0)>>5)-g)*n/div;
 *p=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
 func_02061CA4((void *)15,offset*32+index*2,(u32)p,2);
}

int func_021B87E8(unsigned a, int *p)
{
    int limit, result;
    if (a == 100) { limit = 65535; result = 5; }
    else if (a >= 80) { limit = 100; result = 4; }
    else if (a >= 60) { limit = 80; result = 3; }
    else if (a >= 30) { limit = 60; result = 2; }
    else if (a > 0) { limit = 30; result = 1; }
    else if (a == 0) { limit = 0; result = 0; }
    else { limit = 100; result = 1; }
    if (p) *p = (int)(a + 3) > limit ? 1 : 0;
    return result;
}

unsigned int func_021B8840(unsigned int x,int y) { unsigned int v; if(y) v=2; else v=1; if(x==100) return v*3; if(x>79) v*=2; return v; }

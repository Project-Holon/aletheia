/*
 * file:     unit_021C8DA0_p06.c
 * unit:     yes
 * function: func_021C9EF0, func_021C9EF4, func_021C9EFC, func_021C9F30, func_021C9F6C, func_021C9F8C, func_021C9FC8, func_021CA014, func_021CA084, func_021CA0BC, func_021CA10C, func_021CA124, func_021CA154, func_021CA16C, func_021CA184, func_021CA19C, func_021CA1E0, func_021CA25C, func_021CA294, func_021CA2AC, func_021CA2C4, func_021CA2DC, func_021CA320, func_021CA3A0, func_021CA3C4, func_021CA3E8, func_021CA40C, func_021CA42C, func_021CA444, func_021CA458, func_021CA478, func_021CA4B4
 * address:  0x021C9EF0
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041300 0x02041300 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_02045A98 0x02045A98 arm
 *   func_02045A90 0x02045A90 arm
 *   _ull_mul 0x0209C054 arm
 *   func_02035C60 0x02035C60 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0202E940 0x0202E940 thumb
 *   func_0202E9AC 0x0202E9AC thumb
 *   func_0202EA20  0x0202EA20  thumb
 *   func_020413B0 0x020413B0 arm
 *   func_0202EB04  0x0202EB04  thumb
 *   func_020355C4 0x020355C4 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0207D658 0x0207D658 arm
 *   func_02045374  0x02045374  arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
#include "../../matched/include/Obj10496.h"
#include "../../matched/include/Obj14048.h"
#include "../../matched/include/Obj00329.h"
#include "../../matched/include/Obj03812.h"
#include "../../matched/include/Obj00725.h"
#include "../../matched/include/Obj00774.h"
#include "../../matched/include/Obj14051.h"
#include "../../matched/include/Obj23113.h"
#include "../../matched/include/Obj00775.h"
#include "../../matched/include/Obj03813.h"
#include "../../matched/include/Obj00179.h"
#include "../../matched/include/Obj14052.h"
#include "../../matched/include/Obj06477.h"
#include "../../matched/include/Obj08135.h"

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
struct U16Vec;
struct CodeIn;
struct Obj0202EA20;
struct Obj;
struct Cfg;
struct PrintSys;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef struct {u16 x,y,z,pad;u32 value;void *items[8];volatile u32 count[8];} Record;

typedef signed short s16;

typedef unsigned long long u64;

typedef signed int     s32;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_02041300(u32,int,u8,u8,u8,u8,u8);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern u16 func_02045A98(void);
extern u16 *func_02045A90(struct U16Vec *vec);
extern int func_02035C60(void);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_0202EB04(struct CodeIn *p);
extern u8 func_020355C4(void);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0207D658(u32,int,int);
extern void func_02045374(struct Cfg *cfg);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
void func_021C9EF0(void *a0);
void func_021C9EF4(u32 p,int unused,u32 index,u32 value,u32 unused5,u16 heap);
void func_021C9EFC(Record *p,u32 index);
void func_021C9F30(char *p,u32 index);
void func_021C9F6C(char *p,void *q);
void func_021C9F8C(void *q,char *p);
void func_021C9FC8(u8 *p,void *unused,u8 *q,u32 item,int x,int y,int color);
u64 func_021CA014(void *p,int *ok);
int func_021CA084(int *p);
void func_021CA0BC(u8 *p,u16 heap);
void func_021CA10C(u8 *p);
void func_021CA124(u32 a,u32 b);
void func_021CA154(u8 *p, int a);
void func_021CA16C(u8 *p, int a);
void func_021CA184(u8 *p, int a, int b);
void func_021CA19C(unsigned *p);
int func_021CA1E0(char *p);
void func_021CA25C(u32 a,u32 b);
void func_021CA294(u8 *p, int a);
void func_021CA2AC(u8 *p, int a);
void func_021CA2C4(u8 *p, int a, int b);
void func_021CA2DC(char *p);
int func_021CA320(char *p);
void func_021CA3A0(char *p);
void func_021CA3C4(char *p);
void func_021CA3E8(int a);
void func_021CA40C(char *p, int n);
void func_021CA42C(char *p);
void func_021CA444(char *p);
void func_021CA458(char *p,void *q);
void func_021CA478(char *p);
void func_021CA4B4(char *p);

void func_021C9EF0(void *a0) {}

void func_021C9EF4(u32 p,int unused,u32 index,u32 value,u32 unused5,u16 heap) { *(u32 *)(p+44+index*4)=value; }

/*
 * volatile: 021C9F1E rereads loop bound field, also entry021C9F0E.
 */
void func_021C9EFC(Record *p,u32 index) {u8 i;if(p->items[index]){for(i=0;i<p->count[index];i++) {} p->items[index]=0;p->count[index]=0;}}

void func_021C9F30(char *p,u32 index) {u32 i;void *q;char *base;base=p+index*4;for(i=0;i<((struct Obj10496 *)base)->f2C;i++){func_02043B5C(func_02045770(**(void ** *)&((struct Obj10496 *)base)->fC),0);q=**(void ** *)&((struct Obj10496 *)base)->fC;func_020456F8(q);func_02041B6C(func_02045730(q));}}

void func_021C9F6C(char *p,void *q) { int i; for(i=0;i<8;i++)func_021C9F30(p,i);func_021C9F8C(q,p); }

static inline int ab(int x) { return x<0?-x:x; }

void func_021C9F8C(void *q,char *p) { func_02041300(3,0,ab(((struct Obj14048 *)p)->f0),ab(((struct Obj14048 *)p)->f2),32,24,0);func_02041B6C(3); }

void func_021C9FC8(u8 *p,void *unused,u8 *q,u32 item,int x,int y,int color)
{
    func_02045CAC(((struct Obj00329 *)q)->f4,item,((struct Obj00329 *)q)->f20);
    func_0201F250(((struct Obj00329 *)q)->f0,(void *)(((struct Obj00329 *)q)->f1C),((struct Obj00329 *)q)->f20);
    func_021B6AE4(p,(void *)(*(u32 *)&((struct Obj00329 *)q)->f34),x,y,((struct Obj00329 *)q)->f1C,*(u32 *)&((struct Obj00329 *)q)->f17C,color,0);
}

/*
 * lever: initialize value before *ok; multiply and add the u64 digit separately;
 *        cast the u16 counter to int for its bound, and share failure via done.
 */
u64 func_021CA014(void *p,int *ok)
{
    u16 end=func_02045A98();
    u16 *text=func_02045A90(p);
    u64 value;
    u16 i;
    u16 digit;
    value=0;
    *ok=0;
    i=0;
    while(text[i]!=end) {
        if((int)i>=18) goto done;
        digit=(u16)(text[i]-0x30);
        if(digit>=10) {
            digit=(u16)(text[i]-0xff10);
            if(digit>=10) goto done;
        }
        value*=10;
        value+=(u64)digit;
        i++;
    }
    *ok=1;
done:
    return value;
}

/*
 * extent: two trailing bytes of zero alignment padding.
 */
int func_021CA084(int *p) { if(func_02035C60()==1) {func_020355D8(1);*p=1;return 1;} if(func_020362DC()&3) {func_020355D8(0);*p=0;return 1;} return 0; }

void func_021CA0BC(u8 *p,u16 heap)
{
    ((struct Obj03812 *)p)->f184=func_0202E940(48,16,0,heap);
    func_0202E9AC(((struct Obj03812 *)p)->f184,*(u8 * *)&((struct Obj03812 *)p)->f8,0,32,48);
    ((struct Obj03812 *)p)->f188=func_0202E940(16,16,0xfffe,heap);
    func_0202E9AC(((struct Obj03812 *)p)->f188,*(u8 * *)&((struct Obj03812 *)p)->f8,2,0,16);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021CA10C(u8 *p)
{
    func_0202EA20(((struct Obj00725 *)p)->f188);
    func_0202EA20(((struct Obj00725 *)p)->f184);
}

void func_021CA124(u32 a,u32 b) {func_020413B0(2,2,(a+1)*5,28,4,b);func_02041B6C(2);}


void func_021CA154(u8 *p, int a)
{
    func_021CA124(a, 1);
    func_0202EB04(((struct Obj00329 *)p)->f184);
}


void func_021CA16C(u8 *p, int a)
{
    func_021CA124(a, 3);
    func_0202EB04(((struct Obj00329 *)p)->f184);
}


void func_021CA184(u8 *p, int a, int b)
{
    func_021CA154(p, b);
    func_021CA16C(p, a);
}

/*
 * extent: two-byte zero padding at 021CA1DE; next labelled function 021CA1E0.
 */
void func_021CA19C(unsigned *p)
{
    unsigned i;
    if(func_020355C4()==1) {
        for(i=0;i<3;i++) func_021CA124(i,1);
        return;
    }
    for(i=0;i<3;i++) {
        if(i==*p) func_021CA124(i,3);
        else func_021CA124(i,1);
    }
}

/*
 * Extent ends with two bytes of zero alignment padding.
 */
int func_021CA1E0(char *p)  {
    switch(((struct Obj00774 *)p)->f8)  {
        case 0: func_021CA124((u32)(((struct Obj00774 *)p)->f0),1);
        ((struct Obj00774 *)p)->fA=0;
        (((struct Obj00774 *)p)->f8)++;
        break;
        case 1: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            func_021CA124((u32)(((struct Obj00774 *)p)->f0),2);
            ((struct Obj00774 *)p)->fA=0;
            (((struct Obj00774 *)p)->f8)++;
        }
        break;
        case 2: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            func_021CA124((u32)(((struct Obj00774 *)p)->f0),1);
            ((struct Obj00774 *)p)->fA=0;
            (((struct Obj00774 *)p)->f8)++;
        }
        break;
        case 3: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            func_021CA124((u32)(((struct Obj00774 *)p)->f0),2);
            ((struct Obj00774 *)p)->fA=0;
            (((struct Obj00774 *)p)->f8)++;
        }
        break;
        case 4: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            ((struct Obj00774 *)p)->f8=0;
            ((struct Obj00774 *)p)->fA=0;
            return 0;
        }
        break;
    }
    return 1;
}

void func_021CA25C(u32 a,u32 b) {func_020413B0(2,(a>>2)*14+2,(a&3)*4+4,14,4,b);func_02041B6C(2);}


void func_021CA294(u8 *p, int a)
{
    func_021CA25C(a, 1);
    func_0202EB04(((struct Obj14051 *)p)->f184);
}


void func_021CA2AC(u8 *p, int a)
{
    func_021CA25C(a, 3);
    func_0202EB04(((struct Obj14051 *)p)->f184);
}


void func_021CA2C4(u8 *p, int a, int b)
{
    func_021CA294(p, b);
    func_021CA2AC(p, a);
}

void func_021CA2DC(char *p)  {
    unsigned i;
    if(func_020355C4()==1)  {
        for(i=0;i<8;i++) func_021CA25C(i,1);
    }
    else  {
        for(i=0;i<8;i++)  {
            if(i==((struct Obj23113 *)p)->f4) func_021CA25C(i,3);
            else func_021CA25C(i,1);
        }
    }
}

int func_021CA320(char *p)  {
    switch(((struct Obj00775 *)p)->f8)  {
        case 0: func_021CA25C(((struct Obj00775 *)p)->f4,1);
        ((struct Obj00775 *)p)->fA=0;
        (((struct Obj00775 *)p)->f8)++;
        break;
        case 1: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            func_021CA25C(((struct Obj00775 *)p)->f4,2);
            ((struct Obj00775 *)p)->fA=0;
            (((struct Obj00775 *)p)->f8)++;
        }
        break;
        case 2: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            func_021CA25C(((struct Obj00775 *)p)->f4,1);
            ((struct Obj00775 *)p)->fA=0;
            (((struct Obj00775 *)p)->f8)++;
        }
        break;
        case 3: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            func_021CA25C(((struct Obj00775 *)p)->f4,2);
            ((struct Obj00775 *)p)->fA=0;
            (((struct Obj00775 *)p)->f8)++;
        }
        break;
        case 4: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            ((struct Obj00775 *)p)->f8=0;
            ((struct Obj00775 *)p)->fA=0;
            return 0;
        }
        break;
    }
    return 1;
}

void func_021CA3A0(char *p) {func_0204B8C4(((struct Obj03813 *)p)->f164,0);func_0204B878(((struct Obj03813 *)p)->f164,9);func_0204B92C(((struct Obj03813 *)p)->f164,1);}

void func_021CA3C4(char *p) {func_0204B8C4(((struct Obj03813 *)p)->f168,0);func_0204B878(((struct Obj03813 *)p)->f168,8);func_0204B92C(((struct Obj03813 *)p)->f168,1);}

void func_021CA3E8(int a) {if(a==1)func_0207D658(0x04000050,28,0);else func_0207D658(0x04000050,28,-8);}

void func_021CA40C(char *p, int n) {func_0204B8C4(((struct Obj00179 *)p)->f1A4,0);func_0204B878(((struct Obj00179 *)p)->f1A4,n+2);}


void func_021CA42C(char *p)
{
    func_02045374(((struct Obj14052 *)p)->fC);
    func_02041B6C(func_02045730(((struct Obj14052 *)p)->fC));
}

void func_021CA444(char *p)
{
    unsigned int i;

    for (i = 0; i < 0x40; i++)
        *(unsigned int *)(p + i * 4 + 0x38) = 0;
}


void func_021CA458(char *p,void *q) {u32 i;for(i=0;i<64;i++) {if(!*(void **)(p+i*4+56)) {*(void **)(p+i*4+56)=q;return;}}}

void func_021CA478(char *p) {u32 i;char *q;void *v;for(i=0;i<64;i++){q=*(char **)(p+i*4+56);if(!q)break;v=((struct Obj06477 *)p)->f34;if(((struct Obj08135 *)q)->f4) {if(!func_0201C6C4(v,func_02045770(((struct Obj08135 *)q)->f0))) {func_02045334(((struct Obj08135 *)q)->f0);((struct Obj08135 *)q)->f4=0;}}}}


void func_021CA4B4(char *p)
{
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
}

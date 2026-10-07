/*
 * file:     unit_021DC860_p02.c
 * unit:     yes
 * function: func_021DD5D4, func_021DD620, func_021DD774, func_021DD874, func_021DD8BC, func_021DD8DC, func_021DD94C, func_021DD964, func_021DDAF0, func_021DDC28, func_021DDFBC, func_021DDFE8, func_021DE014, func_021DE030, func_021DE064, func_021DE080, func_021DE0AC, func_021DE0C0, func_021DE0E4
 * address:  0x021DD5D4
 * region:   ov171
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   d_021DEB56 0x021DEB56 data
 *   func_021DE5F4 0x021DE5F4 thumb ov171
 *   func_021DE608 0x021DE608 thumb ov171
 *   func_021DE684 0x021DE684 thumb ov171
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045748 0x02045748 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_0201EE60 0x0201EE60 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_021DE114 0x021DE114 thumb ov171
 *   func_021DE144 0x021DE144 thumb ov171
 *   func_021DE2D4 0x021DE2D4 thumb ov171
 *   func_021DE80C 0x021DE80C thumb ov171
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_021DE884  0x021DE884  thumb  ov171
 *   func_021DE368  0x021DE368  thumb  ov171
 *   func_021DE258  0x021DE258  thumb  ov171
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204B944 0x0204B944 arm
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B454  0x0204B454  arm
 */
#include "../../matched/include/Obj14289.h"
#include "../../matched/include/Obj00347.h"
#include "../../matched/include/Obj00142.h"
#include "../../matched/include/Obj03850.h"
#include "../../matched/include/Obj08249.h"
#include "../../matched/include/Obj14290.h"
#include "../../matched/include/Obj14291.h"
#include "../../matched/include/Obj00210.h"
#include "../../matched/include/Obj24055.h"
#include "../../matched/include/Obj05441.h"
#include "../../matched/include/Obj08250.h"
#include "../../matched/include/Obj10660.h"

struct Descriptor;
struct PrintSys;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Obj;
struct StrObj;
struct Actor;
struct PtS;
typedef signed char s8;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef struct { char pad[0xb10]; s16 previous; char gap[10]; s16 current; } Angle;

typedef unsigned int   u32;

struct RowBits { u8 pad[0x13]; unsigned char low:6; unsigned char kind:2; };

typedef struct Vec2 {s16 x,y;} Vec2;

extern int _s32_div_f(int, int);
extern int func_021DE5F4(char *);
extern void func_021DE608(char *,int,int);
extern void func_021DE684(u8 *p);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u8 func_02045748(struct Descriptor *p);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void func_020257D0(struct Obj *o);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_020456F8(struct Descriptor *);
extern void func_021DE114(u8 *);
extern void func_021DE144(char *);
extern void func_021DE2D4(char *);
extern void func_021DE80C(char *);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern void func_021DE884(int *);
extern void func_021DE368(char *p);
extern void func_021DE258(char *p);
extern void func_0204A5AC(void);
extern u32 func_0204B944(struct Obj *);
extern void func_0204B8D4(struct Obj *,u32);
extern void func_0204A600(void);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B8C4(struct Obj *,u32);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B92C(struct Obj *,u32);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
u8 func_021DD5D4(char *p, s8 i, int target, s8 step);
void func_021DD620(char *p, int step);
int func_021DD774(char *p);
void func_021DD874(char *p);
void func_021DD8BC(int *p);
void func_021DD8DC(char *p);
void func_021DD94C(int *p);
void func_021DD964(u8 *p);
void func_021DDAF0(u8 *p);
void func_021DDC28(u8 *p);
void func_021DDFBC(u8 *p);
void func_021DDFE8(u8 *p);
void func_021DE014(int *p);
void func_021DE030(u8 *p);
void func_021DE064(int *p, int i, int a);
void func_021DE080(u8 *p, int i, int value);
int func_021DE0AC(int *p, int i);
void func_021DE0C0(u8 *p, int i, int x, int y);
void func_021DE0E4(u8 *obj, int i, s16 *out1, s16 *out2);
extern const u8 d_021DEB56[];

/*
 * lever: signed byte step avoids an extra entry truncation.
 */
u8 func_021DD5D4(char *p, s8 i, int target, s8 step)
{
    u8 count;
    count = 1;
    do {
        i += step;
        if (i < 0)
            i = *(u16 *)(p + ((struct Obj14289 *)p)->fC5E * 0xbc + 0xc4) - 1;
        else if (i >= *(u16 *)(p + ((struct Obj14289 *)p)->fC5E * 0xbc + 0xc4))
            i = 0;
        if (i == target)
            break;
        count++;
    } while (count < 6);
    return count;
}


/*
 * lever: A u16 count preserves the word spill at sp+0; bind the final quotient
 *   before multiplying. Explicit runtime calls preserve the zero divisor path.
 */
void func_021DD620(char *p, int step) {
    s16 dst = ((struct Obj00347 *)p)->fC5C;
    s16 src = dst + step;
    unsigned i;
    int angle;
    u16 count;
    if (src < 0) {
        count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
        src += (s16)count;
    } else {
        count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
        if (src >= count) src -= (s16)count;
    }
    for (i = 0; i < (unsigned)count; i++) {
        *(s16 *)(p + dst * 2 + 0xb1c) = *(s16 *)(p + src * 2 + 0xb10);
        *(u8 *)(p + dst + 0xb40) = *(u8 *)(p + src + 0xb34);
        dst += (s16)_s32_div_f(step, step < 0 ? -step : step);
        if (dst < 0) {
            count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
            dst = count - 1;
        } else {
            count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
            if (dst >= count) dst = 0;
        }
        src += (s16)_s32_div_f(step, step < 0 ? -step : step);
        if (src < 0) src = count - 1;
        else if (src >= count) src = 0;
    }
    angle = ((struct Obj00347 *)p)->fC61;
    if (angle < 0) angle = -angle;
    if (step < 0) step = -step;
    angle = _s32_div_f(d_021DEB56[count - 1], angle);
    ((struct Obj00347 *)p)->fC62 = angle * step;
}

/*
 * lever: Access the far halfwords as struct members; cache only the guard value, and retain field updates and reads.
 */
int func_021DD774(char *p) {
    int base;
    unsigned i;
    Angle *a;
    int angle;
    base=func_021DE5F4(p);
    if (((struct Obj00142 *)p)->fC62==0) {
        for(i=0;i<*(u16 *)(p+((struct Obj00142 *)p)->fC5E*0xbc+0xc4);i++) {
            a=(Angle *)(p+i*2);
            a->previous=a->current;
            func_021DE608(p,base+i,a->previous);
        }
        func_021DE684((u8 *)p);
        return 0;
    } else {
        for(i=0;i<*(u16 *)(p+((struct Obj00142 *)p)->fC5E*0xbc+0xc4);i++) {
            a=(Angle *)(p+i*2);
            a->previous+=((struct Obj00142 *)p)->fC61;
            angle=a->previous;
            if (angle<0) a->previous+=360;
            else if (angle>=360) a->previous-=360;
            func_021DE608(p,base+i,a->previous);
        }
        func_021DE684((u8 *)p);
        (((struct Obj00142 *)p)->fC62)--;
        return 1;
    }
}

/*
 * lever: the first creation call passes 3 in r0, shared with its stack argument.
 */
void func_021DD874(char *p)
{
    func_02045088(0x8c);
    ((struct Obj03850 *)p)->fB48 = func_020450F0(3, 1, 0, 30, 2, 3, 1);
    ((struct Obj03850 *)p)->fB50 = func_020450F0(5, 4, 7, 24, 15, 1, 1);
}

void func_021DD8BC(int *p)
{
    func_020452E8(*(struct Descriptor * *)&((struct Obj08249 *)p)->fB48);
    func_020452E8(*(struct Descriptor * *)&((struct Obj08249 *)p)->fB50);
    func_020450C8();
}

/*
 * lever: offset locals carry both their initial and replacement constants.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`a = 0xb6c;` before `a = 0xb48;`; `b = 0xb6c;` before `b = 0xb4c;` and 2
 * more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT in --lang c99 and --lang c: the output bytes
 * do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021DD8DC(char *p)
{
    int a, b, c, d;
    unsigned i;
    int obj;
    char *q;
    func_0201C4E4((struct PrintSys *)(((struct Obj14290 *)p)->fB6C));
    a = 0xb48;
    b = 0xb4c;
    c = 0xb48;
    d = 0xb4c;
    for (i = 0; i < 2; ++i) {
        obj = ((struct Obj14290 *)p)->fB6C;
        q = p + i * 8;
        if (*(unsigned char *)(q + d)) {
            if (!func_0201C6C4((struct PrintSys *)obj, (void *)((int)func_02045770((struct Descriptor *)*(int *)(q + c))))) {
                func_02045334((struct Descriptor *)*(int *)(q + a));
                *(unsigned char *)(q + b) = 0;
            }
        }
    }
}


void func_021DD94C(int *p)
{
    func_02045374((struct Cfg *)(((struct Obj14291 *)p)->f0));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj14291 *)p)->f0)));
}

void func_021DD964(u8 *p)
{
    u32 offset;
    u8 *group;
    void *s0,*s1,*s2;
    u32 width;
    offset=((struct Obj00210 *)p)->fC5E*0xbc;
    group=p+0xc;
    func_02043B5C(func_02045770(((struct Obj00210 *)p)->fB48),0);
    if(((struct Obj24055 *)(*(u8 * *)&((struct Obj00210 *)p)->f0))->f4==0) {
        s0=func_02045EC0(((struct Obj00210 *)p)->fB60,0);
        func_021B6AE4(p+0xb48,(void *)(((struct Obj00210 *)p)->fB6C),0,0,(u32)s0,*(u32 *)&((struct Obj00210 *)p)->fB58,0x440,0);
        func_02045808(s0);
    } else {
        s1=func_02045EC0(((struct Obj00210 *)p)->fB60,1);
        func_0201EFA4(((struct Obj00210 *)p)->fB64,0,*(u16 *)(group+offset+0xba),4,0,1);
        func_0201F250(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s1);
        func_021B6AE4(p+0xb48,(void *)(((struct Obj00210 *)p)->fB6C),0,0,*(u32 *)&((struct Obj00210 *)p)->fB68,*(u32 *)&((struct Obj00210 *)p)->fB58,0x440,0);
        func_02045808(s1);
    }
    s2=func_02045EC0(((struct Obj00210 *)p)->fB60,2);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,0,*(u32 *)(group+offset+0xa8),2,2,1);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,1,*(u32 *)(group+offset+0xac),2,2,1);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,2,*(u32 *)(group+offset+0xb0),2,2,1);
    func_0201F250(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s2);
    width=func_02045748(((struct Obj00210 *)p)->fB48);
    func_021B6AE4(p+0xb48,(void *)(((struct Obj00210 *)p)->fB6C),width<<3,0,*(u32 *)&((struct Obj00210 *)p)->fB68,*(u32 *)&((struct Obj00210 *)p)->fB58,0x14c0,1);
    func_02045808(s2);
    func_021DD94C((int *)(p+0xb48));
}

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

void func_021DDC28(u8 *p)
{
    u8 *row;
    void *s0,*s1,*s2,*s3,*s4,*s5,*s6,*s7;
    u32 width,i;
    row=p+0xc+((struct Obj00142 *)p)->fC5E*0xbc+((struct Obj00142 *)p)->fC5C*0x1c;
    func_02043B5C(func_02045770(((struct Obj00142 *)p)->fB50),0);
    s0=func_02045EC0(((struct Obj00142 *)p)->fB60,5);
    func_0201EE60(((struct Obj00142 *)p)->fB64,0,((struct Obj05441 *)row)->f10);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s0);
    func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),0,0,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    func_02045808(s0);
    if(((struct RowBits *)row)->kind==0) {
      if(((struct Obj05441 *)row)->f10!=32) {
        s1=func_02045EC0(((struct Obj00142 *)p)->fB60,6);
        func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),64,0,(u32)s1,((struct Obj00142 *)p)->fB58,0xc80,0);
        func_02045808(s1);
      }
    } else if(((struct RowBits *)row)->kind==1) {
      if(((struct Obj05441 *)row)->f10!=29) {
        s2=func_02045EC0(((struct Obj00142 *)p)->fB60,7);
        func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),64,0,(u32)s2,((struct Obj00142 *)p)->fB58,0x14c0,0);
        func_02045808(s2);
      }
    }
    s3=func_02045EC0(((struct Obj00142 *)p)->fB60,11);
    width=func_0201D304(s3,((struct Obj00142 *)p)->fB5C,0);
    func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),80,4,(u32)s3,((struct Obj00142 *)p)->fB5C,0x440,0);
    func_02045808(s3);
    s4=func_02045EC0(((struct Obj00142 *)p)->fB60,8);
    func_0201EFA4(((struct Obj00142 *)p)->fB64,0,row[0x12],3,0,1);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s4);
    func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),width+80,0,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    func_02045808(s4);
    s5=func_02045EC0(((struct Obj00142 *)p)->fB60,9);
    func_0201EE0C(((struct Obj00142 *)p)->fB64,0,(const void *)(((struct Obj05441 *)row)->f0),0,1,2);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s5);
    func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),0,24,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    func_02045808(s5);
    s6=func_02045EC0(((struct Obj00142 *)p)->fB60,10);
    func_0201EE0C(((struct Obj00142 *)p)->fB64,0,(const void *)(((struct Obj05441 *)row)->f4),0,1,2);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s6);
    func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),0,48,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    func_02045808(s6);
    for(i=0;i<4;i++) {
        s7=func_02045EC0(((struct Obj00142 *)p)->fB60,i+12);
        func_0201EF34(((struct Obj00142 *)p)->fB64,0,*(u16 *)(row+i*2+0x14));
        func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s7);
        func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),(i&1)*96,(i>>1)*16+88,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
        func_02045808(s7);
    }
    func_021DD94C((int *)(p+0xb50));
}

void func_021DDFBC(u8 *p)
{
    func_020456F8(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50);
    func_02041B6C(func_02045730(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50));
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50),0);
    func_02045334(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50);
}

void func_021DDFE8(u8 *p)
{
    func_021DE114(p);
    func_021DE144((char *)p);
    func_021DE2D4((char *)p);
    func_021DE80C((char *)p);
    func_020434DC(16,1);
    func_02043598(16,1);
}


void func_021DE014(int *p)
{
    func_021DE884(p);
    func_021DE368((char *)p);
    func_021DE258((char *)p);
    func_0204A5AC();
}

void func_021DE030(u8 *p)
{
    unsigned i;
    u8 *element;
    for(i=0;i<16;i++) {
        element=p+i*4;
        if(((struct Obj10660 *)element)->fB74!=0 && func_0204B944(*(struct Obj * *)&((struct Obj10660 *)element)->fB74)!=1)
            func_0204B8D4(*(struct Obj * *)&((struct Obj10660 *)element)->fB74,4096);
    }
    func_0204A600();
}


void func_021DE064(int *p, int i, int a)
{
    int v = *(int *)((char *)p + i * 4 + 0xB74);

    if (v)
        func_0204B3DC((struct Obj *)v, a);
}

void func_021DE080(u8 *p, int i, int value)
{
    struct Obj **base=(struct Obj **)(p+0xb74);
    func_0204B8C4(*(struct Obj **)((u32)base+i*4),0);
    func_0204B878(*(struct Obj **)((u32)base+i*4),value);
    func_0204B92C(*(struct Obj **)((u32)base+i*4),1);
}


int func_021DE0AC(int *p, int i)
{
    return func_0204B98C((struct Actor *)(*(int *)((char *)p + i * 4 + 0xB74)));
}

void func_021DE0C0(u8 *p, int i, int x, int y)
{
    Vec2 pos;
    pos.x=x; pos.y=y;
    func_0204B404(*(struct Obj **)((u32)p+i*4+0xb74), &pos,0);
}


/*
 * Recursive MATCH unblocker: unresolved dep named by the parked func_021DE960
 * (func_021DE0E4(obj, i, &win[1], &win[0])).  Reads the 0xb74-indexed word and
 * expands it through the arm9 helper at 0x0204B454 into the two signed shorts.
 *
 * Addresses are Black-image addresses.
 */
void func_021DE0E4(u8 *obj, int i, s16 *out1, s16 *out2)
{
    int v = *(int *)(obj + i * 4 + 0xb74);
    s16 tmp[2];

    func_0204B454((struct Actor *)v, (struct PtS *)tmp, 0);
    *out1 = tmp[0];
    *out2 = tmp[1];
}

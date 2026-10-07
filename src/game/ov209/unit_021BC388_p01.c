/*
 * file:     unit_021BC388_p01.c
 * unit:     yes
 * function: func_021BC388, func_021BC52C, func_021BC574, func_021BC6C4, func_021BC704, func_021BC730, func_021BC7B8, func_021BC7D0, func_021BC810, func_021BC824, func_021BC868, func_021BC88C, func_021BC8A4, func_021BC8B4, func_021BC90C, func_021BC91C, func_021BC9A8, func_021BCB60, func_021BCB90
 * address:  0x021BC388
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   data_021BE804 0x021BE804 data a4
 *   data_021BE894 0x021BE894 data a4
 *   data_021BE874 0x021BE874 data a4
 *   data_021BE814 0x021BE814 data a4
 *   data_021BE8F4 0x021BE8F4 data a4
 *   data_021BE8B4 0x021BE8B4 data a4
 *   data_021BE854 0x021BE854 data a4
 *   data_021BE8D4 0x021BE8D4 data a4
 *   data_021BE834 0x021BE834 data a4
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027628 0x02027628 thumb
 *   func_02027624 0x02027624 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02049740 0x02049740 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_020056BC 0x020056BC thumb
 *   func_0202173C 0x0202173C thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201AF80 0x0201AF80 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BD958 0x021BD958 thumb ov209
 *   func_021BD934 0x021BD934 thumb ov209
 *   func_0200CA8C 0x0200CA8C thumb
 *   func_021B7754 0x021B7754 thumb ov067
 *   func_021B7A10 0x021B7A10 thumb ov067
 *   func_021B7A4C 0x021B7A4C thumb ov067
 *   func_021B79E4 0x021B79E4 thumb ov067
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200D064 0x0200D064 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045874 0x02045874 arm
 *   data_021BE7AC 0x021BE7AC data a4
 *   data_020A7370 0x020A7370 data a4
 *   func_021B796C 0x021B796C thumb ov067
 *   func_021B9398 0x021B9398 thumb ov067
 *   func_021BD75C 0x021BD75C thumb ov209
 *   func_021BE29C 0x021BE29C thumb ov209
 */
#include "../../matched/include/Obj00123.h"
#include "../../matched/include/Obj00088.h"
#include "../../matched/include/Obj02924.h"

struct DispConfig;
struct PalAnmSlot;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
struct Rec;
struct Blk37;
struct S;
struct Tmpl;
typedef unsigned int u32;

typedef unsigned short u16;

struct Display {u32 w[4];};

struct BgTemplate {u32 w[8];};

typedef unsigned char  u8;

typedef signed char s8;

typedef signed short s16_021BC810;

typedef signed int s32;

typedef short s16_021BC8B4;

typedef short s16_021BC91C;

struct Template {u8 head[20];u16 count,pad16;u8 index,pad19;u16 start;u32 p1c,p20;void *p24;};

struct Inputs {u32 p0;void *save;u16 pad8,count;u16 *ids;};

struct Context {struct Inputs *in;u8 pad4[0xc2c-4];void *list;u32 padc30;u32 visible;};

extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041B6C(u32);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern u32 func_020275E4(void);
extern u32 func_02027628(void);
extern u32 func_02027624(void);
extern u32 func_0202762C(void);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void *func_02021518(u32);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020215A0(struct PalAnmSlot *,unsigned);
extern void func_02021540(struct PalAnmSlot *);
extern u32 func_020056BC(void);
extern int func_0202173C(void *, u16, u16, short, u8, u8, u16, void *);
extern void func_0207D63C(void *,unsigned,unsigned,unsigned,unsigned);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *);
extern void func_0201C4C0(struct PrintSys *);
extern void func_0201ED04(struct WordSet *);
extern void func_0201D83C(void *);
extern void func_02045C04(struct Rec *);
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern u32 func_020307B0(void *p);
extern void func_02041EE4(u32, u32, u32);
extern void func_021BD958(char *p, u32 idx, s16_021BC8B4 *x, s16_021BC8B4 *y, u16 space);
extern void func_021BD934(char *p, int idx, short a, short b, unsigned short c);
extern u16 func_0200CA8C(struct Blk37 *p);
extern struct S *func_021B7754(struct Tmpl *tmpl, u32 heap);
extern void func_021B7A10(u8 *p, u32 a, u32 b, u32 c, u32 index);
extern void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void func_021B79E4(char *ctx, unsigned first, unsigned second);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_021B796C(struct S *);
extern u32 func_021B9398(char *p, int index);
extern void func_021BD75C(char *p, unsigned char *dest, unsigned text0, unsigned index);
extern void func_021BE29C(char *, u16, int, int);
void func_021BC388(void);
void func_021BC52C(void);
void func_021BC574(void);
void func_021BC6C4(char *p);
void func_021BC704(char *p);
void func_021BC730(char *p, u8 a, u8 b);
void func_021BC7B8(void);
void func_021BC7D0(void);
void func_021BC810(void);
void func_021BC824(char *p);
void func_021BC868(char *p);
void func_021BC88C(char *p);
void func_021BC8A4(char *p);
void func_021BC8B4(char *p);
void func_021BC90C(char *a, int b);
int func_021BC91C(char *p);
void func_021BC9A8(struct Context *p);
void func_021BCB60(char *p);
void func_021BCB90(char *p, int index, int a, u16 b, int c);
extern const struct Display data_021BE804;
extern const struct BgTemplate data_021BE894,data_021BE874,data_021BE814,data_021BE8F4,data_021BE8B4,data_021BE854,data_021BE8D4,data_021BE834;
extern const struct Template data_021BE7AC;
extern void *data_020A7370;

void func_021BC388(void)
{
    struct Display display;
    struct BgTemplate b0,b1,b2,b3,b4,b5,b6,b7;
    func_0203F8F4(107);
    display=data_021BE804;func_0203FC28((struct DispConfig *)(&display));
    b0=data_021BE894;func_0203FCA0(0,&b0,0);
    func_020414EC(0);func_02040B94(0,32,0,107);func_02041B6C(0);
    b1=data_021BE874;func_0203FCA0(1,&b1,0);
    b2=data_021BE814;func_0203FCA0(2,&b2,0);
    func_020414EC(2);func_02041B6C(2);
    b3=data_021BE8F4;func_0203FCA0(3,&b3,0);
    b4=data_021BE8B4;func_0203FCA0(4,&b4,0);
    func_020414EC(4);func_02040B94(4,32,0,107);func_02041B6C(4);
    b5=data_021BE854;func_0203FCA0(5,&b5,0);
    b6=data_021BE8D4;func_0203FCA0(6,&b6,0);
    func_020414EC(6);func_02041B6C(6);
    b7=data_021BE834;func_0203FCA0(7,&b7,0);
    func_020434DC(15,1);func_02043598(15,1);
}


void func_021BC52C(void)
{
    func_020434DC(0xf, 0);
    func_02043598(0xf, 0);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}

void func_021BC574(void)
{
    void *arc;
    arc=func_020490F4(159,107);
    func_02049B68(arc,48,0,0,128,107);
    func_02049B68(arc,49,4,0,160,107);
    func_02049658(arc,58,2,0,0,0,107);
    func_02049658(arc,56,3,0,0,0,107);
    func_02049658(arc,59,6,0,0,0,107);
    func_02049658(arc,57,7,0,0,0,107);
    func_020498F4(arc,62,3,0,0,0,107);
    func_020498F4(arc,69,5,0,0,0,107);
    func_020498F4(arc,63,7,0,0,0,107);
    func_02049238(arc);
    arc=func_020490F4(func_020275E4(),107);
    func_02049740(arc,func_02027628(),1,0,0,107);
    func_02049B68(arc,func_02027624(),0,448,32,107);
    func_020498F4(arc,func_0202762C(),1,0,0,0,107);
    func_020413B0(1,0,21,32,3,14);
    func_02041B6C(1);
    func_02049238(arc);
    func_02049B40(23,5,0,480,32,107);
    func_02049B40(23,5,4,480,32,107);
}

void func_021BC6C4(char *p)
{
    ((struct Obj00123 *)p)->fC = func_02021518(0x6B);
    func_0202155C(((struct Obj00123 *)p)->fC, 0, 0x200, 0x6B);
    func_0202155C(((struct Obj00123 *)p)->fC, 1, 0x200, 0x6B);
    func_0202155C(((struct Obj00123 *)p)->fC, 2, 0x200, 0x6B);
    func_0202155C(((struct Obj00123 *)p)->fC, 3, 0x200, 0x6B);
}

void func_021BC704(char *p){func_020215A0(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,0);func_020215A0(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,1);func_020215A0(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,2);func_020215A0(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,3);func_02021540(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC);}

void func_021BC730(char *p, u8 a, u8 b)
{
    void *ctx;
    ctx = (void *)func_020056BC();
    func_0202173C(((struct Obj00088 *)p)->fC, 1, 0xBFFF, -14, a, b, 0, ctx);
    ctx = (void *)func_020056BC();
    func_0202173C(((struct Obj00088 *)p)->fC, 2, 0xFFEF, -14, a, b, 0, ctx);
    ctx = (void *)func_020056BC();
    func_0202173C(((struct Obj00088 *)p)->fC, 4, 0xF878, -14, a, b, 0, ctx);
    ctx = (void *)func_020056BC();
    func_0202173C(((struct Obj00088 *)p)->fC, 8, 0xBFFF, -14, a, b, 0, ctx);
}

void func_021BC7B8(void){func_0207D63C((void *)0x04001050,4,8,6,10);}

static inline void obj(int wnd, int effect)
{
    u32 tmp = (*(volatile u16 *)0x0400104A & ~0x3F00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    *(volatile u16 *)0x0400104A = (u16)tmp;
}

static inline void outside(int wnd, int effect)
{
    u32 tmp = (*(volatile u16 *)0x0400104A & ~0x3F) | (u32)wnd;
    if (effect) tmp |= 0x20;
    *(volatile u16 *)0x0400104A = (u16)tmp;
}

/*
 * volatile: WINOUT reads/writes at 021BC7D4..021BC7F2; DISPCNT read/write at 021BC7F8..021BC802
 */
void func_021BC7D0(void)
{
    obj(27, 1);
    outside(31, 1);
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0xE000) | 0x8000;
}


void func_021BC810(void)
{
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
}

void func_021BC824(char *p)
{
    ((struct Obj00123 *)p)->f3C = func_02045B38(0, 2, 0x114, 0x6B);
    ((struct Obj00123 *)p)->f38 = func_0201D7EC(0x17, 0, 0, 0, 0x6B);
    ((struct Obj00123 *)p)->f40 = func_0201EC64(0x6B);
    ((struct Obj00123 *)p)->f48 = func_0201C440((void *)0x6B);
    ((struct Obj00123 *)p)->f44 = func_020457B0(0x80, 0x6B);
}

void func_021BC868(char *p){func_02045808(*(struct U16Vec * *)&((struct Obj00088 *)p)->f44);func_0201C4C0(*(struct PrintSys * *)&((struct Obj00088 *)p)->f48);func_0201ED04(*(struct WordSet * *)&((struct Obj00088 *)p)->f40);func_0201D83C(((struct Obj00088 *)p)->f38);func_02045C04(*(struct Rec * *)&((struct Obj00088 *)p)->f3C);}

void func_021BC88C(char *p) { ((struct Obj00123 *)p)->fC38=func_0201AF80(107,0); }

void func_021BC8A4(char *p) { func_020307B0(((struct Obj00088 *)p)->fC38); }

void func_021BC8B4(char *p)
{
    unsigned i;
    s16_021BC8B4 pair[2];
    func_02041EE4(5, 3, 48);
    func_02041EE4(1, 3, -48);
    for (i = 3; i <= 9; i++) {
        func_021BD958(p, i, &pair[1], &pair[0], 0);
        pair[0] += 48;
        func_021BD934(p, i, pair[1], pair[0], 0);
    }
}


void func_021BC90C(char *a, int b)
{
    ((struct Obj00088 *)a)->fC40 = 0x30;
    *(unsigned short *)&((struct Obj00088 *)a)->fC42 = b;
}

int func_021BC91C(char *p)
{
    unsigned i;
    s16_021BC91C pair[2];
    int d;
    if (((struct Obj00088 *)p)->fC40 == 0) return 0;
    func_02041EE4(5, 4, ((struct Obj00088 *)p)->fC42);
    func_02041EE4(1, 5, ((struct Obj00088 *)p)->fC42);
    for (i = 3; i <= 9; i++) {
        func_021BD958(p, i, &pair[1], &pair[0], 0);
        pair[0] += ((struct Obj00088 *)p)->fC42;
        func_021BD934(p, i, pair[1], pair[0], 0);
    }
    d = ((struct Obj00088 *)p)->fC42;
    if (d < 0) d = -d;
    ((struct Obj00088 *)p)->fC40 -= d;
    return 1;
}

/*
 * ov067 is loaded by the same overlay's 021BCC94/021BCD48 path.
 */
void func_021BC9A8(struct Context *p)
{
    struct Template tmpl;
    void *arc,*str;
    u32 species,i;
    arc=func_020490F4(159,0x806b);
    species=func_0200CA8C((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->save);
    tmpl=data_021BE7AC;
    tmpl.count=649;tmpl.p24=p;
    for(i=0;i<(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count;i++){
        if(species==(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]){
            if(i>(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count-7){
                tmpl.index=i-((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count-7);
                tmpl.start=i-tmpl.index;
            }else if(i<7){tmpl.index=i;}
            else{tmpl.start=i;}
            break;
        }
    }
    p->list=func_021B7754((struct Tmpl *)(&tmpl),107);
    if(p->in->count<7)p->visible=p->in->count;else p->visible=7;
    func_021B7A10(p->list,(u32)arc,66,0,0);
    func_021B7A10(p->list,(u32)arc,67,0,1);
    func_021B7A10(p->list,(u32)arc,68,0,2);
    func_021B7A4C(p->list,arc,48,2,3);
    func_02049238(arc);
    for(i=0;i<(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count;i++){
        if(func_0200CED4((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->save,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i])==1){
            str=func_02045EC0(data_020A7370,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
            *(void **)((u32)p+i*4+0x4c)=func_02045874(str,107);
            func_02045808(str);
            func_021B79E4(p->list,0,0x20000000|(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
        }else if(func_0200D064((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->save,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i])==1){
            str=func_02045EC0(data_020A7370,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
            *(void **)((u32)p+i*4+0x4c)=func_02045874(str,107);
            func_02045808(str);
            func_021B79E4(p->list,1,0x10000000|(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
        }else{
            *(void **)((u32)p+i*4+0x4c)=func_02045EC0(((struct Obj00123 *)p)->f3C,7);
            func_021B79E4(p->list,2,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
        }
    }
}

void func_021BCB60(char *p) { u32 i;func_021B796C(*(struct S * *)&((struct Obj00088 *)p)->fC2C);for(i=0;i<649;i++){struct U16Vec *q=*(struct U16Vec **)((u32)p+i*4+76);if(q)func_02045808(q);} }

void func_021BCB90(char *p, int index, int a, u16 b, int c)
{
    u32 v;
    u32 low;
    v = func_021B9398(((struct Obj02924 *)p)->fC2C, index);
    low = v & 0x0FFFFFFF;
    func_021BD75C(p, (unsigned char *)a, *(u32 *)(p + index * 4 + 0x4C), low);
    if ((v & 0xF0000000) >> 28) func_021BE29C(p, low, b, c);
}

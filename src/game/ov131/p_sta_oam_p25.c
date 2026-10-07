/*
 * file:     p_sta_oam_p25.c
 * unit:     yes
 * function: func_021D9428, func_021D9440, func_021D949C, func_021D9568, func_021D964C, func_021D9670, func_021D96B0, func_021D9734, func_021D9740, func_021D9980, func_021D9A04, func_021D9A4C, func_021D9BD4, func_021D9C3C, func_021D9CD0, func_021D9D44, func_021D9D94, func_021D9E30, func_021D9E44, func_021D9EE8
 * address:  0x021D9428
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D93E4  0x021D93E4  thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_021DBF2C 0x021DBF2C thumb ov131
 *   func_021DBF94 0x021DBF94 thumb ov131
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02041570 0x02041570 arm
 *   func_02030734 0x02030734 arm
 *   d_021DC844 0x021DC844 data a1
 *   func_020307B0 0x020307B0 arm
 *   func_021DA958 0x021DA958 thumb ov131
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_021D9EF0 0x021D9EF0 thumb ov131
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021DBA78 0x021DBA78 thumb ov131
 *   func_021DB468 0x021DB468 thumb ov131
 *   func_021DB7D0 0x021DB7D0 thumb ov131
 *   func_0204B878 0x0204B878 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_021DBA90 0x021DBA90 thumb ov131
 *   func_021DA84C 0x021DA84C thumb ov131
 *   func_021DBAC0 0x021DBAC0 thumb ov131
 *   func_0204B92C 0x0204B92C arm
 *   func_021DB700 0x021DB700 thumb ov131
 *   func_021DB7B8 0x021DB7B8 thumb ov131
 *   d_021DC2C2 0x021DC2C2 data a1
 *   func_02045798 0x02045798 arm
 *   func_021DB7D4 0x021DB7D4 thumb ov131
 *   func_020410D0 0x020410D0 arm
 *   func_021DB964 0x021DB964 thumb ov131
 *   func_021DB9E8 0x021DB9E8 thumb ov131
 *   func_021DB9FC 0x021DB9FC thumb ov131
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021DA0B0  0x021DA0B0  thumb
 *   func_021DA3FC  0x021DA3FC  thumb
 *   func_021DA488 0x021DA488 thumb ov131
 */
#include "../../matched/include/Obj23156.h"
#include "../../matched/include/Obj00136.h"
#include "../../matched/include/Obj03815.h"
#include "../../matched/include/Obj02484.h"
#include "../../matched/include/Obj03816.h"
#include "../../matched/include/Obj23157.h"
#include "../../matched/include/Obj05394.h"
#include "../../matched/include/Obj06485.h"
#include "../../matched/include/Obj23158.h"
#include "../../matched/include/Obj02189.h"
#include "../../matched/include/Obj14075.h"
#include "../../matched/include/Obj23159.h"
#include "../../matched/include/Obj00502.h"
#include "../../matched/include/Obj00776.h"
#include "../../matched/include/Obj05395.h"
#include "../../matched/include/Obj02190.h"
#include "../../matched/include/Obj00344.h"
#include "../../matched/include/Obj01939.h"
#include "../../matched/include/Obj05396.h"
#include "../../matched/include/Obj04511.h"
#include "../../matched/include/Obj04512.h"
#include "../../matched/include/Obj14076.h"
#include "../../matched/include/Obj10519.h"
#include "../../matched/include/Obj10520.h"

struct Descriptor;
struct MsgBank;
struct U16Vec;
struct Cfg;
struct Obj;
struct PrintSys;
struct S;
typedef unsigned char u8;

typedef signed char s8;

typedef signed short s16;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {u16 x,y,z;u8 priority,flags;} ObjPos;

typedef signed int     s32;

extern unsigned int func_021D93E4(unsigned char *, unsigned int);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_021DBF2C(u32,u32);
extern unsigned int func_021DBF94(int i);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0204A8D4(u32 i);
extern void func_0204B3B4(struct Obj *p);
extern void func_02041570(int,u16);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_021DA958(u8 *,u8 *);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_021D9EF0(u8 *,u8 *);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_021DBA78(u8 *,int);
extern void func_021DB468(u8 *,u8 *,u8,int);
extern void func_021DB7D0(void *a0, void *a1, void *a2);
extern void func_0204B878(struct Obj *p, u16 value);
extern void *func_02049EF4(void *,u32,u32,void **,u16);
extern struct S *func_021DBA90(u32 a, u32 b);
extern void func_021DA84C(u8 *, u8 *);
extern void func_021DBAC0(u8 *);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021DB700(u8 *,void *,u8 *,u8);
extern void func_021DB7B8(void *, void *, u8 *);
extern void func_02045798(struct Descriptor *p, u8 v);
extern void func_021DB7D4(u8 *p, u8 *q, u8 *entry);
extern void func_020410D0(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_021DB964(u8 *a, void *b, u8 *p);
extern void func_021DB9E8(void *, void *, u8 *);
extern void func_021DB9FC(void *,void *,u8 *);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void func_020409B4(u32);
extern void func_021DA0B0(u8 *, u8 *);
extern void func_021DA3FC(u8 *a, u8 *b);
extern void func_021DA488(u8 *,u8 *);
unsigned int func_021D9428(unsigned char *p, unsigned int target);
s16 func_021D9440(u8 *p, u32 target);
void func_021D949C(u8 *a,u8 *p);
void func_021D9568(u8 *a,u8 *p);
void func_021D964C(u8 *a,u8 *p);
void func_021D9670(u8 *a,u8 *p);
u8 *func_021D96B0(u8 *a);
void func_021D9734(u8 *a,u8 *p);
void func_021D9740(u8 *a,u8 *p);
void func_021D9980(u8 *a,u8 *p,void *resource);
void func_021D9A04(u8 *a, u8 *p);
void func_021D9A4C(u8 *a,u8 *p);
void func_021D9BD4(void *a, u8 *p);
void func_021D9C3C(void *a,u8 *p);
void func_021D9CD0(u8 *a,u8 *p);
void func_021D9D44(void *a, u8 *p);
void func_021D9D94(u8 *a,u8 *p);
void func_021D9E30(void *a, int b);
void func_021D9E44(u8 *a,u8 *p);
void func_021D9EE8(u8 *a,u8 *p);
extern const char d_021DC844[];
extern const u8 d_021DC2C2[];


/*
 * Addresses are Black-image addresses.
 */
unsigned int func_021D9428(unsigned char *p, unsigned int target)
{
    unsigned int r = func_021D93E4(p, target);

    if (r < p[0x10])
        return r;
    return 0xffff;
}

s16 func_021D9440(u8 *p, u32 target)
{
    u32 position;
    u8 row, remainder;
    s8 delta;
    position = ((struct Obj23156 *)p)->f14;
    row = position / 24u;
    remainder = position % 24u;
    delta = target - (u8)(row % 10);
    if (delta < -2) delta += 10;
    if (delta > 8 && row > 6) delta -= 10;
    return delta * 24 + 8 - remainder;
}

/*
 * extent: two zero alignment bytes at 021D9566 follow the 202-byte body.
 * proof: index is ldrb at 021D94DA, hence 0..255; index*8+316
 * is at most 2356 and has no signed overflow. No selector bound assumed.
 */
void func_021D949C(u8 *a,u8 *p)
{
    u8 index;
    void *text;
    *(u32 *)&((struct Obj03815 *)p)->f20=func_020450F0(4,5,7,22,2,14,1);
    *(u32 *)&((struct Obj03815 *)p)->f24=func_020450F0(4,1,16,30,4,14,1);
    index=(p+p[0x59]*8)[0x13c];
    text=func_02045EC0(((struct Obj03815 *)p)->f50,func_021DBF2C(index,3));
    func_0201C724(((struct Obj00136 *)a)->f84,(u32)func_02045770(((struct Obj03815 *)p)->f20),1,1,(u32)text,((struct Obj00136 *)a)->f80,1088);
    func_02045808(text);
    text=func_02045EC0(((struct Obj03815 *)p)->f50,func_021DBF94(index));
    func_0201C724(((struct Obj00136 *)a)->f84,(u32)func_02045770(((struct Obj03815 *)p)->f24),1,1,(u32)text,((struct Obj00136 *)a)->f80,1088);
    func_02045808(text);
    ((struct Obj03815 *)p)->f8=1;
}

/*
 * extent: two zero alignment bytes at 021D964A follow the 226-byte body.
 * proof: selector is a byte; selector*8+316 <=2356. Position stores
 * initialize every byte of the eight-byte descriptor before passing it.
 * prototype: 0204B294 leaves 0204CFDC's pointer return live at 0204B318;
 * 021D960E stores it. Keep the own body's u32,u32,u32,u32,u32,u16,u16
 * inputs, and expose the observed r0 result despite its legacy void return.
 */
void func_021D9568(u8 *a,u8 *p)
{
    void *cell;
    void *archive;
    u8 index;
    ObjPos pos;
    index=(p+p[0x59]*8)[0x13c];
    cell=((struct Obj02484 *)p)->f20;
    func_02045334(cell);
    func_02045374(cell);
    func_02041B6C(func_02045730(cell));
    cell=((struct Obj02484 *)p)->f24;
    func_02045334(cell);
    func_02045374(cell);
    func_02041B6C(func_02045730(cell));
    archive=func_020490F4(78,((struct Obj03816 *)a)->f0);
    ((struct Obj02484 *)p)->f18=func_0204A6C8((void *)((u32)archive),func_021DBF2C(index,1),0,1,((struct Obj03816 *)a)->f0);
    func_02049238(archive);
    pos.x=128;
    pos.y=100;
    pos.priority=10;
    pos.flags=0;
    pos.z=0;
    *(u32 *)&((struct Obj02484 *)p)->f1C=(u32)func_0204B294((void *)((struct Obj03816 *)a)->f174,((struct Obj02484 *)p)->f18,((struct Obj03816 *)a)->fB4,((struct Obj03816 *)a)->f128,&pos,1,((struct Obj03816 *)a)->f0);
    func_0204B6F4(((struct Obj02484 *)p)->f1C,(u8)func_021DBF2C(index,2),1);
    func_0204B3DC(((struct Obj02484 *)p)->f1C,1);
    func_02040AE0(6,*(u8 * *)&((struct Obj02484 *)p)->f38+12,((struct Obj23157 *)(*(u8 * *)&((struct Obj02484 *)p)->f38))->f8);
    func_02041B6C(6);
    ((struct Obj02484 *)p)->f4=1;
}

void func_021D964C(u8 *a,u8 *p)
{
    if(((struct Obj05394 *)p)->f20!=0) {
        func_020452E8(((struct Obj05394 *)p)->f20);
        ((struct Obj05394 *)p)->f20=0;
    }
    if(((struct Obj05394 *)p)->f24!=0) {
        func_020452E8(((struct Obj05394 *)p)->f24);
        ((struct Obj05394 *)p)->f24=0;
    }
}

void func_021D9670(u8 *a,u8 *p)
{
    u8 *q;
    if(((struct Obj06485 *)p)->f4==1) {
        func_0204A8D4((u32)(((struct Obj06485 *)p)->f18));
        func_0204B3B4(((struct Obj06485 *)p)->f1C);
        func_02041570(4,0);
        func_02041B6C(4);
        ((struct Obj06485 *)p)->f4=0;
        q=*(u8 * *)&((struct Obj06485 *)p)->f30;
        func_02040AE0(6,q+0xc,((struct Obj23158 *)q)->f8);
        func_02041B6C(6);
    }
}

u8 *func_021D96B0(u8 *a)
{
    u8 *p;
    u8 i;
    p=func_02030734(((struct Obj14075 *)a)->f0,296,0,d_021DC844,315);
    ((struct Obj02189 *)p)->f0=0;
    ((struct Obj02189 *)p)->f4=0;
    ((struct Obj02189 *)p)->f8=0;
    ((struct Obj02189 *)p)->f10=0;
    ((struct Obj02189 *)p)->f14=0;
    ((struct Obj02189 *)p)->f18=0;
    ((struct Obj02189 *)p)->f24=0;
    p[42]=5;
    p[41]=255;
    if ((*(u8 **)(a+8))[13]==2 && ((struct Obj23159 *)(*(u8 * *)&((struct Obj14075 *)a)->f8))->f14!=0) p[43]=5;
    else p[43]=4;
    for(i=0;i<5;i++) {
        p[0xb0+i*24]=255;
        *(u32 *)(p+0xb4+i*24)=0;
    }
    return p;
}

void func_021D9734(u8 *a,u8 *p)
{
    func_020307B0(p);
}

/*
 * proof: all scaled indices are ldrb or byte loop counters, hence
 * *24 <=6120 and *4 <=1020. p[40]+1 <=256 before the byte store;
 * signed %8 uses the reloaded byte 0..255, with no overflow or division
 * failure. No smaller range or successful callee result is assumed.
 */
void func_021D9740(u8 *a,u8 *p)
{
    u8 i;
    int ready;
    void *cell;
    if(((struct Obj00502 *)p)->f4==0 && ((struct Obj00502 *)p)->f8==0 && ((struct Obj00502 *)p)->f10==0 && ((struct Obj00502 *)p)->f20==0) func_021DA958(a,p);
    if(((struct Obj00502 *)p)->f4==1) {
        ready=1;
        for(i=0;i<=7;i++) {
            if(func_0201C6C4(((struct Obj00136 *)a)->f84,func_02045770(*(void **)((p+i*4)+0x5c)))==1) {
                ready=0;
                break;
            }
        }
        if(ready==1) {
            for(i=0;i<=7;i++) {
                cell=*(void **)((p+i*4)+0x5c);
                func_02045334(cell);
                func_02045374(cell);
                func_02041B6C(func_02045730(cell));
            }
            func_021D9E44(a,p);
            ((struct Obj00502 *)p)->f4=0;
        }
    }
    if(((struct Obj00502 *)p)->f8==1) {
        ready=1;
        for(i=8;i<=11;i++) {
            if(func_0201C6C4(((struct Obj00136 *)a)->f84,func_02045770(*(void **)((p+i*4)+0x5c)))==1) {
                ready=0;
                break;
            }
        }
        if(ready==1) {
            for(i=8;i<=11;i++) {
                cell=*(void **)((p+i*4)+0x5c);
                func_02045334(cell);
                func_02045374(cell);
                func_02041B6C(func_02045730(cell));
            }
            func_021D9EF0(a,p);
            ((struct Obj00502 *)p)->f8=0;
        }
    }
    if(((struct Obj00502 *)p)->fC==1) {
        if(func_0201C6C4(((struct Obj00136 *)a)->f84,func_02045770(((struct Obj00502 *)p)->f8C))==0) {
            cell=((struct Obj00502 *)p)->f8C;
            func_02045334(cell);
            func_02045374(cell);
            func_02041B6C(func_02045730(cell));
            ((struct Obj00502 *)p)->fC=0;
        }
    }
    if(((struct Obj00502 *)p)->f10==1 && func_0201C6B4(((struct Obj00136 *)a)->f84)==1) {
        ((struct Obj00502 *)p)->f14=0;
        func_021DBA78((p+0xb0)+p[0x2a]*24,0);
        p[0x2a]=5;
        func_021DB468(a,p,p[0x29],0);
        func_0204B3DC(((struct Obj00502 *)p)->f9C,0);
        ((struct Obj00502 *)p)->f10=0;
    }
    for(i=0;i<5;i++) func_021DB7D0(a,p,(p+0xb0)+i*24);
    if(((struct Obj00502 *)p)->f20==1) {
        p[40]++;
        if((int)p[40]%8<4) {
            if(((struct Obj00502 *)p)->f24==1) func_0204B878(*(void **)((p+p[41]*24)+0xb8),15);
            else func_021DBA78((p+0xb0)+p[41]*24,0);
        } else {
            if(((struct Obj00502 *)p)->f24==1) func_0204B878(*(void **)((p+p[41]*24)+0xb8),16);
            else func_021DBA78((p+0xb0)+p[41]*24,1);
        }
        if(p[40]>16) ((struct Obj00136 *)a)->f50=2;
    }
}

void func_021D9980(u8 *a,u8 *p,void *resource)
{
    ((struct Obj05395 *)p)->f38=func_02049EF4(resource,72,0,(void **)(p+0x34),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f40=func_02049EF4(resource,73,0,(void **)(p+0x3c),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f48=func_02049EF4(resource,74,0,(void **)(p+0x44),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f50=func_02049EF4(resource,75,0,(void **)(p+0x4c),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f58=func_02049EF4(resource,76,0,(void **)(p+0x54),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->fA4=func_021DBA90(((struct Obj00776 *)a)->f0,(u32)(((struct Obj00776 *)a)->f174));
}

void func_021D9A04(u8 *a, u8 *p)
{
    if (((struct Obj02190 *)p)->f0 == 1) {
        if ((*(u8 **)(a + 8))[13] == 2) func_021DA84C(a, p);
        else func_021D9D44(a, p);
    }
    func_021DBAC0(*(u8 * *)&((struct Obj02190 *)p)->fA4);
    func_020307B0(((struct Obj02190 *)p)->f38);
    func_020307B0(((struct Obj02190 *)p)->f40);
    func_020307B0(((struct Obj02190 *)p)->f48);
    func_020307B0(((struct Obj02190 *)p)->f50);
    func_020307B0(((struct Obj02190 *)p)->f58);
}

/*
 * extent: two zero alignment bytes at 021D9BD2 follow the 390-byte body.
 * proof: i is byte-wrapped; i*24 <=6120, every descriptor byte initialized.
 * No bound smaller than the ldrb domain is assumed for p[43].
 * prototype: 0204B294 leaves 0204CFDC's pointer result live at 0204B318;
 * this caller stores r0 after every call. Keep all seven own-body inputs.
 */
void func_021D9A4C(u8 *a,u8 *p)
{
    ObjPos pos;
    u8 i;
    pos.x=159;
    pos.y=52;
    pos.priority=10;
    pos.flags=1;
    i=0;
    pos.z=0;
    *(u32 *)&((struct Obj01939 *)p)->f90=(u32)func_0204B294((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fE4,((struct Obj00344 *)a)->fAC,((struct Obj00344 *)a)->f114,&pos,1,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f90,0);
    pos.x=172;
    pos.y=56;
    *(u32 *)&((struct Obj01939 *)p)->f94=(u32)func_0204B294((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fD8,((struct Obj00344 *)a)->fA8,*(u32 *)&((struct Obj00344 *)a)->f10C,&pos,1,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f94,0);
    pos.flags=0;
    *(u32 *)&((struct Obj01939 *)p)->f98=(u32)func_0204B294((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fEC,((struct Obj00344 *)a)->fC4,((struct Obj00344 *)a)->f11C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f98,0);
    pos.z=5;
    pos.priority=8;
    *(u32 *)&((struct Obj01939 *)p)->f9C=(u32)func_0204B294((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fEC,((struct Obj00344 *)a)->fC4,((struct Obj00344 *)a)->f11C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f9C,0);
    func_0204B92C(((struct Obj01939 *)p)->f9C,1);
    pos.z=2;
    pos.priority=4;
    pos.flags=0;
    *(u32 *)&((struct Obj01939 *)p)->fA0=(u32)func_0204B294((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fEC,((struct Obj00344 *)a)->fC4,((struct Obj00344 *)a)->f11C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->fA0,0);
    func_0204B92C(((struct Obj01939 *)p)->fA0,1);
    for(;i<p[0x2b];i++) func_021DB700(a,p,(p+0xb0)+i*24,i);
}

void func_021D9BD4(void *a, u8 *p)
{
    u8 i;
    for (i = 0; i < p[0x2b]; i++)
        func_021DB7B8(a, p, p + 0xb0 + i * 24);
    func_0204B3B4(((struct Obj05396 *)p)->f90);
    func_0204B3B4(((struct Obj05396 *)p)->f94);
    func_0204B3B4(((struct Obj05396 *)p)->f98);
    func_0204B3B4(((struct Obj05396 *)p)->f9C);
    func_0204B3B4(((struct Obj05396 *)p)->fA0);
}

void func_021D9C3C(void *a,u8 *p)
{
    u8 i;
    for(i=0;i<13;i++) {
        *(void **)(p+0x5c+i*4)=(void *)func_020450F0(4,d_021DC2C2[i*4],d_021DC2C2[i*4+1],d_021DC2C2[i*4+2],d_021DC2C2[i*4+3],14,1);
    }
    func_02045798(((struct Obj04511 *)p)->f60,13);
    func_021D9E30(a,(int)p);
    for(i=0;i<p[43];i++) func_021DB7D4(a,p,p+0xb0+i*24);
    p[41]=255;
    ((struct Obj04511 *)p)->f0=1;
    ((struct Obj04511 *)p)->f20=0;
    p[40]=0;
}

void func_021D9CD0(u8 *a,u8 *p)
{
    u8 i;
    func_020410D0(2,0,0,32,24,((struct Obj04512 *)p)->f34+12,0,0,32,32);
    func_02041B6C(2);
    func_021D9E44(a,p);
    for(i=0;i<p[0x2b];i++) func_021DB964(a,p,p+0xb0+i*24);
    func_0204B878(((struct Obj00136 *)a)->f17C,4);
}

void func_021D9D44(void *a, u8 *p)
{
    u8 i;
    for (i = 0; i < p[0x2b]; i++)
        func_021DB9E8(a, p, p + 0xb0 + i * 24);
    for (i = 0; i < 13; i++)
        func_020452E8(*(void **)(p + 0x5c + i * 4));
    ((struct Obj14076 *)p)->f0 = 0;
}

void func_021D9D94(u8 *a,u8 *p)
{
    u8 i;
    for(i=0;i<p[0x2b];i++) func_021DB9FC(a,p,p+0xb0+i*24);
    func_02041300(1,0,0,0,19,21,16);
    func_020409B4(1);
    func_02041570(4,0);
    func_02041B6C(4);
    func_0204B3DC(((struct Obj10520 *)p)->f90,0);
    func_0204B3DC(((struct Obj10520 *)p)->f94,0);
    func_0204B3DC(((struct Obj10519 *)a)->f198,0);
    func_0204B3DC(((struct Obj10519 *)a)->f19C,0);
    func_0204B878(((struct Obj10519 *)a)->f17C,1);
}


void func_021D9E30(void *a, int b)
{
    func_021DA0B0(a, (u8 *)b);
    func_021DA3FC(a, (u8 *)b);
}

void func_021D9E44(u8 *a,u8 *p)
{
    u8 i;
    void *cell;
    i=0;
    func_02041570(4,0);
    for(;i<=7;i++) {
        cell=*(void **)(p+0x5c+i*4);
        func_02045334(cell);
        func_02045374(cell);
        func_020409B4(func_02045730(cell));
    }
    func_02040AE0(6,*(u8 * *)&((struct Obj04512 *)p)->f3C+12,*((u32 *)(*(u8 * *)&((struct Obj04512 *)p)->f3C+8)));
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,((struct Obj04512 *)p)->f4C+12,0,0,32,32);
    func_02041B6C(5);
    func_0204B3DC(((struct Obj04512 *)p)->f90,1);
    func_0204B3DC(((struct Obj04512 *)p)->f94,0);
    func_0204B3DC(((struct Obj00136 *)a)->f198,0);
    func_0204B3DC(((struct Obj00136 *)a)->f19C,0);
}

void func_021D9EE8(u8 *a,u8 *p)
{
    func_021DA488(a,p);
}

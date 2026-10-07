/*
 * file:     namein_graphic_p12.c
 * unit:     yes
 * function: func_021F32FC, func_021F3304, func_021F3350, func_021F3358, func_021F3364, func_021F33C0, func_021F35A8, func_021F366C, func_021F36E8
 * address:  0x021F32FC
 * region:   ov194
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
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02040804 0x02040804 arm
 *   func_02040618 0x02040618 arm
 *   func_02040588 0x02040588 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021F2608 0x021F2608 thumb ov194
 *   func_021F256C 0x021F256C thumb ov194
 *   func_02043B5C 0x02043B5C arm
 *   func_021F26F0 0x021F26F0 thumb ov194
 *   func_02040AE0 0x02040AE0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F2884 0x021F2884 thumb ov194
 *   func_021F25F8 0x021F25F8 thumb ov194
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021F2828 0x021F2828 thumb ov194
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F26E0 0x021F26E0 thumb ov194
 *   func_021F1A1C 0x021F1A1C thumb ov194
 */
#include "../../matched/include/Obj24907.h"
#include "../../matched/include/Obj05512.h"
#include "../../matched/include/Obj24908.h"
#include "../../matched/include/Obj00117.h"
#include "../../matched/include/Obj01773.h"

struct Descriptor;
struct Rect;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct {int x,y;} Pair;

typedef struct {unsigned char pad[0xD8];Pair xy;} Ctx;

typedef struct {int left,top,right,bottom;} Rect;

extern void *func_02045770(struct Descriptor *);
extern int func_0201C6C4(int,int);
extern void func_02045334(struct Descriptor *d);
extern void func_0207D63C(void *,int,int,int,int);
extern u32 func_02040804(u32 layer);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021F2608(void *p);
extern void func_021F256C(char *p, unsigned mode, int index, void *table, u32 a4);
extern void func_02043B5C(int,unsigned);
extern void func_021F26F0(char *p, char *target, void *window, void *font, u16 heap);
extern void func_02040AE0(unsigned,const void *,unsigned);
extern void func_020409B4(unsigned);
extern void func_021F2884(int *,int,int);
extern void func_021F25F8(int *,int,void *);
extern unsigned func_0203633C(void),func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8),func_020061E4(unsigned);
extern int func_021F2828(const char *,int,Pair *);
extern int func_021F2818(char *,int,int);
extern void func_021F26E0(char *,int,int);
extern void func_021F1A1C(char *p, int mode, const struct Rect *rect, int flag, int selected);
void *func_021F32FC(const u8 *p);
int func_021F3304(char *p);
void *func_021F3350(const u8 *p);
u32 func_021F3358(u32 a,u32 b,u32 c);
int func_021F3364(char *p,int mode);
int func_021F33C0(char *p);
void func_021F35A8(char *p, u32 mode);
void func_021F366C(char *p,int index,int variant);
int func_021F36E8(char *p,int *out);

void *func_021F32FC(const u8 *p) {return ((struct Obj24907 *)p)->f104;}

int func_021F3304(char *p) {
 int q;
 q=((struct Obj05512 *)p)->fF8;
 if(((struct Obj05512 *)p)->fF0) {
 if(func_0201C6C4(q,(int)func_02045770((struct Descriptor *)*(int *)&((struct Obj05512 *)p)->fEC))==0) {
 func_02045334(((struct Obj05512 *)p)->fEC);((struct Obj05512 *)p)->fF0=0;
 }}
 if(((struct Obj05512 *)p)->fF0==0)return 1;return 0;
}

void *func_021F3350(const u8 *p) {return ((struct Obj24908 *)p)->f100;}

u32 func_021F3358(u32 a,u32 b,u32 c) {if(a==3) a=b+(a+2*c);return a;}

int func_021F3364(char *p,int mode) {
 int flag;
 if(((struct Obj00117 *)p)->f114!=mode) {
 ((struct Obj00117 *)p)->f114=mode;((struct Obj00117 *)p)->f10A=0;((struct Obj00117 *)p)->f10C=0;((struct Obj00117 *)p)->f110=1;
 flag=0;
 if(mode==3 || ((struct Obj00117 *)p)->f100==3)flag=1;
 ((struct Obj00117 *)p)->f118=flag;
 if(flag)func_0207D63C((void *)0x04000050,14,47,16,16);
 else func_0207D63C((void *)0x04000050,10,47,16,16);
 return 1;
 }return 0;
}

/*
 * note: 2026-10-05 wD4 lane09: EXACT. The calls in case 0 are written out in each arm of the f118 test (tail merge builds the shared movs r1,#0 join), so the join block holds only the state stores and the zero is not hoisted.
 */
int func_021F33C0(char *p) {
    int c;
    int y;
    if (*(u32 *)(p + 0x110) != 0)
    switch (*(u16 *)(p + 0x10c)) {
    case 0:
        func_02040804(1);
        c = *(u16 *)(p + 0x10a);
        *(u16 *)0x04000052 = (s16)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16)((c * -48) / 7);
        func_02040618(1, 3, y);
        func_02040618(3, 3, y);
        if (*(u32 *)(p + 0x118)) func_02040618(2, 3, y);
        if ((*(u16 *)(p + 0x10a))++ > 7) {
            if (*(u32 *)(p + 0x118)) {
                func_02040588(1, 0);
                func_02040588(2, 0);
                func_02040588(3, 0);
            } else {
                func_02040588(1, 0);
                func_02040588(3, 0);
            }
            *(u16 *)(p + 0x10a) = 0;
            *(u16 *)(p + 0x10c) = 1;
        }
        break;
    case 1:
        y = -48;
        func_02040618(1, 3, y);
        func_02040618(3, 3, y);
        if (*(u32 *)(p + 0x118)) func_02040618(2, 3, y);
        func_021F35A8(p, *(u32 *)(p + 0x114));
        *(u16 *)(p + 0x10c) = 2;
        break;
    case 2:
        *(u16 *)(p + 0x10a) = 7;
        *(u16 *)(p + 0x10c) = 3;
        func_02040588(1, 1);
        func_02040588(3, 1);
        if (*(u32 *)(p + 0x100) != 3) func_02040588(2, 1);
        *(u16 *)0x04000052 = 1 << 12;
        break;
    case 3:
        c = *(u16 *)(p + 0x10a);
        *(u16 *)0x04000052 = (s16)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16)((c * -48) / 7);
        func_02040618(1, 3, y);
        func_02040618(3, 3, y);
        if (*(u32 *)(p + 0x118)) func_02040618(2, 3, y);
        if ((*(u16 *)(p + 0x10a))-- == 0) *(u16 *)(p + 0x10c) = 4;
        break;
    case 4:
        func_02040618(1, 3, 0);
        func_02040618(3, 3, 0);
        func_02040618(2, 3, 0);
        *(u32 *)(p + 0x118) = 0;
        *(u16 *)0x04000050 = 0;
        *(u32 *)(p + 0x110) = 0;
        return 1;
    }
    return 0;
}

void func_021F35A8(char *p, u32 mode) {
 int index;
 if(((struct Obj01773 *)p)->f100==mode)return;
 func_021F2608(p);
 index=func_021F3358(mode,((struct Obj01773 *)p)->f104,((struct Obj01773 *)p)->f108);
 func_021F256C(p,mode,index,((struct Obj01773 *)p)->f12C,((struct Obj01773 *)p)->fFE);
 func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj01773 *)p)->fE0),0);
 func_021F26F0(p,p+0xEC,(void *)(((struct Obj01773 *)p)->fF8),(void *)(((struct Obj01773 *)p)->fF4),((struct Obj01773 *)p)->fFE);
 if(mode==3) {func_02040AE0(1,*(char * *)&((struct Obj01773 *)p)->f124+12,2048);func_02040588(2,0);}
 else func_02040AE0(1,*(char * *)&((struct Obj01773 *)p)->f128+12,2048);
 func_020409B4(1);
 if(mode==3 || ((struct Obj01773 *)p)->f100==3)func_021F2884((int *)(p+0xD8),((struct Obj01773 *)p)->f100,mode);
 ((struct Obj01773 *)p)->f100=mode;
}

/*
 * volatile: 021F3676 and 021F3696 re-read the mode word at +0x100.
 */
void func_021F366C(char *p,int index,int variant) {
 int selected;
 if(*(volatile int *)&((struct Obj00117 *)p)->f100!=3)return;
 if(((struct Obj00117 *)p)->f108==variant && ((struct Obj00117 *)p)->f104==index)return;
 selected=(int)func_021F3358((int)(*(volatile int *)&((struct Obj00117 *)p)->f100),(int)index,(unsigned char)variant);
 func_021F25F8((int *)p,selected,((struct Obj00117 *)p)->f12C);
 func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj00117 *)p)->fE0),0);
 func_021F26F0(p,p+0xEC,(void *)(((struct Obj00117 *)p)->fF8),(void *)(((struct Obj00117 *)p)->fF4),((struct Obj00117 *)p)->fFE);
 ((struct Obj00117 *)p)->f104=index;((struct Obj00117 *)p)->f108=variant;
}

int func_021F36E8(char *p,int *out)
{
    Rect rect;
    Pair delta;
    int changed=0;
    if(func_0203633C()&64){delta.x=0;delta.y=-1;changed=1;}
    else if(func_0203633C()&128){delta.x=0;delta.y=1;changed=1;}
    else if(func_0203633C()&32){delta.x=-1;delta.y=0;changed=1;}
    else if(func_0203633C()&16){delta.x=1;delta.y=0;changed=1;}
    else if(func_020362DC()&8){
        delta.x=0;delta.y=0;changed=1;
        func_021F2828(p,7,(Pair *)(p+0xD8));
        func_021F26E0(p,(int)(p+0xD8),(int)&delta);
    }
    if(changed){
        if(func_020355C4()==1){
            if(func_021F2818(p,(int)(p+0xD8),(int)&rect)){
                func_020355D8(0);
                func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                func_020061E4(1352);
            }
        }else{
            func_021F26E0(p,(int)p+0xD8,(int)&delta);
            if(func_021F2818(p,(int)(p+0xD8),(int)&rect)){
                func_020061E4(1352);
                func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
            }
        }
    }
    return 0;
}

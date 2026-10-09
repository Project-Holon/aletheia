/*
 * file:     namein_graphic_p03.c
 * unit:     yes
 * function: func_021F2F8C, func_021F3008, func_021F31B8, func_021F31F4, func_021F32D8, func_021F32FC, func_021F3304, func_021F3350, func_021F3358, func_021F3364, func_021F33C0, func_021F35A8, func_021F366C, func_021F36E8, func_021F37EC, func_021F38CC, func_021F391C, func_021F3A0C
 * address:  0x021F2F8C
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
 *   func_02082BCC 0x02082BCC arm
 *   func_02049EB4 0x02049EB4 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_02040588 0x02040588 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F19A0 0x021F19A0 thumb ov194
 *   func_021F256C 0x021F256C thumb ov194
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_021F26F0 0x021F26F0 thumb ov194
 *   func_020355C4 0x020355C4 arm
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F1A1C 0x021F1A1C thumb ov194
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021F2608 0x021F2608 thumb ov194
 *   func_021F1A10 0x021F1A10 thumb ov194
 *   func_021F3BD4 0x021F3BD4 thumb ov194
 *   func_021F3B18 0x021F3B18 thumb ov194
 *   func_021F3C40 0x021F3C40 thumb ov194
 *   func_021F23E4 0x021F23E4 thumb ov194
 *   func_021F2828 0x021F2828 thumb ov194
 *   func_021F1BFC 0x021F1BFC thumb ov194
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_02040804 0x02040804 arm
 *   func_02040618 0x02040618 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021F2884 0x021F2884 thumb ov194
 *   func_021F25F8 0x021F25F8 thumb ov194
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021F26E0 0x021F26E0 thumb ov194
 *   func_02035D20 0x02035D20 arm
 *   func_021F265C 0x021F265C thumb ov194
 *   func_021F2614 0x021F2614 thumb ov194
 */
#include "../../matched/include/Obj00733.h"
#include "../../matched/include/Obj24905.h"
#include "../../matched/include/Obj00117.h"
#include "../../matched/include/Obj10809.h"
#include "../../matched/include/Obj24907.h"
#include "../../matched/include/Obj05512.h"
#include "../../matched/include/Obj24908.h"
#include "../../matched/include/Obj01773.h"
#include "../../matched/include/Obj14503.h"

struct Descriptor;
struct Cfg;
struct Rect;
typedef struct {int x,y;} Pair;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned u32_021F2F8C;

typedef struct {int x,y,z,w;} Box;

typedef unsigned int u32_021F31B8;

typedef struct {int left,top,right,bottom;} Rect;

typedef unsigned int u32;

typedef short s16;

typedef struct {unsigned char pad[0xD8];Pair xy;} Ctx;

extern void func_02082BCC(void *,unsigned,unsigned);
extern void *func_02049EB4(u32_021F2F8C,u32_021F2F8C,u32_021F2F8C,u32_021F2F8C,u32_021F2F8C);
extern void func_02040AE0(u32_021F2F8C,const void *,u32_021F2F8C);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020409B4(u32_021F2F8C);
extern void func_021F19A0(u8 *,void *,void *,u32_021F2F8C);
extern void func_021F256C(char *,unsigned,int,void *,u32_021F2F8C);
extern u32_021F2F8C func_020450F0(u32_021F2F8C,u32_021F2F8C,u32_021F2F8C,u32_021F2F8C,u8,u8,u8);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_021F26F0(char *,char *,void *,void *,u32_021F2F8C);
extern u8 func_020355C4(void);
extern int func_021F2818(char *,Pair *,Box *);
extern void func_021F1A1C(char *p, int mode, const struct Rect *rect, int flag, int selected);
extern u32_021F31B8 func_020452E8(struct Descriptor *d);
extern u32_021F31B8 func_020307B0(void *p);
extern void func_021F2608(void *);
extern void func_021F1A10(void *);
extern int func_021F3BD4(char *,int *);
extern int func_021F3A0C(char *,int *);
extern int func_021F3B18(char *,int *);
extern void func_021F3C40(char *,int *);
extern int func_021F2828(const char *,int,Pair *);
extern void func_021F1BFC(char *p, int sel, const void *rect);
extern void *func_02045770(struct Descriptor *);
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_0207D63C(void *,int,int,int,int);
extern u32 func_02040804(u32 layer);
extern void func_02040618(u32 layer, u32 a, u32 b);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021F2884(Pair *,int,int);
extern void func_021F25F8(int *,int,int);
extern unsigned func_0203633C(void);
extern unsigned func_020362DC(void);
extern void func_020355D8(u8);
extern void func_020061E4(unsigned);
extern void func_021F26E0(char *,int,int);
extern void func_020355D8(u8);
extern unsigned func_02035D20(unsigned *,unsigned *);
extern int func_021F265C(const char *,int *,Pair *);
extern unsigned func_021F2614(char *,int *,unsigned short *);
int func_021F2F8C(Pair *p,Pair *out);
void func_021F3008(u8 *p,int mode,void *font,void *window,void *data,void *palette,u32_021F2F8C heap);
void func_021F31B8(u8 *p);
void func_021F31F4(char *p,char *q);
int func_021F32D8(char *p, unsigned short *out);
void *func_021F32FC(const u8 *p);
int func_021F3304(char *p);
void *func_021F3350(const u8 *p);
u32 func_021F3358(u32 a,u32 b,u32 c);
int func_021F3364(char *p,int mode);
int func_021F33C0(char *p);
void func_021F35A8(char *p, u32 mode);
void func_021F366C(char *p,int index,int variant);
int func_021F36E8(char *p,int *out);
int func_021F37EC(char *p,int *out);
int func_021F38CC(char *p,int *out);
void func_021F391C(char *p,int *input);
int func_021F3A0C(char *p,int *out);




int func_021F2F8C(Pair *p,Pair *out) {
 int result;Pair xy;
 result=0;
 switch((unsigned)p->y) {
 case 0: if(p->x==10)result=6;else {xy=*p;result=1;}break;
 case 1: if(p->x==9)result=7;else {xy=*p;result=1;}break;
 case 2: if(p->x==0 || p->x==9)result=8;else {xy.x=p->x-1;xy.y=p->y;result=1;}break;
 case 3: result=9;if(p->x!=4)result=p->x+2;break;
 }
 if(result==1 && out) {*out=xy;}return result;
}




/*
 * tail: two zero alignment bytes at 021F31B6 before 31B8.
 * prototype: 256C retains fifth heap input visibly stored by caller; heap forwards use full words without caller-side truncation.
 */
void func_021F3008(u8 *p,int mode,void *font,void *window,void *data,void *palette,u32_021F2F8C heap)
{
 Box box;
 void *bg;
 int index;
 func_02082BCC(p,0,0x130);
 ((struct Obj00733 *)p)->fD8=0;((struct Obj00733 *)p)->fDC=0;
 ((struct Obj00733 *)p)->fF4=font;((struct Obj00733 *)p)->fF8=window;((struct Obj00733 *)p)->fFE=heap;
 ((struct Obj00733 *)p)->f100=mode;((struct Obj00733 *)p)->f114=mode;((struct Obj00733 *)p)->f12C=data;
 ((struct Obj00733 *)p)->f11C=func_02049EB4(118,10,0,(u32_021F2F8C)(p+0x124),heap);
 ((struct Obj00733 *)p)->f120=func_02049EB4(118,5,0,(u32_021F2F8C)(p+0x128),heap);
 if(mode==3){func_02040AE0(1,*(char * *)&((struct Obj00733 *)p)->f124+12,2048);func_02040588(2,0);}
 else {func_02040AE0(1,*(char * *)&((struct Obj00733 *)p)->f128+12,2048);func_02040588(2,1);}
 func_020409B4(1);
 func_021F19A0(p+0x24,(void *)mode,palette,heap);
 index=func_021F3358(((struct Obj00733 *)p)->f100,((struct Obj00733 *)p)->f104,p[0x108]);
 func_021F256C((char *)p,mode,index,((struct Obj00733 *)p)->f12C,heap);
 bg=(void *)func_020450F0(3,3,5,26,15,15,1);
 ((struct Obj00733 *)p)->fE0=bg;
 func_02045334(bg);func_02045374(bg);func_020409B4(func_02045730(bg));
 ((struct Obj00733 *)p)->fEC=((struct Obj00733 *)p)->fE0;p[0xf0]=0;
 func_021F26F0((char *)p,(char *)p+0xec,window,font,heap);
 if(func_020355C4()==0){
  if(func_021F2818((char *)p,(Pair *)(p+0xd8),&box))func_021F1A1C((char *)p+0x24,1,(const struct Rect *)(&box),((struct Obj00733 *)p)->f104,((struct Obj00733 *)p)->f100);
 }else {
  if(func_021F2818((char *)p,(Pair *)(p+0xd8),&box))func_021F1A1C((char *)p+0x24,0,(const struct Rect *)(&box),((struct Obj00733 *)p)->f104,((struct Obj00733 *)p)->f100);
 }
}




void func_021F31B8(u8 *p) {int off;func_020452E8(((struct Obj24905 *)p)->fE0);func_021F2608(p);func_021F1A10(p+36);off=0x11c;func_020307B0(*(void **)(p+off));func_020307B0(*(void **)(p+off+4));off+=20;func_02082BCC(p,0,off);}




void func_021F31F4(char *p,char *q)
{
    int out0[4];
    int out2[4];
    Rect rect;
    int result;
    ((struct Obj00117 *)p)->fE8=0;
    switch(((struct Obj00117 *)p)->fE4){
    case 0:
        func_02082BCC(out0,0,16);
        result=func_021F38CC(p,out0);
        if(!result){func_021F36E8(p,out0);result=func_021F37EC(p,out0);}
        if(result)func_021F391C(p,out0);
        break;
    case 2:
        func_02082BCC(out2,0,16);
        result=func_021F3BD4(p,out2);
        if(!result){func_021F3A0C(p,out2);result=func_021F3B18(p,out2);}
        if(result)func_021F3C40(p,out2);
        if(func_021F33C0(p))((struct Obj00117 *)p)->fE4=0;
        break;
    case 1:
        if(func_021F23E4(q)){func_021F2828(p,7,(Pair *)(p+0xD8));((struct Obj00117 *)p)->fE8=11;}
        ((struct Obj00117 *)p)->fE4=0;
        break;
    }
    func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect));
    func_021F1BFC(p+0x24,((struct Obj00117 *)p)->f100,&rect);
    func_021F3304(p);
}





int func_021F32D8(char *p, unsigned short *out)
{
    int s = ((struct Obj10809 *)p)->fE8;
    if ((s == 1 || s == 2 || s == 9) && out != 0)
    {
        *out = ((struct Obj10809 *)p)->fFC;
    }
    return ((struct Obj10809 *)p)->fE8;
}



void *func_021F32FC(const u8 *p) {return ((struct Obj24907 *)p)->f104;}



int func_021F3304(char *p) {
 int q;
 q=((struct Obj05512 *)p)->fF8;
 if(((struct Obj05512 *)p)->fF0) {
 if(func_0201C6C4((struct PrintSys *)q,(void *)func_02045770((struct Descriptor *)*(int *)&((struct Obj05512 *)p)->fEC))==0) {
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
 func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)((struct Obj01773 *)p)->fE0),0);
 func_021F26F0(p,p+0xEC,(void *)(((struct Obj01773 *)p)->fF8),(void *)(((struct Obj01773 *)p)->fF4),((struct Obj01773 *)p)->fFE);
 if(mode==3) {func_02040AE0(1,*(char * *)&((struct Obj01773 *)p)->f124+12,2048);func_02040588(2,0);}
 else func_02040AE0(1,*(char * *)&((struct Obj01773 *)p)->f128+12,2048);
 func_020409B4(1);
 if(mode==3 || ((struct Obj01773 *)p)->f100==3)func_021F2884((Pair *)(p+0xD8),((struct Obj01773 *)p)->f100,mode);
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
 func_021F25F8((int *)p,selected,(int)((struct Obj00117 *)p)->f12C);
 func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)((struct Obj00117 *)p)->fE0),0);
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
            if(func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                func_020355D8(0);
                func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                func_020061E4(1352);
            }
        }else{
            func_021F26E0(p,(int)p+0xD8,(int)&delta);
            if(func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                func_020061E4(1352);
                func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
            }
        }
    }
    return 0;
}


int func_021F37EC(char *p,int *out)
{
    Rect rect;
    int changed;
    changed=0;
    if(func_020362DC()==1) {
        *(Pair *)(out+2)=*(Pair *)(p+0xD8);
        out[1]=1;changed=1;
    }
    if(func_020362DC()==2) {
        func_021F2828(p,6,(Pair *)(out+2));out[0]=6;changed=1;
    }
    if(func_020362DC()==4) {
        out[0]=((struct Obj00117 *)p)->f100+3;
        if(out[0]>5)out[0]=2;
        func_021F2828(p,out[0],(Pair *)(p+0xD8));
        *(Pair *)(out+2)=*(Pair *)(p+0xD8);changed=1;
    }
    if(func_020362DC()==256){((struct Obj00117 *)p)->fE8=10;changed=0;}
    if(changed && func_020355C4()==1) {
        if(func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))) {
            func_020061E4(1352);func_020355D8(0);
            func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
            return 0;
        }
    }
    return changed;
}


int func_021F38CC(char *p,int *out) {
 int point[2];unsigned x,y;int u;
 if(func_02035D20(&x,&y)) {
 point[0]=x;point[1]=y;
 if(func_021F265C(p,point,(Pair *)(p+0xD8))) {
 u=((struct Obj14503 *)p)->fD8;out[3]=((struct Obj14503 *)p)->fDC;out[1]=1;out[2]=u;func_020355D8(1);return 1;
 }}return 0;
}


void func_021F391C(char *p,int *input)
{
    unsigned code;
    Rect rect;
    if(input[1])code=func_021F2614(p,(int *)(p+0xD8),(unsigned short *)(p+0xFC));
    else code=input[0];
    switch(code){
    case 0:break;
    case 1:((struct Obj00117 *)p)->fE8=1;((struct Obj00117 *)p)->fE4=1;break;
    case 9:((struct Obj00117 *)p)->fE8=9;((struct Obj00117 *)p)->fE4=1;break;
    case 2:case 3:case 4:case 5:
        if(func_021F3364(p,code-2)){
            func_020061E4(1611);((struct Obj00117 *)p)->fE4=2;((struct Obj00117 *)p)->fE8=6;
        }break;
    case 6:((struct Obj00117 *)p)->fE8=5;break;
    case 7:((struct Obj00117 *)p)->fE8=7;break;
    case 8:
        func_020061E4(1356);((struct Obj00117 *)p)->fE8=8;
        func_021F366C(p,((struct Obj00117 *)p)->f104^1,((struct Obj00117 *)p)->f108);break;
    case 10:((struct Obj00117 *)p)->fE8=3;break;
    case 11:((struct Obj00117 *)p)->fE8=4;break;
    }
    if(func_021F2818(p, (Pair *)((int)(input+2)), (Box *)((int)&rect)))
        func_021F1A1C(p+0x24,2,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
}


/*
 * lever: Integer address arithmetic for26E0 avoids caching p+D8 across2818.
 */
int func_021F3A0C(char *p,int *out)
{
    Rect rect;
    Pair delta;
    Pair point;
    int changed=0;
    if(((struct Obj00117 *)p)->f118==0){
        if(func_020362DC()&64){delta.x=0;delta.y=-1;changed=1;}
        else if(func_020362DC()&128){delta.x=0;delta.y=1;changed=1;}
        else if(func_020362DC()&32){delta.x=-1;delta.y=0;changed=1;}
        else if(func_020362DC()&16){delta.x=1;delta.y=0;changed=1;}
    }
    if(changed){
        point=*(Pair *)(p+0xD8);
        func_021F26E0(p,(int)&point,(int)&delta);
        if(func_021F2614(p,&point.x,0)-2<=3){
            if(func_020355C4()==1){
                if(func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                    func_020061E4(1352);func_020355D8(0);
                    func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                }
            }else{
                func_021F26E0(p,(int)p+0xD8,(int)&delta);
                if(func_021F2818(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                    func_020061E4(1352);
                    func_021F1A1C(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                }
            }
        }
    }
    return 0;
}

/*
 * file:     mystery_p03.c
 * unit:     yes
 * function: func_021D72F0, func_021D73DC, func_021D7814, func_021D7B4C
 * address:  0x021D72F0
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D81B0 0x021D81B0 thumb ov121
 *   func_021D83B0 0x021D83B0 thumb ov121
 *   func_021D8380 0x021D8380 thumb ov121
 *   func_021DA8C0 0x021DA8C0 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021DA8C4 0x021DA8C4 thumb ov121
 *   func_021D6E3C 0x021D6E3C thumb ov121
 *   func_021DE308 0x021DE308 thumb ov121
 *   func_021DE3E0 0x021DE3E0 thumb ov121
 *   func_021DE4DC 0x021DE4DC thumb ov121
 *   func_021DEF6C 0x021DEF6C thumb ov121
 *   func_021D9554 0x021D9554 thumb ov121
 *   func_021DE500 0x021DE500 thumb ov121
 *   func_021DE550 0x021DE550 thumb ov121
 *   func_021D83DC 0x021D83DC thumb ov121
 *   func_021D8138 0x021D8138 thumb ov121
 *   func_021DA178 0x021DA178 thumb ov121
 *   func_021D8198 0x021D8198 thumb ov121
 *   func_021D849C 0x021D849C thumb ov121
 *   func_020362DC 0x020362DC arm
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_021D9750 0x021D9750 thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_021D9744 0x021D9744 thumb ov121
 *   func_021D84D4 0x021D84D4 thumb ov121
 *   func_021D8C1C 0x021D8C1C thumb ov121
 *   func_021D8D00 0x021D8D00 thumb ov121
 *   func_021D8D18 0x021D8D18 thumb ov121
 *   func_0200A2B8 0x0200A2B8 thumb
 *   func_0200A2D8 0x0200A2D8 thumb
 *   func_021D8CA8 0x021D8CA8 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021D9790 0x021D9790 thumb ov121
 *   func_02082BCC 0x02082BCC arm
 *   func_021DCFC8 0x021DCFC8 thumb ov121
 *   func_021DD24C 0x021DD24C thumb ov121
 *   func_021DE0AC 0x021DE0AC thumb ov121
 *   func_021DD9CC 0x021DD9CC thumb ov121
 *   func_021DDF5C 0x021DDF5C thumb ov121
 *   func_021DE014 0x021DE014 thumb ov121
 *   func_021D93F4 0x021D93F4 thumb ov121
 *   func_021D94B8 0x021D94B8 thumb ov121
 *   func_021D9488 0x021D9488 thumb ov121
 *   func_021D6DF4 0x021D6DF4 thumb ov121
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021D9288 0x021D9288 thumb ov121
 *   func_021DAC18 0x021DAC18 thumb ov121
 *   func_021DAEF0 0x021DAEF0 thumb ov121
 *   func_021DB008 0x021DB008 thumb ov121
 *   func_021DAE1C 0x021DAE1C thumb ov121
 *   func_021D694C 0x021D694C thumb ov121
 *   func_021D6C60 0x021D6C60 thumb ov121
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_021DAFCC 0x021DAFCC thumb ov121
 */
#include "../../matched/include/Obj00326.h"
#include "../../matched/include/Obj13939.h"
#include "../../matched/include/Obj00297.h"
#include "../../matched/include/Obj00989.h"

#define P(k) (*(void **)(p+(k)))
#define W(k) (*(u32 *)(p+(k)))
struct RtcDate;
struct Obj;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {int y,m,d,week;} Date;

typedef struct {u8 bit:1;} Flag;

typedef struct { u32 w[12]; } Desc_021D7814;

typedef struct { u32 w[9]; } Desc_021D7B4C;

typedef signed int     s32;

extern void func_021D9F08(u8 *a, int b, int c, int d);
extern void func_021D81B0(u8 *p, u32 which, int heap);
extern int func_021D83B0(char *p);
extern void func_021D8380(char *p);
extern void func_021DA8C0(u32 *p, u32 a);
extern void func_021DA8B0(u32 *p, u32 a);
extern unsigned func_021D9FF8(u8 *p);
extern void func_021DA8C4(u32 *p);
extern void func_021D6E3C(void *task, u32 *state, u8 *p);
extern void func_021DE308(char *,unsigned);
extern int func_021DE3E0(void *);
extern int func_021DE4DC(u8 *p, void *a, u32 b);
extern int func_021DEF6C(char *,void *,u16);
extern int func_021D9554(char *p, int n);
extern int func_021DE500(void *);
extern void func_021DE550(char *p);
extern void func_021D83DC(u8 *,int);
extern void func_021D8138(u8 *,int,int);
extern int func_021DA178(char *);
extern void func_021D8198(char *);
extern void func_021D849C(char *p);
extern u32 func_020362DC(void);
extern void func_0203F4E4(struct RtcDate *date);
extern int func_0200A1A8(char *p, unsigned int bit);
extern int func_0200A034(void *p, void *arg);
extern void func_0200A1E4(void *p, unsigned int idx);
extern void func_021D9750(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern unsigned func_021D9744(char *p);
extern void func_021D84D4(u8 *out, void *owner, const u8 *desc, void *save, void *list, void *a5, void *a6, u16 heap);
extern void func_021D8C1C(u8 *p, int mode);
extern void func_021D8D00(char *p);
extern int func_021D8D18(char *p);
extern void func_0200A2B8(void *a0, int a1);
extern int func_0200A2D8(void *a0, int a1);
extern void func_021D8CA8(u8 *p);
extern void func_021D9E04(u8 *p);
extern void func_021D9790(char *p);
extern void func_02082BCC(void *,int,int);
extern void *func_021DCFC8(Desc_021D7814 *,u16);
extern void *func_021DD24C(void *,void *,void *,u16);
extern void func_021DE0AC(u8 *p, u32 b);
extern void func_021DD9CC(char *p);
extern void func_021DDF5C(u8 *p);
extern int func_021DE014(char *p);
extern void func_021D93F4(u8 *p, const void *q, int n, int k, int x, int y, int z, u16 heap);
extern int func_021D94B8(char *p);
extern void func_021D9488(void **p);
extern void func_021D6DF4(void *a, int *state);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021D9288(unsigned *p, unsigned v);
extern void *func_021DAC18(Desc_021D7B4C *,int);
extern void func_021DAEF0(struct Obj *obj);
extern int func_021DB008(char *p);
extern void func_021DAE1C(struct Obj *obj);
extern void func_021D694C(u16 *p, int mode);
extern void func_021D6C60(u8 *p, int heap);
extern void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap);
extern void func_021D9FFC(u8 *p, int a, int b);
extern void func_021DAFCC(char *p);
void func_021D72F0(void *a, int *state, char *p);
void func_021D73DC(void *task,u32 *state,u8 *p);
void func_021D7814(void *task,u32 *state,u8 *p);
void func_021D7B4C(void *task,u32 *state,u8 *p);

void func_021D72F0(void *a, int *state, char *p)
{
    int result;
    switch (*state) {
    case 0:
        func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 126, 0);
        func_021D81B0((u8 *)p, 3, 29);
        *state = 2;
        break;
    case 2:
        result = func_021D83B0(p);
        if (result == -1) break;
        func_021D8380(p);
        if (result == 0) {
            func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 132, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 1) {
            func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 133, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 2) {
            func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 134, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 3) {
            func_021DA8B0(a, (u32)func_021D6E3C);
        }
        break;
    case 3:
        if (func_021D9FF8(((struct Obj00326 *)p)->f284)) func_021DA8C4(a);
        break;
    }
}

void func_021D73DC(void *task,u32 *state,u8 *p)
{
    int v,flag;
    Date date;
    switch(*state) {
    case 0:
        switch(W(940)) {
        case 1:func_021DE308(P(944),4);break;
        case 0:func_021DE308(P(944),7);break;
        case 2:func_021DE308(P(944),10);break;
        }
        func_021D9F08(P(644),W(932),105,0);
        W(964)=0;*state=1;break;
    case 1:
        if(func_021DE3E0(P(944))==0) {
            v=func_021DE4DC(P(944),p+972,720);
            if(v==1) {
                v=func_021DEF6C((char *)p+972,P(952),32797);
                if(func_021D9554((char *)(p+972),v)) *state=5;
                else *state=12;
            } else if(v==2) *state=2;
        }
        v=func_021DE500(P(944));
        switch(v) {case 1:case 2:func_021DE550(P(944));func_021DA8B0(task,(u32)func_021D6E3C);break;}
        if((func_020362DC()&2) || W(964)++>7200) {
            flag=0;
            switch(W(940)) {
            case 1:
                if(func_021DE3E0(P(944))==4) {func_021DE308(P(944),5);flag=1;}break;
            case 0:
                if(func_021DE3E0(P(944))==8) {func_021DE308(P(944),9);flag=1;}break;
            case 2:
                if(func_021DE3E0(P(944))==11) {func_021DE308(P(944),12);flag=1;}break;
            }
            if(flag) {*state=2;W(964)=0;}
        }
        break;
    case 2:
        func_021D9F08(P(644),W(932),136,2);
        func_021DA8C0(task,3);*state=14;break;
    case 3:
        W(964)++;
        if(func_021DE3E0(P(944))==0 && W(964)>30) {
            W(964)=0;
            func_021D9F08(P(644),W(932),139,1);
            func_021DA8C0(task,4);*state=14;
        }
        break;
    case 4:func_021DA8B0(task,(u32)func_021D6E3C);break;
    case 5:
        func_021D81B0(p,2,29);func_021D83DC(p,29);
        func_021D9F08(P(644),W(932),106,0);*state=6;break;
    case 6:
        flag=0;v=func_021D83B0((char *)p);
        if(v!=-1) {
        if(v==0) {
            func_021D9F08(P(644),W(932),110,1);
            func_021DA8C0(task,7);*state=14;
        } else if(v==-2) flag=1;
        } else if(func_020362DC()&2) flag=1;
        if(flag) {
            func_021D9F08(P(644),W(932),107,1);
            func_021DA8C0(task,9);*state=14;
        }
        break;
    case 7:func_021D8138(p,0,29);*state=8;break;
    case 8:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) {
                func_021D8380((char *)p);
                if(((Flag *)(p+1152))->bit && func_0200A1A8(P(956),((struct Obj13939 *)p)->f47C)) {*state=11;break;}
                func_0203F4E4((struct RtcDate *)(&date));
                W(1144)=(((u32)date.y+2000)<<16)|(((u32)date.m<<24)>>16)|(u8)date.d;
                func_0200A034(P(956),p+972);
                func_0200A1E4(P(956),((struct Obj13939 *)p)->f47C);
                func_021DA8B0(task,(u32)func_021D7814);
            } else if(v==1) *state=5;
        }
        break;
    case 9:func_021D8138(p,0,29);*state=10;break;
    case 10:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) {
                func_021D8380((char *)p);func_021D849C((char *)p);
                func_021DA8B0(task,(u32)func_021D6E3C);
            } else if(v==1) *state=5;
        }
        break;
    case 11:
        func_021D9F08(P(644),W(932),138,1);
        func_021DA8C0(task,13);*state=14;break;
    case 12:
        func_021D9F08(P(644),W(932),144,1);
        func_021DA8C0(task,13);*state=14;break;
    case 13:
        func_021D8380((char *)p);func_021D849C((char *)p);
        func_021DA8B0(task,(u32)func_021D6E3C);break;
    case 14:
        if(func_021D9FF8(P(644))) func_021DA8C4(task);
        break;
    }
}

/*
 * volatile: 0x021D79BC writes the display blend register 0x04000050.
 */
void func_021D7814(void *task,u32 *state,u8 *p)
{
    Desc_021D7814 d;
    switch (*state) {
    case 0:
        func_021D9750(((struct Obj00297 *)p)->f394);
        func_02040588(1,1);
        func_02040588(3,1);
        func_021D84D4(p+12,(void *)func_021D9744(((struct Obj00297 *)p)->f394),p+972,(void *)(*(int *)&((struct Obj00297 *)p)->f3B8),p+660,p+912,p+312,29);
        func_021D8C1C(p+12,0);
        func_021D9F08(((struct Obj00297 *)p)->f284,((struct Obj00297 *)p)->f3A4,113,2);
        *state=1;
        break;
    case 1:
        func_02040588(0,1);
        *state=2;
        break;
    case 2:
        if (func_021D9FF8(((struct Obj00297 *)p)->f284)) *state=3;
        break;
    case 3:
        func_021D8D00((char *)(p+12));
        if (func_021D8D18((char *)(p+12))) *state=4;
        break;
    case 4:
        func_0200A2B8(((struct Obj00297 *)p)->f3BC,(int)(((struct Obj00297 *)p)->f3B8));
        *state=5;
        break;
    case 5:
        if (func_0200A2D8(((struct Obj00297 *)p)->f3BC,(int)(((struct Obj00297 *)p)->f3B8))==2) *state=6;
        break;
    case 6:
        func_021D8C1C(p+12,1);
        *state=7;
        break;
    case 7:
        func_021D8D00((char *)(p+12));
        if (func_021D8D18((char *)(p+12))) *state=8;
        break;
    case 8:
        func_021D9F08(((struct Obj00297 *)p)->f284,((struct Obj00297 *)p)->f3A4,114,1);
        *state=9;
        break;
    case 9:
        if (func_021D9FF8(((struct Obj00297 *)p)->f284)) *state=10;
        break;
    case 10:
        func_021D8CA8(p+12);
        func_021D9E04(((struct Obj00297 *)p)->f284);
        ((struct Obj00297 *)p)->f284=0;
        func_021D8380((char *)p);
        *(volatile u16 *)0x04000050=0;
        func_021D9790(((struct Obj00297 *)p)->f394);
        func_02040588(1,1);
        func_02040588(3,1);
        *state=11;
        break;
    case 11:
        func_02040588(0,1);
        *state=12;
        break;
    case 12:
        func_02040588(1,0);
        func_02082BCC(&d,0,48);
        d.w[0]=2;
        d.w[1]=0;
        d.w[2]=8;
        d.w[3]=15;
        d.w[5]=13;
        d.w[4]=10;
        d.w[6]=(u32)func_021D9744(((struct Obj00297 *)p)->f394);
        d.w[7]=*(u32 *)&((struct Obj00297 *)p)->f3BC;
        d.w[8]=*(u32 *)&((struct Obj00297 *)p)->f3A4;
        d.w[9]=((struct Obj00297 *)p)->f398;
        d.w[10]=((struct Obj00297 *)p)->f39C;
        d.w[11]=((struct Obj00297 *)p)->f3A8;
        ((struct Obj00297 *)p)->f4=func_021DCFC8(&d,29);
        ((struct Obj00297 *)p)->f0=func_021DD24C(p+972,((struct Obj00297 *)p)->f4,((struct Obj00297 *)p)->f3B8,29);
        func_021DE0AC(((struct Obj00297 *)p)->f0,0);
        *state=13;
        break;
    case 13:
        func_021DD9CC(((struct Obj00297 *)p)->f0);
        func_021DDF5C(((struct Obj00297 *)p)->f0);
        *state=14;
        break;
    case 14:
        func_021DD9CC(((struct Obj00297 *)p)->f0);
        if (func_021DE014(((struct Obj00297 *)p)->f0)) {
            ((struct Obj00297 *)p)->f3C4=0;
            *state=15;
        }
        break;
    case 15:
        if (func_020362DC()&1) *state=18;
        if ((((struct Obj00297 *)p)->f3C4)++>240) {
            ((struct Obj00297 *)p)->f3C4=0;
            *state=16;
        }
        break;
    case 16:
        func_021D93F4(p+612,p+660,(int)func_021D9744(((struct Obj00297 *)p)->f394),*(int *)&((struct Obj00297 *)p)->f39C,((struct Obj00297 *)p)->f3A4,155,*(int *)&((struct Obj00297 *)p)->f398,29);
        func_021D94B8((char *)(p+612));
        *state=17;
        break;
    case 17:
        func_021D94B8((char *)(p+612));
        if (func_020362DC()&1) {
            func_021D9488((void **)(p+612));
            *state=18;
        }
        break;
    case 18:
        func_021DA8B0(task,(u32)func_021D6DF4);
        break;
    }
}

void func_021D7B4C(void *task,u32 *state,u8 *p)
{
    Desc_021D7B4C d;
    switch(*state) {
    case 0:
        func_0204E720(3,0,16,-1);
        func_021DA8C0(task,1);
        *state=8;
        break;
    case 1:
        func_021D9288((unsigned int *)(p+312),0);
        func_021D8380((char *)p);
        func_021D9E04(((struct Obj00989 *)p)->f284);
        ((struct Obj00989 *)p)->f284=0;
        func_02082BCC(&d,0,36);
        d.w[0]=0;
        d.w[2]=(u32)func_021D9744(((struct Obj00989 *)p)->f394);
        d.w[3]=((struct Obj00989 *)p)->f3BC;
        d.w[4]=*(u32 *)&((struct Obj00989 *)p)->f398;
        d.w[5]=*(u32 *)&((struct Obj00989 *)p)->f39C;
        d.w[6]=((struct Obj00989 *)p)->f3A8;
        d.w[7]=((struct Obj00989 *)p)->f3A4;
        d.w[8]=((struct Obj00989 *)p)->f3B8;
        ((struct Obj00989 *)p)->f8=func_021DAC18(&d,29);
        *state=2;
        break;
    case 2:
        func_0204E720(3,16,0,-1);
        func_021DA8C0(task,3);
        *state=8;
        break;
    case 3:
        func_021DAEF0(((struct Obj00989 *)p)->f8);
        if(func_021DB008(((struct Obj00989 *)p)->f8)) *state=4;
        break;
    case 4:
        func_0204E720(3,0,16,0);
        func_021DA8C0(task,5);
        *state=8;
        break;
    case 5:
        func_021D9288((unsigned int *)(p+312),1);
        func_021DAE1C(((struct Obj00989 *)p)->f8);
        ((struct Obj00989 *)p)->f8=0;
        func_021D694C((u16 *)(p+912),0);
        func_021D6C60(p+660,29);
        ((struct Obj00989 *)p)->f284=func_021D9CA4(1,15,((struct Obj00989 *)p)->f39C,((struct Obj00989 *)p)->f398,29);
        func_021D9FFC(((struct Obj00989 *)p)->f284,10,14);
        func_021D81B0(p,0,29);
        func_0207D63C((void *)0x04000050,4,24,15,3);
        *state=6;
        break;
    case 6:
        func_0204E720(3,16,0,0);
        func_021DA8C0(task,7);
        *state=8;
        break;
    case 7:
        func_021DA8B0(task,(u32)func_021D6E3C);
        break;
    case 8:
        if(!func_0204E804()) func_021DA8C4(task);
        break;
    }
    if(((struct Obj00989 *)p)->f8) func_021DAFCC(((struct Obj00989 *)p)->f8);
}

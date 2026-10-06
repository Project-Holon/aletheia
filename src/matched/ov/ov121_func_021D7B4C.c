/*
 * function: func_021D7B4C
 * address: 0x021D7B4C
 * packet: pkt_ov121_021D7B4C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021DA8C0 0x021DA8C0 thumb ov121
 *   func_021DA8C4 0x021DA8C4 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D9288 0x021D9288 thumb ov121
 *   func_021D8380 0x021D8380 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021D9744 0x021D9744 thumb ov121
 *   func_021DAC18 0x021DAC18 thumb ov121
 *   func_021DAEF0 0x021DAEF0 thumb ov121
 *   func_021DB008 0x021DB008 thumb ov121
 *   func_021DAE1C 0x021DAE1C thumb ov121
 *   func_021D694C 0x021D694C thumb ov121
 *   func_021D6C60 0x021D6C60 thumb ov121
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_021D81B0 0x021D81B0 thumb ov121
 *   func_021DAFCC 0x021DAFCC thumb ov121
 *   func_021D6E3C 0x021D6E3C thumb ov121
 */
#include "../include/Obj00989.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 w[9]; } Desc;
typedef signed int     s32;
struct Obj;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_02082BCC(void *,int,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021DA8C0(u32 *p, u32 a);
extern void func_021DA8C4(u32 *p);
extern void func_021DA8B0(u32 *p, u32 a);
typedef unsigned short u16;
extern void func_021D9288(unsigned *p, unsigned v);
extern void func_021D8380(char *p);
extern void func_021D9E04(u8 *p);
extern unsigned func_021D9744(char *p);
extern void *func_021DAC18(Desc *,int);
extern void func_021DAEF0(struct Obj *obj);
extern int func_021DB008(char *p);
extern void func_021DAE1C(struct Obj *obj);
extern void func_021D694C(u16 *p, int mode);
extern void func_021D6C60(u8 *p, int heap);
extern void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap);
extern void func_021D9FFC(u8 *p, int a, int b);
extern void func_021D81B0(u8 *p, u32 which, int heap);
extern void func_021DAFCC(char *p);
extern void func_021D6E3C(void *task, u32 *state, u8 *p);
void func_021D7B4C(void *task,u32 *state,u8 *p)
{
    Desc d;
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

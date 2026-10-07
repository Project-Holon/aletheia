/*
 * file:     mystery_p04.c
 * unit:     yes
 * function: func_021D7CF4, func_021D7EAC, func_021D80C0, func_021D80F0
 * address:  0x021D7CF4
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
 *   func_0200A0C8 0x0200A0C8 thumb
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
 *   func_021DE500 0x021DE500 thumb ov121
 *   func_021DE550 0x021DE550 thumb ov121
 *   func_021D6C28 0x021D6C28 thumb ov121
 *   func_021D6948 0x021D6948 thumb ov121
 *   func_021D96C4 0x021D96C4 thumb ov121
 *   func_02030734 0x02030734 arm
 *   func_0200A350 0x0200A350 thumb
 *   func_020312CC 0x020312CC arm
 *   func_021D9624 0x021D9624 thumb ov121
 *   func_021D6924 0x021D6924 thumb ov121
 *   func_021D6AEC 0x021D6AEC thumb ov121
 *   func_0203D34C 0x0203D34C arm
 *   func_02005D90 0x02005D90 thumb
 *   func_021D73DC 0x021D73DC thumb ov121
 *   func_020307B0 0x020307B0 arm
 *   d_021DFB80 0x021DFB80 data a1
 *   d_021D6338 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data a1
 *   func_021D8198 0x021D8198 thumb ov121
 *   func_021D849C 0x021D849C thumb ov121
 *   func_021DD980 0x021DD980 thumb ov121
 *   func_021DD1FC 0x021DD1FC thumb ov121
 *   func_021DA8B8 0x021DA8B8 thumb ov121
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 */
#include "../../matched/include/Obj00827.h"
#include "../../matched/include/Obj00533.h"
#include "../../matched/include/Obj22858.h"
#include "../../matched/include/Obj22859.h"
#include "../../matched/include/Obj22860.h"
#include "../../matched/include/Obj22861.h"
#include "../../matched/include/Obj22862.h"
#include "../../matched/include/Obj22863.h"
#include "../../matched/include/Obj22864.h"
#include "../../matched/include/Obj22865.h"
#include "../../matched/include/Obj22866.h"
#include "../../matched/include/Obj00326.h"
#include "../../matched/include/Obj10409.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u32 w[9]; } Desc;

typedef signed int     s32;

typedef unsigned short u16;

extern u32 func_0200A0C8(u8 *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_02082BCC(void *,int,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021DA8C0(u32 *p, u32 a);
extern void func_021DA8C4(u32 *p);
extern void func_021DA8B0(u32 *p, u32 a);
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
extern int func_021DE500(void *);
extern void func_021DE550(char *p);
extern void func_021D6C28(u8 *p);
extern void func_021D6948(void *);
extern void func_021D96C4(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_0200A350(struct Obj *a0);
extern void func_020312CC(u32,u32,u32);
extern u8 *func_021D9624(int arg, u16 heap);
extern void func_021D6924(u16 *p, u16 heap);
extern void func_021D6AEC(char *p, void *owner, u16 heap);
extern void func_0203D34C(u32,u32);
extern void func_02005D90(int,int);
extern void func_021D73DC(void *task, u32 *state, u8 *p);
extern u32 func_020307B0(void *p);
extern void func_021D8198(char *),func_021D8380(char *),func_021D849C(char *),func_021DD980(char *);
extern void func_021DD1FC(void **);
extern void func_021DA8B8(u32 *p);
extern void func_021D9F08(u8 *, int, int, int);
extern unsigned func_021D9FF8(u8 *p);
void func_021D7CF4(void *task,u32 *state,u8 *p);
void func_021D7EAC(void *task,u32 *state,u8 *p);
void func_021D80C0(void *p,int n,char *q);
void func_021D80F0(void *a, int *state, u8 *p);
extern const char d_021DFB80[];
extern const int d_021D6338[];
extern char ov115_id[];

void func_021D7CF4(void *task,u32 *state,u8 *p)
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
        func_021D9E04(((struct Obj00827 *)p)->f284);
        ((struct Obj00827 *)p)->f284=0;
        func_02082BCC(&d,0,36);
        d.w[0]=1;
        d.w[2]=(u32)func_021D9744(((struct Obj00827 *)p)->f394);
        d.w[3]=*(u32 *)&((struct Obj00827 *)p)->f3BC;
        d.w[4]=*(u32 *)&((struct Obj00827 *)p)->f398;
        d.w[5]=*(u32 *)&((struct Obj00827 *)p)->f39C;
        d.w[6]=((struct Obj00827 *)p)->f3A8;
        d.w[7]=((struct Obj00827 *)p)->f3A4;
        d.w[8]=((struct Obj00827 *)p)->f3B8;
        ((struct Obj00827 *)p)->f8=func_021DAC18(&d,29);
        *state=2;
        break;
    case 2:
        func_0204E720(3,16,0,-1);
        func_021DA8C0(task,3);
        *state=8;
        break;
    case 3:
        func_021DAEF0(((struct Obj00827 *)p)->f8);
        if(func_021DB008(((struct Obj00827 *)p)->f8)) *state=4;
        break;
    case 4:
        func_0204E720(3,0,16,0);
        func_021DA8C0(task,5);
        *state=8;
        break;
    case 5:
        func_021D9288((unsigned int *)(p+312),1);
        func_021DAE1C(((struct Obj00827 *)p)->f8);
        ((struct Obj00827 *)p)->f8=0;
        func_021D694C((u16 *)(p+912),0);
        func_021D6C60(p+660,29);
        ((struct Obj00827 *)p)->f284=func_021D9CA4(1,15,((struct Obj00827 *)p)->f39C,((struct Obj00827 *)p)->f398,29);
        func_021D9FFC(((struct Obj00827 *)p)->f284,10,14);
        func_0207D63C((void *)0x04000050,4,24,15,3);
        func_021D81B0(p,0,29);
        *state=6;
        break;
    case 6:
        func_0204E720(3,16,0,0);
        func_021DA8C0(task,7);
        *state=8;
        break;
    case 7:
        ((struct Obj00827 *)p)->f3C8=(void *)func_0200A0C8(((struct Obj00827 *)p)->f3BC);
        func_021DA8B0(task,(u32)func_021D6E3C);
        break;
    case 8:
        if(!func_0204E804()) func_021DA8C4(task);
        break;
    }
    if(((struct Obj00827 *)p)->f8) func_021DAFCC(((struct Obj00827 *)p)->f8);
}

void func_021D7EAC(void *task,u32 *state,u8 *p)
{
    int result;
    result=func_021DE500(((struct Obj00533 *)p)->f3B0);
    switch(result) {
    case 1: case 2:
        func_021DE550(((struct Obj00533 *)p)->f3B0);
        func_021DA8B0(task,(u32)func_021D6E3C);
        break;
    }
    switch(*state) {
    case 0:
        func_0204E720(3,0,16,0);
        *state=1; return;
    case 1:
        if(!func_0204E804()) {
            func_021D9288((unsigned int *)(p+312),0);
            *state=2; return;
        }
        break;
    case 2:
        if(((struct Obj00533 *)p)->f284) {
            func_021D9E04(((struct Obj00533 *)p)->f284);
            ((struct Obj00533 *)p)->f284=0;
        }
        func_021D6C28(p+660);
        func_021D6948(p+912);
        func_021D96C4(((struct Obj00533 *)p)->f394);
        ((struct Obj00533 *)p)->f394=0;
        *state=3; return;
    case 3:
        *(u8 * *)&((struct Obj00533 *)p)->f3C0=func_02030734(29,40,0,d_021DFB80,2664);
        func_02082BCC(((struct Obj00533 *)p)->f3C0,0,40);
        ((struct Obj22858 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f0=((struct Obj00533 *)p)->f3B8;
        ((struct Obj22859 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f4=0;
        ((struct Obj22860 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f8=1;
        ((struct Obj22861 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f10=0;
        ((struct Obj22862 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f18=0;
        ((struct Obj22863 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->fC=9;
        if(!func_0200A350(((struct Obj00533 *)p)->f3BC)) ((struct Obj22864 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f14=2;
        else ((struct Obj22865 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f14=0;
        func_020312CC((u32)ov115_id,(u32)d_021D6338,(u32)((struct Obj00533 *)p)->f3C0);
        *state=5; return;
    case 5:
        ((struct Obj00533 *)p)->f394=func_021D9624(1,29);
        func_021D6924((u16 *)(p+912),29);
        func_021D6AEC((char *)(p+660),(void *)func_021D9744(((struct Obj00533 *)p)->f394),29);
        ((struct Obj00533 *)p)->f284=func_021D9CA4(1,15,((struct Obj00533 *)p)->f39C,((struct Obj00533 *)p)->f398,29);
        func_021D9FFC(((struct Obj00533 *)p)->f284,10,14);
        func_0207D63C((void *)0x04000050,4,24,15,3);
        func_0203D34C(1,29);
        func_02005D90(1154,65535);
        func_021D9288((unsigned int *)(p+312),1);
        *state=4; return;
    case 4:
        *state=6; return;
    case 6:
        func_0204E720(3,16,0,0);
        *state=7; return;
    case 7:
        if(!func_0204E804()) { *state=8; return; }
        break;
    case 8:
        if(!((struct Obj22866 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f1C) func_021DA8B0(task,(u32)func_021D73DC);
        else func_021DA8B0(task,(u32)func_021D6E3C);
        func_020307B0(((struct Obj00533 *)p)->f3C0);
        break;
    }
}

void func_021D80C0(void *p,int n,char *q) {
 func_021D8198(q);func_021D8380(q);func_021D849C(q);
 if(*(char * *)&((struct Obj00326 *)q)->f0) {func_021DD980(*(char * *)&((struct Obj00326 *)q)->f0);func_021DD1FC(*(void ** *)&((struct Obj00326 *)q)->f4);}
 func_021DA8B8(p);
}

void func_021D80F0(void *a, int *state, u8 *p)
{
    switch (*state) {
    case 0: func_021D9F08(*(u8 * *)&((struct Obj10409 *)p)->f284, ((struct Obj10409 *)p)->f3A0, 22, 1); *state = 1; break;
    case 1: if (func_021D9FF8(((struct Obj10409 *)p)->f284)) func_021DA8B0(a, (u32)func_021D6E3C); break;
    }
}

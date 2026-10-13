/*
 * function: func_021D7EAC
 * address: 0x021D7EAC
 * packet: pkt_ov121_021D7EAC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE500 0x021DE500 thumb ov121
 *   func_021DE550 0x021DE550 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D6E3C 0x021D6E3C thumb ov121
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021D9288 0x021D9288 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021D6C28 0x021D6C28 thumb ov121
 *   func_021D6948 0x021D6948 thumb ov121
 *   func_021D96C4 0x021D96C4 thumb ov121
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   MYSTERY_DATA_IsMainSave 0x0200A350 thumb
 *   PROCSYS_PushGlobal 0x020312CC arm
 *   func_021D9624 0x021D9624 thumb ov121
 *   func_021D6924 0x021D6924 thumb ov121
 *   func_021D9744 0x021D9744 thumb ov121
 *   func_021D6AEC 0x021D6AEC thumb ov121
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_0207D63C 0x0207D63C arm
 *   func_0203D34C 0x0203D34C arm
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_021D73DC 0x021D73DC thumb ov121
 *   func_020307B0 0x020307B0 arm
 *   d_021DFB80 0x021DFB80 data a1
 *   gNetSaveMainProc 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data a1
 */
#include "../include/Obj00533.h"
#include "../include/Obj22858.h"
#include "../include/Obj22859.h"
#include "../include/Obj22860.h"
#include "../include/Obj22861.h"
#include "../include/Obj22862.h"
#include "../include/Obj22863.h"
#include "../include/Obj22864.h"
#include "../include/Obj22865.h"
#include "../include/Obj22866.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021DE500(void *);
typedef signed int     s32;
extern void func_021DE550(char *p);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021D6E3C(void *task, u32 *state, u8 *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_021D9288(unsigned *p, unsigned v);
extern void func_021D9E04(u8 *p);
extern void func_021D6C28(u8 *p);
extern void func_021D6948(void *);
extern void func_021D96C4(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
struct Obj;
extern int MYSTERY_DATA_IsMainSave(struct Obj *a0);
extern void PROCSYS_PushGlobal(u32,u32,u32);
extern u8 *func_021D9624(int arg, u16 heap);
extern void func_021D6924(u16 *p, u16 heap);
extern unsigned func_021D9744(char *p);
extern void func_021D6AEC(char *p, void *owner, u16 heap);
extern void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap);
extern void func_021D9FFC(u8 *p, int a, int b);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_0203D34C(u32,u32);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void func_021D73DC(void *task, u32 *state, u8 *p);
extern u32 func_020307B0(void *p);
extern const char d_021DFB80[];
extern const int gNetSaveMainProc[];
extern char ov115_id[];
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
        if(!MYSTERY_DATA_IsMainSave(((struct Obj00533 *)p)->f3BC)) ((struct Obj22864 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f14=2;
        else ((struct Obj22865 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f14=0;
        PROCSYS_PushGlobal((u32)ov115_id,(u32)gNetSaveMainProc,(u32)((struct Obj00533 *)p)->f3C0);
        *state=5; return;
    case 5:
        ((struct Obj00533 *)p)->f394=func_021D9624(1,29);
        func_021D6924((u16 *)(p+912),29);
        func_021D6AEC((char *)(p+660),(void *)func_021D9744(((struct Obj00533 *)p)->f394),29);
        ((struct Obj00533 *)p)->f284=func_021D9CA4(1,15,((struct Obj00533 *)p)->f39C,((struct Obj00533 *)p)->f398,29);
        func_021D9FFC(((struct Obj00533 *)p)->f284,10,14);
        func_0207D63C((void *)0x04000050,4,24,15,3);
        func_0203D34C(1,29);
        GFL_USE_CancelChangeAndPlayBgm(1154,65535);
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

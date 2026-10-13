/*
 * file:     irc_appbar.c
 * unit:     yes
 * function: func_021B70DC, func_021B71C0, func_021B71E4, func_021B7250, func_021B7254, func_021B7264, func_021B727C, func_021B728C, func_021B72A0, func_021B72A8, func_021B732C, func_021B7384, func_021B739C
 * address:  0x021B70DC
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02028148 0x02028148 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021B73E8 0x021B73E8 thumb ov101
 *   APP_TASKMENU_WIN_IsTouch  0x0202824C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb
 *   APP_TASKMENU_WIN_ResetDecide  0x020282A4  thumb
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb
 *   func_02028178  0x02028178  thumb
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   d_021B7550 0x021B7550 data a1
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb  arm9
 */
#include "../../matched/include/Obj03227.h"
#include "../../matched/include/Obj06364.h"
#include "../../matched/include/Obj02158.h"
#include "../../matched/include/Obj10232.h"
#include "../../matched/include/Obj13722.h"
#include "../../matched/include/Obj13723.h"
#include "../../matched/include/Obj22132.h"
#include "../../matched/include/Obj03228.h"

struct MsgBank;
struct R;
struct Rec;
struct U16Vec;
struct TaskMenuState;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { SIDE_ZERO, SIDE_ONE } Side;

typedef struct { void *str; u16 color,pad; u32 flag; } Desc_021B70DC;

typedef short s16;

typedef struct { unsigned data; u16 tag,pad; unsigned flag; } Desc_021B72A8;

typedef struct { u16 x,y,z; u8 pad,n; } Desc_021B739C;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,u32);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u8 func_020416D4(u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 APP_TASKMENU_WIN_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02028148(unsigned char *);
extern void func_02027FD8(struct TaskMenuState *);
extern void func_020307B0(void *);
extern void func_021B73E8(void *);
extern unsigned int APP_TASKMENU_WIN_IsTouch(void **p);
extern void func_020061E4(u32 a);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern void func_02028178(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204AC18(void *,unsigned,unsigned,u16,u16,u16,unsigned);
extern int func_0204A6C8(void *,unsigned,unsigned,unsigned,unsigned);
extern int func_0204AF28(void *,unsigned,unsigned,unsigned);
extern void func_02049238(void *);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
void *func_021B70DC(u32 a,u32 b,u16 layer,u16 x,u8 y,u32 extra,u32 c,u32 d,u16 heap);
void func_021B71C0(void *p);
void func_021B71E4(int a);
int func_021B7250(int *p);
int func_021B7254(int *p);
void func_021B7264(int p);
int func_021B727C(int p);
void func_021B728C(int p,int b);
void func_021B72A0(int p,int b);
void func_021B72A8(unsigned *p,unsigned b);
void func_021B732C(int *p,unsigned b,int c,int unused,int unused2,u8 d,unsigned e);
void func_021B7384(unsigned p);
void func_021B739C(unsigned *p,unsigned b,int c,unsigned d,u8 e,u16 f);
extern char d_021B7550[];

/*
 * lever: distinct enum first/choice values preserve branch-local setup and saved-register allocation.
 * prototype: own 27F60 fixes layer/x/heap as u16; stack x/heap forward unchanged without truncation.
 * func_02030734 0x02030734 arm
 * func_02082BCC 0x02082BCC arm
 * func_021B732C 0x021B732C thumb ov101
 * func_02027F60 0x02027F60 thumb
 * func_020416D4 0x020416D4 arm
 * func_021B739C 0x021B739C thumb ov101
 * func_02045B38 0x02045B38 arm
 * func_02045EC0 0x02045EC0 arm
 * APP_TASKMENU_WIN_Create 0x02027FEC thumb
 * func_02045808 0x02045808 arm
 * func_02045C04 0x02045C04 arm
 * d_021B7550 0x021B7550 data a1
 */
void *func_021B70DC(u32 a,u32 b,u16 layer,u16 x,u8 y,u32 extra,u32 c,u32 d,u16 heap)
{
    Side side=SIDE_ZERO;
    Desc_021B70DC desc;
    char *p;
    void *bank;
    Side choice,first;
    p=func_02030734(heap,96,0,d_021B7550,125);
    func_02082BCC(p,0,96);
    ((struct Obj03227 *)p)->f3C=layer;
    ((struct Obj03227 *)p)->f44=side-1;
    ((struct Obj03227 *)p)->f48=side-1;
    ((struct Obj03227 *)p)->f54=side;
    ((struct Obj03227 *)p)->f58=heap;
    ((struct Obj03227 *)p)->f5C=1;
    if(layer>=4) { side=1; first=1; choice=4; }
    else { first=0; choice=0; }
    func_021B732C((int *)p,first,choice,extra,x,y,heap);
    ((struct Obj03227 *)p)->f4=func_02027F60(layer,x,c,d,heap);
    func_021B739C((unsigned int *)p,b,a,side,func_020416D4(layer),heap);
    bank=func_02045B38(0,2,49,heap);
    func_02082BCC(&desc,0,12);
    desc.color=0x39e3;
    desc.str=func_02045EC0(bank,8);
    desc.flag=1;
    ((struct Obj03227 *)p)->f0=APP_TASKMENU_WIN_Create((u32)(((struct Obj03227 *)p)->f4),(u32)(&desc),19,21,13,heap);
    func_02045808(desc.str);
    func_02045C04(bank);
    return p;
}

void func_021B71C0(void *p) { func_02028148(*(unsigned char * *)&((struct Obj06364 *)p)->f0); func_021B73E8(p); func_02027FD8(*(struct TaskMenuState * *)&((struct Obj06364 *)p)->f4); func_021B7384((unsigned)p); func_020307B0(p); }


void func_021B71E4(int a)
{
    if (((struct Obj02158 *)a)->f5C != 0) {
        switch (((struct Obj02158 *)a)->f50) {
        case 0:
            ((struct Obj02158 *)a)->f44 = -1;
            if (APP_TASKMENU_WIN_IsTouch((void **)(((struct Obj02158 *)a)->f0))) {
                func_020061E4(0x551);
                APP_TASKMENU_WIN_SetDecide((char *)(((struct Obj02158 *)a)->f0), 1);
                ((struct Obj02158 *)a)->f50 = 1;
            }
            break;
        case 1:
            if (APP_TASKMENU_WIN_IsFinish((u8 *)(((struct Obj02158 *)a)->f0))) {
                APP_TASKMENU_WIN_ResetDecide((struct Obj *)(((struct Obj02158 *)a)->f0));
                APP_TASKMENU_WIN_SetActive((struct Obj *)(((struct Obj02158 *)a)->f0), 0);
                ((struct Obj02158 *)a)->f50 = 2;
            }
            break;
        case 2:
            ((struct Obj02158 *)a)->f44 = 1;
            break;
        }
        func_02028178((u8 *)(((struct Obj02158 *)a)->f0));
    }
}

int func_021B7250(int *p) { return p[17]; }

/*
 * note: Parent-cleared leaf for ov102 021B81B0. Getter starts immediately after separately filed 4-byte 021B7250; 14 bytes of code followed by two zero alignment bytes before 021B7264.
 */
int func_021B7254(int *p) { if(p[20]>0) return 1; return 0; }

/*
 * APP_TASKMENU_WIN_ResetDecide 0x020282A4 thumb
 * APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 */
void func_021B7264(int p) {
 APP_TASKMENU_WIN_ResetDecide((struct Obj *)(((struct Obj10232 *)p)->f0));
 APP_TASKMENU_WIN_SetActive((struct Obj *)(((struct Obj10232 *)p)->f0),0);
 ((struct Obj10232 *)p)->f50=0;
}

int func_021B727C(int p) { if(((struct Obj22132 *)p)->f50) return 1; return 0; }

/*
 * func_02040588 0x02040588 arm
 */
void func_021B728C(int p,int b) {
 ((struct Obj13722 *)p)->f5C=b;
 func_02040588((u8)(((struct Obj13722 *)p)->f3C),(u8)b);
}

void func_021B72A0(int p,int b) {
 ((struct Obj13723 *)p)->f5C=b;
 ((struct Obj13723 *)p)->f50=0;
}

/*
 * func_02028148 0x02028148 thumb
 * func_02045B38 0x02045B38 arm
 * func_02082BCC 0x02082BCC arm
 * func_02045EC0 0x02045EC0 arm
 * APP_TASKMENU_WIN_Create 0x02027FEC thumb
 * func_02045808 0x02045808 arm
 * func_02045C04 0x02045C04 arm
 */
void func_021B72A8(unsigned *p,unsigned b) {
 unsigned q;
 Desc_021B72A8 t;
 if(b==p[21]) return;
 func_02028148((u8 *)p[0]);
 q=(unsigned int)func_02045B38(0,2,0x31,((struct Obj03228 *)p)->f58);
 func_02082BCC(&t,0,12);
 t.tag=0x39e3;
 t.data=(unsigned int)func_02045EC0((struct MsgBank *)q,b+8);
 t.flag=1;
 p[0]=APP_TASKMENU_WIN_Create(p[1],(u32)(&t),0x13,0x15,0xd,((struct Obj03228 *)p)->f58);
 func_02045808((struct U16Vec *)t.data);
 func_02045C04((struct Rec *)q);
 p[21]=b; p[20]=0; p[17]=-1;
}

/*
 * func_020490F4 0x020490F4 arm
 * func_0204AC18 0x0204AC18 arm
 * func_0204A6C8 0x0204A6C8 arm
 * func_0204AF28 0x0204AF28 arm
 * func_02049238 0x02049238 arm
 */
void func_021B732C(int *p,unsigned b,int c,int unused,int unused2,u8 d,unsigned e) {
 void *q;
 q=func_020490F4(0x5e,e);
 p[12]=func_0204AC18(q,0x29,b,d<<5,0,1,e);
 p[13]=func_0204A6C8(q,0x28,0,b,e);
 p[14]=func_0204AF28(q,0x27,0x26,e);
 func_02049238(q);
}

void func_021B7384(unsigned p) { func_0204AFD8(((struct Obj06364 *)p)->f38); func_0204A8D4(((struct Obj06364 *)p)->f34); func_0204ADA4(((struct Obj06364 *)p)->f30); }

void func_021B739C(unsigned *p,unsigned b,int c,unsigned d,u8 e,u16 f) {
 Desc_021B739C t;
 func_02082BCC(&t,0,8);
 t.x=128; t.y=96; t.z=0; t.n=e+1;
 p[2]=(unsigned)func_0204B294((void *)b,p[13],p[12],p[14],&t,d,f);
}

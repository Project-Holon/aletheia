/*
 * file:     pmsiv_menu_p01.c
 * unit:     yes
 * function: func_021BBE8C, func_021BBEF4, func_021BBF54, func_021BC068, func_021BC0CC, func_021BC120, func_021BC160
 * address:  0x021BBE8C
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02005624 0x02005624 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021BBE80 0x021BBE80 thumb ov110
 *   func_02040618 0x02040618 arm
 *   func_0204B4EC 0x0204B4EC arm
 *   func_0204B49C 0x0204B49C arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082A60 0x02082A60 arm
 *   func_020862F0 0x020862F0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 *   func_021BF6E4 0x021BF6E4 thumb ov110
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_021BAC50 0x021BAC50 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../../matched/include/Obj04447.h"
#include "../../matched/include/Obj02816.h"
#include "../../matched/include/Obj01053.h"
#include "../../matched/include/Obj22369.h"
#include "../../matched/include/Obj10276.h"
#include "../../matched/include/Obj02817.h"

struct WinMgr;
struct Node;
struct V3;
struct Obj_021BC160;
typedef unsigned char u8;

typedef signed char s8;

typedef signed short s16_021BBE8C;

typedef unsigned int u32;

typedef unsigned short u16;

typedef short s16_021BBF54;

typedef struct { u8 pad[0x14]; void *desc[2]; void *items[2][2]; } Obj_021BBF54;

typedef short s16_021BC160;

typedef struct { int a,b,c; } Triple;

typedef struct { void *root; u8 pad[0x18]; void *items[2][2]; } Obj_021BC160;

extern void func_02041300(unsigned, int, int, int, u8, u8, u8);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
extern void func_02030EAC(struct Node *n);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void *func_020056A0(void *, void *, unsigned);
extern void func_021BBE80(void);
extern void func_02040618(unsigned,unsigned,unsigned);
extern s16_021BBF54 func_0204B4EC(void *,u16,unsigned);
extern void func_0204B49C(void *,s16_021BBF54,u16,unsigned);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082A60(const void *, void *, int);
extern void func_020862F0(void *, unsigned);
extern u32 func_020307B0(void *p);
extern unsigned func_021BF6D8(u8 *);
extern int func_021BF6E4(u8 *p);
extern void func_0207E3D0(void *,int,int);
extern void func_0207E468(void *,int,int);
extern void func_021BAC50(char *p, struct V3 *out, int i);
extern struct Obj_021BC160 *func_021BAC78(char *p, unsigned int *r, short x, short y, unsigned int a, int mode);
extern void func_0204B3DC(struct Obj_021BC160 *p, u32 v);
void func_021BBE8C(void *unused, u8 *p);
void func_021BBEF4(u8 *p, u8 value);
int func_021BBF54(Obj_021BBF54 *p);
void func_021BC068(u8 *p, void *a);
void func_021BC0CC(u8 *p);
void func_021BC120(u8 *p);
void func_021BC160(Obj_021BC160 *p);

void func_021BBE8C(void *unused, u8 *p)
{
    ((struct Obj04447 *)p)->f1A8 = 0;
    ((struct Obj04447 *)p)->f1AC = 0;
    if (((struct Obj04447 *)p)->f1B8) {
        func_02041300(0, 0, 0, 0, 32, 6, 17);
        func_0202CB4C(((struct Obj04447 *)p)->f1B4, 0, 0, (s8)(-((struct Obj04447 *)p)->f198 / 8));
        func_0202CC58(((struct Obj04447 *)p)->f1B4, 0);
        ((struct Obj04447 *)p)->f1B8 = 0;
    }
}

void func_021BBEF4(u8 *p, u8 value)
{
    p[0x19c] = 0;
    p[0x19d] = value;
    if (((struct Obj02816 *)p)->f1A4) func_02030EAC(((struct Obj02816 *)p)->f1A4);
    ((struct Obj02816 *)p)->f1A4 = func_02005624((u32)func_021BBE80, (u32)p, 1);
    ((struct Obj02816 *)p)->f1A8 = 0;
    ((struct Obj02816 *)p)->f1AC = 0;
    if (((struct Obj02816 *)p)->f1B0) func_02030EAC(((struct Obj02816 *)p)->f1B0);
    ((struct Obj02816 *)p)->f1B0 = func_020056A0(func_021BBE8C, p, 1);
}

/*
 * lever: plain signed-halfword assignments and named coordinate results.
 * prototype: original call truncates space to u16; legacy 02040618 fourth input is unused by 02042360.
 */
int func_021BBF54(Obj_021BBF54 *p)
{
    int delta,i,j;
    u8 *b=(u8 *)p;
    if(b[0x19c]>5) return 1;
    if(b[0x19d]) delta=-8; else delta=8;
    ((struct Obj01053 *)b)->f19A=((struct Obj01053 *)b)->f19A+delta;
    ((struct Obj01053 *)b)->f198=((struct Obj01053 *)b)->f198+delta;
    func_02040618(4,3,((struct Obj01053 *)b)->f19A);
    for(i=0;i<2;i++) {
        s16_021BBF54 pos=func_0204B4EC(p->desc[i],i,1)-delta;
        func_0204B49C(p->desc[i],pos,i,1);
        for(j=0;j<2;j++) {
            s16_021BBF54 pos=func_0204B4EC(p->items[j][i],i,1)-delta;
            func_0204B49C(p->items[j][i],pos,i,1);
        }
    }
    b[0x19c]++;
    if(b[0x19d] && b[0x19c]==7) {
        func_02030EAC(((struct Obj01053 *)b)->f1A4);
        ((struct Obj01053 *)b)->f1A4=0;
        func_02030EAC(((struct Obj01053 *)b)->f1B0);
        ((struct Obj01053 *)b)->f1B0=0;
    }
    ((struct Obj01053 *)b)->f1B8=1;
    return 0;
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021BC068(u8 *p, void *a)
{
    u8 *data;
    void *handle;
    func_02049B68(a, 3, 0, 0, 448, 42);
    func_02049B68(a, 4, 4, 0, 160, 42);
    handle = func_02049F78(a, 6, (u32)((void **)&data), 42);
    func_02082A60(((struct Obj22369 *)data)->fC, p + 0x58, 320);
    func_020862F0(p + 0x58, 320);
    func_020307B0(handle);
}

void func_021BC0CC(u8 *p)
{
    if (func_021BF6D8(*(u8 * *)&((struct Obj10276 *)p)->f4)==2 && (unsigned)func_021BF6E4(*(u8 * *)&((struct Obj10276 *)p)->f4)<5) {
        unsigned n=(unsigned)func_021BF6E4(*(u8 * *)&((struct Obj10276 *)p)->f4)+1;
        func_0207E3D0(p+0x58+n*32,0,32);
        func_0207E468(p+0x58+n*32,0,32);
    } else {
        func_0207E3D0(p+0x58,0,32);
        func_0207E468(p+0x58,0,32);
    }
}

void func_021BC120(u8 *p)
{
    switch (func_021BF6D8(*(u8 * *)&((struct Obj02817 *)p)->f4)) {
    case 0: ((struct Obj02817 *)p)->f38=104; ((struct Obj02817 *)p)->f3A=16; ((struct Obj02817 *)p)->f44=1; break;
    case 1: ((struct Obj02817 *)p)->f38=48; ((struct Obj02817 *)p)->f3A=16; ((struct Obj02817 *)p)->f3C=160; ((struct Obj02817 *)p)->f3E=16; ((struct Obj02817 *)p)->f44=2; break;
    case 2: ((struct Obj02817 *)p)->f44=0; break;
    }
}

void func_021BC160(Obj_021BC160 *p)
{
    Triple t;
    int i,j;
    for (i=0;i<2;i++) {
        func_021BAC50(p->root,(struct V3 *)(&t),i);
        for (j=0;j<2;j++) {
            p->items[j][i]=func_021BAC78(p->root,(unsigned int *)(&t),0,0,2,i+1);
            func_0204B3DC(p->items[j][i],0);
        }
    }
}

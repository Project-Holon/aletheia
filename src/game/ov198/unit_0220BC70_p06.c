/*
 * file:     unit_0220BC70_p06.c
 * unit:     yes
 * function: func_0220E584, func_0220E5FC, func_0220E684, func_0220E6E0, func_0220E74C
 * address:  0x0220E584
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_0202775C 0x0202775C thumb
 *   func_02027758 0x02027758 thumb
 *   func_02027760 0x02027760 thumb
 *   func_02027764 0x02027764 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_020216D4 0x020216D4 thumb
 *   func_0220E7E4 0x0220E7E4 thumb ov198
 *   d_02211DFC 0x02211DFC data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0220AFC4 0x0220AFC4 thumb ov196
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "../../matched/include/Obj00172.h"
#include "../../matched/include/Obj25212.h"
#include "../../matched/include/Obj25213.h"
#include "../../matched/include/Obj25214.h"
#include "../../matched/include/Obj25215.h"
#include "../../matched/include/Obj25216.h"
#include "../../matched/include/Obj25217.h"
#include "../../matched/include/Obj25218.h"
#include "../../matched/include/Obj25219.h"
#include "../../matched/include/Obj25220.h"
#include "../../matched/include/Obj25221.h"
#include "../../matched/include/Obj25222.h"
#include "../../matched/include/Obj14559.h"

struct Obj;
struct Bank;
struct PalAnmSlot;
typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {short x,y,z; u8 a,b;} Point;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(void *,unsigned,unsigned,unsigned,u16);
extern int func_0204AC18(void *,unsigned,unsigned,unsigned,u16,u16,u16);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern unsigned func_020275E4(void);
extern int func_0202775C(int);
extern int func_02027758(void);
extern int func_02027760(int);
extern int func_02027764(int);
extern int func_0204ABF0(void *,unsigned,unsigned,unsigned,u16);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0203D34C(u32 a, u32 b);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_0220E7E4(void *);
extern void func_0204B3B4(struct Obj *p);
extern void func_0220AFC4(u8 *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
void func_0220E584(char *p);
void func_0220E5FC(char *p);
unsigned func_0220E684(char *p,const int *q);
void func_0220E6E0(char *p);
void func_0220E74C(char *p);
extern const int d_02211DFC[][5];

void func_0220E584(char *p)
{
    void *owner;
    owner=func_020490F4(11,(u16)((((struct Obj25212 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10&0x7fff)|0x8000));
    ((struct Obj00172 *)p)->f2504=func_0204A6C8(owner,119,0,1,((struct Obj25213 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f251C=func_0204AC18(owner,116,1,256,4,1,((struct Obj25214 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2534=func_0204AF28(owner,120,121,((struct Obj25215 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}

void func_0220E5FC(char *p)
{
    void *owner;
    int first;
    owner=func_020490F4(func_020275E4(),(u16)((((struct Obj25216 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10&0x7fff)|0x8000));
    ((struct Obj00172 *)p)->f2508=func_0204A6C8(owner,func_0202775C(0),0,1,((struct Obj25217 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2520=func_0204ABF0(owner,func_02027758(),1,0x120,((struct Obj25218 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    first=func_02027760(0);
    ((struct Obj00172 *)p)->f2538=func_0204AF28(owner,first,func_02027764(0),((struct Obj25219 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}

unsigned func_0220E684(char *p,const int *q)
{
    Point point;
    point.x=0;
    point.y=0;
    point.z=0;
    point.a=q[4];
    point.b=q[3];
    return (unsigned)func_0204B294((void *)((struct Obj00172 *)p)->f1EB8,*(unsigned *)(p+q[0]*4+0x24a4),*(unsigned *)(p+q[1]*4+0x250c),*(unsigned *)(p+q[2]*4+0x2524),&point,1,((struct Obj25220 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
}

void func_0220E6E0(char *p)
{
    unsigned i;
    ((struct Obj00172 *)p)->f1EB8=(unsigned int)func_0204B100((unsigned)45,(unsigned)0,(u16)((((struct Obj25221 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10&0x7fff)|0x8000));
    for(i=0;i<41;i++) *(unsigned *)(p+i*4+0x1ebc)=func_0220E684(p,d_02211DFC[i]);
    func_0203D34C(0,((struct Obj25222 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_020216D4((struct PalAnmSlot *)(((struct Obj00172 *)p)->f1D8),(int)3,(int)0,(int)0x1e0);
    func_0220E7E4(p);
}

void func_0220E74C(char *p)
{
    unsigned i;
    for(i=0;i<41;i++) func_0204B3B4(*(void **)(p+i*4+0x1ebc));
    func_0220AFC4(((struct Obj14559 *)p)->f2188);
    for(i=0;i<26;i++) func_0204A8D4((u32)(*(void **)(p+i*4+0x24a4)));
    for(i=0;i<6;i++) func_0204ADA4((u32)(*(void **)(p+i*4+0x250c)));
    for(i=0;i<6;i++) func_0204AFD8((u32)(*(void **)(p+i*4+0x2524)));
    func_0204B1CC(((struct Obj14559 *)p)->f1EB8);
}

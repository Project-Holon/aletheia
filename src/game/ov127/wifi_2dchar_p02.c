/*
 * file:     wifi_2dchar_p02.c
 * unit:     yes
 * function: func_021C4214, func_021C4224, func_021C4230, func_021C424C, func_021C425C, func_021C4268, func_021C4270, func_021C4274, func_021C4280, func_021C428C, func_021C42A8
 * address:  0x021C4214
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B800  0x0204B800  arm
 *   func_0204B838  0x0204B838  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_0204B908 0x0204B908 arm
 *   func_0204B918 0x0204B918 arm
 *   func_0204B528 0x0204B528 arm
 *   tbl_021C5FBC  0x021C5FBC  data  a4
 */
#include "../../matched/include/Obj23014.h"
#include "../../matched/include/Obj23015.h"
#include "../../matched/include/Obj10464.h"
#include "../../matched/include/Obj14015.h"
#include "../../matched/include/Obj23016.h"
#include "../../matched/include/Obj23017.h"
#include "../../matched/include/Obj23018.h"
#include "../../matched/include/Obj23019.h"
#include "../../matched/include/Obj23020.h"
#include "../../matched/include/Obj23021.h"
#include "../../matched/include/Obj14016.h"

struct Node;
struct Obj;
struct Actor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short s16;

typedef struct Pt { u16 x,y; } Pt;

struct obj {
    int pad0[3];
    int idx;
    int pad1;
    u16 f14;
};

extern void func_0204B800(struct Node *node, u32 val);
extern int func_0204B838(int a0);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u32 func_0204B3F4(struct Obj *p);
/* Callee and its forwarding target read only r0/r1; legacy r2/r3 inputs are unused. */
extern void func_0204B908(int a0, int a1);
extern u16 func_0204B918(struct Obj *p);
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
void func_021C4214(u8 *p, u32 v);
int func_021C4224(u8 *p);
void func_021C4230(char *p, int a);
void func_021C424C(char *p, int a);
int func_021C425C(char *p);
void *func_021C4268(u8 *p);
u32 func_021C4270(char *p);
void func_021C4274(char *p,u32 a);
int func_021C4280(char *p);
void func_021C428C(char *p,int x,int y);
void func_021C42A8(struct obj *p, int idx, int a);


/*
 * Addresses are Black-image addresses.
 */
void func_021C4214(u8 *p, u32 v)
{
    func_0204B800(((struct Obj23014 *)p)->f4, (u8)v);
}


/*
 * Leaf of ov099 func_021B989C's callee func_021C5858 (a forwarder to here).
 */
int func_021C4224(u8 *p)
{
    return func_0204B838((int)(((struct Obj23015 *)p)->f4));
}


void func_021C4230(char *p, int a)
{
    func_0204B3DC(((struct Obj10464 *)p)->f4, a);
    if (((struct Obj10464 *)p)->f8 != 0)
        func_0204B3DC(((struct Obj10464 *)p)->f8, a);
}


void func_021C424C(char *p, int a)
{
    if (((struct Obj14015 *)p)->f8 != 0)
        func_0204B3DC(((struct Obj14015 *)p)->f8, a);
}


/*
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=0x0204B3F4; bx r3.
 * Leaf of ov127 func_021C5834 (blocker of ov099 func_021BA2D4).
 */
int func_021C425C(char *p)
{
    return func_0204B3F4(((struct Obj23016 *)p)->f4);
}

void *func_021C4268(u8 *p)
{
    return ((struct Obj23018 *)(*(u8 * *)&((struct Obj23017 *)p)->f0))->f10;
}


u32 func_021C4270(char *p) { return ((struct Obj23019 *)p)->fC; }

void func_021C4274(char *p,u32 a) { func_0204B908(((struct Obj23020 *)p)->f4,a); }

int func_021C4280(char *p) { return func_0204B918(((struct Obj23021 *)p)->f4); }

/*
 * extent: trailing 2-byte alignment padding only.
 */
void func_021C428C(char *p,int x,int y) { Pt pt; if(((struct Obj14016 *)p)->f8) { pt.x=x+8; pt.y=y+14; func_0204B528(((struct Obj14016 *)p)->f8,&pt); } }


extern void (*tbl_021C5FBC[])(struct obj *, int);


/*
 * lever: the indirect callback receives the object in r0 and payload in r1;
 * declaring both arguments preserves p and restores both store ordering and table register allocation.
 *
 * Addresses are Black-image addresses.
 */
void func_021C42A8(struct obj *p, int idx, int a)
{
    p->f14 = 0;
    p->idx = idx;
    if (tbl_021C5FBC[idx] != 0)
        tbl_021C5FBC[idx](p,a);
}

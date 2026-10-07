/*
 * file:     sta_act_light_p09.c
 * unit:     yes
 * function: func_021F8084, func_021F80A0, func_021F80B0, func_021F80D4, func_021F8120, func_021F812C, func_021F8140
 * address:  0x021F8084
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F539C 0x021F539C thumb ov112
 *   func_021F53B4 0x021F53B4 thumb ov112
 *   func_021F5424 0x021F5424 thumb ov112
 *   func_021F53CC 0x021F53CC thumb ov112
 *   func_021F5374 0x021F5374 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_0204F720 0x0204F720 arm
 *   func_021F5388 0x021F5388 thumb ov112
 *   func_021F5414 0x021F5414 thumb ov112
 */
#include "../../matched/include/Obj13844.h"
#include "../../matched/include/Obj13845.h"
#include "../../matched/include/Obj13846.h"
#include "../../matched/include/Obj22568.h"
#include "../../matched/include/Obj10327.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 pad0[0x4c]; int zero; u8 pad50[8]; int target; } Obj;

typedef struct { int pad[33]; int a; int pad2[17]; int b; } Slot;

extern void func_021F539C(void **p);
extern void func_021F53B4(int);
extern void func_021F5424(int, int);
extern void func_021F53CC(int, unsigned int);
extern void func_021F5374(int *p, int b);
extern void func_021F4E6C(u8 *p, u8 *e, u32 value);
extern void func_0204F720(void *p, u32 idx, u32 *flag);
extern int func_021F5388(u8 **p);
extern void func_021F5414(int a, int b);
void func_021F8084(void *unused,u32 *p,const u32 *q);
void func_021F80A0(int a,u8 *p);
void func_021F80B0(int a, Obj *b);
void func_021F80C8(int a, Obj *b, unsigned int c);
void func_021F80D4(char *p, char *q, int v);
int func_021F8120(int a,u8 *p);
int func_021F812C(int unused, int *p, int flag);
void func_021F8140(int a,u8 *p,int b);

void func_021F8084(void *unused,u32 *p,const u32 *q) { p[12]=q[0]; p[13]=q[1]; p[14]=q[2]; if(p[4]==1) p[13]=0; p[1]=1; }

void func_021F80A0(int a,u8 *p) { func_021F539C(((struct Obj13844 *)p)->f58); ((struct Obj13844 *)p)->f4C=1; }

/*
 * Struct parameter fixes the zero/load/store scheduling. The extent's
 * 021F80C8 tail stub is included; 021F53CC has its own verified shard.
 */
void func_021F80B0(int a, Obj *b)
{
    func_021F53B4(b->target);
    b->zero = 0;
    func_021F5424(b->target, 0);
}

void func_021F80C8(int a, Obj *b, unsigned int c)
{
    func_021F53CC(b->target, c);
}

/*
 * note: handed label 021F80D6 follows the parameter-home push.
 */
void func_021F80D4(char *p, char *q, int v) {
    int i;
    int value = v;
    func_021F5374((int *)(((struct Obj13846 *)q)->f58), value);
    for (i = 0; i < 9; i++) {
        if (((Slot *)(q + i * 4))->a != 0 && ((Slot *)(q + i * 4))->b == 1)
            func_021F4E6C((u8 *)(((struct Obj13845 *)p)->f10), (u8 *)(((Slot *)(q + i * 4))->a), value);
    }
    func_0204F720((void *)(((struct Obj13845 *)p)->f8), ((struct Obj13846 *)q)->f5C, (u32 *)(&v));
}

/*
 * extent: Existing matched follower ov112_func_021F812C.c follows.
 */
int func_021F8120(int a,u8 *p) { return func_021F5388(((struct Obj22568 *)p)->f58); }

/*
 * note: parent-coordinated blocker leaf for ov132 021FB258.
 */
int func_021F812C(int unused, int *p, int flag)
{
    if (p[5] == 1) p[21] = 0;
    else p[21] = flag;
    p[1] = 1;
    return 1;
}

void func_021F8140(int a,u8 *p,int b) { ((struct Obj10327 *)p)->f8=b; func_021F5414((int)(((struct Obj10327 *)p)->f58),b); ((struct Obj10327 *)p)->f4=1; }

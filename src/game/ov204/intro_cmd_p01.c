/*
 * file:     intro_cmd_p01.c
 * unit:     yes
 * function: func_021BE328, func_021BE360, func_021BE374, func_021BE398, func_021BE3A4, func_021BE3B8, func_021BE3CC, func_021BE3DC, func_021BE3EC, func_021BE420, func_021BE430, func_021BE44C, func_021BE460, func_021BE478, func_021BE4AC, func_021BE4B8, func_021BE510, func_021BE524, func_021BE54C, func_021BE560, func_021BE578, func_021BE61C, func_021BE6A4, func_021BE6B4, func_021BE6E8, func_021BE6F8, func_021BE708, func_021BE770, func_021BE78C, func_021BE7A8, func_021BE838, func_021BE864, func_021BE874, func_021BE884, func_021BE898
 * address:  0x021BE328
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_02023EF4 0x02023EF4 thumb
 *   func_02024004 0x02024004 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02006148 0x02006148 thumb
 *   func_020062BC 0x020062BC thumb
 *   func_02006268 0x02006268 thumb
 *   func_020061F8 0x020061F8 thumb
 *   func_021BF204 0x021BF204 thumb ov204
 *   d_021C09D4 0x021C09D4 data a4
 *   func_021BF23C 0x021BF23C thumb ov204
 *   func_021BF2F4 0x021BF2F4 thumb ov204
 *   func_021BF2D4 0x021BF2D4 thumb ov204
 *   func_021BF624 0x021BF624 thumb ov204
 *   func_021BF67C 0x021BF67C thumb ov204
 *   func_021BF7CC 0x021BF7CC thumb ov204
 *   d_021BFFE4 0x021BFFE4 data a1
 *   func_021BF720 0x021BF720 thumb ov204
 *   func_021BF744 0x021BF744 thumb ov204
 *   func_021BF77C 0x021BF77C thumb ov204
 *   func_021BF788 0x021BF788 thumb ov204
 *   func_021BF804 0x021BF804 thumb ov204
 *   func_021BF794 0x021BF794 thumb ov204
 *   func_021BF2E0 0x021BF2E0 thumb ov204
 *   func_021BD2B0 0x021BD2B0 thumb
 *   func_021BD368 0x021BD368 thumb ov088
 *   func_021BD380 0x021BD380 thumb ov088
 *   func_021BD374 0x021BD374 thumb ov088
 *   func_021BD39C 0x021BD39C thumb ov088
 *   func_021BD3A0 0x021BD3A0 thumb ov088
 *   func_021BF560 0x021BF560 thumb ov204
 *   func_021BF580 0x021BF580 thumb ov204
 *   func_020083EC 0x020083EC thumb
 *   func_0200854C 0x0200854C thumb
 *   func_02006238  0x02006238  thumb
 *   func_02006A64  0x02006A64  thumb
 *   func_02006BD0  0x02006BD0  thumb
 *   func_021BF864  0x021BF864  thumb ov204
 *   func_0207D63C 0x0207D63C arm
 *   func_021BFCE8 0x021BFCE8 thumb ov204
 *   func_021BFAE4 0x021BFAE4 thumb
 *   func_021BFBC8 0x021BFBC8 thumb
 *   func_021BFA40 0x021BFA40 thumb ov204
 *   func_021BFAE8 0x021BFAE8 thumb ov204
 *   func_021BFB2C 0x021BFB2C thumb ov204
 *   func_020362DC 0x020362DC arm
 */
#include "../../matched/include/Obj25350.h"
#include "../../matched/include/Obj14608.h"
#include "../../matched/include/Obj25352.h"
#include "../../matched/include/Obj10874.h"
#include "../../matched/include/Obj25353.h"
#include "../../matched/include/Obj25354.h"
#include "../../matched/include/Obj25355.h"
#include "../../matched/include/Obj25357.h"
#include "../../matched/include/Obj25359.h"
#include "../../matched/include/Obj04609.h"
#include "../../matched/include/Obj05529.h"
#include "../../matched/include/Obj25360.h"
#include "../../matched/include/Obj14612.h"
#include "../../matched/include/Obj25361.h"
#include "../../matched/include/Obj25362.h"
#include "../../matched/include/Obj05530.h"
#include "../../matched/include/Obj25363.h"
#include "../../matched/include/Obj25365.h"
#include "../../matched/include/Obj25366.h"
#include "../../matched/include/Obj08382.h"
#include "../../matched/include/Obj25369.h"
#include "../../matched/include/Obj25370.h"
#include "../../matched/include/Obj25372.h"
#include "../../matched/include/Obj25374.h"
#include "../../matched/include/Obj03920.h"

struct Sub0200852CObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef enum { B_FALSE, B_TRUE } Bool;

extern void func_0204E720(unsigned,int,int,int);
extern int func_0204E804(void);
extern void func_02023F60(u32 a0, u32 a1, u32 mask);
extern void func_02023EF4(int, int, int, int, int);
extern int func_02024004(int a);
extern void func_02005D90(u32, u32);
extern int func_02005F38(void);
extern void func_02005E30(u32 a);
extern void func_02005DF8(u32 a);
extern void func_020061E4(unsigned),func_020062BC(int,unsigned),func_02006268(int,unsigned,unsigned,unsigned);
extern int func_02006148(unsigned);
extern void func_020061F8(int);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_021BF204(char *,void *,unsigned short);
extern void func_021BF23C(char *,void *,int);
extern int func_021BF2F4(char *);
extern void func_021BF2D4(u8 *p);
extern void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i);
extern void func_021BF67C(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i);
extern void func_021BF7CC(u8 *p, u8 index, int flag);
extern void func_021BF720(u8 *p, int flag, u8 index);
extern void func_021BF744(char *p, unsigned int i, unsigned int flag, unsigned int v);
extern unsigned func_021BF77C(char *,unsigned char);
extern void func_021BF788(u8 *p, u8 index);
extern int func_021BF804(char *p, unsigned int i, int step, int limit);
extern void func_021BF794(u8 *p, u8 index, u32 alpha);
extern u32 func_021BF2E0(u8 *p);
extern void func_021BD2B0(int);
extern void func_021BD368(unsigned char *);
extern int func_021BD380(unsigned char *);
extern void func_021BD374(unsigned char *p);
extern void func_021BD39C(int);
extern int func_021BD3A0(unsigned char *p);
extern void func_021BF560(u8 *p);
extern void func_021BF580(u8 *p);
extern void func_020083EC(u16*,u32);
extern void func_0200854C(struct Sub0200852CObj*,u32);
extern void func_020061E4(u32);
extern int  func_02006238(void);
extern int func_02006A64(u32 idx);
extern u32 func_02006BD0(u32 i);
extern int func_021BF864(char *p, int delta, int limit);
extern void func_0207D63C(void*,int,int,int,int);
extern void func_021BFCE8(u32*,u32,u32,u32);
extern void func_021BFAE4(char *p, int v);
extern void func_021BFBC8(char *p, unsigned value);
extern int func_021BFA40(char*);
extern void func_021BFAE8(char *,u32);
extern int func_021BFB2C(char *);
int func_021BE328(char *p,int *state,int *q);
u32 func_021BE360(u32 a, u32 b, u32 *c);
int func_021BE374(int a0, int a1, int *src);
int func_021BE398(void);
u32 func_021BE3A4(u32 a, u32 b, u32 *c);
u32 func_021BE3B8(void);
int func_021BE3CC(int a, int b, int *p);
int func_021BE3DC(int a, int b, int *p);
int func_021BE3EC(char *p,int *state,unsigned *q);
int func_021BE420(int a, int b, int *p);
u32 func_021BE430(void);
int func_021BE44C(char *p,int *state,unsigned *q);
int func_021BE460(char *p,int *state,int *q);
int func_021BE478(char *p,int *state,unsigned *q);
int func_021BE4AC(char *p,int *state,int *q);
int func_021BE4B8(char *p, int unused, unsigned *q);
int func_021BE510(char *p,int *state,int *q);
int func_021BE524(char *p,int *state,unsigned *q);
unsigned func_021BE53C(char *p,int *state,unsigned *q);
int func_021BE54C(char *p,int *state,unsigned *q);
int func_021BE560(char *p,int *state,int *q);
int func_021BE578(char *p, int *state, unsigned *q);
int func_021BE61C(char *p, int *state, unsigned *q);
int func_021BE6A4(char *a);
int func_021BE6B4(char *p,int *state,unsigned *q);
int func_021BE6E8(char *a);
int func_021BE6F8(char *a);
int func_021BE708(char *p, int *state);
int func_021BE770(u8*p,u32 unused,u32*q);
int func_021BE78C(u8*p,u32 unused,u32*q);
int func_021BE7A8(u8 *p, u32 *q);
int func_021BE838(u8*p,u32 unused,u32*q);
int func_021BE864(char *a, int b, int *p);
int func_021BE874(char *a, int b, int *p);
int func_021BE884(u8*p);
int func_021BE898(char *p,u32 *q);
extern const char d_021BFFE4[];

int func_021BE328(char *p,int *state,int *q){switch(*state){case 0:func_0204E720(q[0],q[1],q[2],q[3]);(*state)++;break;case 1:if(func_0204E804()==0)return 1;break;}return 0;}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021BE360(u32 a, u32 b, u32 *c)
{
    func_02023F60((s16)*c, 0x1d, 1);
    return 1;
}


int func_021BE374(int a0, int a1, int *src)
{
    func_02023EF4((unsigned char)src[0], (short)src[1], (short)src[2], 0x1d, 1);
    return 1;
}

int func_021BE398(void) {func_02024004(1);return 1;}


u32 func_021BE3A4(u32 a, u32 b, u32 *c)
{
    func_02005D90(*c, 0xffff);
    return 1;
}


u32 func_021BE3B8(void)
{
    if (func_02005F38() != 0) {
        return 1;
    }
    return 0;
}


int func_021BE3CC(int a, int b, int *p)
{
    func_02005E30((unsigned short)*p);
    return 1;
}


int func_021BE3DC(int a, int b, int *p)
{
    func_02005DF8((unsigned short)*p);
    return 1;
}

int func_021BE3EC(char *p,int *state,unsigned *q){int i;func_020061E4(q[0]);i=func_02006148(q[0]);if(q[1])func_020062BC(i,q[1]);if(q[2])func_02006268(i,-1,-1,q[2]);return 1;}


int func_021BE420(int a, int b, int *p)
{
    func_020061F8(func_02006148(*p));
    return 1;
}


u32 func_021BE430(void)
{
    if (func_02035C60() != 0 || func_020362DC() != 0) {
        return 1;
    }
    return 0;
}

int func_021BE44C(char *p,int *state,unsigned *q){func_021BF204(*(char * *)&((struct Obj25350 *)p)->f18,(void *)q[0],q[1]);return 1;}

extern int (*const d_021C09D4[])(char *,int);

int func_021BE460(char *p,int *state,int *q){d_021C09D4[q[0]](p,q[1]);return 1;}

int func_021BE478(char *p,int *state,unsigned *q){switch(*state){case 0:func_021BF23C(*(char * *)&((struct Obj14608 *)p)->f18,(void *)q[0],q[1]);(*state)++;break;case 1:if(func_021BF2F4(*(char * *)&((struct Obj14608 *)p)->f18))return 1;break;}return 0;}

int func_021BE4AC(char *p,int *state,int *q){func_021BF2D4((u8 *)(*(char * *)&((struct Obj25352 *)p)->f18));return 1;}

int func_021BE4B8(char *p, int unused, unsigned *q)
{
    if (q[1] == 0) {
        func_021BF624(((struct Obj10874 *)p)->f8, q[2], q[3], 0, (void *)d_021BFFE4, q[0]);
        func_021BF7CC(((struct Obj10874 *)p)->f8, q[0], 1);
    } else {
        func_021BF67C(((struct Obj10874 *)p)->f8, q[2], q[3], 0x1000, q[1], q[0]);
    }
    return 1;
}

int func_021BE510(char *p,int *state,int *q){func_021BF720(((struct Obj25353 *)p)->f8,q[1],q[0]);return 1;}

/*
 * follower: tail-call stub 0x021BE53C included; function_starts seed.
 */
int func_021BE524(char *p,int *state,unsigned *q){func_021BF744(*(char * *)&((struct Obj25354 *)p)->f8,(unsigned char)q[0],q[1],q[2]);return 1;}

unsigned func_021BE53C(char *p,int *state,unsigned *q){return func_021BF77C(*(char * *)&((struct Obj25355 *)p)->f8,q[0]);}

int func_021BE54C(char *p,int *state,unsigned *q){func_021BF788((u8 *)(*(char * *)&((struct Obj25357 *)p)->f8),q[0]);return 1;}

int func_021BE560(char *p,int *state,int *q){return func_021BF804(*(char * *)&((struct Obj25359 *)p)->f8,(unsigned char)q[0],q[1],q[2]);}

int func_021BE578(char *p, int *state, unsigned *q)
{
    switch (*state) {
    case 0:
        if (q[1] != 0)
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)1);
        else
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)31);
        func_021BF720(((struct Obj04609 *)p)->f8, 1, q[0]);
        state[1] = 31;
        ++*state;
        break;
    case 1:
        state[1] -= 2;
        if (state[1] <= 0) {
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)31);
            func_021BF720(((struct Obj04609 *)p)->f8, q[1], q[0]);
            return 1;
        }
        if (q[1] == 1)
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)(31 - state[1]));
        else if (q[1] == 0)
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)state[1]);
        break;
    }
    return 0;
}

int func_021BE61C(char *p, int *state, unsigned *q)
{
    unsigned index = q[0];
    unsigned other = q[1];
    switch (*state) {
    case 0:
        func_021BF23C(((struct Obj05529 *)p)->f18, (void *)index, q[2]);
        ++*state;
        break;
    case 1:
        if (func_021BF2F4(((struct Obj05529 *)p)->f18) != 0) {
            func_021BF7CC(((struct Obj05529 *)p)->f8, other, 1);
            return 1;
        }
        switch (func_021BF2E0(((struct Obj05529 *)p)->f18)) {
        case 1:
            func_021BF7CC(((struct Obj05529 *)p)->f8, other, 1);
            state[1] = 0;
            break;
        case 0:
            func_021BF7CC(((struct Obj05529 *)p)->f8, other, state[1] % 12 < 6 ? 1 : 0);
            state[1]++;
            break;
        case 2:
            break;
        }
        break;
    }
    return 0;
}


int func_021BE6A4(char *a)
{
    func_021BD2B0(((struct Obj25360 *)a)->fA4);
    return 1;
}

int func_021BE6B4(char *p,int *state,unsigned *q){switch(*state){case 0:func_021BD368(*(unsigned char * *)&((struct Obj14612 *)p)->fA4);(*state)++;break;case 1:if(func_021BD380(*(unsigned char * *)&((struct Obj14612 *)p)->fA4)==1)return 1;break;}return 0;}


int func_021BE6E8(char *a)
{
    func_021BD374((unsigned char *)(((struct Obj25361 *)a)->fA4));
    return 1;
}


/*
 * UNBLOCKED: 0x021BD39C is now an EXACT entry in layout/matched/ov088 (the
 * only overlay in the window that does not overlap the caller's ov204), so
 * the bl site resolves as matched and the verdict promoted to EXACT.
 */
int func_021BE6F8(char *a)
{
    func_021BD39C(((struct Obj25362 *)a)->fA4);
    return 1;
}

int func_021BE708(char *p, int *state)
{
    switch (*state) {
    case 0:
        if (func_021BD3A0(((struct Obj05530 *)p)->fA4) == 1)
            return 1;
        func_021BF23C(((struct Obj05530 *)p)->f18, (void *)5, 0);
        ++*state;
        break;
    case 1:
        if (func_021BF2F4(((struct Obj05530 *)p)->f18) == 1) {
            func_021BF560(((struct Obj05530 *)p)->f18);
            ++*state;
        }
        break;
    case 2:
        if (func_021BD3A0(((struct Obj05530 *)p)->fA4) == 1) {
            func_021BF580(((struct Obj05530 *)p)->f18);
            return 1;
        }
        break;
    }
    return 0;
}

int func_021BE770(u8*p,u32 unused,u32*q){u16*obj=*(u16* *)&((struct Obj25365 *)(*(u8* *)&((struct Obj25363 *)p)->f4))->f4;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;func_020083EC(obj,flag);return 1;}

/*
 * prototype: 0200854C widened to u32: original has no byte truncation; its u8 prototype added a shift pair.
 */
int func_021BE78C(u8*p,u32 unused,u32*q){struct Sub0200852CObj*obj=**(struct Sub0200852CObj** *)&((struct Obj25366 *)p)->f4;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;func_0200854C(obj,flag);return 1;}


int func_021BE7A8(u8 *p, u32 *q)
{
    switch (*q) {
    case 0:
        if (q[1] == 3) {
            q[1] = 0;
            (*q)++;
        } else {
            q[1] = q[1] + 1;
        }
        break;
    case 1:
        if (func_021BF864((char *)(((struct Obj08382 *)p)->f8), 0x1000, 0xFFFF4800) == 1) {
            func_020061E4(0x7F5);
            (*q)++;
        }
        break;
    case 2:
        if (func_02006238() == 0) {
            func_021BF744((char *)(((struct Obj08382 *)p)->f8), 1, 0, 1);
            func_02006A64(*(u32 *)(((struct Obj08382 *)p)->f4 + 0x10));
            (*q)++;
        }
        break;
    case 3:
        if (func_02006BD0(*(u32 *)(((struct Obj08382 *)p)->f4 + 0x10)) == 0) {
            *q = 0;
            return 1;
        }
        break;
    }
    return 0;
}

int func_021BE838(u8*p,u32 unused,u32*q){func_0207D63C((void*)0x04000050,1,9,0,0);func_021BFCE8(*(u32* *)&((struct Obj25369 *)p)->f10,q[0],q[1],0);return 1;}


int func_021BE864(char *a, int b, int *p)
{
    func_021BFAE4((char *)(((struct Obj25370 *)a)->fC), *p);
    return 1;
}


int func_021BE874(char *a, int b, int *p)
{
    func_021BFBC8((char *)(((struct Obj25372 *)a)->fC), *p);
    return 1;
}

int func_021BE884(u8*p){if(func_021BFA40(*(char* *)&((struct Obj25374 *)p)->fC))return 1;return 0;}

/*
 * lever: load the case-2 object once before q[1]'s comparison and reuse
 *   it in both arms; repeated arm loads gave 220 bytes/80 different.
 */
int func_021BE898(char *p,u32 *q)
{
    void *obj;
    switch (*q) {
    case 0:
        func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,0);
        *q=4;
        break;
    case 1:
        if (func_020362DC()&16) {
            if (q[1]!=1) {
                func_020061E4(0x548);
                func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,2);
                q[1]=1;
                *q=4;
            }
        } else if (func_020362DC()&32) {
            if (q[1]!=0) {
                func_020061E4(0x548);
                func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,1);
                q[1]=0;
                *q=4;
            }
        } else if (func_020362DC()&1) {
            func_020061E4(0x54D);
            (*q)++;
        }
        break;
    case 2:
        obj=**(void ** *)&((struct Obj03920 *)p)->f4;
        if (q[1]==0) {
            func_0200854C(obj,0);
            func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,3);
        } else {
            func_0200854C(obj,1);
            func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,4);
        }
        (*q)++;
        break;
    case 3:
        if (func_021BFB2C(*(char * *)&((struct Obj03920 *)p)->fC)!=0) return 1;
        break;
    case 4:
        if (func_021BFB2C(*(char * *)&((struct Obj03920 *)p)->fC)!=0) *q=1;
        break;
    }
    return 0;
}

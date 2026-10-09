/*
 * file:     unit_021B7518_p03.c
 * unit:     yes
 * function: func_021B86DC, func_021B86E4, func_021B8714, func_021B871C, func_021B8724, func_021B873C, func_021B8748, func_021B8750, func_021B8778, func_021B87E8
 * address:  0x021B86DC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200CF28  0x0200CF28  thumb
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_021B8834  0x021B8834  thumb  ov093
 *   func_021B88EC  0x021B88EC  thumb  ov093
 *   func_021B8C50  0x021B8C50  thumb  ov093
 */
#include "../../matched/include/Obj18129.h"
#include "../../matched/include/Obj20957.h"
#include "../../matched/include/Obj20958.h"
#include "../../matched/include/Obj20959.h"
#include "../../matched/include/Obj20961.h"
#include "../../matched/include/Obj18131.h"
#include "../../matched/include/Obj01889.h"
#include "../../matched/include/Obj20962.h"

struct QF;
struct Blk37;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Unk021B8CB0 { u32 f0; u32 mode; };

extern u16 func_021D5444(struct QF *p);
extern int func_0200CED4(void *,unsigned int);
u16 func_0200CF28(struct Blk37 *p);
extern unsigned int func_021B86B8(void *);
extern void *func_021D5844(void *);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern u8 func_021B8834(void *p, u32 k, u8 v, u8 *out);
extern u8 func_021B88EC(void *p, u32 k, u32 v, u8 *out);
extern u8 func_021B8C50(char **p, u32 v, int k);
u16 func_021B86DC(void **p);
int func_021B86E4(unsigned int **p);
char *func_021B8714(char **p);
int func_021B871C(char *p);
int func_021B8724(char *p,void *m);
u32 func_021B873C(char **p);
u32 func_021B8748(void **p);
void func_021B8750(char *p,unsigned char k,void *m);
u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
u8 func_021B87E8(void *p, u32 k, u32 v, u8 *out);


/*
 * double deref u16
 */
u16 func_021B86DC(void **p)
{
    return ((struct Obj18129 *)((u8 *)*p))->f1A;
}

int func_021B86E4(unsigned int **p) { switch(**p) { case 0:return 0; case 1:return 1; case 2:return 2; case 3:return 2; default:return 1; } }

char *func_021B8714(char **p)
{
    return *p + 8;
}


int func_021B871C(char *p)
{
    return ((struct Obj20957 *)p)->fC0;
}

int func_021B8724(char *p,void *m) { unsigned int s=func_021D5444(m); return func_0200CED4(((struct Obj20959 *)(*(char * *)&((struct Obj20958 *)p)->f0))->f68,s); }

u32 func_021B873C(char **p)
{
    return func_0200CF28((struct Blk37 *)(((struct Obj20961 *)(*p))->f68));
}


/*
 * double deref: *(u32*)(*p + 0x58)
 */
u32 func_021B8748(void **p)
{
    return ((struct Obj18131 *)((u8 *)*p))->f58;
}

void func_021B8750(char *p,unsigned char k,void *m) { if(func_021B86B8(p)<=1 && k!=0) func_0200CFA0(((struct Obj20962 *)(*(char * *)&((struct Obj01889 *)p)->f0))->f68,func_021D5844(m)); }


u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out)
{
    u8 hi = k >> 8;
    u8 lo = k;

    if (hi == 0) {
        *out = lo;
        return *out != 6;
    }
    if (lo != 6) {
        switch ((*p)->mode) {
        case 0:
        default:
            return func_021B87E8(p, hi, lo, out);
        case 1:
            return func_021B8834(p, hi, lo, out);
        case 2:
            return func_021B88EC(p, hi, lo, out);
        case 3:
            return func_021B87E8(p, hi, lo, out);
        }
    }
    *out = 6;
    return 0;
}


u8 func_021B87E8(void *p, u32 k, u32 v, u8 *out)
{
    switch (k) {
    case 0:
    case 4:
    case 7:
    default:
        return 0;
    case 1:
    case 2:
    case 6:
        *out = func_021B8C50(p, v, 0);
        break;
    case 3:
        *out = v;
        break;
    case 5:
    case 8:
        out[0] = 0;
        out[1] = 1;
        return 2;
    }
    return 1;
}

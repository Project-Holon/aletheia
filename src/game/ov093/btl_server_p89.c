/*
 * file:     btl_server_p89.c
 * unit:     yes
 * function: func_021C814C, func_021C815C, func_021C8168, func_021C8174, func_021C8180, func_021C818C, func_021C81C8, func_021C81D0
 * address:  0x021C814C
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
 *   func_0689D588 0x0689D588 thumb ov095
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021B8714  0x021B8714  thumb  ov093
 *   func_021B8670  0x021B8670  thumb  ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_0201B718 0x0201B718 thumb
 *   func_021BC948   0x021BC948  thumb ov093
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 */
#include "../../matched/include/Obj26329.h"
#include "../../matched/include/Obj26330.h"
#include "../../matched/include/Obj18335.h"
#include "../../matched/include/Obj18336.h"
#include "../../matched/include/Obj18337.h"
#include "../../matched/include/Obj13341.h"

struct QF;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_0689D588(u8 *, int);
extern u32 func_021B8588(void **p);
extern void *func_021B86B8(void ***p);
char *func_021B8714(char **p);
unsigned int func_021B8670(unsigned int **p);
extern u8 *func_021B9934(char *p, int i);
extern u16 func_021D5444(struct QF *p);
extern unsigned int func_0201B718(void *, unsigned int, unsigned int, unsigned int);
extern u16 func_021BC948(u8 *p, u8 *x, int flag);
extern void func_021BD2B4(u8 *it, u8 **q);
extern int func_021BD34C(u8 *it, u8 **q, u8 **x);
extern u8 func_021D5440(u8 *p);
int func_021C814C(u8 *p, int v);
int func_021C815C(int *p);
void func_021C8168(int *p);
int func_021C8174(int *p);
int func_021C8180(int *p);
int func_021C818C(u8 *p, int v);
u16 func_021C81C8(u8 *p, u8 *x, int flag);
u16 func_021C81D0(u8 *p, u8 *a, u32 y);

/*
 * ABI: ov095 D588 forwards the same table pointer and key to D5C8;
 * original keeps r1 live and has no narrowing, so retain a full-word key.
 */
int func_021C814C(u8 *p, int v) { return func_0689D588(p+0x1ab8,v); }


/*
 * Two tail thunks forwarding p->field4 to distinct callees.
 */
int func_021C815C(int *p)
{
    return func_021B8588((void **)(((struct Obj26329 *)p)->f4));
}


void func_021C8168(int *p)
{
    func_021B86B8((void ***)(((struct Obj26330 *)p)->f4));
}


int func_021C8174(int *p)
{
    return ((struct Obj18336 *)((char *)func_021B8714((char **)(((struct Obj18335 *)p)->f4))))->f4;
}


int func_021C8180(int *p)
{
    return func_021B8670((unsigned int **)(((struct Obj18337 *)p)->f4));
}

int func_021C818C(u8 *p, int v) { unsigned int species; u16 i; species=func_021D5444((struct QF *)func_021B9934(*(char * *)&((struct Obj13341 *)p)->f8,v)); for(i=0;i<7;i++) { if(func_0201B718(((struct Obj13341 *)p)->f4A4,species,0,i)) return 1; } return 0; }


u16 func_021C81C8(u8 *p, u8 *x, int flag)
{
    return func_021BC948(p, x, flag);
}


u16 func_021C81D0(u8 *p, u8 *a, u32 y)
{
    u32 it;
    u8 *x;
    u16 n;
    u32 base = func_021C81C8(p, a, y);
    int k = func_021D5440(a);
    n = 0;
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        if (k != func_021D5440(x)) {
            if (func_021C81C8(p, x, y) > base) {
                n++;
            }
        }
    }
    return n;
}

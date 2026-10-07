/*
 * file:     weather_task_p07.c
 * unit:     yes
 * function: func_021A2108, func_021A2114, func_021A2120, func_021A2130, func_021A213C, func_021A2148, func_021A2154
 * address:  0x021A2108
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A0590  0x021A0590  thumb  ov021
 *   func_021A05D8  0x021A05D8  thumb  ov021
 *   func_021A0618  0x021A0618  thumb  ov021
 *   func_021A065C 0x021A065C thumb ov021
 *   func_0218E188 0x0218E188 thumb ov021
 *   func_021A063C 0x021A063C thumb ov021
 */
#include "../../matched/include/Obj18000.h"
#include "../../matched/include/Obj18001.h"
#include "../../matched/include/Obj19728.h"
#include "../../matched/include/Obj00954.h"
#include "../../matched/include/Obj19729.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_021A0590(u32, u32, u32, u32);
void func_021A05D8(u8 *a);
extern void func_021A0618(u8 *p, u32 a, u32 b, u32 c);
extern int func_021A065C(u8 *p);
int func_0218E188(unsigned char *o);
extern void func_021A063C(u8 *p, u32 b, u32 c);
int func_021A2108(u32 a, int b, int c);
int func_021A2114(u32 a, int b, u32 c);
void func_021A2120(u32 *p, int x);
void func_021A2130(u8 *p, u32 b, u32 c, u32 d);
int func_021A213C(u8 *p);
int func_021A2148(unsigned char *o);
void func_021A2154(u8 *p, u32 b, u32 c);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A2108(u32 a, int b, int c)
{
return func_021A0590(((struct Obj18000 *)((u8 *)(a)))->f8, b, c, 60);
}


int func_021A2114(u32 a, int b, u32 c)
{
return func_021A0590(((struct Obj18001 *)((u8 *)(a)))->f8, b, c, 1);
}


void func_021A2120(u32 *p, int x)
{
    if (x == 1)
        func_021A05D8((u8 *)p[2]);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A2130(u8 *p, u32 b, u32 c, u32 d)
{
    func_021A0618((u8 *)(((struct Obj19728 *)p)->f8), b, c, d);
}


/*
 * Unlabelled tail-call stub, filed for the ov026 lane.
 */
int func_021A213C(u8 *p)
{
    return func_021A065C(*(u8 * *)&((struct Obj00954 *)p)->f8);
}


/*
 * Unlabelled tail-call leaf (ldr r0,[r0,#0x14]; ldr r3,[pc]; bx r3), filed
 * for lane S30 (callee of ov028 functions).
 */
int func_021A2148(unsigned char *o)
{
    return func_0218E188((unsigned char *)(((struct Obj19729 *)o)->f14));
}


void func_021A2154(u8 *p, u32 b, u32 c)
{
    func_021A063C(*(u8 * *)&((struct Obj00954 *)p)->f8, b, c);
}

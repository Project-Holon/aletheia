/*
 * file:     weather_task_p37.c
 * unit:     yes
 * function: func_021A3968, func_021A396C, func_021A3970, func_021A3974, func_021A3980, func_021A398C, func_021A3990
 * address:  0x021A3968
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
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B2C  0x02012B2C  thumb
 */
#include "../../matched/include/Obj18039.h"
#include "../../matched/include/Obj18041.h"
#include "../../matched/include/Obj18042.h"
#include "../../matched/include/Obj18043.h"
#include "../../matched/include/Obj18044.h"

struct Rec44;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u32 func_02012B28(const struct Rec44 *p);
extern void func_02012B2C(struct Rec44 *p, u32 v);
u32 func_021A3968(u32 *p);
void func_021A396C(u8 *p, u32 v);
u32 func_021A3970(u32 *p);
u32 func_021A3974(u8 *p);
void func_021A3980(u8 *p, u32 a1);
u32 func_021A398C(u8 *p);
u32 func_021A3990(u8 *p);


/*
 * Unlabelled leaf getter at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A3968(u32 *p)
{
    return p[5];
}


/*
 * Field setter at +0x10.
 *
 * Addresses are Black-image addresses.
 */
void func_021A396C(u8 *p, u32 v)
{
    ((struct Obj18039 *)p)->f10 = v;
}


/*
 * Unlabelled leaf getter at +0x10.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A3970(u32 *p)
{
    return p[4];
}


/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A3974(u8 *p)
{
    return func_02012B28((const struct Rec44 *)(((struct Obj18041 *)p)->fC));
}


void func_021A3980(u8 *p, u32 a1)
{
    func_02012B2C((struct Rec44 *)(((struct Obj18042 *)p)->fC), a1);
}


/*
 * Loads the 32-bit word at byte +0x18 of the object.
 */
u32 func_021A398C(u8 *p)
{
    return ((struct Obj18043 *)p)->f18;
}


/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021A3990(u8 *p)
{
    return ((struct Obj18044 *)p)->f4;
}

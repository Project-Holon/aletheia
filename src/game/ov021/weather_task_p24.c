/*
 * file:     weather_task_p24.c
 * unit:     yes
 * function: func_021A3050, func_021A305C, func_021A3068, func_021A3074, func_021A3080, func_021A308C, func_021A3098
 * address:  0x021A3050
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
 *   func_021A3920  0x021A3920  thumb
 *   func_021A392C  0x021A392C  thumb  ov021
 *   func_021A395C  0x021A395C  thumb
 *   func_021A3960  0x021A3960  thumb
 *   func_021A3968  0x021A3968  thumb  ov021
 *   func_021A3970  0x021A3970  thumb  ov021
 *   func_021A3974  0x021A3974  thumb
 */
#include "../../matched/include/Obj18013.h"
#include "../../matched/include/Obj19764.h"
#include "../../matched/include/Obj18014.h"
#include "../../matched/include/Obj00614.h"
#include "../../matched/include/Obj18015.h"
#include "../../matched/include/Obj18016.h"
#include "../../matched/include/Obj18017.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u16 func_021A3920(u8 *p);
void func_021A392C(void *p, int b);
extern u32 func_021A395C(u8 *p);
extern void *func_021A3960(u8 *p);
extern u32 func_021A3968(u32 *p);
extern u32 func_021A3970(u32 *p);
extern u32 func_021A3974(u8 *p);
u16 func_021A3050(u8 *p);
void func_021A305C(char *p, u32 b);
u32 func_021A3068(u8 *p);
void *func_021A3074(u8 *p);
u32 func_021A3080(u8 *p);
u32 func_021A308C(u8 *p);
u32 func_021A3098(u8 *p);


/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021A3050(u8 *p)
{
    return func_021A3920((u8 *)(((struct Obj18013 *)p)->f4));
}


/*
 *          (ov009/ov021 overlap; the ov021 hint does not locate a func_ label).
 *
 * UNBLOCKED: func_021A392C is now an EXACT entry in layout/matched/ov021;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
void func_021A305C(char *p, u32 b)
{
    func_021A392C((void *)(((struct Obj19764 *)p)->f4), b);
}


u32 func_021A3068(u8 *p)
{
    return func_021A395C((u8 *)(((struct Obj18014 *)p)->f4));
}


void *func_021A3074(u8 *p)
{
    return func_021A3960(*(u8 * *)&((struct Obj00614 *)p)->f4);
}


u32 func_021A3080(u8 *p)
{
    return func_021A3968((u32 *)(((struct Obj18015 *)p)->f4));
}


u32 func_021A308C(u8 *p)
{
    return func_021A3970((u32 *)(((struct Obj18016 *)p)->f4));
}


u32 func_021A3098(u8 *p)
{
    return func_021A3974((u8 *)(((struct Obj18017 *)p)->f4));
}

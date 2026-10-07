/*
 * file:     field_nogrid_mapper_p15.c
 * unit:     yes
 * function: func_021BB3A0, func_021BB3AC, func_021BB3B8, func_021BB3C4, func_021BB3D0, func_021BB3DC
 * address:  0x021BB3A0
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
 *   func_021B79AC  0x021B79AC  thumb
 *   func_021B79C4  0x021B79C4  thumb  ov021
 *   func_021B79CC  0x021B79CC  thumb  ov021
 *   func_021BB13C  0x021BB13C  thumb
 *   func_021B7D68  0x021B7D68  thumb ov021
 *   func_021B7C04  0x021B7C04  thumb  ov021
 */
#include "../../matched/include/Obj18167.h"
#include "../../matched/include/Obj18168.h"
#include "../../matched/include/Obj18169.h"
#include "../../matched/include/Obj18170.h"

struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021B79AC();
extern void func_021B79C4(u32 *p, u32 v);
extern void func_021B79CC(u32 *p);
extern int func_021BB13C(char *a, char *b);
extern void func_021B7D68(struct Obj *o, void *r);
extern void func_021B7C04(u8 *o, int k, int flag);
void func_021BB3A0(u8 *p, u32 a1);
void func_021BB3AC(u8 *p, u32 b);
void func_021BB3B8(u8 *p);
u32 func_021BB3C4(u8 *p, char *a1);
void func_021BB3D0(void **h, void *r);
void func_021BB3DC(u32 *p, int b, int c);


/*
 * Tail-call thunk: the object's word at +0x0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB3A0(u8 *p, u32 a1)
{
    func_021B79AC(((struct Obj18167 *)p)->f0);
}


void func_021BB3AC(u8 *p, u32 b)
{
    func_021B79C4((u32 *)(((struct Obj18168 *)p)->f0), b);
}


void func_021BB3B8(u8 *p)
{
    func_021B79CC((u32 *)(((struct Obj18169 *)p)->f0));
}


u32 func_021BB3C4(u8 *p, char *a1)
{
    return func_021BB13C((char *)(((struct Obj18170 *)p)->f8), a1);
}

void func_021BB3D0(void **h, void *r) { func_021B7D68(*h, r); }


void func_021BB3DC(u32 *p, int b, int c)
{
    func_021B7C04((u8 *)(*p), b, c);
}

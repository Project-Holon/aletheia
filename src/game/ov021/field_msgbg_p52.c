/*
 * file:     field_msgbg_p52.c
 * unit:     yes
 * function: func_0219049C, func_021904A8, func_021904AC, func_021904B0, func_021904C8, func_021904D0, func_021904DC
 * address:  0x0219049C
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
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02193208  0x02193208  thumb  ov021
 */
#include "../../matched/include/Obj17922.h"
#include "../../matched/include/Obj17923.h"
#include "../../matched/include/Obj17924.h"

struct PrintSys;
struct MsgBank;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_021904A8;

typedef signed short   s16_021904B0;

typedef signed char    s8;

extern u32 func_0201C6B4(const struct PrintSys *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02193208(u8 *p, u8 v);
int func_0219049C(u8 *p);
u32 func_021904A8(u32 *p);
u32 func_021904AC(u8 *p);
int func_021904B0(u32 a, u32 b);
u32 func_021904C8(struct Rec *a0);
void func_021904D0(u8 *p);
void func_021904DC(u8 *p, u8 v);


/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
int func_0219049C(u8 *p)
{
    return func_0201C6B4((const struct PrintSys *)(((struct Obj17922 *)p)->fC));
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021904A8(u32 *p)
{
    return p[3];
}


/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021904AC(u8 *p)
{
    return ((struct Obj17923 *)p)->f8;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021904B0(u32 a, u32 b)
{
return (int)func_02045B38(0, 2, ((b << 16) >> 16), ((struct Obj17924 *)((u8 *)(a)))->f0);
}


/*
 * Tail-call thunk: forwards to func_02045C04 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021904C8(struct Rec *a0)
{
    return func_02045C04(a0);
}


/*
 * Unlabelled leaf: sets the byte at +0x170.
 * Addresses are Black-image addresses.
 */
void func_021904D0(u8 *p)
{
    p[0x170] = 1;
}


/*
 * Tail call on the object displaced by 0x160 bytes, forwarding the value.
 * The second parameter is what puts the offset temp in r2 instead of r1.
 *
 * Addresses are Black-image addresses.
 */
void func_021904DC(u8 *p, u8 v)
{
    func_02193208(p + 0x160, v);
}

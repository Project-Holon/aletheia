/*
 * file:     fieldmap_p06.c
 * unit:     yes
 * function: func_02188C90, func_02188C98, func_02188C9C, func_02188CA4, func_02188CAC, func_02188CB4, func_02188CBC, func_02188CCC, func_02188CD0, func_02188CD8, func_02188CE0, func_02188CE8, func_02188CF0, func_02188CFC, func_02188D20
 * address:  0x02188C90
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
 *   data_021D35A8  0x021D35A8  data
 *   func_021A6DC0  0x021A6DC0  thumb
 */
#include "../../matched/include/Obj17864.h"
#include "../../matched/include/Obj17865.h"
#include "../../matched/include/Obj17866.h"
#include "../../matched/include/Obj17867.h"
#include "../../matched/include/Obj17868.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj17870.h"
#include "../../matched/include/Obj17871.h"
#include "../../matched/include/Obj17872.h"
#include "../../matched/include/Obj19490.h"
#include "../../matched/include/Obj17873.h"
#include "../../matched/include/Obj17875.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

extern u32 func_021A6DC0(u8 *p);
u32 func_02188C90(u8 *p);
u32 func_02188C98(u8 *p);
u16 func_02188C9C(u8 *p);
u32 func_02188CA4(u8 *p);
void func_02188CAC(u8 *p, u32 v);
void *func_02188CB4(struct Obj00020 *p);
int func_02188CBC(u32 a);
u32 func_02188CCC(u8 *p);
u32 func_02188CD0(u8 *p);
u32 func_02188CD8(u8 *p);
u32 func_02188CE0(u8 *p);
u32 func_02188CE8(u8 *p);
int func_02188CF0(u32 a);
u32 func_02188CFC(u8 *p);
u32 func_02188D20(u8 *p);
extern const u8 data_021D35A8[];


/*
 * Loads the 32-bit word at byte +0xb8 of the object.
 */
u32 func_02188C90(u8 *p)
{
    return ((struct Obj17864 *)p)->fB8;
}


/*
 * Loads the 32-bit word at byte +0x48 of the object.
 */
u32 func_02188C98(u8 *p)
{
    return ((struct Obj17865 *)p)->f48;
}


/*
 * Loads the halfword at byte +0xd8 of the object.
 */
u16 func_02188C9C(u8 *p)
{
    return ((struct Obj17866 *)p)->fD8;
}


/*
 * Loads the 32-bit word at byte +0x10c of the object.
 */
u32 func_02188CA4(u8 *p)
{
    return ((struct Obj17867 *)p)->f10C;
}


/*
 * Stores the 32-bit word into byte +0x10c of the object.
 */
void func_02188CAC(u8 *p, u32 v)
{
    ((struct Obj17868 *)p)->f10C = v;
}


/*
 * Loads the 32-bit word at byte +0x8c of the object.
 */
void *func_02188CB4(struct Obj00020 *p)
{
    return p->f8C;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02188CBC(u32 a)
{
if (*(u32 *)((u8 *)((a + 140))) != 0) {
    return 1;
}
return 0;
}


/*
 * Loads the 32-bit word at byte +0x24 of the object.
 */
u32 func_02188CCC(u8 *p)
{
    return ((struct Obj17870 *)p)->f24;
}


/*
 * Loads the 32-bit word at byte +0x94 of the object.
 */
u32 func_02188CD0(u8 *p)
{
    return ((struct Obj17871 *)p)->f94;
}


/*
 * Unlabelled leaf getter at +0x130.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02188CD8(u8 *p)
{
    return ((struct Obj17872 *)p)->f130;
}


/*
 * Unlabelled leaf getter at +0x98 (between func_02188CD8 and
 * func_02188CE8); sole blocker of ov019 func_0217B264's call.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02188CE0(u8 *p)
{
    return ((struct Obj19490 *)p)->f98;
}


/*
 * Loads the 32-bit word at byte +0x90 of the object.
 */
u32 func_02188CE8(u8 *p)
{
    return ((struct Obj17873 *)p)->f90;
}


int func_02188CF0(u32 a)
{
return *(u32 *)((u8 *)(*(u32 *)((u8 *)(a) + ((66 << 2)))));
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_02188CFC(u8 *p)
{
    u32 r;
    u32 k = data_021D35A8[**(u32 * *)&((struct Obj00020 *)p)->f108];

    if (k == 2)
        k = func_021A6DC0(((struct Obj00020 *)p)->f10C);
    r = k;
    return r;
}


/*
 * Loads the 32-bit word at byte +0x30 of the object.
 */
u32 func_02188D20(u8 *p)
{
    return ((struct Obj17875 *)p)->f30;
}

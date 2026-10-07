/*
 * file:     fieldmap_p05.c
 * unit:     yes
 * function: func_02188BD8, func_02188BE8, func_02188BF8, func_02188C54, func_02188C58, func_02188C5C, func_02188C60, func_02188C64, func_02188C68, func_02188C6C, func_02188C70, func_02188C7C, func_02188C80, func_02188C84, func_02188C88
 * address:  0x02188BD8
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
 *   func_021A3098  0x021A3098  thumb
 *   func_021A2F48  0x021A2F48  thumb
 *   func_021A2F54  0x021A2F54  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0202C794  0x0202C794  thumb
 */
#include "../../matched/include/Obj12061.h"
#include "../../matched/include/Obj17857.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj17858.h"
#include "../../matched/include/Obj17859.h"
#include "../../matched/include/Obj19487.h"
#include "../../matched/include/Obj19488.h"
#include "../../matched/include/Obj17860.h"
#include "../../matched/include/Obj17861.h"
#include "../../matched/include/Obj17862.h"
#include "../../matched/include/Obj17863.h"

struct Sub02008C20Obj;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

extern u32 func_021A3098(u8 *p);
extern void func_021A2F48(u8 *p, u32 a1);
extern int func_021A2F54(u8 *p);
extern void func_020061E4(u32 a);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u8 func_0202C794(void *a0, u32 a1);
void func_02188BD8(u8 *obj);
int func_02188BE8(void *a);
u32 func_02188BF8(u8 *a);
u32 func_02188C54(u8 *p);
void *func_02188C58(void *p);
u32 func_02188C5C(u8 *p);
u32 func_02188C60(u8 *p);
u32 func_02188C64(u8 *p);
u32 func_02188C68(u8 *p);
u32 func_02188C6C(u8 *p);
int func_02188C70(int *p, int b);
void *func_02188C7C(u8 *p);
void *func_02188C80(void *p);
u16 func_02188C84(u8 *p);
u32 func_02188C88(u8 *p);


/*
 * Sets the two words at +0xC0 and +0xC4 of its argument to 2 and 4.  A leaf
 * with no lr-saving prologue that nothing in ov021 branches to (its caller
 * is sub_02014488 in arm9), so the listing emits it as data words after
 * pool_02188BD4.
 */
void func_02188BD8(u8 *obj)
{
    ((struct Obj12061 *)obj)->fC0 = 2;
    ((struct Obj12061 *)obj)->fC4 = 4;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02188BE8(void *a)
{
if (((struct Obj17857 *)a)->fC0 == 1) {
    return 1;
}
return 0;
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_02188BF8(u8 *a)
{
    u32 r = 0;
    u32 t = func_021A3098((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C));

    if (t == 1) {
        r = 1;
        func_021A2F48((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C), 1);
    } else if (t == 0) {
        r = 1;
        func_020061E4(0x55F);
        func_021A2F48((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C), 2);
        func_02008DF0(func_02012F2C((int *)(*(u32 *)&((struct Obj00020 *)a)->f8)), 3);
    }
    if (r == 1)
        func_021A2F54((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C));
    return r;
}


/*
 * Loads the 32-bit word at byte +0x28 of the object.
 */
u32 func_02188C54(u8 *p)
{
    return ((struct Obj17858 *)p)->f28;
}


/*
 * Loads the 32-bit word at byte +0x10 of the object.
 */
void *func_02188C58(void *p)
{
    return ((struct Obj00020 *)p)->f10;
}


/*
 * Loads the 32-bit word at byte +0x3c of the object.
 */
u32 func_02188C5C(u8 *p)
{
    return ((struct Obj17859 *)p)->f3C;
}


/*
 * Unlabelled leaf getter: the word at +0x14.
 * Addresses are Black-image addresses.
 */
u32 func_02188C60(u8 *p)
{
    return ((struct Obj19487 *)p)->f14;
}


/*
 * Unlabelled leaf accessor: returns the +0x18 member.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02188C64(u8 *p)
{
    return ((struct Obj19488 *)p)->f18;
}


/*
 * Loads the 32-bit word at byte +0x1c of the object.
 */
u32 func_02188C68(u8 *p)
{
    return ((struct Obj17860 *)p)->f1C;
}


/*
 * Loads the 32-bit word at byte +0x20 of the object.
 */
u32 func_02188C6C(u8 *p)
{
    return ((struct Obj17861 *)p)->f20;
}


/*
 * Unlabelled tail-call leaf (no lr saved): forwards p[1] and the second argument.
 */
int func_02188C70(int *p, int b)
{
    return func_0202C794((void *)p[1], b);
}


/*
 * Loads the 32-bit word at byte +0x38 of the object.
 */
void *func_02188C7C(u8 *p)
{
    return ((struct Obj00020 *)p)->f38;
}


/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
void *func_02188C80(void *p)
{
    return ((struct Obj00020 *)p)->f4;
}


/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02188C84(u8 *p)
{
    return ((struct Obj17862 *)p)->f0;
}


u32 func_02188C88(u8 *p)
{
    return ((struct Obj17863 *)p)->fB4;
}

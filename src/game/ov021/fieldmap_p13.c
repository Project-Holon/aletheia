/*
 * file:     fieldmap_p13.c
 * unit:     yes
 * function: func_021899F8, func_02189A00, func_02189A08, func_02189A10, func_02189A18, func_02189A1C, func_02189A24, func_02189A2C
 * address:  0x021899F8
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
 *   func_020120D8  0x020120D8  thumb
 */
#include "../../matched/include/Obj19502.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj19503.h"
#include "../../matched/include/Obj17887.h"
#include "../../matched/include/Obj17888.h"
#include "../../matched/include/Obj17889.h"

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Obj {
    u8 pad00[0xA0];
    void *fa0;          /* 0xA0 */
} Obj;

extern int func_020120D8(char *a);
void func_021899F8(u8 *p, u32 v);
void *func_02189A00(u8 *p);
int func_02189A08(unsigned char *p);
void *func_02189A10(Obj *p);
u32 func_02189A18(u8 *p);
void func_02189A1C(u8 *p, u32 v);
u32 func_02189A24(u8 *p);
int func_02189A2C(int *a);


/*
 * Unlabelled leaf setter: the word at +0x12C.
 * Addresses are Black-image addresses.
 */
void func_021899F8(u8 *p, u32 v)
{
    ((struct Obj19502 *)p)->f12C = v;
}


/*
 * Loads the 32-bit word at byte +0x124 of the object.
 */
void *func_02189A00(u8 *p)
{
    return ((struct Obj00020 *)p)->f124;
}


int func_02189A08(unsigned char *p)
{
    return ((struct Obj19503 *)p)->f13C;
}


/*
 * Unlabelled leaf accessor (prints as .word in the listing): returns the pointer at +0xA0.
 * Sole blocker of ov010 func_0215ECBC's MATCH.
 */
void *func_02189A10(Obj *p)
{
    return p->fa0;
}


/*
 * Loads the 32-bit word at byte +0x40 of the object.
 */
u32 func_02189A18(u8 *p)
{
    return ((struct Obj17887 *)p)->f40;
}


/*
 * Stores the 32-bit word into byte +0x138 of the object.
 */
void func_02189A1C(u8 *p, u32 v)
{
    ((struct Obj17888 *)p)->f138 = v;
}


/*
 * Loads the 32-bit word at byte +0x138 of the object.
 */
u32 func_02189A24(u8 *p)
{
    return ((struct Obj17889 *)p)->f138;
}


int func_02189A2C(int *a)
{
    return func_020120D8((char *)a[1]);
}

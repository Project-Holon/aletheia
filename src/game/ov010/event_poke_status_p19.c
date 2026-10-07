/*
 * file:     event_poke_status_p19.c
 * unit:     yes
 * function: func_0215A63C, func_0215A644, func_0215A64C, func_0215A654, func_0215A660, func_0215A66C
 * address:  0x0215A63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj18789.h"
#include "../../matched/include/Obj18790.h"
#include "../../matched/include/Obj18791.h"
#include "../../matched/include/Obj18792.h"
#include "../../matched/include/Obj18793.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

u8 *func_0215A63C(u8 *p);
void func_0215A644(void *p, u32 v);
void *func_0215A64C(void *p);
u32 func_0215A654(u8 *p);
void func_0215A660(u8 *p, u32 v);
u8 func_0215A66C(u8 *p);


/*
 * Address of the block at +0xD4 inside the object at +0x20.
 */
u8 *func_0215A63C(u8 *p)
{
    return *(u8 * *)&((struct Obj00005 *)p)->f20 + 0xd4;
}


/*
 * Unlabelled leaf (setter through the pointer at +0x20), filed as a blocker
 * of ov021 func_021C459C / func_021C4628.
 */
void func_0215A644(void *p, u32 v)
{
    ((struct Obj18789 *)(*(char * *)&((struct Obj00005 *)p)->f20))->f10 = v;
}


/*
 * Unlabelled leaf, blocker of ov021 func_021C457C/func_021C4608: reads the word at +0x10 of the record held at +0x20.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void *func_0215A64C(void *p)
{
    return ((struct Obj18791 *)(*(char * *)&((struct Obj18790 *)p)->f20))->f10;
}


/*
 * Getter: byte at +0x104 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of func_021B03E4).
 */
u32 func_0215A654(u8 *p)
{
    return *((u8 *)((struct Obj18792 *)p)->f20 + 0x104);
}


/*
 * Setter: byte at +0x104 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of func_021B03E4).
 */
void func_0215A660(u8 *p, u32 v)
{
    *((u8 *)((struct Obj18793 *)p)->f20 + 0x104) = v;
}


/*
 * Reads the byte at +0x105 of the object at +0x20.
 */
u8 func_0215A66C(u8 *p)
{
    return (*(u8 **)(p + 0x20))[0x105];
}

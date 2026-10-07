/*
 * file:     event_poke_status_p18.c
 * unit:     yes
 * function: func_0215A5D8, func_0215A5DC, func_0215A5E4, func_0215A5EC, func_0215A5F4, func_0215A5FC, func_0215A60C, func_0215A610, func_0215A614, func_0215A61C, func_0215A624, func_0215A630
 * address:  0x0215A5D8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02158F58  0x02158F58  thumb  ov010
 */
#include "../../matched/include/Obj17656.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj17657.h"
#include "../../matched/include/Obj17658.h"
#include "../../matched/include/Obj17659.h"
#include "../../matched/include/Obj17660.h"
#include "../../matched/include/Obj17661.h"
#include "../../matched/include/Obj17662.h"
#include "../../matched/include/Obj17663.h"
#include "../../matched/include/Obj18787.h"
#include "../../matched/include/Obj18788.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_02158F58(int a0);
u32 func_0215A5D8(void *p);
void *func_0215A5DC(void *a0);
void *func_0215A5E4(void *a0);
void *func_0215A5EC(void *p);
void *func_0215A5F4(void *p);
int func_0215A5FC(int a0);
u32 func_0215A60C(u8 *p);
u16 func_0215A610(void *p);
void func_0215A614(u8 *p, u32 v);
int func_0215A61C(int a0);
void func_0215A624(u8 *p, u32 v);
u32 func_0215A630(u8 *p);


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215A5D8.c \
 *       --func func_0215A5D8 --addr 0x0215A5D8 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0215A5D8(void *p) { return ((struct Obj17656 *)p)->f8; }




void *func_0215A5DC(void *a0)
{
    return ((struct Obj17657 *)(*(char * *)&((struct Obj00005 *)a0)->f20))->f4;
}




void *func_0215A5E4(void *a0)
{
    return ((struct Obj17658 *)(*(char * *)&((struct Obj00005 *)a0)->f20))->f8;
}

/*
 * Getter: word at +0xc of the object whose pointer sits at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void *func_0215A5EC(void *p)
{
    return ((struct Obj17659 *)(*(u8 * *)&((struct Obj00005 *)p)->f20))->fC;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Double dereference: one field load then a load through the resulting pointer.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215A5F4.c \
 *       --func func_0215A5F4 --addr 0x0215A5F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0215A5F4(void *p) { return ((struct Obj17660 *)(((struct Obj00005 *)p)->f20))->f0; }


int func_0215A5FC(int a0)
{
    void *v0;

    v0 = func_0215A5F4((void *)a0);
loc_0215A602:
    a0 = func_02158F58((int)v0);
loc_0215A606:
a0 = *(int *)&((struct Obj00005 *)((char *)a0))->f0;
    return a0;}



/*
 * Reads the word field at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0215A60C(u8 *p)
{
    return ((struct Obj17661 *)p)->f14;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215A610.c \
 *       --func func_0215A610 --addr 0x0215A610 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0215A610(void *p) { return ((struct Obj17662 *)p)->f18; }

/*
 * Setter: word at +0xfc of the object whose pointer sits at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void func_0215A614(u8 *p, u32 v)
{
*(u32 *)((u8 *)((struct Obj17663 *)p)->f20 + 0xfc) = v;
}




int func_0215A61C(int a0)
{

a0 = *(int *)&((struct Obj00005 *)a0)->f20;
a0 = a0 + 0xfc;
a0 = *(int *)&((struct Obj00005 *)((char *)a0))->f0;
    return a0;}


/*
 * Setter: word at +0x100 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of func_021B0480).
 */
void func_0215A624(u8 *p, u32 v)
{
    *(u32 *)((u8 *)((struct Obj18787 *)p)->f20 + 0x100) = v;
}


/*
 * Getter: word at +0x100 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of func_021B0480).
 */
u32 func_0215A630(u8 *p)
{
    return *(u32 *)((u8 *)((struct Obj18788 *)p)->f20 + 0x100);
}

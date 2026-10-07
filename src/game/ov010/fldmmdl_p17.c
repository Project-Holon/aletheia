/*
 * file:     fldmmdl_p17.c
 * unit:     yes
 * function: func_0216D4E4, func_0216D4F0, func_0216D4F4, func_0216D4F8, func_0216D4FC, func_0216D508, func_0216D514, func_0216D518, func_0216D51C
 * address:  0x0216D4E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj17774.h"
#include "../../matched/include/Obj17775.h"
#include "../../matched/include/Obj17776.h"
#include "../../matched/include/Obj17777.h"
#include "../../matched/include/Obj17778.h"
#include "../../matched/include/Obj17779.h"
#include "../../matched/include/Obj17780.h"
#include "../../matched/include/Obj17781.h"

typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

u32 *func_0216D4E4(u32 *p, u32 v);
u16 func_0216D4F0(void *p);
u16 func_0216D4F4(void *p);
u32 func_0216D4F8(u8 *p);
int func_0216D4FC(int a0);
int func_0216D508(int a0);
u32 func_0216D514(void *p);
u32 func_0216D518(u8 *p);
void func_0216D51C(u8 *p, u32 v);


u32 *func_0216D4E4(u32 *p, u32 v)
{
    *p &= ~v;
    return p;
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
 *   python tools/match.py one --src src/matched/func_0216D4F0.c \
 *       --func func_0216D4F0 --addr 0x0216D4F0 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D4F0(void *p) { return ((struct Obj17774 *)p)->f4; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D4F4.c \
 *       --func func_0216D4F4 --addr 0x0216D4F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D4F4(void *p) { return ((struct Obj17775 *)p)->fC; }

/*
 * Getter: halfword at +0xa.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D4F8(u8 *p)
{
return ((struct Obj17776 *)p)->fA;
}




int func_0216D4FC(int a0)
{
    int a1;
a1 = 6;
a1 = *(short *)((char *)a0 + a1);
a1 = a1 + 1;
((struct Obj17777 *)a0)->f6 = a1;
    return a0;}




int func_0216D508(int a0)
{
    int a1;

a1 = 6;
a1 = *(short *)((char *)a0 + a1);
a1 = a1 - 1;
((struct Obj17778 *)a0)->f6 = a1;
    return a0;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D514.c \
 *       --func func_0216D514 --addr 0x0216D514 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D514(void *p) { return ((struct Obj17779 *)p)->f20; }



/*
 * Reads the word field at +0x10.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D518(u8 *p)
{
    return ((struct Obj17780 *)p)->f10;
}



/*
 * Stores the word field at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_0216D51C(u8 *p, u32 v)
{
    ((struct Obj17781 *)p)->f24 = v;
}

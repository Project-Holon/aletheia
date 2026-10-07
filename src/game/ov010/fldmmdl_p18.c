/*
 * file:     fldmmdl_p18.c
 * unit:     yes
 * function: func_0216D520, func_0216D524, func_0216D528, func_0216D52C, func_0216D530, func_0216D534, func_0216D538, func_0216D548, func_0216D550, func_0216D55C, func_0216D564, func_0216D568, func_0216D570, func_0216D57C, func_0216D584, func_0216D588, func_0216D58C
 * address:  0x0216D520
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj17782.h"
#include "../../matched/include/Obj19121.h"
#include "../../matched/include/Obj17783.h"
#include "../../matched/include/Obj17784.h"
#include "../../matched/include/Obj17785.h"
#include "../../matched/include/Obj17786.h"
#include "../../matched/include/Obj19122.h"
#include "../../matched/include/Obj17788.h"
#include "../../matched/include/Obj17789.h"
#include "../../matched/include/Obj17790.h"
#include "../../matched/include/Obj19125.h"
#include "../../matched/include/Obj17791.h"
#include "../../matched/include/Obj17792.h"
#include "../../matched/include/Obj17793.h"
#include "../../matched/include/Obj17794.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

u32 func_0216D520(void *p);
void func_0216D524(void *p, void *v);
u32 func_0216D528(u8 *p);
u32 func_0216D52C(void *p);
void *func_0216D530(void *p);
u32 func_0216D534(void *p);
u32 func_0216D538(u8 *p);
u32 *func_0216D548(u32 *p, u32 v);
u32 *func_0216D550(u32 *p, u32 v);
int func_0216D55C(int a0, int a1);
u32 func_0216D564(void *p);
void *func_0216D568(void *p, u32 v);
char *func_0216D570(char *p, u32 v);
u32 func_0216D57C(void *p, u32 v);
void func_0216D584(void *p, u16 v);
u16 func_0216D588(void *p);
void func_0216D58C(void *p, u16 v);


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D520.c \
 *       --func func_0216D520 --addr 0x0216D520 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D520(void *p) { return ((struct Obj17782 *)p)->f24; }


/*
 * Unlabelled leaf: str r1, [r0, #0x28]; bx lr.
 */
void func_0216D524(void *p, void *v)
{
    ((struct Obj19121 *)p)->f28 = v;
}

/*
 * Getter: word at +0x28.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D528(u8 *p)
{
return ((struct Obj17783 *)p)->f28;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D52C.c \
 *       --func func_0216D52C --addr 0x0216D52C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D52C(void *p) { return ((struct Obj17784 *)p)->f34; }

/*
 * Getter: word at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void *func_0216D530(void *p)
{
    return ((struct Obj17785 *)p)->f38;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D534.c \
 *       --func func_0216D534 --addr 0x0216D534 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D534(void *p) { return ((struct Obj17786 *)p)->f3C; }


/*
 * Unlabelled leaf (no lr push): returns the halfword at the pointer held at +0x40, or 0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D538(u8 *p)
{
    u16 *q = *(u16 * *)&((struct Obj19122 *)p)->f40;
    if (q != 0)
        return *q;
    return 0;
}




u32 *func_0216D548(u32 *p, u32 v)
{
    *p |= v;
    return p;
}


u32 *func_0216D550(u32 *p, u32 v)
{
    *p &= ~v;
    return p;
}




int func_0216D55C(int a0, int a1)
{

a0 = ((struct Obj17788 *)((char *)a0))->f0;
a0 = a0 & a1;
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
 *   python tools/match.py one --src src/matched/func_0216D564.c \
 *       --func func_0216D564 --addr 0x0216D564 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D564(void *p) { return ((struct Obj17789 *)p)->f4; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Read-modify-write OR into a word field.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D568.c \
 *       --func func_0216D568 --addr 0x0216D568 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D568(void *p, u32 v) { ((struct Obj17790 *)p)->f4 |= v;  return p; }


char *func_0216D570(char *p, u32 v)
{
    ((struct Obj19125 *)p)->f4 &= ~v;
    return p;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field mask test: load and return `field & mask`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D57C.c \
 *       --func func_0216D57C --addr 0x0216D57C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D57C(void *p, u32 v) { return ((struct Obj17791 *)p)->f4 & v; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D584.c \
 *       --func func_0216D584 --addr 0x0216D584 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D584(void *p, u16 v) { ((struct Obj17792 *)p)->f8 = v; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D588.c \
 *       --func func_0216D588 --addr 0x0216D588 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D588(void *p) { return ((struct Obj17793 *)p)->f8; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D58C.c \
 *       --func func_0216D58C --addr 0x0216D58C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D58C(void *p, u16 v) { ((struct Obj17794 *)p)->fA = v; }

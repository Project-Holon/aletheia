/*
 * file:     fldmmdl_p20.c
 * unit:     yes
 * function: func_0216D600, func_0216D608
 * address:  0x0216D600
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj00113.h"
#include "../../matched/include/Obj17808.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

int func_0216D600(int a0, u16 a1);
u16 func_0216D608(void *p);




int func_0216D600(int a0, u16 a1)
{
    int a2;

a2 = ((struct Obj00113 *)a0)->f1A;
((struct Obj00113 *)a0)->f1E = a2;
((struct Obj00113 *)a0)->f1A = a1;
    return a0;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D608.c \
 *       --func func_0216D608 --addr 0x0216D608 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D608(void *p) { return ((struct Obj17808 *)p)->f1A; }

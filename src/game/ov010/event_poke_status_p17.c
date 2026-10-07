/*
 * file:     event_poke_status_p17.c
 * unit:     yes
 * function: func_0215A5CC, func_0215A5D0, func_0215A5D4
 * address:  0x0215A5CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj17653.h"
#include "../../matched/include/Obj17654.h"
#include "../../matched/include/Obj17655.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

u16 func_0215A5CC(void *a0);
u16 func_0215A5D0(void *p);
u32 func_0215A5D4(void *p);




u16 func_0215A5CC(void *a0)
{
    return ((struct Obj17653 *)a0)->f0;
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
 *   python tools/match.py one --src src/matched/func_0215A5D0.c \
 *       --func func_0215A5D0 --addr 0x0215A5D0 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0215A5D0(void *p) { return ((struct Obj17654 *)p)->f4; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215A5D4.c \
 *       --func func_0215A5D4 --addr 0x0215A5D4 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0215A5D4(void *p) { return ((struct Obj17655 *)p)->fC; }

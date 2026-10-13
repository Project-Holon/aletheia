/*
 * function: FLDMMDL_SetGridNowX
 * address:  0x0216D844
 * packet:   pkt_0216D4F0
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_SetGridNowX.c \
 *       --func FLDMMDL_SetGridNowX --addr 0x0216D844 --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17844.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

void FLDMMDL_SetGridNowX(void *p, short v) { ((struct Obj17844 *)p)->f3C = v; }

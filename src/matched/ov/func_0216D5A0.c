/*
 * function: FLDMMDL_GetMoveCode
 * address:  0x0216D5A0
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
 *   python tools/match.py one --src src/matched/FLDMMDL_GetMoveCode.c \
 *       --func FLDMMDL_GetMoveCode --addr 0x0216D5A0 --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17799.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

u16 FLDMMDL_GetMoveCode(void *p) { return ((struct Obj17799 *)p)->fE; }

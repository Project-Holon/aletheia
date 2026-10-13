/*
 * function: FLDMMDL_SetNowAttr
 * address:  0x0216D7D8
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
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_SetNowAttr.c \
 *       --func FLDMMDL_SetNowAttr --addr 0x0216D7D8 --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17828.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

void FLDMMDL_SetNowAttr(void *p, u32 v) { ((struct Obj17828 *)p)->f74 = v; }

/*
 * function: FLDMMDL_CheckMoveBit
 * address:  0x0216D57C
 * packet:   pkt_0216D4F0
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field mask test: load and return `field & mask`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_CheckMoveBit.c \
 *       --func FLDMMDL_CheckMoveBit --addr 0x0216D57C --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17791.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

u32 FLDMMDL_CheckMoveBit(void *p, u32 v) { return ((struct Obj17791 *)p)->f4 & v; }

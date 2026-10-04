/*
 * function: func_0216D568
 * address:  0x0216D568
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
 * Read-modify-write OR into a word field.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D568.c \
 *       --func func_0216D568 --addr 0x0216D568 --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17790.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

void func_0216D568(void *p, u32 v) { ((struct Obj17790 *)p)->f4 |= v; }

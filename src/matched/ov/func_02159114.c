/*
 * function: func_02159114
 * address:  0x02159114
 * packet:   pkt_021590F4
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field setter, same shape as its getter partner.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159114.c \
 *       --func func_02159114 --addr 0x02159114 --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17641.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

void func_02159114(void *p, u32 v) { ((struct Obj17641 *)p)->f144 = v; }

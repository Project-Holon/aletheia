/*
 * function: func_0216D5AC
 * address:  0x0216D5AC
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
 *   python tools/match.py one --src src/matched/func_0216D5AC.c \
 *       --func func_0216D5AC --addr 0x0216D5AC --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17802.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

void func_0216D5AC(void *p, u16 v) { ((struct Obj17802 *)p)->f12 = v; }

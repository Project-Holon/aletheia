/*
 * function: func_0216670C
 * address:  0x0216670C
 * packet:   pkt_0216670C
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216670C.c \
 *       --func func_0216670C --addr 0x0216670C --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17727.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

int func_0216670C(void *p) { return ((struct Obj17727 *)p)->f4; }

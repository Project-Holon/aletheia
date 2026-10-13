/*
 * function: FLDMMDL_GetGridNowX
 * address:  0x0216D83C
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
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_GetGridNowX.c \
 *       --func FLDMMDL_GetGridNowX --addr 0x0216D83C --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17843.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

int FLDMMDL_GetGridNowX(void *p) { return ((struct Obj17843 *)p)->f3C; }

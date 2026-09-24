/*
 * function: func_0216D810
 * address:  0x0216D810
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
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D810.c \
 *       --func func_0216D810 --addr 0x0216D810 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

int func_0216D810(void *p) { return *(s16 *)((char *)p + 56); }

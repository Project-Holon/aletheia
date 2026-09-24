/*
 * function: func_02159240
 * address:  0x02159240
 * packet:   pkt_02159240
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Constant leaf: `movs r0, #N; bx lr`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159240.c \
 *       --func func_02159240 --addr 0x02159240 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

int func_02159240(void) { return 0; }

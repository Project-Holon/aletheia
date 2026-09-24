/*
 * function: func_0215A5D4
 * address:  0x0215A5D4
 * packet:   pkt_0215A5D0
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
 *   python tools/match.py one --src src/matched/func_0215A5D4.c \
 *       --func func_0215A5D4 --addr 0x0215A5D4 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

u32 func_0215A5D4(void *p) { return *(u32 *)((char *)p + 12); }

/*
 * function: func_0216D57C
 * address:  0x0216D57C
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
 * Word-field mask test: load and return `field & mask`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D57C.c \
 *       --func func_0216D57C --addr 0x0216D57C --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

u32 func_0216D57C(void *p, u32 v) { return *(u32 *)((char *)p + 4) & v; }

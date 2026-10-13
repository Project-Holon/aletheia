/*
 * function: FLDMMDL_GetMoveCmdWork
 * address:  0x0216D6D4
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
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_GetMoveCmdWork.c \
 *       --func FLDMMDL_GetMoveCmdWork --addr 0x0216D6D4 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

void *FLDMMDL_GetMoveCmdWork(void *p) { return (char *)p + 180; }

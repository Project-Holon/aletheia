/*
 * function: FLDMMDL_GetObjCodeParam
 * address:  0x0216E3C4
 * packet:   pkt_0216E3C4
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
 *   python tools/match.py one --src src/matched/FLDMMDL_GetObjCodeParam.c \
 *       --func FLDMMDL_GetObjCodeParam --addr 0x0216E3C4 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

void *FLDMMDL_GetObjCodeParam(void *p) { return (char *)p + 228; }

/*
 * function: SCRIPT_WORK_GetUserWorkPtr
 * address:  0x02158FB4
 * packet:   pkt_02158F50
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
 *   python tools/match.py one --src src/matched/SCRIPT_WORK_GetUserWorkPtr.c \
 *       --func SCRIPT_WORK_GetUserWorkPtr --addr 0x02158FB4 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

void *SCRIPT_WORK_GetUserWorkPtr(void *p) { return (char *)p + 60; }

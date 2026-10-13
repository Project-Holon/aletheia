/*
 * function: SCRCMD_WORK_GetChildScriptIndex
 * address:  0x0215AA4C
 * packet:   pkt_0215AA48
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Byte-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SCRCMD_WORK_GetChildScriptIndex.c \
 *       --func SCRCMD_WORK_GetChildScriptIndex --addr 0x0215AA4C --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17667.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

u8 SCRCMD_WORK_GetChildScriptIndex(void *p) { return ((struct Obj17667 *)p)->f1A; }

/*
 * function: SCRCMD_WORK_SetChildScriptIndex
 * address:  0x0215AA48
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
 *   python tools/match.py one --src src/matched/SCRCMD_WORK_SetChildScriptIndex.c \
 *       --func SCRCMD_WORK_SetChildScriptIndex --addr 0x0215AA48 --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17666.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

void SCRCMD_WORK_SetChildScriptIndex(void *p, int v) { ((struct Obj17666 *)p)->f1A = v; }

/*
 * function: SCRIPT_WORK_SetReturnScriptId
 * address:  0x021590F4
 * packet:   pkt_021590F4
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field setter, same shape as its getter partner.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SCRIPT_WORK_SetReturnScriptId.c \
 *       --func SCRIPT_WORK_SetReturnScriptId --addr 0x021590F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17639.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

void SCRIPT_WORK_SetReturnScriptId(void *p, u32 v) { ((struct Obj17639 *)p)->f13C = v; }

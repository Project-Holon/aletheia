/*
 * function: SCRIPT_WORK_GetReturnScriptId
 * address:  0x021590FC
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
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SCRIPT_WORK_GetReturnScriptId.c \
 *       --func SCRIPT_WORK_GetReturnScriptId --addr 0x021590FC --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17640.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

u32 SCRIPT_WORK_GetReturnScriptId(void *p) { return ((struct Obj17640 *)p)->f13C; }

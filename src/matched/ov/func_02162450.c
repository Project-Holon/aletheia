/*
 * function: EVENTDATA_SYSTEM_GetSpecialScriptData
 * address:  0x02162450
 * packet:   pkt_02162450
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
 *   python tools/match.py one --src src/matched/EVENTDATA_SYSTEM_GetSpecialScriptData.c \
 *       --func EVENTDATA_SYSTEM_GetSpecialScriptData --addr 0x02162450 --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17714.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

u32 EVENTDATA_SYSTEM_GetSpecialScriptData(void *p) { return ((struct Obj17714 *)p)->f120; }

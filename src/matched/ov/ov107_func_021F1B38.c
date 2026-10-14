/*
 * function: MB_UTIL_MSG_SetTimeIconPending
 * address:  0x021F1B38
 * packet:   pkt_ov107_021F1B38
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22310.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void MB_UTIL_MSG_SetTimeIconPending(u8 *p, u32 v) { ((struct Obj22310 *)p)->f58 = v; }

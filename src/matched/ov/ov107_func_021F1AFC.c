/*
 * function: MB_UTIL_MSG_GetMsgData
 * address:  0x021F1AFC
 * packet:   pkt_ov107_021F1AFC
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22306.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u32 MB_UTIL_MSG_GetMsgData(u8 *p) { return ((struct Obj22306 *)p)->f1C; }

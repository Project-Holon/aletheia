/*
 * function: WIFI_BSUBWAY_SetHttpError
 * address:  0x021D7250
 * packet:   pkt_ov116_021D7250
 * region:   ov116
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj06417.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void WIFI_BSUBWAY_SetHttpError(u8 *p, u32 v) { ((struct Obj06417 *)p)->fC = 3; ((struct Obj06417 *)p)->f10 = v; }

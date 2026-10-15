/*
 * function: WIFI_BSUBWAY_AsyncReset
 * address:  0x021D70E4
 * packet:   pkt_ov116_021D70E4
 * region:   ov116
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Zeroes the two u16 at +0x08/+0x0a.
 */
#include "../include/Obj13864.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void WIFI_BSUBWAY_AsyncReset(u8 *p) { ((struct Obj13864 *)p)->f8 = 0; ((struct Obj13864 *)p)->fA = 0; }

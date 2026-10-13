/*
 * function: PDC_GetMyStatus
 * address:  0x021B6148
 * packet:   pkt_ov098_021B6148
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj22001.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u32 PDC_GetMyStatus(u8 *p) { return ((struct Obj22001 *)p)->fC; }

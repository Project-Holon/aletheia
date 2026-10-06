/*
 * function: func_021B7FF0
 * address:  0x021B7FF0
 * packet:   pkt_ov103_021B7FF0
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22185.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
u32 func_021B7FF0(u8 *p) { return func_0201C4E4((struct PrintSys *)(((struct Obj22185 *)p)->f8)); }

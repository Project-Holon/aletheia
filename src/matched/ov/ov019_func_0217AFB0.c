/*
 * function: func_0217AFB0
 * address: 0x0217AFB0
 * packet: pkt_ov019_0217AFB0
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217AED4 0x0217AED4 thumb ov019
 *   func_02012964 0x02012964 thumb
 *   func_0216DE94 0x0216DE94 thumb ov010
 *   func_02034714 0x02034714 arm
 *   d_021807E0 0x021807E0 data a1
 */
#include "../include/Obj19389.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern u16 func_0217AED4(u8 *,u8 *);
extern void *func_02012964(void *);
extern void *func_0216DE94(void *,unsigned int);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_021807E0[];
void *func_0217AFB0(void **a,u8 *b,u8 *c) { u16 key; void *p; key = func_0217AED4(b,c); p = func_0216DE94(func_02012964(((struct Obj19389 *)((u8 *)*a))->f8),key); if(p == 0) func_02034714(d_021807E0,0,d_021807E0); return p; }

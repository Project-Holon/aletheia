/*
 * function: func_0218677C
 * address: 0x0218677C
 * packet: pkt_ov020_0218677C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Follower 021867A8 is already filed separately; 020084F4 returns its unchanged incoming r0.
 * symbols:
 *   func_02008530 0x02008530 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj09436.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_020084F4(void *p);
extern void func_02082D44(const void *src, void *dst, u32 size);
void func_0218677C(u8 *p, void *src) { p[0] = (p[0] & ~0xF0) | 0x10; ((struct Obj09436 *)p)->f14 = func_02008530(src); func_02082D44(func_020084F4(src), p + 4, 16); }

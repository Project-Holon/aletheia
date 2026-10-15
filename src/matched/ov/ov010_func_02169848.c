/*
 * function: FIELD_G3D_MAP_QueryPlane
 * address: 0x02169848
 * packet: pkt_ov010_02169848
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * output proof: VEC_Subtract stores buf[0:2] at 0207CA20/0207CA28;
 * callback receives that initialized three-word vector, with original arity.
 * address arithmetic: unsigned 32-bit index scaling and base addition
 * preserve the original lsls/adds wraparound without an invented index bound.
 * symbols:
 *   VEC_Subtract 0x0207CA00 arm
 */
#include "../include/Obj07317.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Cb)(void *,u32,u32 *,u32,u32);
extern void VEC_Subtract(u32,void *,u32 *);
void FIELD_G3D_MAP_QueryPlane(void *a,u8 *b,u32 c,u32 d) { u32 buf[3]; Cb cb; VEC_Subtract(c,b+4,buf); cb=*(Cb *)(((struct Obj07317 *)b)->f28+((struct Obj07317 *)b)->f18*16u+12u); cb(a,((struct Obj07317 *)b)->fD4,buf,d,((struct Obj07317 *)b)->f8); }

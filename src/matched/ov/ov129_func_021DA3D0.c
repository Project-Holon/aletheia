/*
 * function: func_021DA3D0
 * address: 0x021DA3D0
 * packet: pkt_ov129_021DA3D0
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: Two zero alignment bytes.
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0202570C 0x0202570C thumb
 *   func_02025588 0x02025588 thumb
 */
#include "../include/Obj08140.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Grid;
extern void func_0204ADA4(u32);
extern void func_0202570C(struct Grid *);
extern void func_02025588(void *);
void func_021DA3D0(u8 *p) { func_0204ADA4(((struct Obj08140 *)p)->f30C); func_0202570C(*(struct Grid * *)&((struct Obj08140 *)p)->f304); func_0202570C(*(struct Grid * *)&((struct Obj08140 *)p)->f308); func_02025588(((struct Obj08140 *)p)->f300); }

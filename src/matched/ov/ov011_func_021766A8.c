/*
 * function: INTRUDE_LINK_ProcExit
 * address: 0x021766A8
 * packet: pkt_ov011_021766A8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two alignment bytes at 021766CA.
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj12441.h"
typedef unsigned char u8;
struct S020314B8;
struct S020315D4;
extern void func_0203133C(struct S020314B8 *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct S020315D4 *p);
int INTRUDE_LINK_ProcExit(void *p, int b, int c, u8 *q)
{
    func_0203133C(((struct Obj12441 *)q)->fF4);
    func_020307B0(((struct Obj12441 *)q)->fF8);
    func_020315D4(p);
    return 1;
}

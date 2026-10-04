/*
 * function: func_021A3898
 * address:  0x021A3898
 * packet:   pkt_021A3810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x1c.
 *
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18032.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);

void func_021A3898(u8 *p, struct VecFx32 *out)
{
    func_0216D88C((const struct Actor *)((struct Obj18032 *)p)->f1C, out);
}

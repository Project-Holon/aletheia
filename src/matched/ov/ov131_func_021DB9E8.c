/*
 * function: func_021DB9E8
 * address:  0x021DB9E8
 * packet:   pkt_021DB9E8
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020437AC  0x020437AC  arm
 *   func_021DBC3C  0x021DBC3C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14077.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj020437AC;
extern void func_020437AC(struct Obj020437AC *p);
extern void func_021DBC3C(u8 *p);

void func_021DB9E8(void *a, void *b, u8 *p)
{
    func_020437AC(((struct Obj14077 *)p)->f10);
    func_021DBC3C(((struct Obj14077 *)p)->f14);
}

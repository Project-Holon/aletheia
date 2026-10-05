/*
 * function: func_021FB1E4
 * address:  0x021FB1E4
 * packet:   pkt_021FB1E4
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F9D90  0x021F9D90  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23253.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021F9D90(char *p);

int func_021FB1E4(void *a, void **pp)
{
    func_021F9D90(((struct Obj23253 *)((u8 *)*pp))->f34);
    return 0;
}

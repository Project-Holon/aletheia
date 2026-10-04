/*
 * function: func_021DE6F8
 * address:  0x021DE6F8
 * packet:   pkt_021DE6F8
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02010498  0x02010498  thumb
 *   func_0201058C  0x0201058C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22915.h"

typedef unsigned int u32;

extern void func_02010498(int, int, void *);
extern u32 func_0201058C(void *key);

void func_021DE6F8(int a, int b, char *c)
{
    func_02010498(a, b, c);
    ((struct Obj22915 *)c)->f54 = func_0201058C(0);
}

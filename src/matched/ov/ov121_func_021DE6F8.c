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
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22915.h"

typedef unsigned int u32;

extern void func_02010498(void);
extern u32 WIH_DWC_PollStatus(void *key);

void func_021DE6F8(int a, int b, char *c)
{
    func_02010498();
    ((struct Obj22915 *)c)->f54 = WIH_DWC_PollStatus(0);
}

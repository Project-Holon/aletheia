/*
 * function: func_021BBF14
 * address:  0x021BBF14
 * packet:   pkt_021BBF14
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCCBC  0x021BCCBC  thumb  ov216
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25767.h"

extern void func_021BCCBC(void *);

int func_021BBF14(char *p)
{
    if (((struct Obj25767 *)p)->fC != 0)
        return 3;
    func_021BCCBC(p);
    return 2;
}

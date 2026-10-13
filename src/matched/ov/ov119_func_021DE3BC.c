/*
 * function: func_021DE3BC
 * address:  0x021DE3BC
 * packet:   pkt_ov119_021DE3BC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_IsNetTypeWifi  0x0203D29C  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DE3E8  0x021DE3E8  thumb  ov119
 */
#include "../include/Obj22743.h"

typedef unsigned int   u32;
extern u32 GFL_NET_IsNetTypeWifi(void);
extern void func_021D8E84(void *p, int next);
extern void func_021DE3E8(char *p);

void func_021DE3BC(char *p)
{
    int lim;
    lim = 3;
    if (GFL_NET_IsNetTypeWifi() != 0) {
        lim = 10;
    }
    if (((struct Obj22743 *)p)->fF2C > lim) {
        func_021D8E84(p, (int)func_021DE3E8);
    }
}

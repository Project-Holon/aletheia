/*
 * function: func_021A4C1C
 * address:  0x021A4C1C
 * packet:   pkt_ov021_021A4C1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A4B54  0x021A4B54  thumb  ov021
 *   func_021A4B98  0x021A4B98  thumb  ov021
 */
#include "../include/Obj19789.h"

typedef unsigned char  u8;
typedef unsigned short u16;

int func_0216D3CC(int b);
int func_021A4B54(int a, int b, u8 *c);
int func_021A4B98(int a, int b, u8 *c);

int func_021A4C1C(int a, int b, u8 *c)
{
    if (func_0216D3CC(b) == 0)
        return 0;
    if (((struct Obj19789 *)c)->f8 == 9)
        return func_021A4B54(a, b, c);
    return func_021A4B98(a, b, c);
}

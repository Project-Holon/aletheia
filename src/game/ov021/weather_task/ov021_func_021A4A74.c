/*
 * function: func_021A4A74
 * address:  0x021A4A74
 * packet:   pkt_ov021_021A4A74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A491C  0x021A491C  thumb  ov021
 *   func_021A4994  0x021A4994  thumb  ov021
 */
#include "../../../matched/include/Obj02084.h"

typedef unsigned char  u8;
typedef unsigned short u16;

int func_0216D3CC(int b);
int func_021A491C(int a, int b, u8 *c);
int func_021A4994(u8 *a, void *b, u8 *c);

int func_021A4A74(int a, int b, u8 *c)
{
    if (func_0216D3CC(b) == 0)
        return 0;
    if (((struct Obj02084 *)c)->f8 == 9)
        return func_021A491C(a, b, c);
    return func_021A4994((u8 *)a, (void *)b, c);
}

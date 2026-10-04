/*
 * function: func_021C1D18
 * address:  0x021C1D18
 * packet:   pkt_ov021_021C1D18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 *   func_021C27F4  0x021C27F4  thumb  ov021
 *   func_021C2854  0x021C2854  thumb  ov021
 */
#include "../include/Obj01213.h"
#include "../include/Obj04273.h"

typedef unsigned short u16;
typedef unsigned int u32;

int func_021C1CB0(int a, char *b, int c);
int func_021C27F4(int a, int *b);
int func_021C2854(int a, char *b);

int func_021C1D18(int a, char *b, int c, int d, int e, int f, int g)
{
    char *q;
    int r;

    r = func_021C1CB0(a, b, 3);
    if (r == 0)
        return 0;
    ((struct Obj01213 *)b)->f128 = func_021C27F4;
    ((struct Obj01213 *)b)->f12C = func_021C2854;
    q = b + 0x9c;
    ((struct Obj04273 *)q)->f8 = e;
    ((struct Obj01213 *)b)->f9C = c;
    ((struct Obj04273 *)q)->fC = f;
    ((struct Obj04273 *)q)->f4 = d;
    ((struct Obj04273 *)q)->f10 = g;
    ((struct Obj04273 *)q)->f18 = 5;
    ((struct Obj04273 *)q)->f14 = 1;
    ((struct Obj04273 *)q)->f1A = 0x1e;
    return r;
}

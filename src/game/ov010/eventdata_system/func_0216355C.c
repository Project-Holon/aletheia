/*
 * function: func_0216355C
 * address:  0x0216355C
 * packet:   pkt_0216355C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02163464  0x02163464  thumb  ov010
 *   func_021AC760  0x021AC760  thumb
 */
#include "../../../matched/include/Obj00110.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02163464(int a0, int a1);
extern int func_021AC760();

void func_0216355C(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;

t4 = a1 + 0;
a1 = ((struct Obj00110 *)t4)->fE;
t5 = a0 + 0;
a0 = 0x20;
    if ((a0 & a1) == 0) goto loc_0216357E;
loc_0216356A:
a0 = ((struct Obj00110 *)t4)->fA;
a1 = ((struct Obj00110 *)t4)->f18;
    a0 = func_02163464(a0, a1);
loc_02163572:
a3 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t5 + 0;
a2 = 1;
    a0 = func_021AC760(a0, a1, a2, a3);
loc_0216357E:
    return;}

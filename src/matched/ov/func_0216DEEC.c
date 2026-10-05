/*
 * function: func_0216DEEC
 * address:  0x0216DEEC
 * packet:   pkt_0216DEEC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 */
#include "../include/Obj17852.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 func_0216D4F0(void *p);
extern int func_0216D55C(int a0, int a1);

int func_0216DEEC(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t4 = 0;
    a0 = func_0216D4F0((void *)a0);
loc_0216DEF6:
t7 = 1;
t5 = ((struct Obj17852 *)t5)->f18;
t6 = a0 + 0;
t7 = t7 << 8;
loc_0216DEFE:
a0 = t5 + 0;
a1 = 1;
    a0 = func_0216D55C(a0, a1);
loc_0216DF06:
    if (a0 != 0) goto loc_0216DF0E;
loc_0216DF0A:
a0 = t5 + 0;
    return a0;
loc_0216DF0E:
t4 = t4 + 1;
t5 = t5 + t7;
    if (t4 < t6) goto loc_0216DEFE;
loc_0216DF16:
a0 = 0;
    return a0;}

/*
 * function: func_0216DF64
 * address:  0x0216DF64
 * packet:   pkt_ov010_0216DF64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030DA8  0x02030DA8  arm
 *   func_0216D4F4  0x0216D4F4  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D514  0x0216D514  thumb  ov010
 *   func_0216D3A8  0x0216D3A8  thumb  ov010
 */
#include "../include/Obj19133.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 func_0216D4F4(void *p);
extern u16 func_0216D5A0(void *p);
extern u16 func_0216D588(void *p);
extern u32 func_0216D514(void *p);
extern void func_0216D3A8(u32 a, u32 b);
extern int func_02030DA8(int owner, int fn, int arg, int n);

void func_0216DF64(u8 *o, u32 b)
{
    int d = 0;
    int base = func_0216D4F4((void *)b);
    int t = func_0216D5A0(o);

    if (t == 0x30 || t == 0x32)
        d = 1;
    else if (func_0216D588(o) == 0xff)
        d--;
    ((struct Obj19133 *)o)->f84 = func_02030DA8(func_0216D514((void *)b), (int)func_0216D3A8, (int)o, base + d);
}

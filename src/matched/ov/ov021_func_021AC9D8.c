/*
 * function: func_021AC9D8
 * address:  0x021AC9D8
 * packet:   pkt_ov021_021AC9D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   d_021D90C0     0x021D90C0  data
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05039.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern u16 func_0216D608(void *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern u8 d_021D90C0[];

int func_021AC9D8(u8 *p)
{
    u32 a = ((struct Obj05039 *)p)->f8;
    u32 x = func_0216D83C((void *)a);
    u32 y = func_0216D86C((void *)a);
    u32 f = d_021D90C0[((struct Obj05039 *)p)->f24];
    if (((struct Obj05039 *)p)->fC == x && ((struct Obj05039 *)p)->f10 == y)
        goto yes;
    if (f == 0 && func_0216D608((void *)a) == 0) {
        x = func_0216D804((void *)a);
        y = func_0216D81C((void *)a);
        if (((struct Obj05039 *)p)->fC == x && ((struct Obj05039 *)p)->f10 == y)
            return 1;
    }
    return 0;
yes:
    return 1;
}

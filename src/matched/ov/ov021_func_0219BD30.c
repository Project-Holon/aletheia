/*
 * function: func_0219BD30
 * address:  0x0219BD30
 * packet:   pkt_ov021_0219BD30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_021642B4  0x021642B4  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 */
#include "../include/Obj05999.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern u16 func_021642B4(int x0, int y0, int x1, int y1);
extern int func_021641E8(int a);
extern u32 func_021641F8(u16);
extern u32 func_02197E7C(u16, u32);
extern void func_0216D438(int a0, int a1);

int func_0219BD30(u32 a, u32 b)
{
    u32 x = func_0216D83C((void *)a);
    u32 y = func_0216D86C((void *)a);
    u32 px = func_0216D83C((void *)(((struct Obj05999 *)b)->f8));
    u32 py = func_0216D86C((void *)(((struct Obj05999 *)b)->f8));
    u32 pz = func_0216D804((void *)(((struct Obj05999 *)b)->f8));
    u32 pw = func_0216D81C((void *)(((struct Obj05999 *)b)->f8));
    u32 r;
    if (x == px && y == py) {
        return 0;
    }
    r = func_021642B4(x, y, pz, pw);
    x += (u32)func_021641E8((u16)r);
    y += func_021641F8(r);
    if (x != px || y != py) {
        func_0216D438(a, (u16)func_02197E7C(r, 12));
        return 1;
    }
    return 0;
}

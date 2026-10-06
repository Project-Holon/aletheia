/*
 * function: func_0216D1C8
 * address:  0x0216D1C8
 * packet:   pkt_ov010_0216D1C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D58C  0x0216D58C  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D5BC  0x0216D5BC  thumb  ov010
 *   func_0216DB98  0x0216DB98  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 */
#include "../include/Obj19119.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0216D58C(void *p, u16 v);
extern void func_0216D548(u32 *p, u32 v);
extern void func_0216D568(void *p, u32 v);
extern int func_0216D5BC(void *p);
extern void func_0216DB98(void *p, u32 v);
extern void func_0216D4B4(char *p);

void func_0216D1C8(u8 *p, u32 a, u32 b)
{
    ((struct Obj19119 *)p)->f88 = a;
    func_0216D58C(p, (u16)b);
    func_0216D548((u32 *)p, 1);
    func_0216D568(p, 0x1800);
    if (func_0216D5BC(p) == 1)
        func_0216DB98(p, 1);
    func_0216D4B4((char *)p);
}

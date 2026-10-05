/*
 * function: func_021F88A4
 * address:  0x021F88A4
 * packet:   pkt_021F88A4
 * region:   ov184
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021FEEC0  0x021FEEC0  thumb  ov186
 *   func_021FBDA4  0x021FBDA4  thumb  ov186
 *   func_021FC1F8  0x021FC1F8  thumb  ov186
 *   func_021FC610  0x021FC610  thumb  ov186
 *   func_021F3AF0  0x021F3AF0  thumb  ov112
 */
#include "../include/Obj06618.h"
#include "../include/Obj08319.h"
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021FEEC0(char *p, int mode, u32 value);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FC1F8(int *p, int i);
extern void func_021FC610(u32 a, u16 b);
extern u32 func_021F3AF0(u32 a, u16 b);

void func_021F88A4(char *p, char *q)
{
    if (((struct Obj06618 *)p)->f0 != 0)
        return;
    func_021FEEC0((char *)(((struct Obj08319 *)q)->f4), 0, 0);
    func_021FBDA4(((struct Obj08319 *)q)->fC, 0);
    func_021FC1F8((int *)(((struct Obj08319 *)q)->fC), 0);
    func_021FC610(((struct Obj08319 *)q)->f8, ((struct Obj06618 *)p)->f24);
    ((struct Obj06618 *)p)->f0 = func_021F3AF0(((struct Obj06618 *)p)->f28, ((struct Obj06618 *)p)->f24);
}

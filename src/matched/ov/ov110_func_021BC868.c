/*
 * function: func_021BC868
 * address: 0x021BC868
 * packet: pkt_ov110_021BC868
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9BA4 0x021B9BA4 thumb ov110
 *   func_021BC8C0 0x021BC8C0 thumb ov110
 *   _s32_div_f 0x0209C0A4 arm
 */
#include "../include/Obj03753.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_021B9BA4(void (*fn)(void *, u8 *), u8 *p, int n);
extern void func_021BC8C0(void *, u8 *);
extern int _s32_div_f(int, int);
void func_021BC868(u8 *p, int a, int b, int start, int end, int frames)
{
    ((struct Obj03753 *)p)->f0 = a;
    ((struct Obj03753 *)p)->f4 = b;
    ((struct Obj03753 *)p)->f14 = frames;
    ((struct Obj03753 *)p)->f8 = start;
    ((struct Obj03753 *)p)->f10 = _s32_div_f(end - start, frames);
    ((struct Obj03753 *)p)->fC = end;
    ((struct Obj03753 *)p)->f18 = 0;
    ((struct Obj03753 *)p)->f1C = func_021B9BA4(func_021BC8C0, p, 0);
}

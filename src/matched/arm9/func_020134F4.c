/*
 * function: func_020134F4
 * address:  0x020134F4
 * packet:   pkt_02013360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020134F4.c \
 *       --func func_020134F4 --addr 0x020134F4 --cc 1.1p1 --thumb
 */
#include "../include/Obj00155.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void func_020130C4(u8 *p);
extern void func_02013360(u8 *o, void *a1, const void *a2);
extern int func_0201333C(int a0, int a1, int a2);

void func_020134F4(u8 *p, u32 a1, u32 a2, u32 a3, u16 h)
{
    func_020130C4(p);
    func_02013360(p, (void *)a1, (const void *)a3);
    func_0201333C((int)p, a1, h);
    ((struct Obj00155 *)p)->f0 = 1;
    ((struct Obj00155 *)p)->f4 = a2;
    ((struct Obj00155 *)p)->f1A = 0x47d;
}

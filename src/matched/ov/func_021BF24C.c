/*
 * function: func_021BF24C
 * address:  0x021BF24C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE7EC  0x021BE7EC  thumb  ov099
 *   func_021BB2B0  0x021BB2B0  thumb  ov099
 *   func_021C2090  0x021C2090  thumb  ov099
 *
 * Under a positive answer from func_021BE7EC, routes on the flag at +0x8EF:
 * hands the selector to func_021BB2B0 when set, otherwise raises the word at
 * +0x8F4 and calls func_021C2090.
 */
#include "../include/Obj06353.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern int func_021BE7EC(char *p);
extern void func_021BB2B0(char *p, int v);
extern void func_021C2090(char *p);

void func_021BF24C(u8 *p, int v)
{
    if (func_021BE7EC((char *)p) <= 0) {
        return;
    }

    if (p[0x8EF] != 0) {
        func_021BB2B0((char *)p, v);
        return;
    }

    ((struct Obj06353 *)p)->f8F4 = 1;
    func_021C2090((char *)p);
}

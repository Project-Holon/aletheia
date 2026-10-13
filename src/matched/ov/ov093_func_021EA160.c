/*
 * function: func_021EA160
 * address:  0x021EA160
 * packet:   pkt_ov093_021EA160
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   func_021ED208  0x021ED208  thumb  ov093
 *   func_021ED250  0x021ED250  thumb  ov093
 *   func_021EA32C  0x021EA32C  thumb  ov093
 */
#include "../include/Obj10108.h"
#include "../include/Obj10109.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_021E9100(u8 *p, int n);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void func_021ED208(char *p, u8 k, u16 a, int flag);
extern int func_021ED250(char *p);
extern void func_021EA32C(u8 *p, int k);

int func_021EA160(int *st, char *ctx)
{
    u8 *t;

    t = func_021E9100((u8 *)ctx, 0xc);
    switch (*st) {
    case 0:
        func_021ED208(*(char * *)&((struct Obj10108 *)ctx)->f17C, t[0xa], ((struct Obj10109 *)t)->f0, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj10108 *)ctx)->f4));
        func_021EA32C((u8 *)ctx, ((struct Obj10109 *)t)->f4);
        *st = *st + 1;
        break;
    case 1:
        if (func_021ED250(*(char * *)&((struct Obj10108 *)ctx)->f17C) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

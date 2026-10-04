/*
 * function: func_021BCE80
 * address:  0x021BCE80
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCBD8  0x021BCBD8  thumb  ov099
 *   func_021BBEB4  0x021BBEB4  thumb  ov099
 *
 * Re-arms through func_021BCBD8, hands the owner record class byte to
 * func_021BBEB4 and stamps selector 0x5D; returns the selector.
 */
#include "../include/Obj12113.h"
#include "../include/Obj18202.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void func_021BCBD8(void *p, int b);
extern void func_021BBEB4(void *p, int a, int b, int c);

int func_021BCE80(char *p, int v)
{
    func_021BCBD8(p, 1);
    func_021BBEB4(p, 0, ((struct Obj18202 *)(*(char * *)&((struct Obj12113 *)p)->f248))->f20, 0);
    ((struct Obj12113 *)p)->f1CC = 0x5D;
    return v;
}

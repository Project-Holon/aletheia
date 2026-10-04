/*
 * function: func_021C5308
 * address:  0x021C5308
 * packet:   pkt_ov093_021C5308
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021CB2D4  0x021CB2D4  thumb  ov093
 *   func_021C5350  0x021C5350  thumb  ov093
 */
#include "../include/Obj05193.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern unsigned char func_021B9A40(unsigned int x);
extern u8 func_021B8FF4(u8 *);
extern char *func_021B9AEC(char *, int);
extern void func_021CB2D4(u8 *p, char *g, u8 *a, u8 *q);
extern int func_021C5350(u8 *p, char *g, u8 *q);

int func_021C5308(u8 *p, u8 *a)
{
    char *g;
    if (func_021B9A40(func_021D5440(a)) == 1) {
        g = func_021B9AEC(*(char * *)&((struct Obj05193 *)p)->f8, func_021B8FF4(*(u8 * *)&((struct Obj05193 *)p)->f4));
        func_021CB2D4(p, g, a, p + 0x1B08);
        return func_021C5350(p, g, p + 0x1B08);
    }
    return 0;
}

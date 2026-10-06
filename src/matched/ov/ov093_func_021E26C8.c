/*
 * function: func_021E26C8
 * address:  0x021E26C8
 * packet:   pkt_ov093_021E26C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021E03F8  0x021E03F8  thumb  ov093
 */
#include "../include/Obj10080.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
struct QQ;
extern u16 func_021D70A8(struct QQ *p);
extern void func_021E03F8(int a, int b);

void func_021E26C8(void *u, int a, int b, int *p)
{
    u8 *s;

    s = func_021C88A4((char *)a, 0xb, b);
    s[8] = b;
    s[0x14] = 1;
    ((struct Obj10080 *)s)->f4 = 0x19;
    func_021C88C8((void *)a, s);
    p[6] = 0;
    func_021E03F8(b, func_021D70A8(u));
}

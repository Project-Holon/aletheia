/*
 * function: ov021_func_021A4AA8
 * address:  0x021A4AA8
 * packet:   pkt_ov021_021A4AA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A4994  0x021A4994  thumb  ov021
 *   func_021A491C  0x021A491C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02084.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_0216D5F8(void *p);
extern void *func_0216D4B4(char *p);
extern int func_0216D3CC(int a0);
extern int func_021A4994(u8 *a, void *b, u8 *c);
extern int func_021A491C(u32, u32, u32);

int ov021_func_021A4AA8(u32 a, u32 b, u8 *c)
{
    u32 r = func_0216D5F8((void *)b);
    if (((struct Obj02084 *)c)->f8 != 9 && ((struct Obj02084 *)c)->f8 != r) {
        func_0216D4B4((char *)b);
        return func_021A4994((u8 *)a, (void *)b, (u8 *)((u32)c));
    }
    if (func_0216D3CC(b) == 0) {
        return 0;
    }
    if (((struct Obj02084 *)c)->f8 == 9) {
        return func_021A491C(a, b, (u32)c);
    }
    return func_021A4994((u8 *)a, (void *)b, (u8 *)((u32)c));
}

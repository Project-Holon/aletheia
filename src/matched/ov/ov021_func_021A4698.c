/*
 * function: ov021_func_021A4698
 * address:  0x021A4698
 * packet:   pkt_ov021_021A4698
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
 *   func_021A4598  0x021A4598  thumb  ov021
 *   func_021A4544  0x021A4544  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01657.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_0216D5F8(void *p);
extern void func_0216D4B4(char *p);
extern int func_0216D3CC(int a0);
extern int func_021A4598(u8 *a, void *b, u8 *c);
extern int func_021A4544(u8 *p, u32 r, u8 *q);

int ov021_func_021A4698(u32 a, u32 b, u8 *c)
{
    u32 r = func_0216D5F8((void *)b);
    if (((struct Obj01657 *)c)->f8 != 9 && ((struct Obj01657 *)c)->f8 != r) {
        func_0216D4B4((char *)b);
        return func_021A4598((u8 *)a, (void *)b, (u8 *)((u32)c));
    }
    if (func_0216D3CC(b) == 0) {
        return 0;
    }
    if (((struct Obj01657 *)c)->f8 == 9) {
        return func_021A4544((u8 *)a, b, (u8 *)((u32)c));
    }
    return func_021A4598((u8 *)a, (void *)b, (u8 *)((u32)c));
}

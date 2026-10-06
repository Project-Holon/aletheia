/*
 * function: func_021A4F0C
 * address:  0x021A4F0C
 * packet:   pkt_ov021_021A4F0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A5630  0x021A5630  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DCE8  0x0216DCE8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19794.h"
#include "../include/Obj19795.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A5630(u32);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(u32, u32);
extern int func_0216DB4C(void *a0, int a1);
extern int func_0216DCE8(void *a0, int a1);
extern void *func_0216D568(void *p, u32 v);

void func_021A4F0C(u32 a, void *b, u32 c)
{
    u32 x = ((struct Obj19795 *)c)->f8;
    if (x == 9) {
        x = func_021A5630(a);
    }
    func_0216D410((u32)b, func_02197E7C(x, 0x34));
    func_0216DB4C(b, 1);
    func_0216DCE8((void *)b, 1);
    func_0216D568((void *)b, 0x8000);
    ((struct Obj19794 *)a)->f0 = 5;
}

/*
 * function: func_021C5C1C
 * address:  0x021C5C1C
 * packet:   pkt_ov093_021C5C1C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6034  0x021D6034  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { int x; } S;
extern u8 func_021D5440(u8 *p);
extern void func_021D6034(u8 *a, int k, S s);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021E8A78(S s);

void func_021C5C1C(u8 *p, u8 *a, int k, S s)
{
    u8 n = func_021D5440(a);
    func_021D6034(a, k, s);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0xf, n, (u8)k, s.x);
    if (k < 6) {
        if (k == 5 && func_021E8A78(s)) k = 6;
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x35, n, k);
    }
}

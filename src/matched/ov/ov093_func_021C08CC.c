/*
 * function: func_021C08CC
 * address:  0x021C08CC
 * packet:   pkt_ov093_021C08CC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B911C  0x021B911C  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5608  0x021D5608  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D56CC  0x021D56CC  thumb  ov093
 */
#include "../include/Obj09966.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021B911C(void *p, int k);
extern u8 func_021D5440(u8 *p);
struct UtilWork;
extern void func_021D5608(struct UtilWork *p, int i, u8 n);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
struct Work;
extern void func_021D56CC(struct Work *p, int i);

void func_021C08CC(u8 *p, u8 *a, int b, u8 c)
{
    u32 n;
    if (func_021B911C(((struct Obj09966 *)p)->f4, 5) == 0) {
        n = func_021D5440(a);
        func_021D5608((struct UtilWork *)a, b, c);
        func_021CD4B0(((struct Obj09966 *)p)->fC, 4, n, b, c);
        func_021D56CC((struct Work *)a, b);
        func_021CD4B0(((struct Obj09966 *)p)->fC, 6, n, b);
    }
}

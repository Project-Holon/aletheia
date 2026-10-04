/*
 * function: func_021B9748
 * address:  0x021B9748
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF308  0x021BF308  arm  ov114
 *
 * Unlinks the record's +0x0c owner from list class 2, keyed 0x3f6.  Both
 * early exits are the ELSE arm of their test, which sinks each tiny return
 * block out of line (0x021B9766, then 0x021B976A last).
 */
#include "../include/Obj22571.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BF308(int);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);

int func_021B9748(u8 *p)
{
    int h;

    if (p != 0) {
        h = func_021BF308(((struct Obj22571 *)p)->fC);
        if (h != 0) {
            func_0203C9AC(h, 2, h, 0x3f6);
            return h;
        }
        return 0;
    }
    return 1;
}

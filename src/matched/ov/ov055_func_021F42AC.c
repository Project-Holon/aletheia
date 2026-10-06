/*
 * function: func_021F42AC
 * address:  0x021F42AC
 * packet:   pkt_ov055_021F42AC
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * d and e are u16, as are func_021F4318's last two parameters (its own
 * file): with u32 the stack parameter's load (ldr r6, [sp, #0x20]) sinks to
 * the first call instead of leading the prologue.
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_021F4318  0x021F4318  thumb  ov055
 */
#include "../include/Obj00204.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Rec;
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D55C(int a, int b);
extern int func_0216DAB4(void *a);
extern int func_021F4318(const u8 *a, void *b, u16 c, u16 d);

int func_021F42AC(u8 *a, void *b, u32 *c, u16 d, u16 e)
{
    u32 iter = 0;
    u32 cur;

    while (func_0216DD1C(b, (struct Rec **)(&cur), &iter) == 1) {
        if (*(u32 *)&((struct Obj00204 *)a)->fC != cur && func_0216D55C(cur, 0x80) == 0 &&
            func_0216DAB4((void *)cur) == 0 && func_021F4318(a, (void *)cur, d, e) != 0) {
            *c = cur;
            return 1;
        }
    }
    return 0;
}

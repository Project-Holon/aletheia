/*
 * function: func_021F4020
 * address:  0x021F4020
 * packet:   pkt_ov046_021F4020
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 */

typedef unsigned int u32;
extern void *func_02188C7C(unsigned char *p);
struct Ctx;
struct Rec;
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
typedef unsigned short u16;
extern u16 func_0216D588(void *p);

int func_021F4020(u32 a, int b)
{
    int s1 = 0;
    int s0;
    void *it = func_02188C7C((void *)a);

    while (func_0216DD1C(it, (struct Rec **)(&s0), (u32 *)(&s1)) == 1) {
        if (b == func_0216D588((void *)s0))
            return s0;
    }
    return 0;
}

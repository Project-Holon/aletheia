/*
 * function: func_0216DF1C
 * address:  0x0216DF1C
 * packet:   pkt_ov010_0216DF1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D55C(int a0, int a1);
extern u16 func_0216D588(void *p);
extern void func_0216CF2C(u8 *o);

void func_0216DF1C(u32 x)
{
    int n;
    u8 *o;
    u32 k = 0x20;

    n = 0;
    while (func_0216DD1C((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n))) {
        if (func_0216D55C((int)o, k) == 0) {
            func_0216D588(o);
            func_0216CF2C(o);
        }
    }
}

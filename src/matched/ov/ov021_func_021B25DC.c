/*
 * function: func_021B25DC
 * address:  0x021B25DC
 * packet:   pkt_ov021_021B25DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F398C  0x021F398C  thumb  ov043
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
typedef unsigned short u16;
struct Stream;
extern u16 func_02011330(struct Stream *s);
extern int func_021F398C(void *a, int b);
extern void func_0215897C(void *vm, void *task);

int func_021B25DC(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F398C(d, func_02011330((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}

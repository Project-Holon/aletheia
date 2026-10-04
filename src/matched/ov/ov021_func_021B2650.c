/*
 * function: func_021B2650
 * address:  0x021B2650
 * packet:   pkt_ov021_021B2650
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F3770  0x021F3770  thumb  ov044
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
typedef unsigned short u16;
struct Stream;
extern u16 func_02011330(struct Stream *s);
extern u32 func_021F3770(void *, u32);
extern void func_0215897C(void *vm, void *task);

int func_021B2650(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F3770(d, func_02011330((struct Stream *)a) ? 1 : 0);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}

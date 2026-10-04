/*
 * function: func_021B24F4
 * address:  0x021B24F4
 * packet:   pkt_ov021_021B24F4
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
 *   func_021F3888  0x021F3888  thumb  ov042
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
typedef unsigned short u16;
struct Stream;
extern u16 func_02011330(struct Stream *s);
extern int func_021F3888(void *a, u32 b);
extern void func_0215897C(void *vm, void *task);

int func_021B24F4(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330((struct Stream *)a);
    u32 r = func_021F3888(d, k);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}

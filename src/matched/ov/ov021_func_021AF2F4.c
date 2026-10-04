/*
 * function: func_021AF2F4
 * address:  0x021AF2F4
 * packet:   pkt_ov021_021AF2F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Stream;
extern u16 func_02011330(struct Stream *s);
extern void *func_02029830(void *a, u32 b);
extern void func_0215897C(void *vm, void *task);

int func_021AF2F4(u32 a, u32 b)
{
    void *y = func_0215A5DC((void *)b);
    void *x = func_0215A5F4((void *)b);

    func_0215897C(x, func_02029830(y, func_02011330((struct Stream *)a)));
    return 1;
}

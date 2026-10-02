/*
 * function: func_021AEC84
 * address:  0x021AEC84
 * packet:   pkt_ov021_021AEC84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE92C  0x021BE92C  thumb  ov021
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
extern void *func_0201210C(void *p);
extern u32 func_021BE92C(void *a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0215897C(void *a, u32 b);

int func_021AEC84(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);

    func_0215897C(x, func_021BE92C(y, func_0201210C((void *)y), 0, 0, 1, 0, 0));
    return 1;
}

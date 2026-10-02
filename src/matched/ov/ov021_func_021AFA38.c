/*
 * function: func_021AFA38
 * address:  0x021AFA38
 * packet:   pkt_ov021_021AFA38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D50  0x02188D50  thumb  ov021
 *   func_021C34F8  0x021C34F8  thumb  ov021
 *   func_0201EEF4  0x0201EEF4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u32 func_02158F74(void *a);
extern u32 func_02159B10(Script *, u32);
extern void *func_0201210C(void *p);
extern u32 func_02188D50(u8 *);
extern u32 func_021C34F8(u32, u32);
extern void func_0201EEF4(u32, u32, u32);

int func_021AFA38(Script *a, u32 b)
{
    u32 x = func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = func_02159B10(a, b);
    func_0201EEF4(x, v, func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC((void *)b))), e));
    return 0;
}

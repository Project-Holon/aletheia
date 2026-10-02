/*
 * function: func_021AEC40
 * address:  0x021AEC40
 * packet:   pkt_ov021_021AEC40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Compiled 66 of a 68-byte extent: the trailing halfword is an unlabelled
 * follower.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0202A230  0x0202A230  thumb
 *   func_02029E20  0x02029E20  thumb
 *   func_02029AF4  0x02029AF4  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern void *func_0215A5F4(void *p);
extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_0202A230(u32 a, u32 b);
extern unsigned short func_02029E20(u32 k);
extern u32 func_02029AF4(void *a, u32 b);
extern void func_0215897C(void *a, u32 b);

int func_021AEC40(u32 a, u32 b)
{
    void *x;
    void *y;

    x = func_0215A5DC((void *)b);
    func_0215A5E4((void *)b);
    y = func_0215A5F4((void *)b);
    func_0215897C(y, func_02029AF4(x, func_02029E20(func_0202A230(func_02159B10(a, b), 1))));
    return 1;
}

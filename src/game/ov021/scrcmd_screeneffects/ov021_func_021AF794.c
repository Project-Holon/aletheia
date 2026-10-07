/*
 * function: func_021AF794
 * address:  0x021AF794
 * packet:   pkt_ov021_021AF794
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
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
extern void *func_02158F74(void *p);
extern unsigned int func_02159B10(void *, void *);

int func_021AF794(Script *a, u32 b, void (*fn)(u32, u32, u32))
{
    u32 x = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    a->cur = p + 1;
    fn(x, v, func_02159B10(a, (void *)b));
    return 0;
}

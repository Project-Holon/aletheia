/*
 * function: func_021AF8D8
 * address:  0x021AF8D8
 * packet:   pkt_ov021_021AF8D8
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
extern u32 func_02158F74(u32);
extern u32 func_02159B10(Script *, u32);

int func_021AF8D8(Script *a, u32 b, void (*fn)(u32, u32, u32))
{
    u32 x = func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    a->cur = p + 1;
    fn(x, v, func_02159B10(a, b));
    return 0;
}

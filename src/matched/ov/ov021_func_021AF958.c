/*
 * function: func_021AF958
 * address:  0x021AF958
 * packet:   pkt_ov021_021AF958
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201EE84  0x0201EE84  thumb
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
extern void *func_0215A5E4(void *a0);
extern u32 func_02158F74(void *a);
extern u32 func_02159B10(Script *, u32);
extern void *func_02012934(void *p);
extern u32 func_0201AB28(void *, u32);
extern void func_0201EE84(u32, u32, u32);

int func_021AF958(Script *a, u32 b)
{
    void *c = func_0215A5F4((void *)b);
    void *d = func_0215A5E4((void *)b);
    u32 x = func_02158F74(c);
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = func_02159B10(a, b);
    func_0201EE84(x, v, func_0201AB28(func_02012934((void *)d), e));
    return 0;
}

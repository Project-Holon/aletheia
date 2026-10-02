/*
 * function: func_021AF684
 * address:  0x021AF684
 * packet:   pkt_ov021_021AF684
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201292C  0x0201292C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0215A5CC(u32);
extern void *func_0215A5E4(void *a0);
extern u32 func_02159B10(u32, u32);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0201292C(void *p);
extern u16 func_02007FB8(void *, u32, u32);

int func_021AF684(u32 a, u32 b)
{
    u32 c = func_0215A5CC(b);
    void *d;
    u32 e;
    u16 *p;
    d = func_0201292C(func_0215A5E4((void *)b));
    e = func_02159B10(a, b);
    p = func_02159AE8((void *)a, (void *)b);
    *p = func_02007FB8(d, e, c);
    return 0;
}

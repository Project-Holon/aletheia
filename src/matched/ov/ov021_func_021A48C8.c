/*
 * function: ov021_func_021A48C8
 * address:  0x021A48C8
 * packet:   pkt_ov021_021A48C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A491C  0x021A491C  thumb  ov021
 *   func_021A4994  0x021A4994  thumb  ov021
 *   func_021A4A74  0x021A4A74  thumb  ov021
 *   func_021A4AA8  0x021A4AA8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_021A3960(unsigned char *p);
extern int func_021A491C(u8 *, u32, u32);
extern int func_021A4994(u8 *, u32, u32);
extern int func_021A4A74(u8 *, u32, u32);
extern int func_021A4AA8(u8 *, u32, u32);

int ov021_func_021A48C8(u8 *a, u32 b)
{
    void *r = func_021A3960(*(void **)(a + 12));
    int ret = 0;
    switch (*(u32 *)a) {
    case 0:
        ret = func_021A491C(a, r, b);
        break;
    case 1:
        ret = func_021A4994(a, r, b);
        break;
    case 2:
        ret = func_021A4A74(a, r, b);
        break;
    case 3:
        ret = func_021A4AA8(a, r, b);
        break;
    }
    return ret;
}

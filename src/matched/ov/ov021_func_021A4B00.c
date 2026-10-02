/*
 * function: ov021_func_021A4B00
 * address:  0x021A4B00
 * packet:   pkt_ov021_021A4B00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A4B54  0x021A4B54  thumb  ov021
 *   func_021A4B98  0x021A4B98  thumb  ov021
 *   func_021A4C1C  0x021A4C1C  thumb  ov021
 *   func_021A4C50  0x021A4C50  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_021A3960(unsigned char *p);
extern int func_021A4B54(u8 *, void *, u32);
extern int func_021A4B98(u8 *, void *, u32);
extern int func_021A4C1C(u8 *, void *, u32);
extern int func_021A4C50(u8 *, void *, u32);

int ov021_func_021A4B00(u8 *a, u32 b)
{
    void *r = func_021A3960(*(void **)(a + 12));
    int ret = 0;
    switch (*(u32 *)a) {
    case 0:
        ret = func_021A4B54(a, r, b);
        break;
    case 1:
        ret = func_021A4B98(a, r, b);
        break;
    case 2:
        ret = func_021A4C1C(a, r, b);
        break;
    case 3:
        ret = func_021A4C50(a, r, b);
        break;
    }
    return ret;
}

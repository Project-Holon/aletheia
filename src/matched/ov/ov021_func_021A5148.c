/*
 * function: func_021A5148
 * address:  0x021A5148
 * packet:   pkt_ov021_021A5148
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A51A4  0x021A51A4  thumb  ov021
 *   func_021A51A8  0x021A51A8  thumb  ov021
 *   func_021A51D8  0x021A51D8  thumb  ov021
 *   func_021A5204  0x021A5204  thumb  ov021
 *   func_021A5228  0x021A5228  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(unsigned char *p);
extern void func_021A51A4(u32, void *, u32);
extern void func_021A51A8(u32, void *, u32);
extern void func_021A51D8(u32, void *, u32);
extern void func_021A5204(u32, void *, u32);
extern void func_021A5228(u32, void *, u32);

void func_021A5148(u32 a, u32 b, u32 c)
{
    void *x = func_021A3960(*(void **)(a + 12));
    switch (b) {
    case 0: func_021A51A4(a, x, c); return;
    case 1: func_021A51A8(a, x, c); return;
    case 2: func_021A51D8(a, x, c); return;
    case 3: func_021A5204(a, x, c); return;
    case 4: func_021A5228(a, x, c); break;
    }
}

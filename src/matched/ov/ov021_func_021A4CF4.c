/*
 * function: func_021A4CF4
 * address:  0x021A4CF4
 * packet:   pkt_ov021_021A4CF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A4D8C  0x021A4D8C  thumb  ov021
 *   func_021A4D90  0x021A4D90  thumb  ov021
 *   func_021A4DC0  0x021A4DC0  thumb  ov021
 *   func_021A4E78  0x021A4E78  thumb  ov021
 *   func_021A4E9C  0x021A4E9C  thumb  ov021
 *   func_021A4ED8  0x021A4ED8  thumb  ov021
 *   func_021A4F04  0x021A4F04  thumb  ov021
 *   func_021A4F0C  0x021A4F0C  thumb  ov021
 *   func_021A4F50  0x021A4F50  thumb  ov021
 *   func_021A4F58  0x021A4F58  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(unsigned char *p);
extern void func_021A4D8C(u32 a, u32 b, u32 c);
extern void func_021A4D90(u32 *p, int b, u8 *c);
extern void func_021A4DC0(u32 *a, u32 b, u32 *c);
extern void func_021A4E78(u32 *p, int b, u8 *c);
extern void func_021A4E9C(u32 *p, int b, u8 *c);
extern void func_021A4ED8(u32 *p, int b, u8 *c);
extern void func_021A4F04(u32, void *, u32);
extern void func_021A4F0C(u32 a, u32 b, u32 c);
extern void func_021A4F50(u32, void *, u32);
extern int func_021A4F58(u32, void *, u32);

void func_021A4CF4(u32 a, u32 b, u32 c)
{
    void *x = func_021A3960(*(void **)(a + 12));
    switch (b) {
    case 0: func_021A4D8C(a, (u32)x, c); return;
    case 1: func_021A4D90((u32 *)a, (int)x, (u8 *)c); return;
    case 2: func_021A4DC0((u32 *)a, (u32)x, (u32 *)c); return;
    case 3: func_021A4E78((u32 *)a, (int)x, (u8 *)c); return;
    case 4: func_021A4E9C((u32 *)a, (int)x, (u8 *)c); return;
    case 5: func_021A4ED8((u32 *)a, (int)x, (u8 *)c); return;
    case 6: func_021A4F04(a, x, c); return;
    case 7: func_021A4F0C(a, (u32)x, c); return;
    case 8: func_021A4F50(a, x, c); return;
    case 9: func_021A4F58(a, x, c); break;
    }
}

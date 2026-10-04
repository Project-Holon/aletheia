/*
 * function: func_021A4FA8
 * address:  0x021A4FA8
 * packet:   pkt_ov021_021A4FA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A5010  0x021A5010  thumb  ov021
 *   func_021A5014  0x021A5014  thumb  ov021
 *   func_021A5044  0x021A5044  thumb  ov021
 *   func_021A50BC  0x021A50BC  thumb  ov021
 *   func_021A50E0  0x021A50E0  thumb  ov021
 *   func_021A511C  0x021A511C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(unsigned char *p);
extern void func_021A5010(u32 a, u32 b, u32 c);
extern void func_021A5014(u32 *p, int b, u8 *c);
extern void func_021A5044(u32 *a, u32 b, u32 *c);
extern void func_021A50BC(u32 *p, int b, u8 *c);
extern void func_021A50E0(u32 *p, int b, u8 *c);
extern void func_021A511C(u32 *p, int b, u8 *c);

void func_021A4FA8(u32 a, u32 b, u32 c)
{
    void *x = func_021A3960(*(void **)(a + 12));
    switch (b) {
    case 0: func_021A5010(a, (u32)x, c); return;
    case 1: func_021A5014((u32 *)a, (int)x, (u8 *)c); return;
    case 2: func_021A5044((u32 *)a, (u32)x, (u32 *)c); return;
    case 3: func_021A50BC((u32 *)a, (int)x, (u8 *)c); return;
    case 4: func_021A50E0((u32 *)a, (int)x, (u8 *)c); return;
    case 5: func_021A511C((u32 *)a, (int)x, (u8 *)c); break;
    }
}

/*
 * function: func_021CFF28
 * address:  0x021CFF28
 * packet:   pkt_ov021_021CFF28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_021CFCF4  0x021CFCF4  thumb  ov021
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02009698  0x02009698  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern u32 func_020120F4(void *a);
extern int func_02012F38(int base);
extern u32 func_021CFCF4(u32 a, u32 b);
extern u32 func_02012EBC(u32 a);
extern u32 func_02009470(u32 a);
extern void func_02009698(u32 a, u32 b, u32 c, u32 d);

int func_021CFF28(u32 a, u32 b)
{
    u32 h, p, r;
    u8 k;

    func_0215A5F4((void *)b);
    h = func_020120F4(func_0215A5DC((void *)b));
    p = func_02012F38(h);
    k = func_02159B10((void *)a, (void *)b);
    r = func_021CFCF4(p, k);
    if (r != 0xff) {
        func_02009698(func_02009470(func_02012EBC(h)), r, 5, 1);
    }
    return 0;
}

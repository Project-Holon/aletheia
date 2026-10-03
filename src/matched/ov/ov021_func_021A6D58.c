/*
 * function: func_021A6D58
 * address:  0x021A6D58
 * packet:   pkt_ov021_021A6D58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3664  0x021A3664  thumb  ov021
 *   func_021A36A4  0x021A36A4  thumb  ov021
 *   func_021BB3AC  0x021BB3AC  thumb  ov021
 *   sub_02030734   0x02030734  arm
 *   data_021DDF1C  0x021DDF1C  data  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188C5C(u8 *p);
extern void *func_02188CB4(u8 *p);
extern void func_021A3664(u32 *p, u32 heap);
extern u32 func_021A36A4(u8 *p);
extern void func_021BB3AC(u32 a, u32 b);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char data_021DDF1C[];

u32 *func_021A6D58(void *a, u32 heap)
{
    u32 r7 = func_02188C5C(a);
    u32 *p = sub_02030734(heap, 8, 1, data_021DDF1C, 0x3e);
    void *r6 = func_02188CB4(a);

    *(void **)p = r6;
    func_021A3664(r6, heap);
    func_021BB3AC(r7, func_021A36A4(r6));
    return p;
}

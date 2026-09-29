/*
 * function: func_021F5488
 * address:  0x021F5488
 * packet:   pkt_ov083_021F5488
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201104C  0x0201104C  thumb
 *   func_020110CC  0x020110CC  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_020120F4(void *a);
extern void *func_02012934(void *a);
extern u32   func_0201AB08(void *p);
extern u32   func_0201AB28(void *p, u8 idx);
extern void  func_0201EEF4(void *a, int b, u32 c);
extern u32   func_0201104C(void *p);
extern u32   func_020110CC(void *p);

void func_021F5488(void *a0, void *a1, int a2)
{
    void *h = func_02012934(func_020120F4(a0));
    u8 i;

    i = func_0201AB08(h);
    func_0201EEF4(a1, 1, func_0201AB28(h, i));
    switch (a2) {
    case 5:
        func_0201104C(h);
        break;
    case 6:
        func_020110CC(h);
        break;
    }
}

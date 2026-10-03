/*
 * function: func_021E6054
 * address:  0x021E6054
 * packet:   pkt_ov093_021E6054
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021E60A8  0x021E60A8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern u8 *func_021E60A8(void *a, u32 b, u8 c);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern u32 _u32_div_f(u32, u32);
extern int func_021D76BC(int key, u32 val);

void func_021E6054(u8 *p, void *a, int b, int *c)
{
    void *r;
    if (b != func_021D775C(3))
        return;
    r = func_021E60A8(a, b, *c);
    if (r == 0)
        r = func_021C7CF4(a, b);
    *c = *c + 1;
    if (*c >= 6)
        *c = 0;
    func_021D76BC(0x30, _u32_div_f(func_021D59B4(r, 0x15), 10) + 5);
}

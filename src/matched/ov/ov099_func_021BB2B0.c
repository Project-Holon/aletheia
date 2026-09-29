/*
 * function: func_021BB2B0
 * address:  0x021BB2B0
 * packet:   pkt_ov099_021BB2B0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009864  0x02009864  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021BB528  0x021BB528  thumb  ov099
 *   func_02043598  0x02043598  arm
 */

typedef unsigned char u8;

extern int func_02009864(void *h, int id, int n);
extern void *func_02045770(void *a);
extern void func_02043B5C(void *a, int b);
extern void func_021BB528(void *p, int v);
extern void func_02043598(int a, int b);

void func_021BB2B0(char *p, int v)
{
    func_02009864(*(void **)(p + 4), *(u8 *)(p + 0x8ED) - 1, 9);
    func_02043B5C(func_02045770(*(void **)(p + 0x958)), 0);
    func_021BB528(p, v);
    func_02043598(2, 0);
    func_02043598(8, 1);
}

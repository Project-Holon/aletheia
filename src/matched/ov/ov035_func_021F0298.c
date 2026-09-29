/*
 * function: func_021F0298
 * address:  0x021F0298
 * packet:   pkt_ov035_021F0298
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045790 0x02045790 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045374 0x02045374 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F79C 0x0201F79C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045808 0x02045808 arm
 */

extern int func_02045EC0(int, int);
extern void func_02045790(int, unsigned char);
extern int func_02045770(int);
extern void func_02043B5C(int, int);
extern void func_0201F7A8(int, int);
extern void func_02045374(int);
extern void func_0201C7A4(int, int, int, int, int);
extern void func_0201F79C(int, int, int, int);
extern void func_02045334(int);
extern void func_02045808(int);

void func_021F0298(char *p, int a1, int a2, int a3)
{
    int r7 = func_02045EC0(*(int *)(p + 0x38), a2);

    func_02045790(a1, a3);
    func_02043B5C(func_02045770(a1), 15);
    func_0201F7A8(a1, 2);
    func_02045374(a1);
    func_0201C7A4(func_02045770(a1), 0, 0, r7, *(int *)(p + 0x34));
    func_0201F79C(a1, 0, *(int *)(p + 0x14), 2);
    func_02045334(a1);
    func_02045808(r7);
}

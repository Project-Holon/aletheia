/*
 * function: func_021EFF78
 * address:  0x021EFF78
 * packet:   pkt_ov035_021EFF78
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EFF78 0x021EFF78 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021F000C 0x021F000C thumb ov035
 *   func_021F0140 0x021F0140 thumb ov035
 *   func_021F0168 0x021F0168 thumb ov035
 *   func_0203D34C 0x0203D34C arm
 *   func_021A12D4 0x021A12D4 thumb ov021
 */

extern int func_0201D7EC(int, int, int, int, int);
extern void func_0201DD68(void);
extern int func_02045B38(int, int, int, int);
extern int func_0201C440(int);
extern void func_021F000C(void *, int);
extern void func_021F0140(void *, int);
extern void func_021F0168(void *, int);
extern void func_0203D34C(int, int);
extern void func_021A12D4(int, int);

void func_021EFF78(char *p, int a1)
{
    *(int *)(p + 0x34) = func_0201D7EC(0x17, 0, 0, 0, a1);
    func_0201DD68();
    *(int *)(p + 0x38) = func_02045B38(0, 2, 0x16, a1);
    *(int *)(p + 0x3C) = func_0201C440(a1);
    func_021F000C(p, a1);
    func_021F0140(p, a1);
    func_021F0168(p, a1);
    func_0203D34C(0, a1);
    func_021A12D4(*(int *)(p + 0xC), a1);
}

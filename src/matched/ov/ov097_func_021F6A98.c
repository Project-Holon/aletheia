/*
 * function: func_021F6A98
 * address:  0x021F6A98
 * packet:   pkt_ov097_021F6A98
 * region:   ov097
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_021F6B7C  0x021F6B7C  thumb  ov097
 *   func_021F6CE4  0x021F6CE4  thumb  ov097
 *   func_021F6D70  0x021F6D70  thumb  ov097
 *   func_021F6EE8  0x021F6EE8  thumb  ov097
 */

extern void func_02045088(int);
extern int func_020450F0(int, int, int, int, int, int, int);
extern int func_02045770(int);
extern void func_02043B5C(int, int);
extern void func_02045334(int);
extern void func_021F6B7C(int, int);
extern void func_021F6CE4(int, int);
extern void func_021F6D70(int, int);
extern void func_021F6EE8(int, int);

void func_021F6A98(int a)
{
    unsigned int i;
    int *p;

    func_02045088(0x71);
    for (i = 0; i < 6; i++)
        *(int *)(a + i * 8 + 0x20) = func_020450F0(0, 0, 0, 0xf, 5, 9, 1);
    for (i = 0; i < 6; i++) {
        p = (int *)(a + i * 8);
        func_02043B5C(func_02045770(p[8]), 0);
        if (*(int *)(a + i * 4 + 0xf8) != 0) {
            func_021F6B7C(a, i);
            func_021F6CE4(a, i);
            func_021F6D70(a, i);
            func_021F6EE8(a, i);
        } else {
            func_02045334(p[8]);
        }
    }
}

/*
 * function: func_021BAF38
 * address:  0x021BAF38
 * packet:   pkt_ov070_021BAF38
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F14C  0x0201F14C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_021BB6E0  0x021BB6E0  thumb  ov070
 *   func_021BB724  0x021BB724  thumb  ov070
 */

extern int func_02045770(int);
extern void func_02043B5C(int, int);
extern void func_02045CAC(int, int, int);
extern void func_0201F14C(int, int, int);
extern void func_0201F250(int, int, int);
extern int func_0201D304(int, int, int);
extern void func_021BB6E0(int, int, int, int, int, int);
extern void func_021BB724(int);

void func_021BAF38(int p, int val)
{
    int r;

    func_02043B5C(func_02045770(*(int *)(p + 0x504)), 0);
    func_02045CAC(*(int *)(p + 0x51C), 0x8B, *(int *)(p + 0x524));
    func_0201F14C(*(int *)(p + 0x520), 0, val);
    func_0201F250(*(int *)(p + 0x520), *(int *)(p + 0x528), *(int *)(p + 0x524));
    r = 0x60 - func_0201D304(*(int *)(p + 0x528), *(int *)(p + 0x530), 0);
    func_021BB6E0(p, p + 0x504, *(int *)(p + 0x528), (unsigned short)(r >> 1), 4, 0x3C40);
    func_021BB724(p + 0x504);
}

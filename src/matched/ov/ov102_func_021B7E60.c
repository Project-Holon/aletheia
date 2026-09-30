/*
 * function: func_021B7E60
 * address: 0x021B7E60
 * packet: pkt_ov102_021B7E60
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: halve before casting to u16, keeping the seventeenth input bit.
 * symbols:
 *   func_021B7CC4 0x021B7CC4 thumb ov102
 *   func_021B7CC0 0x021B7CC0 thumb ov102
 *   func_021B7CBC 0x021B7CBC thumb ov102
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C724 0x0201C724 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int func_021B7CC4(void *);
extern int func_021B7CC0(void *);
extern int func_021B7CBC(void *);
extern int func_02045770(int);
extern void func_02043B5C(int, u8);
extern void func_02045CAC(int, int, int);
extern int func_02045738(int);
extern int func_02045740(int);
extern int func_0201D304(int, int, int);
extern int func_0201D42C(int, int);
extern void func_0201C6EC(int);
extern void func_0201C724(int, int, s16, s16, int, int, int);
void func_021B7E60(u8 *p, void *q, int n)
{
    int a, b, c;
    u16 x, y;
    a = func_021B7CC4(q);
    b = func_021B7CC0(q);
    c = func_021B7CBC(q);
    func_02043B5C(func_02045770(*(int *)p), *(u16 *)(p + 16));
    func_02045CAC(a, n, *(int *)(p + 12));
    x = func_02045738(*(int *)p) * 4;
    y = func_02045740(*(int *)p) * 4;
    x -= (u16)(func_0201D304(*(int *)(p + 12), c, 0) >> 1);
    y -= (u16)(func_0201D42C(*(int *)(p + 12), c) >> 1);
    func_0201C6EC(b);
    func_0201C724(b, func_02045770(*(int *)(p + 4)), x, y, *(int *)(p + 12), c, 0x3dc1);
    p[8] = 1;
}

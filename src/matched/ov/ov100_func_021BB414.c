/*
 * function: func_021BB414
 * address:  0x021BB414
 * packet:   pkt_ov100_021BB414
 * region:   ov100
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_0203D0D0  0x0203D0D0  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_021BA780  0x021BA780  thumb  ov100
 */

typedef unsigned short u16;

extern void func_0203064C(int, int, int);
extern int func_0203159C(int, int, int);
extern void func_02082BCC(int, int, int);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_0203D0D0(void);
extern void func_0207D63C(int, int, int, int, int);
extern void func_021BA780(int);

int func_021BB414(int a, int b, int c)
{
    int r5;

    func_0203064C(1, 0x1f, 0x20000);
    r5 = 0xcf0;
    a = func_0203159C(a, r5, 0x1f);
    func_02082BCC(a, 0, r5);
    *(int *)(a + 0x244) = c;
    *(u16 *)(a + 0x278) = 0x1f;
    *(int *)(a + 0x24c) = *(int *)(*(int *)(a + 0x244) + 0x1c);
    *(int *)(a + 0xcb4) =
        (int)func_02030734(*(u16 *)(a + 0x278), 0x200, 0, (const char *)0x021BB8AC, 0xb07);
    func_021BA780(a);
    func_0203D0D0();
    func_0207D63C(0x04000050, 0x10, 3, 9, 0xe);
    return 1;
}

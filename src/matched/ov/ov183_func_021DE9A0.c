/*
 * function: func_021DE9A0
 * address: 0x021DE9A0
 * packet: pkt_ov183_021DE9A0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02025538 0x02025538 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DF0DC 0x021DF0DC thumb ov183
 *   func_021DEB4C 0x021DEB4C thumb ov183
 */
typedef unsigned short u16;
extern u16 func_021F9B9C(void *);
extern void *func_0203159C(void *, int, u16);
extern void func_02082BCC(void *, int, unsigned int);
extern void *func_02025538(unsigned int a0, void *a1);
extern void *func_0201C440(u16);
extern void *func_021FD760(void *, int, int, u16);
extern void *func_021FD6D8(void *, int, u16);
extern void func_021FD73C(int *p, int v);
extern void func_021DF0DC(int *p, int *state, char *q);
extern void func_021DEB4C(int *task, int *state, char *p);
int func_021DE9A0(void *a, int b, char *q)
{
    char *p = func_0203159C(a, 0x10C, func_021F9B9C(*(void **)(q + 0x14)));
    int i;
    func_02082BCC(p, 0, 0x10C);
    *(char **)(p + 0x108) = q;
    *(u16 *)(p + 0x18) = func_021F9B9C(*(void **)(q + 0x14));
    *(void **)p = func_02025538(*(u16 *)(p + 0x18), *(void **)(q + 0xC));
    *(void **)(p + 0x14) = func_0201C440(*(u16 *)(p + 0x18));
    for (i = 0; i < 2; i++)
        *(void **)(p + i * 4 + 0x1C) = func_021FD760(*(void **)(q + 0xC), *(int *)(q + 0x10), i, *(u16 *)(p + 0x18));
    *(void **)(p + 0x10) = func_021FD6D8(p, (int)func_021DF0DC, *(u16 *)(p + 0x18));
    if (*(int *)(*(char **)(p + 0x108) + 4) != 0)
        func_021FD73C(*(void **)(p + 0x10), (int)func_021DEB4C);
    else
        func_021FD73C(*(void **)(p + 0x10), (int)func_021DF0DC);
    return 1;
}

/*
 * function: func_021FEF50
 * address: 0x021FEF50
 * packet: pkt_ov135_021FEF50
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021FF570 0x021FF570 thumb ov135
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021F88B0 0x021F88B0 thumb ov135
 *   func_021F8010 0x021F8010 thumb ov135
 *   d_02202EAC 0x02202EAC data a4
 */
typedef unsigned short u16;
extern int func_021F99F0(void *);
extern void func_021FF570(int);
extern void func_0201F7A8(void *, unsigned);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern int func_02045730(void *);
extern void func_020409B4(int);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, unsigned);
extern const int d_02202EAC;
extern void func_021F88B0(char *, int);
extern void func_021F8010(void *, void *, void *, unsigned, unsigned, unsigned, u16, void *);
int func_021FEF50(char *p)
{
    int r;
    void *w;
    r = func_021F99F0(*(void **)(p + 0xde4));
    if (r == -1) {
    } else if (r == -2 || r == d_02202EAC + 1) {
        func_021FF570(0);
        func_0201F7A8(*(void **)(p + 0xd40), 0);
        w = *(void **)(p + 0xd40);
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
        *(int *)(p + 0x28) = 0;
    } else {
        func_021FF570(0);
        func_021F88B0(p, r);
        *(int *)(p + 0x28) = 0;
        func_02043B5C(func_02045770(*(void **)(p + 0xddc)), 0);
        func_021F8010(*(void **)(p + 0xddc), *(void **)(p + 0xb7c), *(void **)(p + 0xb6c), *(unsigned *)(p + 0xf84), 0, 0, 0x3c40, p + 0xfa0);
    }
    return 2;
}

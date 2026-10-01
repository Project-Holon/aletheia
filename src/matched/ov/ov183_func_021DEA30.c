/*
 * function: func_021DEA30
 * address: 0x021DEA30
 * packet: pkt_ov183_021DEA30
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DF388 0x021DF388 thumb ov183
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 */
extern void func_021DF388(void *);
extern void func_021FC734(void *);
extern void func_021FB494(void *);
extern void func_021FC0C8(void *, int);
extern void func_021FBDA4(void *, int);
extern void func_021FD714(void *);
extern void func_021FD15C(void *, int);
extern void func_021FD820(void *);
extern void func_02025588(void *);
extern void func_0201C4C0(void *);
extern void func_020315D4(void *);
int func_021DEA30(void *a, int b, char *q, char *p)
{
    int i;
    if (*(int *)(p + 0x100) != 0) {
        func_021DF388(p + 0x28);
        *(int *)(p + 0x100) = 0;
    }
    if (*(void **)(p + 0xC) != 0) {
        func_021FC734(*(void **)(p + 0xC));
        *(void **)(p + 0xC) = 0;
    }
    if (*(void **)(p + 8) != 0) {
        func_021FC734(*(void **)(p + 8));
        *(void **)(p + 8) = 0;
    }
    if (*(void **)(p + 4) != 0) {
        func_021FB494(*(void **)(p + 4));
        *(void **)(p + 4) = 0;
    }
    if (*(int *)(p + 0x104) != 0) {
        func_021FC0C8(*(void **)(*(char **)(p + 0x108) + 0x10), 6);
        func_021FBDA4(*(void **)(*(char **)(p + 0x108) + 0x10), 24);
        *(int *)(p + 0x104) = 0;
    }
    func_021FD714(*(void **)(p + 0x10));
    if (*(void **)(p + 0x24) != 0) {
        func_021FD15C(*(void **)(p + 0x24), *(int *)(q + 0x10));
        *(void **)(p + 0x24) = 0;
    }
    for (i = 0; i < 2; i++) func_021FD820(*(void **)(p + 0x1C + i * 4));
    func_02025588(*(void **)p);
    func_0201C4C0(*(void **)(p + 0x14));
    func_020315D4(a);
    return 1;
}

/*
 * unit:     yes
 * address:  0x021B6910
 * packet:   pkt_ov098_021B6910
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_021B6910, func_021B6988, func_021B69C4
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_021B6140  0x021B6140  thumb  ov098
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021B6B8C  0x021B6B8C  thumb  ov098
 *   func_02045808  0x02045808  arm
 *   func_021B6148  0x021B6148  thumb  ov098
 *   func_0201F02C  0x0201F02C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_02045EC0(int, int);
extern int func_021B6140(int);
extern void func_0201EEF4(int, int, int);
extern void func_0201F250(int, int, int);
extern int func_021B6B8C(int, int);
extern void func_02045808(int);

void func_021B6910(int a, int b) {
    int r;
    int t;
    r = func_02045EC0(*(int *)(a + 0x20), 0);
    t = func_021B6140(b);
    func_0201EEF4(*(int *)(a + 0x30), 0, t);
    func_0201F250(*(int *)(a + 0x30), *(int *)(a + 0x2c), r);
    func_021B6B8C(a, 0x50);
    func_02045808(r);
}

void func_021B6988(int a, int b) {
    int r;
    int t;
    r = func_02045EC0(*(int *)(a + 0x20), 3);
    t = func_021B6148(b);
    func_0201F02C(*(int *)(a + 0x30), 0, t);
    func_0201F250(*(int *)(a + 0x30), *(int *)(a + 0x2c), r);
    func_021B6B8C(a, 0);
    func_02045808(r);
}

void func_021B69C4(int a, int b) {
    int r;
    int t;
    r = func_02045EC0(*(int *)(a + 0x20), 1);
    t = func_021B6140(b);
    func_0201EEF4(*(int *)(a + 0x30), 0, t);
    func_0201F250(*(int *)(a + 0x30), *(int *)(a + 0x2c), r);
    func_021B6B8C(a, 0x50);
    func_02045808(r);
}

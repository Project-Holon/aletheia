/*
 * function: func_021D883C
 * address:  0x021D883C
 * packet:   pkt_021D883C
 * region:   ov120
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tear-down: releases the handle at p+0x68, the pointer at p+0xC4, six
 * p+0x6C slots, then two ov120 callbacks and a six-argument SDK call.
 *
 * symbols:
 *   func_0201F7A8    0x0201F7A8  thumb
 *   func_020456F8    0x020456F8  arm
 *   func_02041B6C    0x02041B6C  arm
 *   func_020452E8    0x020452E8  arm
 *   func_02028148    0x02028148  thumb
 *   func_02049B40    0x02049B40  arm
 *   func_021D7D3C    0x021D7D3C  thumb  ov120
 *   func_021D7C1C    0x021D7C1C  thumb  ov120
 */

typedef unsigned short u16;

extern void func_0201F7A8(void *h, int mode);
extern void func_020456F8(void *h);
extern void func_02041B6C(int a);
extern void func_020452E8(void *h);
extern void func_02028148(void *p);
extern void func_02049B40(int a, int b, int c, int d, int e, int f);
extern void func_021D7D3C(char *p);
extern void func_021D7C1C(char *p);

void func_021D883C(char *p)
{
    int i;

    if (*(void **)(p + 0x68) != 0) {
        func_0201F7A8(*(void **)(p + 0x68), 2);
        func_020456F8(*(void **)(p + 0x68));
        func_02041B6C(1);
        func_020452E8(*(void **)(p + 0x68));
        *(void **)(p + 0x68) = 0;
    }
    if (*(void **)(p + 0xC4) != 0) {
        func_02028148(*(void **)(p + 0xC4));
        *(void **)(p + 0xC4) = 0;
    }
    for (i = 0; i < 6; i++) {
        char *q = p + i * 4;

        if (*(void **)(q + 0x6C) != 0) {
            func_020456F8(*(void **)(q + 0x6C));
            func_020452E8(*(void **)(q + 0x6C));
            *(void **)(q + 0x6C) = 0;
        }
    }
    func_021D7D3C(p);
    func_021D7C1C(p);
    func_02049B40(0x17, 5, 4, 0x160, 0x20, *(u16 *)(p + 0xC8));
    func_02041B6C(5);
}

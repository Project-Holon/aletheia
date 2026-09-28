/*
 * function: func_0203CF3C
 * address:  0x0203CF3C
 * packet:   pkt_0203CDD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *
 * The same vtable dispatch as src/matched/func_0203CF10.c, one slot further
 * on (+0x2C) and without the null test: the state object is assumed live and
 * the hook's value is dropped.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CF3C.c \
 *       --func func_0203CF3C --addr 0x0203CF3C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef void (*Fn)(u32);

extern u8 *func_0203D788(void);

void func_0203CF3C(u32 a)
{
    u8  *p;
    Fn   f;

    p = func_0203D788();
    f = *(Fn *)(*(u32 *)(p + 0x340) + 0x2C);
    f(a);
}

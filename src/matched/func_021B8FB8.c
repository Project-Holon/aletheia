/*
 * function: func_021B8FB8
 * address:  0x021B8FB8
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tears down both 0x2c/0x7c buffers and the five 0x90 blocks, then clears the
 * display register.
 *
 * symbols:
 *   func_02027858  0x02027858  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_020414EC  0x020414EC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern void func_02027858(void *p);
extern int  func_020456F8(void *p);
extern int  func_02045730(void *p);
extern void func_020409B4(int v);
extern void func_020452E8(void *p);
extern void func_0204B3B4(void *p);
extern void func_020414EC(int v);

void func_021B8FB8(void *a0, char *a1)
{
    void *p;

    if (*(void **)(a1 + 0x80) != 0)
        func_02027858(*(void **)(a1 + 0x80));

    p = *(void **)(a1 + 0x2c);
    func_020456F8(p);
    func_020409B4(func_02045730(p));

    p = *(void **)(a1 + 0x7c);
    func_020456F8(p);
    func_020409B4(func_02045730(p));

    func_020452E8(*(void **)(a1 + 0x2c));
    func_020452E8(*(void **)(a1 + 0x7c));
    func_0204B3B4(*(void **)(a1 + 0x98));
    func_0204B3B4(*(void **)(a1 + 0xa0));
    func_0204B3B4(*(void **)(a1 + 0x9c));
    func_0204B3B4(*(void **)(a1 + 0x94));
    func_0204B3B4(*(void **)(a1 + 0x90));
    func_020414EC(6);
    func_020409B4(6);
    *(u16 *)0x04001050 = 0;
}

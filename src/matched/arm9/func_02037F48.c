/*
 * function: func_02037F48
 * address:  0x02037F48
 * packet:   pkt_02037F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Declaration order is what closes this one: p must be declared LAST of the
 * four locals so it takes r6 and the loop index takes r4 (see
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * The failure arm of the +0x5C poll is an out-of-line `goto`, not an
 * if-converted tail; the (u16) truncation of v happens after the n>0 test
 * and the index is zeroed before it.
 *
 * symbols:
 *   lbl_021469D0   0x021469D0  data
 *   d_020A7A20     0x020A7A20  data
 *   func_0203D788  0x0203D788  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *   func_02037D98  0x02037D98  arm
 *   func_020387A0  0x020387A0  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *lbl_021469D0;
extern u8 d_020A7A20[];
extern void *func_0203D788(void);
extern u32 func_0203D6BC(void);
extern u32 func_0203D680(void);
extern int func_02037D98(int a);
extern void func_020387A0(u32 a, u32 b, u32 c);

void func_02037F48(void)
{
    s32 i;
    s32 n;
    u32 v;
    u8 *p;

    p = func_0203D788();

    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x58))() == 0)
        return;

    if (*(u8 *)(lbl_021469D0 + 0x1EB) != 0)
        func_02037D98(1);

    if (((u32 (*)(u32)) * (u32 *)(*(u32 *)(p + 0x340) + 0x5C))(*(u32 *)lbl_021469D0) != 1)
        goto fail;

    *(u8 *)(d_020A7A20 + 1) = 4;
    *(u8 *)(lbl_021469D0 + 0x1EB) = 1;

    v = func_0203D6BC();
    n = func_0203D680();
    i = 0;
    if (n > 0) {
        v = (unsigned short)v;
        do {
        func_020387A0((unsigned short)i,
                      ((u32 (*)(u32))
                           * (u32 *)(*(u32 *)(p + 0x340) + 0x60))(i), v);
            i++;
        } while (i < n);
    }
    return;

fail:
    *(u8 *)(lbl_021469D0 + 0x1EB) = 0;
}

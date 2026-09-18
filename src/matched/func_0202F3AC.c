/*
 * function: func_0202F3AC
 * address:  0x0202F3AC
 * packet:   pkt_0202F30C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E88   0x02017E88  thumb
 *   func_0202F358   0x0202F358  thumb
 *
 * Reads the four resource slots of one variant and hands them, with the
 * opposite flag, to func_0202F358.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F3AC.c \
 *       --func func_0202F3AC --addr 0x0202F3AC --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void func_0202F358(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);

void func_0202F3AC(void *a0, u32 a1)
{
    u8 base = (a1 == 1);
    u32 x, y, z, flag, w;

    x = func_02017E88(a0, base + 0x95, 0);
    base = (u8)(base * 3);
    y = func_02017E88(a0, base + 0x8F, 0);
    z = func_02017E88(a0, base + 0x90, 0);
    w = func_02017E88(a0, base + 0x91, 0);

    flag = (a1 == 0);
    func_0202F358(a0, x, y, z, w, flag);
}

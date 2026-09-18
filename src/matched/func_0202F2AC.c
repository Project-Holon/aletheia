/*
 * function: func_0202F2AC
 * address:  0x0202F2AC
 * packet:   pkt_0202EF98
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
 *   func_0202F464   0x0202F464  thumb
 *   func_02017E64   0x02017E64  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F2AC.c \
 *       --func func_0202F2AC --addr 0x0202F2AC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void func_0202F358(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void func_0202F464(void *a0);
extern void func_02017E64(void *p, u32 id, u32 v);

void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    if (func_02017E88(a0, 0xAA, 0) == 1)
        func_0202F358(a0, a1, a2, a3, a4, 0);
    else
        func_0202F358(a0, a1, a2, a3, a4, 1);
    func_0202F464(a0);
    func_02017E64(a0, 0x6D, 1);
}

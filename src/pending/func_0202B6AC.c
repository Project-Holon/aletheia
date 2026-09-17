/*
 * function: func_0202B6AC
 * address:  0x0202B6AC
 * packet:   pkt_0202B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B6AC.c \\
 *       --func func_0202B6AC --addr 0x0202B6AC --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202AB28(u8 *p);
extern void func_0202C08C(u8 *p);
extern void func_0202B404(u8 *p);
extern void func_0202BEBC(u8 *p);
extern void func_0202C0C0(u8 *p);

void func_0202B6AC(u8 *p)
{
    func_0202C08C(*(u8 **)(p + 0x20));
    *(u32 *)(p + 0x20) = 0;
}

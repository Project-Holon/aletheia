/*
 * function: func_020619E8
 * address:  0x020619E8
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020619E8.c \
 *       --func func_020619E8 --addr 0x020619E8 --arm --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0207F308(void);
extern void func_0207F394(u32 a, u32 b, u32 c);
extern void func_0207F428(void);

void func_020619E8(u32 a, u32 b, u32 c)
{
    func_0207F308();
    func_0207F394(a, b, c);
    func_0207F428();
}

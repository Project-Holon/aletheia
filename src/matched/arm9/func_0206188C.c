/*
 * function: func_0206188C
 * address:  0x0206188C
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206188C.c \
 *       --func func_0206188C --addr 0x0206188C --arm --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0207F7A0(void);
extern void func_0207F7FC(u32 a, u32 b, u32 c);
extern void func_0207F9B4(void);

void func_0206188C(u32 a, u32 b, u32 c)
{
    func_0207F7A0();
    func_0207F7FC(a, b, c);
    func_0207F9B4();
}

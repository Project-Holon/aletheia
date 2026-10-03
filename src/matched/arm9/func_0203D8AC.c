/*
 * function: func_0203D8AC
 * address:  0x0203D8AC
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Runs func_020371AC(0, 0) and func_0203D2CC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D8AC.c \
 *       --func func_0203D8AC --addr 0x0203D8AC --arm --cc 1.1p1
 */

extern void func_020371AC(unsigned short a, unsigned int b);
extern void func_0203D2CC(void);

void func_0203D8AC(void)
{
    func_020371AC(0, 0);
    func_0203D2CC();
}

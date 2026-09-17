/*
 * function: func_02031C04
 * address:  0x02031C04
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031C04.c \\
 *       --func func_02031C04 --addr 0x02031C04 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02032970(u8 *p, u32 v);
extern void func_020331D0(void);

void func_02031C04(void)
{
    func_020331D0();
}

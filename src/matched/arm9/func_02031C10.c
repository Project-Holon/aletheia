/*
 * function: func_02031C10
 * address:  0x02031C10
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031C10.c \\
 *       --func func_02031C10 --addr 0x02031C10 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02032970(u8 *p, u32 v);
extern void func_020331D0(void);

void func_02031C10(u8 *a, u8 *b, u32 v)
{
    *(u32 *)(a + 0x20) = v;
    a[0x1e] = 0;
    a[0x1f] = 2;
    b[0x1e] = 0;
    b[0x1f] = 2;
}

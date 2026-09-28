/*
 * function: func_0206DF14
 * address:  0x0206DF14
 * packet:   pkt_0206DB40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DF14.c \
 *       --func func_0206DF14 --addr 0x0206DF14 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_0207D988(void);
extern void func_0206A700(void);

void func_0206DF14(void)
{
    func_0207D988();
    func_0206A700();
    *(u32 *)0x04000600 = (*(u32 *)0x04000600 & 0x3FFFFFFFu) | 0x80000000u;
}

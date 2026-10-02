/*
 * function: func_02051360
 * address:  0x02051360
 * packet:   pkt_02051230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051360.c \
 *       --func func_02051360 --addr 0x02051360 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

extern void func_02051230(void *p, unsigned int a1, unsigned int a2, unsigned int a3);

void func_02051360(void *p, unsigned int a1, unsigned int a2, unsigned int a3)
{
    func_02051230(p, a1, a2, a3);
    *(u16 *)((char *)p + 50) = (u16)((*(u16 *)((char *)p + 50) & ~1) | 1);
}

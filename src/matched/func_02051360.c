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

extern void func_02051230(void *p);

void func_02051360(void *p)
{
    func_02051230(p);
    *(u16 *)((char *)p + 50) = (u16)((*(u16 *)((char *)p + 50) & ~1) | 1);
}

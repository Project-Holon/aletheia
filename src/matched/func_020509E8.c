/*
 * function: func_020509E8
 * address:  0x020509E8
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020509E8.c \
 *       --func func_020509E8 --addr 0x020509E8 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

extern void func_020500A0(void *p);

int func_020509E8(void *p, void *q)
{
    *(u16 *)((char *)p + 14) = *(u16 *)((char *)q + 2);
    func_020500A0(p);
    return 0;
}

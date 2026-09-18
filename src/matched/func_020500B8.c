/*
 * function: func_020500B8
 * address:  0x020500B8
 * packet:   pkt_020500B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Second of the three 0x0204F6xx-series object initialisers; the eight bytes
 * of literal pool at 0x020500EC (0x0000FFFF) are this function's own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020500B8.c \
 *       --func func_020500B8 --addr 0x020500B8 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020500A0(void *p);

void func_020500B8(u32 *p)
{
    p[0] = 0xFFFF;
    p[2] = 0;
    *(u16 *)((char *)p + 12) = 0;
    *(u16 *)((char *)p + 14) = 0;
    func_020500A0(p);
    p[6] = 0;
    p[8] = 0;
    p[9] = 0;
}

/*
 * function: func_02051E64
 * address:  0x02051E64
 * packet:   pkt_02051C6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051E64.c \
 *       --func func_02051E64 --addr 0x02051E64 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

void func_02051E64(void *p, int a)
{
    *(unsigned char *)p = (unsigned char)a;
    *(u16 *)((char *)p + 2) = 0;
}

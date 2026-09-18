/*
 * function: func_02051C6C
 * address:  0x02051C6C
 * packet:   pkt_02051C6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051C6C.c \
 *       --func func_02051C6C --addr 0x02051C6C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_020307B0(void *p);

void func_02051C6C(void *p)
{
    func_020307B0((void *)*(u32 *)((char *)p + 16));
    func_020307B0(p);
}

/*
 * function: func_0203D578
 * address:  0x0203D578
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Forwards the first argument through func_020395EC and passes the result
 * with the second argument to func_02039468.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D578.c \
 *       --func func_0203D578 --addr 0x0203D578 --arm --cc 1.1p1
 */

typedef unsigned int u32;

extern int func_020395EC(void *a);
extern void func_02039468(u32 b, u32 r);

void func_0203D578(u32 a, u32 b)
{
    u32 r = func_020395EC((void *)a);

    func_02039468(b, r);
}

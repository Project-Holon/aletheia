/*
 * function: func_020312B4
 * address:  0x020312B4
 * packet:   pkt_020312B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146990    0x02146990  data
 *   func_020313EC  0x020313EC  arm
 *
 * Tail-call forwarder passing g_02146990 to func_020313EC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020312B4.c \
 *       --func func_020312B4 --addr 0x020312B4 --cc 1.1p1 --arm
 */

extern void *g_02146990;
extern int func_020313EC(void *arg);

int func_020312B4(void)
{
    return func_020313EC(g_02146990);
}

/*
 * function: PROCSYS_MainGlobal
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
 *   PROCSYS_MainInternal  0x020313EC  arm
 *
 * Tail-call forwarder passing g_02146990 to PROCSYS_MainInternal.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PROCSYS_MainGlobal.c \
 *       --func PROCSYS_MainGlobal --addr 0x020312B4 --cc 1.1p1 --arm
 */

extern void *g_02146990;
extern int PROCSYS_MainInternal(void *arg);

int PROCSYS_MainGlobal(void)
{
    return PROCSYS_MainInternal(g_02146990);
}

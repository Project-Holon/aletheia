/*
 * function: func_02029FD0
 * address:  0x02029FD0
 * packet:   pkt_02029FD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_02146944     0x02146944  data
 *   func_0202A084  0x0202A084  thumb
 *
 * ringtone_sys.c: forward the global ringtone state (g_02146944, set by
 * func_02029F14) to func_0202A084 with event 3, a pool-word tail call.
 * The two thunks 0x02029FD0 / 0x02029FE4 differ only in the event id.
 */

typedef unsigned int u32;

extern u32 *g_02146944;
extern void func_0202A084(u32 *state, int event);

void func_02029FD0(void)
{
    func_0202A084(g_02146944, 3);
}

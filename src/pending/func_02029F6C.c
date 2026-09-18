/*
 * function: func_02029F6C
 * address:  0x02029F6C
 * packet:   pkt_02029F6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker: 0x02029FD1 / 0x02029FE5 (data) - neither word occurs in any other pool.
 *
 * Debug/log hook: when the pointer parked at 0x02146944 holds anything, hand
 * it and two nearby string literals to func_0203508C.  The two strings must
 * be named externs, not cast constants: as constants mwccarm spots that the
 * second is the first plus 0x14 and replaces its pool word with an `adds`.
 *
 * symbols:
 *   g_02146944     0x02146944  data
 *   str_02029FD1   0x02029FD1  data
 *   str_02029FE5   0x02029FE5  data
 *   func_0203508C  0x0203508C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02029F6C.c \
 *       --func func_02029F6C --addr 0x02029F6C --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern const char str_02029FD1[];
extern const char str_02029FE5[];
extern void func_0203508C(const char *a, const char *b, u32 v);

void func_02029F6C(void)
{
    u32 v = *(u32 *)0x02146944;

    if (v != 0) {
        func_0203508C(str_02029FD1, str_02029FE5, v);
    }
}

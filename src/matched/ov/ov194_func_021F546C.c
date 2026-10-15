/*
 * function: PROF_WORD_CompareChunks
 * address:  0x021F546C
 * packet:   pkt_ov194_021F546C
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-05 (wD6 lane09): EXACT. The function returns the callee result (the caller uses it); the uninitialised result local keeps r0 live and moves the stack load to r1.
 *
 * symbols:
 *   PROF_WORD_MatchWord 0x021F5494 thumb ov194
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern int PROF_WORD_MatchWord(const u16 *a, const u16 *b);
int PROF_WORD_CompareChunks(const u16 *a, u32 b, u32 c, const u16 *d, u32 n)
{
    int r;
    int i;
    int cnt = (n << 10) >> 16;
    for (i = 0; i < cnt; i++) {
        r = PROF_WORD_MatchWord(a, d + i * 32);
        if (r == 1) break;
    }
    return r;
}

/*
 * function: func_02010DF4
 * address:  0x02010DF4
 * packet:   pkt_02010DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  codegen, 13 bytes wrong out of 32; size is exact.  The original
 *           has BOTH an unfolded pre-loop guard (`movs r4,#0; cmp r4,#0xd;
 *           bge`) and a plain `adds r4, r4, #1` increment.  An `int` counter
 *           folds the guard away (28 bytes, 19 out); a narrow counter (s8,
 *           char, u8, s16 all tried) emits the guard but pays for it with a
 *           truncation pair on the increment.  No C type gives both.  The
 *           full table of spellings, the permuter runs (1050 compiles across
 *           three searches, no movement) and the three readings that could
 *           still close it are in docs/notes/pkt_02010DCC.c.txt.
 *
 * note:     status was hand-written EXACT and corrected to DIFF by the
 *           2026-09-21 re-verification.  This file's source has since been
 *           corrected too: the earlier body stopped at the loop and dropped
 *           the trailing `g_02146228[0x1c] = 0xd` deselect that the pool word
 *           at 0x02010E10 (0x02146228) evidences.
 *
 * symbols:
 *   func_02010F50  0x02010F50  thumb
 *   g_02146228     0x02146228  data
 */

typedef unsigned char u8;
typedef signed char   s8;

extern void func_02010F50(int idx);
extern u8   g_02146228[];

void func_02010DF4(void)
{
    s8 i;

    for (i = 0; i < 13; i++) {
        func_02010F50(i);
    }
    g_02146228[0x1c] = 0xd;
}

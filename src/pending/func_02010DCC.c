/*
 * function: func_02010DCC
 * address:  0x02010DCC
 * packet:   pkt_02010DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  codegen, 23 bytes wrong out of 40; size is exact.  Same residue
 *           as its neighbour func_02010DF4 and for the same reason: the
 *           original wants an unfolded pre-loop guard together with an
 *           untruncated increment, and no counter type gives both.  See
 *           docs/notes/pkt_02010DCC.c.txt for the full table and the
 *           permuter runs.
 *
 * note:     replaces src/pending/unit_02010DCC.c, whose body named the wrong
 *           counter array (g_02146954) and stopped at the loop.  The pool
 *           word at 0x02010DEC is 0x021461E8 (the family's thirteen counters,
 *           already declared by src/matched/func_02010EC0.c), and the one at
 *           0x02010DF0 is 0x02010FAD, i.e. sub_02010FAC + the Thumb bit: the
 *           function ends in a tail call to the empty placeholder already
 *           matched as src/matched/sub_02010FAC.c.
 *
 * symbols:
 *   g_021461E8     0x021461E8  data
 *   sub_02010FAC   0x02010FAC  thumb
 */

typedef signed char  s8;
typedef unsigned int u32;

extern u32  g_021461E8[];
extern void sub_02010FAC(void);

void func_02010DCC(void)
{
    s8 i;

    for (i = 0; i < 13; i++) {
        if (g_021461E8[i] > 1) {
            g_021461E8[i]--;
        }
    }
    sub_02010FAC();
}

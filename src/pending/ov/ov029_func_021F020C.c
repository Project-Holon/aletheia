/*
 * function: func_021F020C
 * address:  0x021F020C
 * packet:   pkt_ov029_021F020C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: DIFF
 * residual: 140/140 bytes, 63 concrete mismatches; ascending-register LDM
 * pair copies agree in shape, argument/result register colouring remains.
 * W76 final retry: six runs. Direct u64/word union emits STM pairs
 * (DIFF121); enum x/y splits LDM and expands to144/DIFF127; enum modulo
 * local unchanged63. Three nonshrinking changes stopped iteration.
 * checks: 1 own EXACT 021F2B9C proves pointer,row,col and unsigned-word
 * return, corrected prototype unchanged; 2 own matched 021F1010 re-read,
 * no twin covering both copies; 3 read-only p const unchanged63;
 * 4 pair assignment/eight-byte copy/coordinate byte-offset idioms reread;
 * 5 directory/neighbour evidence and declared object shape reviewed.
 * Prior searches spent: --types600 plus two2500 searches; invalid
 * uninitialized/volatile mutants rejected; W75 inline out-pair and enum
 * return unchanged63, by-value pair148/DIFF130. No searches repeated.
 * Best original u64-to-Pair spelling preserved. Next untried hypothesis:
 * separate ABI pair type for both table conversions with scalar accesses.
 *
 * 2026-10-04 (wD1 lane 11): re-run, still 63 bytes, same length. The original
 * keeps y (b) in r2 and ret in r1 (x's old register) and loads both pairs
 * through r3/r5 ldm; ours moves b to r5 and loads through r2/r4. Reproduced
 * by: struct Pair, u64 Pair, x/y reuse of the parameters, ret assigned
 * after x, declaration order of ret and the temps (63..132).
 *
 * 2026-10-05 (wD4 lane 15): tried (all no gain, 63 bytes or worse): one-field `const struct Pair` tables copied by value
 * (144 B, stack copy changes), ret declared last and assigned before x with `return ret` (144 B), a local copy of the
 * c pointer (63), x computed before the table loads (144), `x - (x/2)*2` for the modulo (136, 109 differ). Residue unchanged:
 * original moves a to r4 early, keeps b in r2 and ret in r1, and runs both ldm through r3/r5.
 *
 * symbols:
 *   func_021F020C  0x021F020C  thumb  ov029
 *   func_021F2B9C  0x021F2B9C  thumb  ov029
 *   d_021F333C     0x021F333C  data  a4
 *   d_021F334C     0x021F334C  data  a4
 */

struct Pair {
    int a;
    int b;
};

extern unsigned int func_021F2B9C(unsigned char *p, int a, int b);
typedef unsigned long long u64;
extern u64 d_021F333C;
extern u64 d_021F334C;

int func_021F020C(const void *p, int a, int b, int *c, int *d)
{
    struct Pair lo;
    struct Pair hi;
    u64 t;
    int ret = 5;
    int x;
    int y;
    int m;

    t = d_021F333C;
    lo.a = (int)t;
    lo.b = (int)(t >> 32);
    t = d_021F334C;
    hi.a = (int)t;
    hi.b = (int)(t >> 32);
    x = (a / 8 + 2) / 4;
    if (x < 0) {
        return 5;
    }
    m = x % 2;
    y = b / 8 - (&lo.a)[m];
    if (y < 0) {
        return 5;
    }
    y = y / 4;
    if (x < 9 && y < (&hi.a)[m]) {
        ret = func_021F2B9C((unsigned char *)p, x, y);
    }
    *c = x;
    *d = y;
    return ret;
}

/*
 * function: func_0206EB7C
 * address:  0x0206EB7C
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 60 compiled against 60: the original recomputes the shift
 *           for the `- 1` arm from the entry halfword instead of reusing the
 *           already shifted value, and mwccarm shares the shifted value.
 *           Carried over from the wave2-F near miss (docs/notes/
 *           pkt_0206E964.c.txt) and re-verified here.  The call target
 *           func_0206EE60 has no caller outside this function either, so the
 *           entry could not reach EXACT even if the codegen closed.
 *
 * symbols:
 *   func_0206EE60    0x0206EE60  arm
 *
 * Clamps the raw coordinate at q (word at +0) into [0, n*0x1000 - 1] and
 * forwards the clamped index.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206EB7C.c \
 *       --func func_0206EB7C --addr 0x0206EB7C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0206EE60(void *p, int v, int idx);

int func_0206EB7C(void *p, u32 *q, int v)
{
    u16 n = *(u16 *)(*(u32 *)((char *)q + 8) + 4);
    int cur = (int)*q;
    int idx;

    if (cur >= (n << 12))
        idx = (n << 12) - 1;
    else if (cur < 0)
        idx = 0;
    else
        idx = cur;
    return func_0206EE60(p, v, idx);
}

/*
 * function: NATSUKI_Calc
 * address:  0x0201B7A0
 * packet:   pkt_0201B7A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0209E45C (literal) - its only pool word is this function's own,
 *           at 0x0201B7B0, inside the compared range; every concrete byte is
 *           right.
 *
 * symbols:
 *   _NatsukiDeltaTable     0x0209E45C  data
 *   NATSUKI_Apply  0x0201B850  thumb
 *
 * A three-byte-stride table entry is handed to NATSUKI_Apply along with the
 * caller's own third and fourth arguments.  Those two are forwarded
 * unchanged - they are already in r2/r3 - so no instruction moves them, and
 * that is also why the call is a real `bl` rather than a tail call: a Thumb
 * tail call spends r3 on the target address, so a four-argument call cannot
 * be one.  The 3 is lsls #1 plus adds; the table pointer is this function's
 * own pool word at 0x0201B7B0.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NATSUKI_Calc.c \
 *       --func NATSUKI_Calc --addr 0x0201B7A0 --cc 1.1p1 --thumb
 */

typedef signed char s8;

extern const s8 _NatsukiDeltaTable[];
typedef unsigned int   u32;
extern void NATSUKI_Apply(void *mon, const s8 *tbl, int a2, u32 a3);

void NATSUKI_Calc(void *a0, int a1, int a2, int a3)
{
    NATSUKI_Apply(a0, &_NatsukiDeltaTable[a1 * 3], a2, a3);
}

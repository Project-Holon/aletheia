/*
 * function: func_021DE960
 * address:  0x021DE960
 * packet:   pkt_021DE960
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * BLOCKER: stack-frame shape.  The algorithm is recovered and correct
 * (clamp a 6-entry window around the current slot, modulo the winning
 * offset by 6, +5), but the original's frame is 0x20 with the two call
 * outputs at sp+0x1c/sp+0x18, the 4-byte window at sp+0x14 and an extra
 * spilled int at sp+0x10; this compiler allocates 0x18 and folds the
 * outputs down.  Length 220 vs 216; the difference is entirely frame
 * layout plus `_s32_div_f` (the `% 6` helper, see note below).
 *
 * The final `best % 6` is emitted as a call to the runtime helper
 * `_s32_div_f` (thumb), reached via `blx 0x209C0A4`; the remainder is
 * returned in r1, and the +5 is added to that.  Do not spell it as a
 * plain `/` (which would be `_s32_div`); the helper only resolves once
 * the routine is named in layout/runtime_arm9.txt.
 *
 * symbols:
 *   func_021DE0E4  0x021DE0E4  thumb
 *   func_021DE5F4  0x021DE5F4  thumb
 *   func_02035D20  0x02035D20  arm
 *   func_0209C0A4  0x0209C0A4  arm
 */

typedef unsigned short u16;
typedef signed short s16;

extern int func_02035D20(int *, int *);
extern int func_021DE5F4(char *);
extern void func_021DE0E4(char *, int, s16 *, s16 *);
extern int func_0209C0A4(int, int);

int func_021DE960(char *obj)
{
    int out2;
    int out1;
    s16 win[2];
    s16 p1;
    s16 p2;
    int start;
    int best;
    s16 bestX;
    int i;

    if (func_02035D20(&out1, &out2) == 0)
        return 0xff;

    i = (s16)func_021DE5F4(obj);
    best = -1;
    start = i;
    bestX = 0;

    for (; i < start + 6; i++) {
        if (*(int *)(obj + 0x0b74 + i * 4) != 0) {
            func_021DE0E4(obj, i, &win[1], &win[0]);

            p1 = win[1];
            p2 = win[0];

            {
                s16 lo, hi;

                lo = p1 - 0x30;
                hi = p1 + 0x30;
                if (lo < 0) lo = 0;
                if (hi > 0xff) hi = 0xff;

                if (out1 < lo) continue;
                if (out1 >= hi) continue;

                lo = p2 - 0x30;
                hi = p2 + 0x30;
                if (lo < 0) lo = 0;
                if (hi > 0xff) hi = 0xff;

                if (out2 < lo) continue;
                if (out2 >= hi) continue;
            }

            if (best == -1 || p2 > bestX) {
                bestX = p2;
                best = i - start;
            }
        }
    }

    if (best == -1)
        return 0xff;
    return (best % 6) + 5;
}

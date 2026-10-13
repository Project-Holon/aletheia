# Register-mismatch lane brief

The function has the original's size and instructions; only register names or
the order of independent instructions differ. The user wants it EXACT. Read
docs/restructure/FINISH_BRIEF.md (rules and levers) first.

## Levers that closed near-misses this week
1. Caller and callee parameter types must agree (twl 02705A4C: a u32 5th
   parameter passed to an s32 callee made a conversion temp, which IRO hoisted
   past the loop guard and swapped two registers).
2. A global's real size changes alias analysis (twl 027060B4: a 28-byte struct
   made a field store fall back to the unknown-memory alias set, so it got
   edges to unrelated stores and was scheduled early; the real 0x50-byte size,
   proven from the next symbol, fixed it). Find the real size from the layout.
3. `x / 2` against `x >> 1` (unsigned): the shift is folded by the front end,
   the division is lowered later.
4. Declaration order sets virtual register ids; simplify pushes same-degree
   nodes in id order. Folded CSE temps get ids at CSE time, not declaration.
5. `ret = 1` before a call, separate u16 locals, two names for one address
   (two pool entries), stores before a test so a hoisted zero is reused.


## The original was written by people
It is sometimes poorly optimised and does needless work: duplicated
variables, a value copied into a second local, a value recomputed or read
twice, two structs (or two names) for one object, dead stores, odd types.
Try such redundant forms before calling a function stuck. A form is a
stand-in only when no person would have a reason to write it (a cast or
statement whose only effect is to steer the compiler).
6. The compiler build itself. Library code was built by its vendor with its
   own compiler: the TWL SDK and TWL wireless with dsi/1.1p1, but NitroSystem
   (G2D, G3D, sound) and some SDK pieces with the NITRO 2.0 builds
   (../2.0/base..sp2p4), and a few with 1.2. When a function stays flat
   across every C spelling, try `--cc ../2.0/sp2` and `--cc ../1.2/sp3`
   before anything else (arm9 020627F0 and twl 02731920 closed this way).

## Method
Use tools/mwccdbg (regalloc, regalloc-replay --renumber, sched, alias): find
which interference or ordering fact differs from what the original colouring
needs, state a hypothesis about the source, test it once. No permuter, no
sweeps. If the function becomes EXACT, file it (FINISH_BRIEF "Filing") and
remove its row from layout/register_mismatch.txt. If not, keep the best draft
in src/pending and the row, and report the exact remaining difference.

## Report
Verdict and bytes differing / size, what closed it or the remaining
difference, every hypothesis tested with its result.

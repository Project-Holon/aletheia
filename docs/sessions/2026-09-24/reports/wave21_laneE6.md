# Wave 21, lane E6: blink_palanm 0x0202E1F0

Every verdict below comes from `tools/match.py one --diff` (dsi/1.1p1, -O4,p, Thumb). There were 30 compiles
in total: 21 of the target and 9 of small scratch probes. All were written by hand, and the permuter was not
used. Scratch files are in `/tmp/aletheia_laneE6`.

## Result

| function | before | after | where |
|---|---|---|---|
| 0x0202E1F0 blink_palanm (412 B) | DIFF 2 | DIFF 2 | `docs/notes/pkt_0202E1F0.c.txt`, section "wave 21 (lane E6)" |

The residue is unchanged. At +008E the image passes w from r7, and the best compile rematerialises
`add r0, sp, #0x38`. I reproduced lane E5's near-lever, `if (n > 0) { do-while; T } else { T }`: it gives
264 bytes out, with o in r6, w in r7, and a `b` to the next instruction at +008A.

## The three directions

**(1) Other shapes where T is reachable from two predecessors.** None of them removes the extra branch:

| shape | result | o / w |
|---|---|---|
| goto-inverted (`if (n > 0) goto L; T; goto J; L: ...`) | 315, `bgt; b` | r6 / r7 |
| `for (;;)` with T before the break | 264 | r6 / r7 |
| do-while with `continue` / `break` | 264 | r6 / r7 |
| switch with fall-through | 424 bytes | |
| T inside the last iteration | 436 bytes | o in r7 |
| else copy passing `ws` | 264 (LVN turns it into r7 and the copies still merge) | |
| `for` in the then arm | 416 bytes (the `for` keeps a second `ble` guard) | |
| else arm ending in `goto K` | 264 | |

Two related ideas also failed:
- **A copy `p = o` with two reaching defs merged at a join.** This is the coalesced-copy class lane E4 left
  unmeasured. It gives 21 bytes out with o in r7, or 322 bytes out when a `for` gets a doubled guard. The
  copy is propagated.
- **A two-def g-argument variable `wq`.** This gives 416 bytes, or 314 bytes out when the in-loop copy
  `wq = w` is also folded to &ws. Copies of w fold to the constant anywhere, not only in B0's EBB.

`const` and `register` on o or w give 21 bytes out.

**(2) Why the merge leaves the `b`.** I tested nine probe functions with duplicated tails. In every one,
cross-jumping replaces the copy that ends in a jump with a `b` to the copy that falls through. Nothing that
runs afterwards threads, inverts or deletes branches, or removes unreachable blocks. The probes covered:
- straight-line arms;
- a one-call tail;
- inverted arms, which give `bgt; b`;
- the copy placed after the return, which gives `ble` onto a `b` with a dead epilogue still emitted;
- three copies;
- top-tested loops.

The image itself contains eight leftover `b` to the next instruction (for example at 0x02022A80 and
0x0202D590), so the image's compiler behaves the same way. I found no condition under which the branch is
deleted.

**(3) The image's control flow.** The loop-1 latch `loc_0202E272` falls straight into the g block
`loc_0202E27A`, and B0's `ble` targets that block directly. There is no hop and no separate join block. The
only nearby unconditional branches are the two loop-arm `b`s to their latches, and they contain only i and n
code. None of them can be the remains of a cross-jumped copy that holds an o reference. The original
therefore had one copy of T at this join. This confirms E5's argument: the cross-jump lever reproduces the
registers but cannot be the original's mechanism.

## Files touched

- `docs/notes/pkt_0202E1F0.c.txt`: section "wave 21 (lane E6)" appended, with every spelling, its bytes out
  and where o and w land.
- `docs/sessions/2026-09-24/reports/wave21_laneE6.md`: this file.

No source was filed to `src/matched/` or `src/pending/`, and no shard was written, because there is no EXACT
or MATCH result. `tools/`, `layout/` and 0x0206DC00 were not touched, and there were no git writes. No other
decompilation or reconstruction was consulted.

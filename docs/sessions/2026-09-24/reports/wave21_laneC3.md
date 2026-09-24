# Wave 21, lane C3: 0x02067080 (g2d DoAffineTransforme_)

**Verdict: DIFF 2, unchanged.** The wave-13 source in `docs/notes/pkt_02066E30.c.txt`
re-verified with `match.py one` under `../2.0/sp2` at the start of the lane: 704/704, 2
bytes out, the y read at +0x21C in ip where the image has r6. The lane was stopped by the
integrator after the allocator probes, before any new spelling of the target was measured,
so no new bytes-out figure for the function exists.

## What was done (about 25 compiles)

Scratch probes under `/tmp/aletheia_laneC3/p`, compiled with the exact mwccarm command
line `match.py` uses, to measure how this compiler hands out registers. The full list with
results is in the notes section "2026-09-24, wave 21 (lane C3)". In brief:

- With r0-r2 live and lr, ip, r3 free, three fresh webs are handed out lr, ip, r3 in that
  order (volatile-pinned loads, p08f/g); one fresh web alone takes ip; long webs in a
  nine-load probe go to the high callee-saved registers (r8, r9) while short ones take r3
  and ip (p01). Use count does not move a web (p08a-c).
- Eight independent temporaries all reuse r2: there is no rotation between free
  registers (p07).
- A def takes a dying operand's register in place often but not always, even in the
  standalone adjust inline (p02/p03), and the y read after the mla in the parameterised
  shape takes the register _11 freed (p04, p07d).
- The ARMv5 `mul rd != rm` rule pushes a return-value operand out of r0 (p06, p07c).
- mwccarm 2.0/sp2 has no scheduling switch; -O4,s and -O1 stop inlining, so the block
  cannot be seen unscheduled.

## Reading

Fixed lowest-first (any order), FIFO, LIFO, rotation, and Chaitin colouring with a fixed
try-order are each refuted by the image's own adjust block or by a probe. What remains
unknown is the order in which the allocator visits webs; the r6/ip flip for the y read
(both registers freed by the same `mla` at +0x214 in both builds) needs that order. The
notes suggest the next probe: a volatile-pinned straight line with two webs freed by one
mla and a load after it, varying which mla operand slot each web occupies.

## Files touched

- `docs/notes/pkt_02066E30.c.txt`: one appended dated section, "2026-09-24, wave 21 (lane C3)".
- `docs/sessions/2026-09-24/reports/wave21_laneC3.md`: this report.

Nothing was written to `src/matched/` or `src/pending/` and no shard was written (nothing
reached MATCH or EXACT). `tools/` and `layout/` are untouched. Scratch files are under
`/tmp/aletheia_laneC3`.

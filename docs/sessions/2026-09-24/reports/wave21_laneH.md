# Wave 21, lane H: 0x02011D9C (ica_anime.c)

**Verdict: MATCH, byte-correct** (272 of 272 bytes, 0 concrete bytes out, dsi/1.1p1). It had been DIFF 8 since wave 17.
It is overlay-capped, so the file is parked at `src/pending/func_02011D9C.c`.

## Lever

The lever comes from `docs/idioms/an-address-held-in-a-u32-local-is-reloaded-at-every-site.md` (2026-09-24). The three
checksum probes share their first argument, `func_02011D28`. The fix holds it in `u32 start = (u32)func_02011D28;` and
casts it back at each probe call. The body keeps the wave-15 single-call shape (`off = 0; if (flag == 0) off = 0x191;`,
one `func_0203064C(1, 4, 4 << 14)`).

The local is rematerialised from the pool at every site, so it costs no instructions. Its web is live across the second
heap call, though, and 1.1p1 then rematerialises the shared constant 4 in that call. That gives the image's
`movs r2,#4 / movs r0,#1 / movs r1,#4 / lsls r2,r2,#14`, where the old compile had `movs r1,#4 / lsls r2,r1,#14`.

Two diagnostics showed the pressure trigger before the fix:
- `i = 0` before the call gave 272/11.
- `flag` kept live to the modulo test gave 276/185, but call 2 then came out in the image's order.

The both-arms shape with the same local gives 137 out.

## What was tried (107 match.py compiles plus one permuter run)

- Enum HeapId prototypes and enum constants: 24 runs, flat at 165 and 8.
- A static inline CreateHeap wrapper with enum, u32 or u16 parameters: 32 runs, flat.
- `i = 0` placements: 11 runs, best 11.
- Loop counter reusing `flag`: 4 runs, no gain.
- Dead stores before call 2: 5 runs, flat.
- Types of flag, off and base: 18 runs, flat or worse.
- Liveness diagnostics: 2 runs.
- `start` local: 6 runs. It reached 0 in three placements (single-call shape) and 137 in both-arms.
- Permuter anneal from the 11-out source: about 840 compiles, flat at 11. I stopped it once the manual lever closed.

Every spelling and its bytes-out is in the dated wave-21 section of `docs/notes/pkt_02011D9C.c.txt`.

## Evidence

22 of 25 sites resolve:
- `ov230_id` resolves as overlay_id.
- `func_0215FA00` resolves as sole-ref/code under the ov010 hint.
- The family targets resolve as sole-ref, and `g_02146248` as literal.

The three probe targets 0x021882A0, 0x02188354 and 0x02188390 do not resolve:
- None of the four overlapping overlays labels them. ov230 prints them as unreached data words, and ov009 has
  mid-function code there.
- No witness exists outside the function.
- `tu --suggest-split` finds no partition.

So MATCH is the strongest verdict the rules allow today. The file would become EXACT with no C change once ov230's
listing traces those three entry points (an integrator seed).

## Files touched

- `src/pending/func_02011D9C.c`: new, status MATCH, with the blocking class in the header.
- `docs/notes/pkt_02011D9C.c.txt`: appended a dated wave-21 section.
- `docs/sessions/2026-09-24/reports/wave21_laneH.md`: this report.
- Shard `layout/matched/arm9/pkt_02011D9C.json`: `manifest --verify --shard pkt_02011D9C` ran twice. Its only entry,
  func_02011EAC, stays EXACT, 0 rewritten, and the file is byte-identical. A pending MATCH file never enters a shard.

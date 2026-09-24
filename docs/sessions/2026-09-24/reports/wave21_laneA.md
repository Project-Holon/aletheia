# Wave 21, lane A: 0x02094B8C (MSL __strtold)

**Verdict: EXACT** (3864/3864 bytes, 17 of 17 relocation sites resolved), filed and shard-verified.

## Starting point

The dispatch brief's "DIFF 39" was stale. Re-measured, the wave-20 lane-20M pending source was already
MATCH with 0 concrete bytes out. `__double_huge` already resolved by sole-ref/self. The two sites still
unresolved were the compiler's anonymous string literals `@52` ("INFINITY", pool word +0x0EF0 -> 0x020A62E4)
and `@70` ("NAN(", +0x0EF4 -> 0x020A62DC), the initialisers of the two local `model[]` arrays.

## What closed it

Each array is now a one-member struct (`struct { unsigned char c[9]; }` and `c[5]`) copied from an extern
pinned in `symbols:` at the address the pool word names. This follows
`docs/idioms/file-string-is-an-abs32-into-the-string-area.md`. The align-1 aggregate copy is byte-identical
to the literal initialiser's copy code. The first attempt gave EXACT. `s_infinity` attests by `string`,
`s_nan` by sole-ref/string.

## Compiles

Two compiles beyond the documented spellings: the unchanged pending source (MATCH) and the extern-struct
spelling (EXACT). After that came the repo-path re-verification and two `manifest --verify` runs. Neither
the permuter nor any colouring lever was needed.

## Files touched

- `src/matched/func_02094B8C.c` (new, status EXACT)
- `src/pending/func_02094B8C.c` (removed, superseded)
- `layout/matched/arm9/pkt_02094B8C.json` (written by `manifest --verify --shard pkt_02094B8C`; second run
  0 rewritten, EXACT)
- `docs/notes/pkt_02094B8C.c.txt` (appended wave-21 section)
- this report

HANDOFF section 6 still lists this function as 39 out. That line is now stale, and updating it is the
integrator's job.

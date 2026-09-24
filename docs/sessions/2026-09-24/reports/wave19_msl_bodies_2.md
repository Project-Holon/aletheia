# Wave 19, lane 19A (msl_bodies_2)

## 0x0209953C: fdlibm __kernel_rem_pio2 (old revision)

Result: 12 bytes short -> EXACT under dsi/1.2, 2992 bytes, 62 of 62 relocations resolved. Filed as src/matched/func_0209953C.c.

What closed it: both missing guards come from an explicit `if` with the loop condition in front of the for loop. mwcc keeps that `if` beside its own rotation guard.
- f[] setup loop: `j = jv-jx; m = jx+jk; i = 0; if(m>=0) for(;i<=m;i++,j++)`. The `i = 0` has to come after j and m. With `i = 0` first, or kept in the for header, i and j swap registers in the recompute loop.
- Recompute loop: `i=0; j=jz; z=q[jz]; if(j>0) for(;j>0;i++,j--)`.

Cost: 5 measurements, no permuter run. The idiom is written up in docs/idioms/a-doubled-loop-entry-guard-is-an-explicit-if-around-the-for.md.

## 0x02094B8C: MSL __strtold (C99)

Result: 3916 -> 3860 bytes against 3864. Still DIFF, not filed. The new best source is in the note.

Closed this wave:
- Mantissa clear through the chptr register: `chptr = (unsigned char *)&mantissa;`. The cast blocks the sp-relative fold.
- The 14-word frac-to-int cross-jump: each digit body ends in its own `c = fetch(); break;`.

Still open:
- The `mov r0,#0xe; cmp r2,r0` form. Enum, static const, local, sizeof, operand-swap and cast spellings all failed.
- One extra copy in the entry zero chain.
- The r2/r3/r4 rotation in the hex tail, together with the CSE of the 0x7FF mask.

Cost: 20 measurements, plus one permuter run (tools/permute.py, 987 compiles). The permuter's best reaches the right size only through a case-layout accident, so it was discarded. Even with exact bytes this function stays MATCH-capped: __double_huge has no outside witness, and there are two anonymous string pool words.

## Files written

- src/matched/func_0209953C.c
- docs/idioms/a-doubled-loop-entry-guard-is-an-explicit-if-around-the-for.md
- docs/notes/pkt_02098B44.c.txt (wave 19 section)
- docs/notes/pkt_02094B8C.c.txt (wave 19 section and best source)
- layout/matched/arm9/pkt_02098B44.json (written by the manifest tool)

## Shards verified

pkt_02098B44, verified twice. Both passes print "1 rewritten", but the second pass's output is byte-identical to the first pass's.

## Seeds

None.

## For the integrator

- 0x0209953C is now EXACT, which also completes the rem_pio2 chain.
- Stage layout/matched/arm9/pkt_02098B44.json together with the new source.

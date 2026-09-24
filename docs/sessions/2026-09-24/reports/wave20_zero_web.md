# Wave 20, lane zero_web (20H)

## 0x0202350C (wipe_sub.c): 4 -> 4, DIFF
Correction: in the image the zero comes first (`ldrb r3,[r4,#8]; movs r0,#0;
ldrb r2,[r4,#0xb]`). The compile emits the kb load first. Measured:
- These all gave output byte-identical to the base, so mwcc folds them: `a2 - a2`,
  `kb & 0`, `kb ^ kb`, `(u32)(obj != obj)`, `&= 0`, `static const` k0.
- `extern const` k0: 96 bytes (a real load).
- Comparisons (`kb > 255`, `k8 > 0xff`): 100 bytes.
- Shifts of a byte (`kb >> 8`, `k8 >> 8`, `k8 >> 31`): 6 to 7 out (a real lsrs).
- Store forwarding `f40 = obj->f44 - kb`: gives a subs.
- `__restrict` cfg: 55 out.
- Candidates 4 and 5 do not apply.

Permuter anneal 800, seed 4601: no gain.

## 0x0202627C (bmp_oam.c): 10 -> 10, DIFF
Measured from the w-first alternative source:
- These all gave output byte-identical to the base: `a - a`, `a & 0`,
  `(u32)(p != p)`, `&= 0`, and forwarding from the cleared field
  (`p->kind = p->f18` after `p->f18 = 0`).
- An extern zero, `(p == 0)`, `(w > 0xff)` and `w >> 8`: 272 to 280 bytes.
- Candidate 5 does not apply.

Permuter anneal 800, seed 4602: flat at 10.

## Finding
mwcc folds every zero spelling that still emits `movs #0` before
codegen, including a value forwarded from a field cleared earlier. Every
spelling that survives folding emits a different instruction (a load, a
compare, a shift or a subs). So the spelling of the zero cannot change its
web or its position in the schedule. Both residues are beyond source spelling
under 1.1p1 -O4,p.

## Files written
- docs/notes/func_0202350C.c.txt (wave 20 zero_web section, best source unchanged)
- docs/notes/pkt_0202627C.c.txt (wave 20 zero_web section, best source unchanged)
- this report

No shards were verified and no idioms were written. Seeds used: 4601 and 4602. The integrator
has nothing to do beyond fixing the direction of the 350C residue in the 20D summary.

# Wave 12: backup_system.c, second lane

**Result: 2 of 4 exact (0x02031F54 and 0x02032688, 660 bytes). 0x02031FE0 went from 42 to 9 bytes out. 0x0203335C did not move from 21.**

| addr | size | verdict | where |
|---|---|---|---|
| 0x02031F54 | 64 | **EXACT**, dsi/1.1p1, ARM | src/matched/func_02031F54.c, shard pkt_02031F54 |
| 0x02032688 | 600 | **EXACT**, dsi/1.1p1, ARM | src/matched/func_02032688.c, shard pkt_02031FE0 |
| 0x02031FE0 | 1704 | DIFF, size-exact, 42 → **9** bytes out | appended to docs/notes/pkt_02031FE0.c.txt |
| 0x0203335C | 156 | DIFF, still 21 bytes out | appended to docs/notes/sub_0203335C.c.txt |

Gates:
- `manifest --verify --shard pkt_02031F54`: 1 entry, EXACT.
- `manifest --verify --shard pkt_02031FE0`: 1 entry, EXACT.

## What closed them (both are declaration fixes, as the lessons predicted)
- **0x02031F54**: the record pointer has to be declared `const struct SaveBackup *`. So do both callees' first parameters. With a non-const pointer, each field load has to stay after the footer store before it, because the compiler must assume the two may overlap. The image loads above the stores, which only a const pointer allows (see idiom const-pointer-lets-a-field-load-survive-a-store). The ~30 earlier spellings and all the permuter runs missed this because it is a type-qualifier change. dsi/1.1p1 only; ../2.0/sp2 still leaves the 16-byte residue on the same source.
- **0x02032688**: **func_020333F8 takes the record only**, so it is called as `func_020333F8(self)`. Its matched body uses only a0 (it clears +0x138 for +0x13C bytes). Passing `(self, mode, arg3)` was the wrong argument list, and it caused the whole 10-byte residue in the argument setup of the first `func_020335E8` call. Checked:
  - all 26 relocations resolve;
  - data flow is unchanged, because mode and arg3 are still read later in the function.

## 0x02031FE0 (9 bytes left)
- The same one-argument `func_020333F8(self)` fix closes residue 1 (42 → 14).
- Reading the record's leading u16 counter through an inline accessor (`cnt16(pa)` / `cnt16(pb)`) fixes both compare operand orders and one load order (14 → 9).
- **Left: B and A+B swap registers r4 and r8.** None of these moved it:
  - all 720 declaration orders of B, pa, pb, AB, A, i;
  - the loop locals declared in the loop block (120 orders);
  - separate variables for the copy-back loop;
  - no AB local, `B + A`, u16* or struct-typed record pointers, a footer-pointer helper;
  - `cur` in the compares.
- Permuter from the 9-byte source: hill 800 and anneal 1500, both with `--types`, stayed at asm=45 bytes-out=9.
- ../2.0/sp2 gives 1748 bytes, so dsi/1.1p1 stays the compiler.
- The best source is written into the note as a diff against the wave-11 source.

## 0x0203335C (unchanged at 21)
I tried the same kinds of declaration fix; none moved it:
- a const pointer (worse, 50);
- width and signedness of v, tmp, slots, w and sh;
- an extra parameter;
- named constants for 3 and 0xFFFFFFFF;
- inline getter and setter helpers.

A 48-way structural grid on the natural form (count, getter, setter, how the 1↔2 swap is written, for vs do/while) compiles to the same 32 lines out every time. So the compiler normalises the code shape, and the residue is only in how the values are numbered. I did not re-run the permuter here: the note already records ~12,000 compiles from this source.

## Family header
docs/families/backup_system.h, updated with:
- the prototype for 0x02031F54, with the const proof;
- func_020333F8 re-declared as one argument, with the proof;
- the new state of 0x02031FE0 and 0x02032688.

## Integrator: seed
None. Both matched files are plain EXACT, with no unlabelled followers.

## General lesson worth propagating
Two more wave-12 closes came from declarations the permuter cannot reach. Two checks before any hand spelling sweep:
- **A load that sits above an earlier store in the image** means the base pointer is `const`.
- **A forwarding call** (like `func_020333F8`): read the callee's matched body to see which arguments it really takes. Extra arguments reshuffle the argument-setup schedule at unrelated call sites.

Nothing committed.

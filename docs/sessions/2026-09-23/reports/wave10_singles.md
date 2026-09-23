# Wave 10 singles: report

**4 functions EXACT (the three assigned plus one sibling), 3 still DIFF, nothing committed.**

## EXACT, filed in src/matched

| function | packet | compiler | bytes | shard verified |
|---|---|---|---|---|
| func_0206E7EC | pkt_0206E62C | ../2.0/sp2 | 360 | EXACT |
| func_0206E62C (sibling, not on the list) | pkt_0206E62C | ../2.0/sp2 | 448 | EXACT |
| func_020917D4 | pkt_020917D4 | 1.1p1 | 788 | EXACT |
| func_0206BA18 | pkt_0206BA18 | ../2.0/sp2 | 1160 | EXACT (not capped at MATCH: both table words now resolve as sole-ref/self) |

`manifest --verify` was run for pkt_0206E62C, pkt_020917D4 and pkt_0206BA18. Every entry in those shards reads EXACT.

### What closed each one
- **0206E7EC / 0206E62C.** These are NitroSystem g3d resource-dictionary lookups by a 16-byte name (the index form and the data-pointer form). The header said 1.1p1, but the right compiler is 2.0. The image keeps a separate +0x10 induction register for the scan's name pointer. Only 2.0 strength-reduces it that way; 1.1p1 never does.
  - Other levers: declare `u32 i` before the four key words (otherwise the ldm splits), write the accessors as `static inline` NNS-style helpers, and keep the trie bit index signed.
  - The last 5 bytes were a child-index register tie. The permuter's mutations closed it and are value-preserving: decl-order(idx<->x), expand(idx), expand(n).
  - 62C compiled EXACT on the first try, using the 7EC body with the data accessor.
- **020917D4.** This is MSL `__fread`, written the way MSL writes it. The first compile was 788/26. The only other fix was the FILE layout: eof and error are plain u8 members at +0x0c and +0x0d. The earlier note called its 456-byte residue a colouring problem; it was actually a wrong body.
- **0206BA18.** This is the NNS g3d SBC MAT internal-default body. I started from the wave-7 source and made three fixes:
  - The material lookup uses the NNS inline pair GetResDataByIdx and GetMatDataByIdx, with the null test on the material block inside the inline and one shared `return 0`.
  - The texture-matrix flag tests are negated, NNS style, so the flag arm if-converts.
  - The packed geometry-command buffer: cmd[0] = 0x293130 is passed as the op argument and cmd[4] = 0x2b2a. The old note had cmd[0] as a pointer to g_020A1954.

## Still DIFF (cluster pkt_02066740, packet pkt_02067080)

| function | best | compiler | where recorded |
|---|---|---|---|
| func_02067340 (1052, first transcription) | 1052/46 | ../2.0/sp2 | new note docs/notes/func_02067340.c.txt |
| func_02067080 | 704/29 (permuter), 32 readable (was 37) | ../2.0/sp2 | appended to docs/notes/pkt_02066E30.c.txt |
| func_0206775C | 572/81 (permuter; readable stays 95) | ../2.0/sp2 | appended to the same note |

- **02067340** is the NNS g2d renderer-core 2D OAM cell loop. It is size-exact with the stack layout exactly right; what's left is a rotation of four callee-saved registers. Hill 800 plus anneal 1800 are flat.
  - Permuter best line: `best DIFF asm=365 bytes-out=46 size=1052/1052, mutations decl-order(flip<->pCache)`.
- **02067080.** Writing the DOUBLE-branch extent indices as signed (GXOamShape) temps fixes the first half. What's left is the MulVec22 accumulator (image r8, compile ip) and the 17D8 base that follows from it.
- **0206775C.** A lever from the 7340 sibling is recorded but not yet tried here: read each flip bit into its own temp before the IsFlip call.
- The required permuter runs (explain, hill 800, anneal 2000) were done on all three. Results and best lines are in the notes.

## Headers and notes updated
- **Cluster headers** (wave-10 addendum in each):
  - docs/families/cluster_0206E62C.h: the compiler pin is really 2.0, and the NNS struct layouts.
  - docs/families/cluster_02091588.h: the MSL FILE layout and the callee names.
  - docs/families/cluster_0206AF08.h: the NNS SBC identification, the three levers, and the pool words no longer being blocked.
  - docs/families/cluster_02066740.h: the 7340 rig layout and the flip-temp lever.
- **Notes:**
  - Closure lines appended to docs/notes/pkt_0206E62C.c.txt, pkt_020916D4.c.txt and func_0206B7D0.c.txt.
  - New note docs/notes/func_02067340.c.txt.
  - docs/notes/pkt_02066E30.c.txt extended with the 080 and 775C re-measurements.

## Lesson for the next lane
Most of these rows are library code: NitroSystem g2d and g3d, and MSL. Recognising the library routine and writing it the way the library does closed three of them where respellings and the permuter had stalled. The shared GetResDataByIdx inline (`dict && idx < numEntry ? ... : 0`) turned up in two unrelated clusters.

## Housekeeping
- Two long permuter runs were auto-moved to the background by the 5-minute timeout. One stale 1.1p1 anneal was killed; nothing is left running.
- At first I used the shared scratch directory w10, which other lanes also write to. I moved to scratchpad/singles10 before relying on any results.

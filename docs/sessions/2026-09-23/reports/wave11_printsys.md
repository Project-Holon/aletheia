# Wave 11: wipe_sub.c, printsys.c, musical_dist_save.c

**10 EXACT: 9 new, plus 1 pending park promoted.** Nothing is committed. Every packet I filed into passes `python3 tools/match.py manifest --verify --shard <pkt>`: pkt_02022F60, pkt_02023964, pkt_0202384C, pkt_02023AF4, pkt_02022AC4, pkt_0201CEE0, pkt_0201CD10 and pkt_0201C7A4.

## Filed EXACT (src/matched)

| address | file | verdict | cc | what closed it |
| --- | --- | --- | --- | --- |
| 0x02022F60 (1284 B) | func_02022F60.c | EXACT | 1.1p1 | When +0x309 is 0 the code writes the MAIN engine WININ/WINOUT registers, reached as 0x04000004+0x44/+0x46. Otherwise it writes the SUB engine registers 0x04001048/4A. The old note had both arms the same, so mwcc cross-jumped them. That was the whole 140-byte gap. Also needed: the engine is read into a local before the window test; the second half base is a named local `h = &p->h[1]`; the body is wrapped in `if (n < 0xC0)`; the mask is `~0x3F00`. |
| 0x02023964 | func_02023964.c | EXACT | 1.1p1 | The note's call was `func_02022F0C(a0, desc, a3)`. The real call is `(a6, obj, a7)`. |
| 0x0202384C | func_0202384C.c | EXACT* | 1.1p1 | func_020237B8's 3rd argument is `w->f14`, not 0. The guard is `if (y<=f14) call; else if (y<=2*f14) copy; else call;`, and mwcc cross-jumps the two calls. EXACT* is only the 2-byte pad. |
| 0x02023464 | func_02023464.c | EXACT | 1.1p1 | The call is written in both arms of the cfg[8] test, with literals 1 and 2. The notes' "r4/r6 allocator tie" (3800 compiles) was really the `mode` local. |
| 0x02023AF4 | func_02023AF4.c | EXACT* | 1.1p1 | Plain `near = near == 0` in a for loop. The hand-hoisted `one`/`zero` locals were causing the 13-byte rotation. EXACT* is only the pad. |
| 0x02022AC4 | sub_02022AC4.c (moved from pending) | EXACT | 1.1p1 | The header named the callee 0x020202CC, but the pool word is 0x020222CD. With the callee as 0x020222CC it resolves `label`. The integrator already committed this move in e3ccd2e while I was working. |
| 0x0201CEE0 (556 B) | func_0201CEE0.c | EXACT | 1.1p1 | First attempt at this function, decoded from the image. The shape: 1-bit fields at +0x22; `goto end` early exits; a guarded preheader holding the dead-store `ctx` pair; a switch whose ctrl helper takes the loaded halfword; `case 1: default:`. |
| 0x0201D110 (348 B) | sub_0201D110.c (pkt_0201CEE0) | EXACT | 1.1p1 | Rewritten. `*cur` is a named local. The kind helper returns a u32 `(u8)p[1]`. state/mode are set through an inline taking the record, so the flag load is not hoisted and cases 0/1 cross-jump. The x copy comes before the y clear. |
| 0x0201CD10 | func_0201CD10.c | EXACT | 1.1p1 | a1/a2 are `s16`, because the real prototype of func_0201C808 takes s16. The 10th argument is `u16 a9`; faking it through `&a4` was what pinned the a4 load late. The ABS32 to 0x0201CEE0 resolves. |
| 0x0201C7A4 | func_0201C7A4.c | EXACT | **../2.0/sp2** | Compiler pin: 1.1p1 caches the scratch address used twice, sp2 reloads it at each site. The header carries `compiler: ../2.0/sp2`. |

## Still DIFF (appended note sections, each with a best-source marker and the permuter result)

- **wipe_sub 0x0202350C** (`docs/notes/func_0202350C.c.txt`): still 90/92 bytes, 23 out, a scheduling window. Hill gave 26 and anneal 24/34, both worse. I tested 12 load/store orders, struct cfg and an inline setter. sp2 is also 23.
- **printsys 0x0201C4E4** (`sub_0201C4E4.c.txt`): improved from **12 to 5** by making the wrap an inline helper, `if (o >= ps->unk04) return 0; return o;`. The rest is one scheduling pair at +0x14E. Hill and anneal best: `DIFF asm=205 bytes-out=5 size=464/464`.
- **printsys 0x0201C8BC** (`pkt_0201C8BC.c.txt`): still 17. Hill found no single mutation that helps. `done` really does need a memory home: made non-volatile it is 180 bytes / 156 out.
- **printsys 0x0201D768** (`func_0201D768.diff.c.txt`): still 72. Correction: MI_CpuCopy8 is (src, dst), so the function copies into the ring. I measured the exact frame the image uses. Declaration order never moves a spill slot. One `int` variant hung the compiler.
- **printsys 0x0201C7D0** (`pkt_0201C7D0.c.txt`): **2 bytes under 2.0/sp2**. The only mismatch is the base of the stacked u16 read: 1.1p1 forms it right but gets the pool caching wrong. Hill found no improvement; I stopped the anneal because sp2 compiles were very slow.
- **musical_dist_save 0x0200CC40** (`pkt_0200CC40.c.txt`): improved from 300 to **239 out**, 364/402 bytes. It has a sixth parameter, a stacked `u16 a5`, and an inline TestBit; the prologue and form loop are now byte-exact. What remains: the image rebuilds the mask and index after every join, and mwcc shares them.
- **musical_dist_save 0x0200C52C** (`pkt_0200C52C.c.txt`): now **size-exact, 120/120, 36 out** (was 116, 58 out). func_02012EBC takes `sys`. I rejected the permuter's two 120-byte hits (a volatile result and a u8-truncated result) as semantically wrong.
- **musical_dist_save 0x0200D144**: still 22. sp2 gets the size right (322) but shares the constant 1, so the compiler is 1.1p1.
- **musical_dist_save 0x0200D064**: still 72/42. The image never hoists `p+off` out of the loop.
- **musical_dist_save 0x0200CA98**: not reworked. I only checked it against both compilers. Correction: its note's recorded 400/344 point was never written back as source; what the note actually contains compiles to 380/358.

## Family headers updated

- `docs/families/wipe_sub.h`:
  - the scanline object's front half: two 0x184 halves, mode at +0x308, engine at +0x309;
  - a correction: WipeScan's s16 arrays belong to the buffer sub_02022D88 returns, not to the 0x334-byte object;
  - the six closing facts.
- `docs/families/printsys.h`:
  - the full 0x50-byte text record layout and how its flags are spelled;
  - func_0201C808's s16 prototype;
  - the 2.0/sp2 pin for 0x0201C7A4 and the status of 0x0201C7D0;
  - the inline-helper facts.
- `docs/families/musical_dist_save.h`: CC40's 6-parameter signature, func_02012EBC(sys), and why D144 is 1.1p1.

## Integrator: seed

- `0x0200D288`: the unlabelled leaf follower of func_0200D144 (`return b != 0 ? 0 : p->unk4D0`, 12 bytes). It was already witnessed in `docs/notes/pkt_0200D144.c.txt` and is still unlabelled; D144's listing extent is still 340.
- No other new unlabelled leaves. Both EXACT* results (0x0202384C, 0x02023AF4) come from 2-byte alignment pads before followers that are already labelled.

## Process notes

- Three compiles hung past 60 s: an `int total; int head;` D768 variant, a C8BC variant under sp2, and the sp2 anneal on C7D0. I killed each one. No processes of mine are still running.
- The two 2.0/sp2 results in printsys (0x0201C7A4 exact, 0x0201C7D0 2 bytes out) suggest part of printsys.c may be built with sp2. CEE0, CD10 and D110 are still 1.1p1-exact, so the pin is per function.

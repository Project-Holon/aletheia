# Wave 11 singles lane: 0x020924DC and 0x0209739C

Result: 1 exact, 1 DIFF (documented). Nothing committed.

## 0x020924DC: EXACT (pkt_02092120, 1.1p1, ARM, 1292 bytes)
- Filed as `src/matched/func_020924DC.c`. The status line reads EXACT. The file has a full header: packet pkt_02092120, compiler 1.1p1, isa arm, and the symbol `__ctype_map 0x020A61DC data a2`, which resolves by `literal`.
- Identified as MSL printf.c `parse_format`. Its caller is `__pformatter` at 0x02093BDC, already EXACT. I wrote it in the Metrowerks source shape instead of transcribing the bytes: `int c`, `int flag_found`, a flag loop of `for(;;){flag_found=1; switch...}`, the length modifiers as a second switch, g/G falling through into e/E, and `*format = f`.
- The first compile was 12 bytes out. Two fixes closed it:
  - isdigit's range test is unsigned: `(unsigned int)c < 0x80` gives movhs/lsllo; the signed form gives movge/lsllt.
  - The length cases are ordered j, t, z.
- No permuter run was needed. Under ../2.0/sp2 the same source is 1392 bytes, so no pin.
- The earlier transcription stopped at 763 out after 2800 permuter compiles because its shape was wrong, not because of register allocation.
- `manifest --verify --shard pkt_02092120`: 3 entries, all EXACT, 0x020924DC included.

## 0x0209739C: DIFF (MSL __dec2num, pkt_02096D10). Unchanged at 1520/1524, 721 out, 1.1p1
- Re-verified at 1520/721.
- Other compilers on the same source:

| Compiler | Size | Result |
| --- | --- | --- |
| ../2.0/sp2, sp1, base | 1576 bytes | wrong from +0x1C |
| ../1.2/sp4 | 1636 bytes | worse |
| ../1.2/base | 1660 bytes | worse |

  The rest of the library is 1.1p1, so no pin.
- Permuter runs, all rejected:

| Run | Best | Mutations | Why rejected |
| --- | --- | --- | --- |
| --explain | map r5->r6 x10, r7->r8 x6, r6->r7 x5 | none | baseline |
| hill, 400 | 1524/788 | volatile-add | size compensation |
| anneal, 1000, --types | 1524/390 | u8 ndig plus others | u8-counter size compensation, same as waves 9 and 10 |
| anneal, 1000, focused on the refinement loop | 547 | volatile/hoist chains | volatile is not the image |

- Hand probes, all 709 to 724 out (the source is 721):
  - do/while(0) and for/break wrappers around the sections before the loop
  - a label before the loop
  - `is_high = !is_low`
  - `is_low = less != 0`
  - storing guess earlier
  - the loop plus found block as a static inline helper. At 709 it was the closest, but 1.1p1 inlines before it places constants, so the helper's constants still sit at +0x2A0.
- The residue stays at constant placement. The image materialises {&dec, &x64, 0} a second time at the refinement loop's preheader (+0x3A4). 1.1p1 CSEs them into the +0x2A0 group, and shares the zero with pow's 5.0.
- Appended as a section to `docs/notes/pkt_0209739C.c.txt`, with the best-source marker and the permuter's best line.

## Headers updated
- `docs/families/cluster_02092120.h`: row list, section 3 rewritten (the parse_format shape and the two load-bearing levers, field_width is a signed int), prototype corrected.
- `docs/families/cluster_02096D10.h`: wave-11 line on func_0209739C.
- `docs/notes/pkt_020924DC.c.txt`: closing section added.

## Integrator: seed
None. No unlabelled leaves were found.

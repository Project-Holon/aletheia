# Lane U6 - ov016 open SDK rows 13..25 (2026-09-30)

Slice: `python scratch/a2/open_rows.py ov016 13 13`. All 13 rows are TwlDWC
`libdwcutil.TWL.HYB.a` members; every parked source was left in place, untouched.
One row closed (0x021D0B44, see row 16 below). Method used: `tools/sdkobj.py <addr> --region ov016` first (register map +
relocations), then the diff by byte offset, then `docs/idioms/`. Every residue below is
named with the first differing instruction, image left of `|`, ours right.

Compiler axis checked once per the wave exception (`--cc ../2.0/base` and `../2.0/sp1p2`)
on the two rows that are size-exact with a differing body: 0x021CFCC8 and 0x021D0B44.
Both trees are larger (360 / 392) and keep the same wrong schedule, so the default
dsi/1.1p1 stands.

## Residues (all sizes = image size unless stated)

| # | address | bytes | symbol (object) | residue |
|---|---|---|---|---|
| 13 | 0x021CFCC8 | 336 | write (setting.o) | image `str r2, [sp]` (work) at +012C *before* `ldr r0, [r6]` (MemSet); ours schedules the MemSet load and `add r1, sp, #4` above work's store. 3 instructions, size exact. 2.0 trees 360 B. |
| 14 | 0x021D0E74 | 344 | scanFirst (usbap.o) | image `str r0, [sp]` - the parameter is spilled to [fb+0] and `i` takes r11; ours `mov fp, r0` (prm in r11, `i` in r8) and folds the loop's prm reload away: 332 vs 344. `../2.0/base` and `../2.0/sp1p2` are also 344 but still `mov fp, r0`. |
| 15 | 0x021D5A58 | 360 | DWCi_FNTlFormBgEx (font.o) | image stores `cv->self` (+0x18) at +00AC before computing `cv->font` (+0x1c); ours emits font first. Also the 8-argument call at +00D0: image computes the `g_021DAA70[lcd]` table load before the constant stack args, ours stores arg4/arg5 first. Both diffs are pure permutations of the same instructions. |
| 16 | 0x021D0B44 | 372 | DWCi_USBAPlBegin (usbap.o) | **EXACT, filed** (`src/matched/ov_sdk/ov016_func_021D0B44.c`, shard `ov016/pkt_ov016_021D0B44`). Image re-reads the global (`ldr r0, [r5]` at +0040) for the `WM_Initialize` argument after the u64 store; a plain read is CSE'd into `mov r0, r4`. Closed by reading the second reference as `*(MemUsbT *volatile *)&g_021DE654`. See docs/notes/idiom_volatile-pointer-cast-forces-a-global-re-read.md. |
| 17 | 0x021C687C | 400 (ours 404) | input (input.o) | switch lowering: image tests the 0x80..0x83 cluster first (`cmp r4, #0x83` / `bgt`, `cmp r4, #0x80` / `blt` to the zero test), 1.1p1 tests case 0 first (`cmp r4, #0`). Every case body byte-identical. |
| 18 | 0x021B87F0 | 464 (ours 448) | AOSSi_WLANConnect (aosslink.o) | **thumb** member (image isa thumb, ours was compiled arm). With `--thumb` we are 448 B: image `push {r3, r4, r5, r6, r7, lr}` / `sub sp, #0x40`, ours `push {r4, r5, r6, r7, lr}` / `sub sp, #0x44`. Needs the thumb source plus 16 more bytes of frame. |
| 19 | 0x021C84BC | 508 | initGraphics (scenesetlist.o) | image holds the 0x04001008 pool constant in r1 and computes `sub r2, r1, #0x1000` **at the use** (+0170), keeping MemSsl in r2; ours holds the constant in r2 with the sub hoisted and MemSsl in r1. Last six register writes only; static-inline vs macro spelling is inert. |
| 20 | 0x021C2610 | 528 (ours 504) | drawInfo | image `add sl, sp, #0x1a` / `mov sb, #0x14`; ours `add sb, sp, #0x1a` / `mov r8, #0x14` (different callee-saved rotation, 24 B short). |
| 21 | 0x021C1210 | 632 (ours 596) | taskFramework (move.o) | image lowers the switch as an `addge pc, pc, r0, lsl #2` jump table 0..0x14 plus a tree for 0x1a/0x1d/0x23/0x26...; 1.1p1 emits a compare chain (`cmp r0, #0x14` instead of `cmp r0, #0x1a` at +0068). Body bytes correct. |
| 22 | 0x021C9A94 | 636 (ours 620) | isPush | image `mov r7, #0x1d` at +000C and `ldr r0, [pc, #0x258]`; ours `mov r6, #0x1d` / `ldr r0, [pc, #0x248]` - callee-saved rotation, 16 B short. |
| 23 | 0x021C00A8 | 640 (ours 624) | disp | image `ldr r3, [pc, #0x24c]` at +0008; ours `ldr r4, [pc, #0x240]` - pool/register rotation, 16 B short. |
| 24 | 0x021BE844 | 656 (ours 652) | disp | image `sub sp, sp, #0x18` and `ldrb r5, [r4, #4]`; ours `sub sp, sp, #0x20` and `ldrb sl, [r5]` - frame is 8 B larger and the base pointer is a different register. 4 B short. |
| 25 | 0x021B9BF8 | 660 | ScanAP (atermset.o) | **thumb** member. Size exact only with `--thumb` (660 = 660, 520 B of diff). Image `push {r3, r4, r5, r6, r7, lr}` / `sub sp, #0x70` / `str r0, [sp, #8]`; ours `push {r4, r5, r6, r7, lr}` / `sub sp, #0x6c` / `str r0, [sp, #0x14]` - the image's frame has 8 B more locals and a different local ordering. |

## Read across the residues

* Rows 13, 15, 16 are **size-exact with a pure instruction permutation around a call or a
  store** - the same pattern the 4.0.0.1025 scheduler produces and 1.1p1 does not. Four
  rows of this shape in this overlay all resisted body re-spellings; they look like a
  scheduler difference, not a source difference. Rows 16 and 13 also resist the 2.0 trees.
* Rows 17 and 21 are **switch lowering** differences (jump table vs compare chain) and are
  not reachable from the source without the 4.0.0.1025 front end.
* Rows 18 and 25 are **thumb** members: the parked sources must be compiled with `--thumb`
  before anything else is measured. 0x021B9BF8 is already size-exact under `--thumb`, so it
  is the best remaining candidate in this slice - the whole job is the 8-byte frame and the
  local layout, not the body.
* Rows 14, 19, 20, 22, 23, 24 are register-allocation differences (which callee-saved
  register a value gets / whether the parameter is spilled); no source shape tried moved
  them.

Verified with:
  python tools/match.py one --src <src> --func <name> --addr <addr> --region ov016 --cc 1.1p1 --arm --lang c99 --diff
  (rows 18 and 25 with --thumb)

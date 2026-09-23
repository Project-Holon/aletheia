# Wave 12: leftovers in bg_sys.c, bmp.c and bmp_win.c

Two functions are now EXACT and filed. The other five are still open. Four of those have a new appended DIFF section in their note. The fifth, 0x02040EC0, is not a real function start. Nothing was committed.

## Now EXACT (2 functions, 840 bytes)

| addr | size | file | shard | what closed it |
| --- | --- | --- | --- | --- |
| 0x02044F64 | 292 | src/matched/func_02044F64.c | pkt_02044F64 | The four extents are `u16` locals written `h = height/8; w = width/8; dep = depth; d = dep/8`, assigned in exactly that order. The old `lsl #13 / lsr #16` reading was just the u16 truncation of an unsigned `/8`. Before: 6 bytes out. All-u16 with w first: 13. Height before width: 0. Declaration order makes no difference. |
| 0x02041FF4 | 548 | src/matched/func_02041FF4.c | pkt_02041FF4 | `u8 px, py` moved to function scope, declared first and assigned after the two calls, so they share registers with x and y (42 → 15). `u8 i` moved to function scope (15 → 9). Locals declared in the order i, then tbl, then buf (9 → 0). |

- Both files re-verify with `match.py one`: EXACT, all relocations resolved (7/7 and 11/11).
- `manifest --verify --shard pkt_02044F64`: writes a new shard with 1 entry, EXACT.
- `manifest --verify --shard pkt_02041FF4`: func_02041FF4 EXACT; the existing func_02042218 entry is still EXACT.
- Data flow is unchanged in both. No `--types` narrowing was accepted.

## Still DIFF (appended sections, each with the best-source marker and the permuter's best line)

- **0x020454E0**, 536/536, 2 bytes out: a 2-byte tie over which register holds the `pal` copy.
  - Note: `docs/notes/pkt_020454E0.c.txt`
  - The AST permuter had never been run on it. `--explain` shows one register, r6 → r4. A hill run of 800 with `--types` found nothing among 278 single mutations.
  - ../2.0/sp2: 600 bytes, 486 out.
  - About 40 more hand spellings all stay at 2 bytes or get worse. They cover parameter and local types, inline helpers, both callees' prototypes, and a ternary, `*0x1000` or mask form for the palette.
- **0x020433E0**, 188/188, 6 bytes out: the same r3 ↔ ip swap as before.
  - Note: `docs/notes/func_020433E0.c.txt`
  - Hill 800 `--types`: no improvement. ../2.0/sp2: also 6.
  - Eight new spellings of the tail (array, register temporaries, `and` then `orr`, `+` instead of `|`, operand order), each tried with a volatile and a non-volatile struct: all 6 to 11.
- **0x0204427C**, 888/888, 276 bytes out (was 277).
  - Note: appended to `docs/notes/pkt_02043B98.c.txt`
  - New diagnosis: the image's keyed loop keeps 5 scratch registers live against our 4. It interleaves the dst and src partial addresses, and that extra pressure causes the ten-register push and the 0x28 frame.
  - The 36 address-shape combinations stay at 888 bytes and 276 to 284 out when p comes first, and drop to 880 bytes (SIZE) when q comes first.
  - Anneal 1400 reaches 197, but only through `addr(v)` noise, so I rejected it. ../2.0/sp2: 1000 bytes, 881 out.
- **0x0203FCA0**, 1860/1876, 1171 bytes out.
  - Note: `docs/notes/func_0203FCA0.c.txt`
  - The brief lists it as 488 bytes. The worklist and the listing both say 1828 code bytes plus a 48-byte pool.
  - New finding: in the affine arms, the image assigns registers by field (screenBase r8, charBase sb in both type 1 and type 2). Every compile assigns them by load order.
  - Tried without effect: SDK-order inline setters, areaOver hoisted before the switch, all 48 OR-term orders, ../2.0/sp2 (1988 bytes).
  - The permuter's `type:ret-var(ss)` hits the right size, 1876, but at 1325 bytes out, and it makes the function return a value. The image returns void, so I rejected it.
- **0x02040EC0** (32 bytes): not a real function start. It begins four bytes inside the `push {r0-r3}` prologue of sub_02040EBC, and those bytes are already EXACT in src/matched/unit_02040E78.c. There is nothing to file.
  - `src/pending/func_02040EC0.c` is a stale DIFF copy of the same bytes. The integrator may want to delete it.

## Family headers

- **New: `docs/families/bmp_win.h`**, written from the 10 matched source files (24 functions, including the 14 accessors in `unit_02045730`).
  - It lays out the 16-byte `struct BmpWin`:
    - +0: a 15-bit tag 0x7fb2 plus an is8bpp bit
    - +2: the BG layer
    - +3/+4: tilemap x and y
    - +5/+6: bitmap width and height in tiles
    - +7/+8: the on-screen width and height
    - +9: palette
    - +0xa: the first tile number of the window's character data
    - +0xc: the window's bitmap (`struct Bmp *`)
  - Two corrections to how existing files read the struct:
    - +3/+4 are coordinates, not the screen/char bases that sub_02045210's parameter names suggest.
    - +0xc is the bitmap, not a "heap handle": sub_02045210 stores func_02043678's result there, func_020437AC frees it and func_020437D4 reads its pixels.
- **`docs/families/bmp.h`**: added the u16 extent locals and the h, w, dep, d assignment order under the func_02044F64 entry. This supersedes the older `(u32)(f*8192)>>16` reading and the "u32 h" section.
- **`docs/families/bg_sys.h`**: the func_02041FF4 entry is now marked EXACT. It records the proven prototypes (func_02043130 with a u16 first parameter, func_02040EE0 taking (u8, u8, u8), func_020415B4 returning `u8 *`) and the function-scope px/py rule.

## Integrator: seed

None. I found no new unlabelled leaves; func_02044F64 and func_02041FF4 both came out plain EXACT.

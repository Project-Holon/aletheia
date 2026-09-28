# tree_ov093 report

Tree: root ov093 func_021BDE98 (1184 B, real; 0x021E91E8 is the only other root of 1 KB or more). There are 210 open functions under it, so the cap applies. I worked leaves up to the finished subtree func_021D80BC (316 B). The root is not attempted, and ov094 was not reached.

EXACT/EXACT\*, 39 filed. Each is in src/matched/ov093_func_<addr>.c with shard pkt_ov093_<addr>, verified twice (the second pass rewrote nothing):
021BD1E0 021BE518 021B99E0 021BDE48 021B8778 021B87E8 021B8834 021B88EC 021B8BEC 021B8C20 021B8C38 021B8CB0 021B8D08 021B8D38 021B8D8C 021D5364 021D539C 021D5584 021D55A0 021D5608 021D5778 021D57A8 021D5814 021D5B68 021D5BB0 021D5BDC 021D5C08 021D5FA4 021D5FC0 021D621C 021D62A8 021D62C4 021D6C2C 021D6E40 021D78AC 021D80A8 021D80BC 021D82D0 021E8B80.

Levers that closed functions:
- The count read through `volatile` (021D55A0).
- A `u8` parameter plus the call argument read from the just-stored field (021D5608).
- A struct-typed return/argument, which forces the frame (021BDE48).
- `(f & 1) == 0` instead of `!` (021B8C20/38; new idiom file).
- Default-merged empty cases (021B87E8, 021D80BC).
- A store written in both arms (021B88EC).
- A shared `return 6` exit (021B8D8C).
- The arm9 RNG shape for `_ull_mul` (021D78AC).

The permuter was not used.

DIFF: 021B9A40 (`x >= 12`, 3 bytes, arm polarity). Notes are in docs/notes/pkt_ov093_021B9A40.c.txt.

Next lane (open under the root, smallest first): 021D57FC 021D7AF0 021C5604 021C5D88 021D61F0 021D6238 021C5480 021C03AC 021C03D8 021C0780 021C88E4 021D7D18 021D732C 021D7360 021D73D4 021D7394 021CC8D8 021BE924 021BE95C 021D74F8 021D75EC 021D7630 021D7540 021CD4B0 021CD64C 021E0354 021E02DC 021D6F0C, then 021C001C (560) and 021BEC58 (916).

Integrator:
- I filed func_021E8918 by mistake and then removed it, because it already lives in pkt_021EA478. `manifest --check` is clean for ov093; the only duplicate left is in ov010, from another lane.
- lane.py counts about 35 Thumb-to-ARM `bx pc` veneers (16 B, for example 0x021BE338..0x021BE398 and 0x021CA8C8) as open game code. Their pointer words target 0x0689xxxx, so no C matches them.
- 0x021EF90C and 0x021EF948 sit beside SetBottomScreenLineCentered (screen.o) and look like libdwcgscommon. That makes them SDK lane work.
- ov093 appears to be largely libdwcutil (DWC_StartUtilityEx at 0x021EF8A4). Please check whether its "game" figure is honest.
- Regenerate the idiom index.

# tree_ov093 report (second lane, 2026-09-28)

## Tree

The root is func_021BDE98 (1184 B, ov093 game). This lane continued the previous lane's "next lane" list under that root, working bottom up. It then took the subtree of func_021C001C (560 B) down to its leaves.

44 functions are filed as EXACT or EXACT\*. The permuter was not used.

## Files

Each file is `src/matched/ov/ov093_func_<addr>.c` with shard `layout/matched/ov093/pkt_ov093_<addr>.json`. Every shard was verified twice, and the second pass rewrote nothing.

EXACT (38): 021BE924 021BE95C 021C0274 021C02CC 021C031C 021C03AC 021C0404 021C0780 021C5480 021C54C8 021C54FC 021C557C 021C5620 021C5D88 021C88E4 021CC8D8 021CD4B0 021CD64C 021D57FC 021D6130 021D61A8 021D61F0 021D6238 021D6F0C 021D732C 021D7360 021D7394 021D73D4 021D7474 021D74F8 021D7540 021D75EC 021D7630 021D77C4 021D7B8C 021D7D18 021E02DC 021E0354

EXACT\* (6): 021C03D8 021C5604 021D62D8 021D7AF0 021E03E8 021E8AFC

New idiom: `docs/idioms/a-varargs-anchor-reloaded-from-its-home-slot-is-a-volatile-parameter.md`.

## Levers that closed functions

- **021CD4B0:** a `volatile` last named parameter in a variadic function (the new idiom above). Its sibling 021CD64C is variadic with a `u8` anchor.
- **021C5620:** a struct-returning callee (`struct Slot func_021D6314`) forces the 8-byte frame.
- **021D732C, 021D7394, 021D73D4:** dropping the overlay token on the contested `data_021F3CB0` line lets the relocation attest.
- **021D7540:** a post-increment store, `keys[i++] = 0`.
- **021D6F0C:** the `if (n != 0) { ... } return 0;` shape, plus the order of the key store.
- **021E02DC:** a `u16` key parameter.

Several shared layouts were recovered from the code:

- The priority list node and its pool (`data_021F3CB0`).
- The `g_021F3ECC` key/value stack.
- The slot-kind union at `+0x1C`.
- The `0x1D74` lock word.

The ints 3985/3987, 4000/4004 and 5537/5544 passed to the lock/stack calls look like debug `__LINE__` arguments.

## Next lane (still open under the root)

- **Callees of func_021C001C:** 021C0450 (208 B) and 021C0520 (608 B). 021C0450's callees include 021C63D0, 021C4F64, 021BC2B0, 021C5C1C and 021C6564.
- **func_021C001C itself.** It also calls 021EF948: sdkclass calls it game, but it sits beside libdwcgscommon, so an SDK lane should check it.
- **func_021BEC58** (916 B), then the root 021BDE98.

## Integrator

- The Thumb-to-ARM `bx pc` veneers at 021C54AC and 021C5698 (target 0x0689D5C9) remain open as "game" code. The callers attest them as sole-ref.
- Regenerate the idiom index.

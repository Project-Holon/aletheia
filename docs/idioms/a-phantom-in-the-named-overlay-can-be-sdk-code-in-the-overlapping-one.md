# A phantom in the named overlay can be real SDK code in an overlapping one

summary: when `show --region R` reports a prologue-shaped data word, do not
"fix" it by switching to the overlapping overlay that holds real code at the
same address before checking `layout/symbols_sdk.json`: if that code is an SDK
function the lane is told to ignore, the lane has no work at all and the only
honest output is a phantom report.

Found in: `0x02170EA4` — `ov010` lists it as a phantom `func_02170EA4`
(pointer-table data), while overlapping `ov009` has it interior to the SDK
function `DWCi_ProcessRecvMatchCommand` (0x021702A0, size 4396,
`layout/symbols_sdk.json`).

## The two listings disagree, and both readings are dead ends

Overlays 9 and 10 are both resident at `ram_start 0x02155160` (`layout/
layout.txt`), so `0x02170EA4` has two different contents depending on which
overlay's file is loaded. A lane can name only one region, and the region it
names may be the wrong one.

In the named region, `ov010`, the address is inside a function-pointer table.
Every 4-byte entry is a `0x0216xxxx` code pointer, so the word at the label is
`0x0216B505`, which little-endian reads `05 B5 16 02` — `push {r0, r2, lr}` to
a Thumb decoder:

```
02170EA4  05 b5 16 02 39 b5 16 02 55 bd 16 02 ...
          ^^^^^^^^^^^ = 0x0216B505 -> func_0216B504 (thumb)
```

`disasm.py` saw that `push` and emitted a `.global func_02170EA4`, so
`show --region ov010` reports a Thumb function and follows "branches" through
the table for the rest of the overlay. The test is fan-in, not the prologue:
there is no `bl`/`blx` and no `.word 0x02170EA4` anywhere in `asm/`; the only
mentions are the label's own `.global`/`.type` lines. This is
[a data word that looks like a saved-lr prologue becoming a phantom
function](a-data-word-that-looks-like-a-saved-lr-prologue-becomes-a-phantom-function.md).

The tempting move is to switch to `ov009`, where `show` decodes coherent ARM
and the address sits in the middle of `func_021702A0`, a 4396-byte switch. That
function is real — but `layout/symbols_sdk.json` already names it
`DWCi_ProcessRecvMatchCommand`, `region: ov009`, `thumb: false`, `size: 4396`
(0x021702A0..0x021713CC), and a lane brief that says "ignoring SDK code" does
not license compiling it. Switching regions would trade a phantom for an
out-of-scope symbol.

## The check, in order

1. Run the phantom procedure first (`grep` for the label and for `.word
   0xADDR` image-wide). Zero outside fan-in plus 4-byte table records is
   already conclusive that the named region has no function.
2. Only then ask whether another overlay's window holds the address, and if
   so whether `layout/symbols_sdk.json` covers it. `grep 0xADDR` there, and
   check `address <= addr < address + size`, not just the exact start.
3. If it does, the lane is empty: file nothing, and report the SDK symbol and
   its extent. Do not write C for a phantom, and do not adopt SDK code as
   "the true function the region hint missed".

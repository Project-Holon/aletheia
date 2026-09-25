# A pooled tail-call target needs a `thumb` (and overlay) `symbols:` hint

summary: A `ldr r3,pool; bx r3` tail call to a Thumb function caps at `MATCH`
unless the target is declared with `thumb` in the `symbols:` block; when the
address sits in more than one overlay it also needs the owning `ovNNN` token,
because the bare `func_XXXXXXXX` name is read as ARM otherwise.

Found in: src/matched/ov110_func_021BAD14.c (0x021BAD14), ov112_func_021F51E8.c
(0x021F51E8), ov115_func_021D5B50.c (0x021D5B50).

The shape is a two-instruction tail call whose target lives in a literal pool:

```
ldr r3, [pc, #4]        ; pool word = target | 1   (Thumb)
movs r1, #0             ; or a field load / adds r0, #K
bx r3
```

Writing the obvious C

```c
extern void func_021BFE24(u32);
void func_021BAD14(u8 *p) { func_021BFE24(*(u32 *)(p + 0x5c)); }
```

compiles to the exact instructions and the pool relocation names
`0x021BFE24`, but `match.py one` reports `MATCH`: the relocation site is
wildcarded because the target was inferred **arm, from name** (`func_` with no
`symbols:` entry defaults to ARM) while the original pool word has bit 0 set.
When the address is in more than one overlay window the report adds
`... none resolvable without a region hint on the symbols: line`.

The fix is to declare the target in the file header, ISA and owner explicit:

```
 * symbols:
 *   func_021BFE24  0x021BFE24  thumb  ov110
```

Then the same C verifies `EXACT`. The region token is only needed when the
overlays overlap; without an overlay token the overlay of the file under test
is tried first when its window holds the address, so a target labelled in the
same overlay resolves from `thumb` alone.

Counter-case: `d_` globals follow the same rule (declare the base symbol the
pool word actually names, e.g. `d_021F6EAC`, then index `+8`), otherwise the
compiler folds the offset into the instruction and the pool word differs by a
field size. See src/matched/ov107_func_021F0D1C.c.

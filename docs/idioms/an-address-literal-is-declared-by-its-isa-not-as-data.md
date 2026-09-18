# An address literal that no `literal` witness reaches is attested by declaring it a code symbol

summary: two address words inside a function's own range have no outside witness
as constants, but if either address is a function that already has an EXACT
manifest entry, declaring it `arm` (or `thumb`) in the `symbols:` block turns
the ABS32 into a relocation that resolves through the `matched` class - and
declaring *both* of them as symbols is also what stops the pair folding into one
pool word plus a `sub`.

Found in: `src/matched/func_0203B258.c` (0x0203B258) and
`src/pending/func_0203B038.c` (0x0203B038)

Both functions pass a *code* address from the pool of the function before them
as a callback argument, and the address they pass is not a `func_` label: it is
one of the bare `bx lr` filler words the compiler leaves between functions
(`0x0203B224`, `0x0203B228`, `0x0203B018`). Passing such an address as a plain
integer literal reproduces the right *bytes* and needs no witness at all - that
is what `src/matched/func_0203B22C.c` does - so it is the right spelling when the
function passes exactly one of them.

The trouble starts when a function passes two addresses four bytes apart, as
0x0203B258 passes 0x0203B22C and 0x0203B228:

```c
    func_02037894(1, 0x200, 1, (int)0x203B22C);
    ...
    func_0203AD80(..., (int)0x203B228, 0, 0x205);
```

The compiler folds the pair into one pool word and derives the second address
from the first:

```
    ldr r4, [pc, #0x38]      ; 0x0203B22C
    sub r1, r4, #4           ; 0x0203B228
```

four bytes short of the original's two pool words. Declaring them as external
symbols in the `symbols:` block stops the fold, because two symbol addresses are
not a constant the front end may combine:

```
 * symbols:
 *   unk_0203B228   0x0203B228  arm
 *   unk_0203B22C   0x0203B22C  arm
```

That gets the shape right, but now each site is an ABS32 relocation and needs a
witness outside the range. As constants they had none - `literal` wants the same
word in a pool at a different address, and 0x0203B22C appears in exactly one
pool image-wide, this function's own. The class that saves it is `matched`, and
it only reaches a *code* address when the third column says so: `arm` rather
than `data`. With `data` the report reads

    +0044 ABS32 unk_0203B22C -> unresolved: 0203B22C (data, from header) has no
         witness outside 0203B258..0203B2A8

and with `arm`, the same site resolves `[matched x1, e.g. 0203B22C]` because
`src/matched/func_0203B22C.c` is an EXACT entry in `pkt_0203AD8C.json`. So the
rule of thumb: a filler or callback word in a pool is declared by its ISA, not
as data, whenever a function is labelled at that address; and the ISA column is
what makes the difference between MATCH and EXACT, not the C.

0x0203B038 is the same shape with only one rescue available: its 0x0203B01C
resolves `literal x10`, while 0x0203B018 - a bare `bx lr` no-op with no label
anywhere - stays unresolved in every spelling, which is why that file is parked.
The general form of the fix is the same in both cases: make both addresses
symbols to keep the two pool words, then give each one an evidence class it can
actually reach.

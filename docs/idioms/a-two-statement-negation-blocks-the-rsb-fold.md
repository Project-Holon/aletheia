# A negated sum must be two statements or mwcc folds `-(a + b) + C` into one `rsb #C`

summary: `-(x) + 0x1000` and `0x1000 - (x)` compile to a single
`rsb dst, x, #0x1000`, four bytes and one live register short of the image's
`rsb r1, r1, #0` followed by `add r2, r1, #0x1000`. Split the negation into its
own statement - `n = a + b; n = 0 - n;` - and the image's two instructions come
back, with the whole block's register plan behind them. The same statement
boundary also survives constant propagation only when the negation is written
`0 - n`, so keep that spelling.

Found in: docs/notes/pkt_02070DDC.c.txt (0x02071034, filed EXACT this way)

## The shape

ARM has no "add a negated register with an immediate" instruction, so an
expression like `f2c * (-(f20 + f22) + 0x1000)` has two possible lowerings:

```
image:       add  r1, r2, r1        ; f20 + f22
             rsb  r1, r1, #0        ; -(f20 + f22)     <- own SSA value
             add  r2, r1, #0x1000   ; + 0x1000
             mul  r2, r3, r2
every compile:
             add  r1, r2, r1
             rsb  r2, r1, #0x1000   ; -x + C folded into one rsb
             mul  r2, r3, r2
```

The fold is a source-level reassociation (`-(t) + C` is `C - t` for all
integers mod 2^32), and mwcc applies it across statements: a named local
`s32 n = -(f20 + f22);` used as `n + 0x1000` folds exactly the same way, and so
do `(f20 + f22) * -1 + 0x1000` and `0x1000 - (f20 + f22)`.

## The spelling that reproduces it

```c
n = s->f20 + s->f22;   /* add  r1, r2, r1  */
n = 0 - n;             /* rsb  r1, r1, #0  */
... (n + 0x1000) ...   /* add  r2, r1, #0x1000 */
```

Two statements, and the subtraction written `0 - n` (not `-n`, not `n * -1`).
The result is a full-byte match on a 208-byte function after four earlier
spellings had each landed four bytes short and reallocated everything.

## How to recognise it before burning spellings

* the image has a bare `rsb rX, rY, #0` (`0 - y`) immediately followed by
  `add rZ, rX, #C` - that pair, in that order, is the tell;
* the compile instead shows one `rsb rZ, rY, #C`, or a `sub rZ, rY, #C`;
* the function's size comes out 4 bytes short and every register in the block
  after it is renamed, which is what makes it look like an allocator wall.

Check the negation spelling first: it is cheap, and unlike the true allocator
residues in `a-materialised-shift-temporary-is-not-reachable-from-c-or-from-flags.md`
this one *is* reachable from C.

## Companion rule

Where the negated value feeds a commutative `+` with a shifted term, the
accumulator is the second operand
(`docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md`),
so the `<< 4` product has to be written second to stay the accumulator. Both
facts were needed on the same function; fixing the negation alone still left
the block's registers wrong.

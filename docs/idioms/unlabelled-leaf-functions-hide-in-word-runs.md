# Half the accessors in a file are printed as .word data, not as code

summary: `disasm.py` labels a function only if it opens with a prologue that
saves `lr`, so every leaf accessor that saves nothing lands in the listing as a
run of `.word`s between two literal pools, and a unit that stops at the last
labelled function leaves most of the original file unmatched.

Found in: `src/matched/unit_0200A6F8.c` (fourteen of twenty-one),
`src/matched/unit_0200A3FC.c` (five of nineteen),
`src/matched/unit_0200ADB8.c` (eleven of twenty-five)

The prologue sweep is documented in `docs/MATCHING.md` under "The two missing
labels" as an occasional gap that cost two entries an `EXACT*`. In an accessor
heavy file it is not occasional: it is the majority. A two-instruction getter
has no prologue at all, so nothing in the generated listing distinguishes it
from the literal pool it sits next to:

```
	.org	0x1224
pool_0200A7F4:
	.word	0x0000029E                  /* 0200A7F4 */
	.word	0x5C404901                  /* 0200A7E0 */
	.word	0x46C04770                  /* 0200A7E4 */
	.word	0x0000029E                  /* 0200A7E8 */
```

Three of those four words are `ldr r1, [pc, #4]; ldrb r0, [r0, r1]; bx lr` plus
its own pool word, which is a complete function.

The practical procedure, and it is worth doing before writing a line of C:

1. take the packet's address range, not its function list, as the work;
2. disassemble every `.word` run in it as Thumb and read what comes out.
   `match.target_bytes(lo, hi - lo, region)` plus capstone in Thumb mode is
   about ten lines and is the whole tool;
3. a run that decodes as a chain of two- and three-instruction bodies each
   ending in `bx lr`, separated by `C0 46` padding and four-byte pool words, is
   a run of functions. A run that decodes as nonsense, or whose "instructions"
   never reach a `bx lr`, is a real pool.

`match.py tu` is what makes this safe rather than a guess: it lays the compiled
sections end to end and compares the whole byte range, so an invented function
boundary shows up immediately as a size or padding mismatch, and the section
table it prints gives every function's address to check against the listing.

Two shapes recur often enough to recognise on sight:

* `movs r0, #<n>; lsls r0, #<k>; bx lr` returning a size. Every block file in
  this region opens with one, and the constant it returns is exactly what the
  constructor a few functions later clears. `sizeof(struct X)` reproduces it
  and makes the struct declaration self-checking.
* `bx lr` alone, two bytes, padded to four. That is `void f(void) {}`, a hook
  that was never filled in. 0x0200A640 and 0x0200AE14 are both this.

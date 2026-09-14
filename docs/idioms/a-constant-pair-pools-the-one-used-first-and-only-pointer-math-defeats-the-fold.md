# A near-miss constant pair pools whichever one the code uses first, and only pointer arithmetic keeps the pair apart

summary: two constants a small encodable distance apart cost one pool word plus
an `add`/`sub`; the pooled one is whichever the *machine* code needs first, not
whichever the source spells as the base, and every integer spelling of "base +
delta" folds before the allocator ever sees the pair.

Found in: docs/notes/sub_02034D60.c.txt (0x02034D60)

A range check against a window whose two bounds are both out of ARM immediate
reach costs one literal-pool word for one bound and one immediate `add` or `sub`
for the other:

```
ldr r1, [pc, #0x24]      /* 0x02FE0000 */
add r0, r1, #0x4000      /* 0x02FE4000 */
cmp r2, r0
bhi  out
cmp r2, r1
```

The obvious C, with the lower bound as the named base, does not produce that:

```c
if (addr <= 0x02FE0000 + 0x4000 && addr >= 0x02FE0000) ...
```

compiles to the mirror image, pooling the *upper* bound and deriving the lower
after the branch:

```
ldr r0, [pc, #0x24]      /* 0x02FE4000 */
cmp r1, r0
bhi  out
sub r0, r0, #0x4000
cmp r1, r0
```

Two separate things are going on, and they have to be fixed separately.

The first is that the front end folds `0x02FE0000 + 0x4000` to `0x02FE4000`
before the pool allocator runs, so the two bounds arrive as unrelated integers
and their relationship is rediscovered late. Every integer spelling folds
identically: a `base`/`top` pair of `u32` locals, a separate `span = 0x4000`
local, a `u32` base with the sum cast back. The only spelling that survives the
fold is *pointer* arithmetic, where the offset stays attached to the base:

```c
const unsigned char *lo = (const unsigned char *)0x02FE0000;
if ((const unsigned char *)addr <= lo + 0x4000 &&
    (const unsigned char *)addr >= lo) ...
```

`&lo[0x4000]`, a `struct { u8 lo[0x4000]; u8 end[1]; }` cast over the base, and
a `Win *` whose member array is indexed all work the same way.

The second is that the pooled constant is the one whose *first use* comes
earliest in the emitted code, not the one written as the base. Reordering the
guard to test the lower bound first (`addr >= lo && addr <= lo + 0x4000`) pools
0x02FE0000 correctly and gets the branch senses wrong instead, because this
compiler never reorders the operands of `&&`. So when the original tests the
upper bound first *and* pools the lower, the pointer spelling is the only thing
that gives you both at once.

What is left over after that is the base/derived register assignment, which the
guard's shape does not reach: see the residue section of the note.

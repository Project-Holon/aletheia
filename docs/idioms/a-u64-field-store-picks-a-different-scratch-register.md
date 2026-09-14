# Storing a constant into a `u64` field takes a different scratch register than storing it into a `u32`

summary: `p->f = 0x1130;` compiles to the same `ldr` and `str` whether `f` is
a `u32` or the low half of a `u64`, but not into the same register: the 64 bit
form has to leave the register that already holds zero free for the high half,
so the pool constant lands in r2 where the 32 bit form puts it in r1; two bytes
in an otherwise byte for byte constructor is the whole of the evidence that the
field is 64 bits wide.

Found in: `src/matched/unit_0201C450.c` (0x0201C450)

`printsys.c`'s constructor allocates its object and initialises it. Ten of its
eleven stores are unambiguous. The eleventh is

```
0201C490  ldr  r2, [pc, #0x28]     /* 0x00001130 */
0201C492  strh r4, [r0, #4]
0201C494  str  r2, [r0, #8]
0201C496  str  r5, [r0, #0xc]      /* r5 has held 0 since before the call */
```

and the obvious reading of it is two independent fields,

```c
p->unk08 = 0x1130;
p->unk0C = 0;
```

which reproduces all 112 bytes except that the constant arrives in **r1**:

```
ldr  r1, [pc, #0x28]
strh r4, [r0, #4]
str  r1, [r0, #8]
str  r5, [r0, #0xc]
```

Nothing else in the function moves; the two differing bytes are a register
number in the `ldr` and the same register number in the `str`. It reads like a
scheduling accident and it is not one. Declaring the field as a single 64 bit
value,

```c
u64 unk08;
...
p->unk08 = 0x1130;
```

is `EXACT`. The store of the high half is then part of the same assignment
rather than a separate statement, so the zero in r5 is an operand of the
instruction pair being scheduled instead of an unrelated value, and the
allocator takes r2 for the low half. Sixty-six spellings of the two-`u32`
form, crossing the declaration order, the field types and the statement order,
all produce r1; every spelling of the 64 bit form produces r2.

Two consequences.

**The width of a field is readable from a store that does not depend on it.**
`docs/idioms/long-long-aligns-to-four.md` recovers a `u64` from a *getter*,
where the tell is the move that keeps the object pointer alive across two
loads. This is the setter side, and the tell is one register number in code
that is otherwise identical, which is why it is worth writing down: there is
nothing in the shape of the two `str`s to notice.

**A `u64` field whose halves are also written separately is a union.** The
same object's setter at 0x0201C4DC takes two `u32` parameters and stores them
at +8 and +0xC with no 64 bit arithmetic at all, so the source cannot have
declared a bare `u64`: it is a union of the 64 bit value and a two-word
struct, which costs nothing in the output and is what
`src/matched/unit_0201C450.c` commits.

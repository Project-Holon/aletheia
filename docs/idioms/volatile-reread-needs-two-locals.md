# Two reads of a hardware address are two named locals, and the address is a cast constant

summary: `(X << 8) | X` on a volatile lvalue interleaves the shift between the
two loads and relocates the address as an extern; the original loads twice into
locals and reaches the address through a cast integer constant, which is a
different register allocation and no relocation at all.

Found in: `src/matched/unit_0200A3FC.c` (0x0200A4B8)

The original builds a 16-bit seed out of a system word at 0x02FFFC3C, reading
it twice:

```
ldr r1, =0x02FFFC3C
ldr r0, [r1]
ldr r1, [r1]        /* the second read clobbers the address register */
lsls r0, r0, #8
orrs r0, r1
```

Two things have to be right and each is worth two bytes or more.

**The address is a cast constant, not an extern.** Declaring

```c
extern volatile u32 unk_02FFFC3C;
```

and pinning it in the `symbols:` block gives correct bytes and an `R_ARM_ABS32`
that resolves through the `literal` class, but it puts the address in `r0` and
the first read in `r1`, the mirror image of the original. Writing it as

```c
#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)
```

puts the address in `r1` and the first read in `r0`. Same pool word, no
relocation, and the difference is visible only in the register numbers. A
hardware or system address in this codebase is a cast constant.

**Each read is its own local.** Written as one expression, in either operand
order, the compiler interleaves:

```c
h->unk02 = (u16)((unk_02FFFC3C << 8) | unk_02FFFC3C);
/* ldr; lsls; ldr; orrs  -- the shift between the two loads */
```

The original does both loads and then shifts, which is what two locals give:

```c
a = unk_02FFFC3C;
b = unk_02FFFC3C;
h->unk02 = (u16)((a << 8) | b);
```

That is the whole difference between `DIFF` and `EXACT` for the unit. Note
that the locals are not an optimisation barrier and not redundant: the object
is `volatile`, so the two reads are two distinct values by construction, and
the source has to say which one gets shifted.

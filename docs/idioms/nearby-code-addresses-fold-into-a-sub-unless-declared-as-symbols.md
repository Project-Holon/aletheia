# Two nearby code addresses written as integers fold into one pool word and a `sub`; declare them as symbols

summary: two code addresses a small encodable distance apart cost one pool word plus an `add`/`sub` when they are written as integer literals, because the front end folds them before the allocator sees the pair; the original's two separate pool words only come back when each address is an `extern` function, whose relocation cannot be folded.

Found in: src/matched/func_0203BBB0.c (0x0203BBB0), func_0203B6EC.c (0x0203B6EC)

`func_0203BBB0` compares a stored pointer against 0x0203B950 and then against
0x0203B5D4, and files an entry naming 0x0203B90C and 0x0203B48C.  Written as
plain integers the whole thing comes out four bytes short: the front end keeps
the first constant of each pair in a callee-saved register across the call and
derives the second with `sub r1, r4, #0x44` (`0x0203B950 - 0x0203B90C`) and
`sub r1, r1, #0x148` (`0x0203B5D4 - 0x0203B48C`), which also shifts every
register in the function because the constant now has to survive a call.

```c
/* four bytes short - folded                        */
if (*(u32 *)(g + 8) == 0x0203B950) { ... 0x0203B90C ... }
```

The original spells each address as a function, and an `R_ARM_ABS32` cannot be
folded against another relocation, so each use gets its own pool word and its
own `ldr`:

```c
extern void func_0203B950(void);
extern void func_0203B90C(void);
if (*(u32 *)(g + 8) == (u32)func_0203B950) { ... (u32)func_0203B90C ... }
```

This is the mirror image of
[a-pooled-small-constant-argument-is-a-linker-symbol.md](a-pooled-small-constant-argument-is-a-linker-symbol.md):
there a small number in a pool word said the source passed a symbol, here a
*single* pool word where the original has two says the source passed two
symbols even though both are just 32-bit constants as far as the C is
concerned.  `func_0203B6EC` is the same shape with 0x0203B6B4 and 0x0203B688,
0x2C apart, and it is four bytes short as integers for the same reason.

Two caveats measured on the same function: the folding only bites when the two
addresses are within an encodable `add`/`sub` immediate, and the declaration
has to be a function (or another relocation), not `(u32)0x…` with a cast.

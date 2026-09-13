# A large struct assignment is an inline ldm/stm loop, and its step is the struct's alignment

summary: above the size where the compiler stops unrolling, a struct assignment
becomes an inline counted `ldm`/`stm` loop rather than a call, and whether the
step is eight bytes or one byte depends only on the declared alignment of the
struct.

Found in: `src/matched/unit_0200ADB8.c` (0x0200B1E0)

`docs/idioms/aggregate-assignment-is-ldm-stm.md` covers the small case: up to
about 32 bytes mwccarm unrolls the copy into straight-line `ldm`/`stm` pairs.
Above that it does **not** call a helper. It emits a counted loop, still inline:

```
movs r3, #0x16
lsls r3, r3, #4      /* 0x160, the struct size */
muls r3, r1, r3
adds r4, r0, r3
movs r3, #0x2c       /* 0x160 / 8 iterations */
.loop:
ldm  r2!, {r0, r1}
stm  r4!, {r0, r1}
subs r3, r3, #1
bne  .loop
```

That is `arr[index] = *src;` on a 0x160-byte struct, and the iteration count is
the size divided by eight.

The trap is the alignment. Declared the natural way for an opaque record,

```c
struct Rec160 { u8 unk000[0x160]; };
```

the struct is one-aligned, the compiler cannot use `ldm`/`stm`, and the same
assignment becomes a `ldrb`/`strb` loop of 0x160 iterations: same shape, same
instruction count, completely different bytes. Declaring it

```c
struct Rec160 { u32 unk000[0x58]; };
```

is four-aligned and gives the register loop above. Nothing else in the file
changes and no accessor cares, because the padding bytes are the same either
way; only this one copy tells them apart.

So an inline eight-byte copy loop is evidence about the *type* the source used,
not just about the size: somewhere in the declaration of that struct there is a
member of at least four-byte alignment. The byte loop is equally good evidence
of the opposite.

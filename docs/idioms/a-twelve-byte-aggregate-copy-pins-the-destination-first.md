# A 12-byte aggregate copy pins the destination pointer and keeps the source in r2

summary: writing a `u64` block plus the following `u32` as one
`struct { u64; u32; }` assignment makes mwcc compute the destination address
first and leave the source pointer in r2; splitting it into two stores makes
the allocator evaluate the source first and move the source into a callee-saved
register, losing the whole byte range.

Found in: `src/matched/ov010_func_02167848.c` (0x02167848)

The original leaf is eight Thumb instructions of address setup followed by a
block copy and two scalar stores:

```
movs r3, #0x1c
muls r3, r1, r3
adds r3, r0, r3      ; dst = a0 + a1*0x1c
adds r5, r2, #4      ; src + 4
adds r4, r3, #0
ldm r5!, {r0, r1}
adds r4, #8
stm r4!, {r0, r1}    ; *(u64*)(dst+8) = *(u64*)(src+4)
ldr r0, [r5]
str r0, [r4]         ; *(u32*)(dst+0x10) = *(u32*)(src+0xC)
```

The C that reproduces it is a *single* aggregate assignment over the first
twelve bytes of the source record:

```c
typedef struct { u64 lo; u32 hi; } Blk12;

char *d = a0 + a1 * 0x1C;
*(Blk12 *)(d + 8) = *(Blk12 *)(a2 + 4);
*(u16 *)(d + 0x18) = *(u16 *)(a2 + 0x10);
*(u32 *)(d + 0x14) = *(u32 *)(a2 + 0);
```

The `Blk12` assignment emits `ldm r5!`/`stm r4!` for the 8-byte half and the
following `ldr`/`str` for the `hi` word through the already-advanced pointers,
exactly as the original. Crucially it also drags the destination address into
r3 before the source is touched, which is what keeps `a2` in r2.

Every variant that separates the two stores fails the same way. A `u64` store,
a `u32` store, an explicit `char *dst` local, a `u32`-indexed source, matching
`Src`/`Dst` structs, and even an `off = a1 * 0x1C` local all produce:

```
push {r3, r4}
adds r4, r2, #0      ; source moved to a callee-saved register FIRST
movs r2, #0x1c
muls r2, r1, r2
adds r1, r4, #4
adds r0, r0, r2
ldm r1!, {r2, r3}
adds r1, r0, #0
adds r1, #8
stm r1!, {r2, r3}
```

`a2` is live to the last store either way, so the difference is not the live
range but how the two adjacent sources are grouped: with a single aggregate the
front end materialises the destination first and has a spare low register for
the source, while two scalar sources let it schedule the source preadress ahead
of the destination. When a 12-byte copy sits at a fixed `u64 + u32` boundary,
try the aggregate spelling before touching the index or declaring pointers.

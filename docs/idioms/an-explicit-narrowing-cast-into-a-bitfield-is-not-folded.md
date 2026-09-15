# An explicit narrowing cast into a bitfield survives; a narrow parameter type does not

summary: a `lsl #16 / lsr #16` pair in front of a bitfield insert whose mask is
narrower than 16 bits is an explicit `(u16)` in the source, not a `u16`
parameter; declaring the parameter `u16` instead makes the compiler drop the
pair, because the insert's own mask already covers it.

Found in: `src/matched/func_020371D8.c` (0x020371D8)

## The shape

0x020371D8 is a one-line setter for a two-bit field at the top of a halfword:

```
ldr  r1, [pc, #0x1c]        ; &g_021469C8
lsl  r0, r0, #0x10          ; <- the pair that is the whole finding
ldrh r2, [r1, #2]
lsr  r0, r0, #0x10
lsl  r0, r0, #0x1e
bic  r2, r2, #0xc000
orr  r0, r2, r0, lsr #16
strh r0, [r1, #2]
```

`lsl #0x1e` plus the `lsr #16` shifter operand on the `orr`, against a `bic`
of the field's own mask, is the ordinary bitfield insert for

```c
struct Notifier {
    u16 unk00;
    u16 unk02 : 14;
    u16 mode  : 2;      /* bits 14-15, which the 0xc000 names */
    void *handler;
};
```

The question is only the `lsl #0x10 / lsr #0x10` above it. It is arithmetically
dead: the insert masks the value down to two bits anyway, so truncating to 16
first cannot change the result.

## What produces it

```c
void func_020371D8(u32 mode)
{
    g_021469C8.mode = (u16)mode;      /* EXACT */
}
```

and what does not:

```c
void func_020371D8(u16 mode)
{
    g_021469C8.mode = mode;           /* DIFF, 32 bytes against 40 */
}
```

The `u16` parameter version emits no narrowing at all: mwccarm knows the value
is about to be masked to two bits and that the parameter arrives in a register,
so it goes straight to `lsl r0, r0, #0x1e`. The explicit cast, by contrast, is
an operation in the tree that the front end materialises before it ever reaches
the insert, and the optimiser never revisits it.

## Why it matters beyond this function

The same pair, in the same place, is the tell for "the source casts" anywhere a
value reaches a narrow bitfield or a `strb`/`strh`: a redundant truncation in
front of a masking consumer is *evidence of a cast in the source*, not noise to
be explained away. Conversely, if the original has no such pair, do not reach
for a cast to fix an unrelated diff.

Note the direction is specific to a value that is already in a register. When
the value lives in a stack parameter slot, the cast is materialised off the
cached register as `lsls/lsrs` rather than as a narrow reload, which is a
different (and usually wrong) shape; see `docs/notes/func_0201F93C.c.txt` for a
case where reaching for this cast made the diff worse.

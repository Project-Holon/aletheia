# A narrow parameter pins its home store to the front of the prologue

summary: a narrow parameter can move its home store before the other parameter copies; confirm the width from body and call-site narrowing, and preserve live full-word forwarding.

**Summary:** a spilled parameter's home store before the callee-saved register
copies can suggest a narrow type (`u8`/`u16`). Store order alone does not prove
the width; original body and call-site behavior must permit the narrowing.

## The diff

`func_0201DA24` (gf_font.c, 0x0201DA24, 128 bytes) came out nine concrete bytes
wrong with everything else in the function already right. The whole residue was
one store sliding across four instructions:

```
original                     compiled with u32 heap
adds r5, r0, #0              adds r5, r0, #0
str  r3, [sp, #4]    <-      adds r7, r1, #0
adds r7, r1, #0              ldr  r0, [r5, #0x50]
ldr  r0, [r5, #0x50]         ldr  r1, [r5, #0x54]
ldr  r1, [r5, #0x54]         adds r4, r2, #0
adds r4, r2, #0              str  r3, [sp, #4]    <-
```

The fix is one token in the signature:

```c
void func_0201DA24(struct Font *f, u32 a, u32 b, u8 heap)   /* not u32 heap */
```

## Why

mwccarm gives a parameter that needs a stack home an ordinary store, and it is
free to schedule that store anywhere in the prologue that r3 is still live.

- With `u32 heap`, the value in r3 on entry **is** the value the home slot must
  hold. The store is pure bookkeeping, nothing depends on it, so the scheduler
  sinks it to the end of the register shuffle and the prologue comes out in
  *declaration* order.
- With `u8 heap`, the home slot holds the **narrowed** value, which is not what
  r3 holds. The store now participates in the conversion and has to be emitted
  before anything can clobber r3, which puts it at the front — and the prologue
  comes out in *first-use* order.

Home-store order suggests a width only when body and call-site narrowing
permit it; preserve live full-word forwarding. In `func_0201DA24`
the original's order is first-use order (the heap id feeds the allocator call
immediately; `a` and `b` are read only at the very end), and that is exactly
what the narrow parameter produces.

## How to spot it

Read the prologue's order against the order the parameters are first *used* in
the body:

- home store **last**, prologue in declaration order → investigate a
  register-width parameter.
- home store **first**, prologue in first-use order → investigate `u8` or
  `u16`, checking every live use before changing the signature.

The instruction multiset is identical either way, so this never shows up as a
size difference — only as a handful of bytes in the prologue, which is easy to
misread as an allocation tie.

## What it is not

This does **not** generalise to an *outgoing* stack argument. The mirror-image
residue in `func_0201DBBC` and `func_0201DBF4`
(`docs/notes/sub_0201DBBC.c.txt`), where the original stores its fifth argument
*later* than mwcc does, is unaffected by the types of the caller's own
parameters: narrowing each of them in turn was tried and changes nothing. An
outgoing argument's store time is a property of the call-setup schedule, not of
the caller's signature. The two look like one heuristic seen from both sides
and are in fact two different ones.

## Finding it mechanically

The canonical big-lane procedure permits one `tools/permuter.py --types`
pass with budget 300. Type changes are not value-preserving automatically;
inspect each winner against the original live uses before adopting it. The
historical font example closed at candidate 205 with `heap:u32->u8`.

Note that `--explain` printed an **empty** register-substitution map on the
baseline. That correctly said the residue was not an allocation tie — but it is
not a reason to stop, because this lever is a type change and not a register
one. An empty map plus a small bytes-out count is a cue to consider the
canonical once-only `--types` pass if its budget remains available.

## Evidence

`src/matched/sub_0201DA24.c` (EXACT, 128 bytes, 9 of 9 relocations resolved).
Full before/after in `docs/notes/sub_0201DA24.c.txt`.

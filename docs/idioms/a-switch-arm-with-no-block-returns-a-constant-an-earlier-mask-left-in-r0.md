# A switch arm with no block of its own returns a constant an earlier mask left in r0

summary: a jump-table entry that lands on another arm's bare `bx lr` is a real
arm whose return value equals a mask or bound the function already had live in
r0, CSE'd rather than rematerialised; and two arms returning the same constant
are two blocks, while stacked case labels over one `return` are one.

Found in: `src/matched/func_021AB504.c` (0x021AB504)

## The shape

A dense `switch` compiles to the usual PC-relative halfword table, and every
arm has its own two-instruction block (`movs r0, #k` / `bx lr`) sitting in the
run after the table. One arm does not: its table entry points at the bare
`bx lr` of the *previous* arm, skipping that arm's `movs`.

`func_021AB504` (ov021, `0x021AB504`):

```
021AB516  movs r0, #4          <- the flag mask, materialised before the switch
021AB518  tst  r2, r0
...
021AB53A  .hword 0x0040 0x0040 0x0040 0x0040 0x0028 0x002c 0x0040 0x0040
021AB54A  .hword 0x0034 0x0040 0x0036
...
021AB570  movs r0, #3
021AB572  bx lr                <- case 10's table entry (0x36) lands HERE
```

Case 10's entry is `0x0036`, which resolves to `0x021AB572`, the `bx lr` of the
`case 8: return 3;` arm. Nothing sets `r0` on that path after the switch
dispatch, so the value returned is whatever `r0` still holds: the `4` written
at `0x021AB516` for the `flags & 4` test, which the dispatch sequence
(`adds r2, r1, r1` / `add r2, pc` / `ldrh` / `lsls` / `asrs` / `add pc, r2`)
never touches.

## What it means for the C

`case 10: return 4;` is a real, ordinary arm. Do not read the missing block as
a fall-through, an empty arm, or a shared tail: the constant is CSE'd out of
the mask the function already had live, and writing the arm normally is what
reproduces it. mwcc does this on its own; the only thing the source has to get
right is that the returned constant and the mask constant are the *same value*.

The tell that you have this and not something else: the arm count in the
table exceeds the number of `movs r0, #k` blocks by exactly one, and the
orphaned target is an `bx lr` whose preceding `movs` writes a different
constant from the one the arm should return.

## What it cost

Written with the arm spelled out, mwcc emits its own `movs r0, #4` / `bx lr`
pair and the function runs four bytes long, which reads as a `SIZE`-adjacent
`DIFF` in which every table displacement after the insertion point is off by
four. The instinct is to hunt for a missing case label; there is none. Check
whether one of the returned constants equals a mask or bound the function
already computed before you touch the case list.

In the same function a second four-byte overrun came from writing

```c
case 0x3f:
    return 6;
case 0x43:
    return 6;
```

as two arms; mwcc emits two `movs r0, #6` blocks for that and tail-merges
nothing. The original has one block reached from two table entries, i.e.

```c
case 0x3f:
case 0x43:
    return 6;
```

Two arms returning the same constant are two blocks; stacked labels over one
`return` are one block. The two effects stack, so the function came out eight
bytes long before both were fixed.

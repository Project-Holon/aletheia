# An ARM guard block of five instructions or fewer is always predicated

summary: at `-O4,p` this compiler predicates the body of an `if` guard in ARM
code whenever the body is five instructions or fewer, and only emits `bxne lr`
at six; an original that spells a short guard as an early `bx<cond> lr` is
therefore unreachable from any plain C spelling of the same guard.

Found in: docs/notes/g2d_srt_setters.c.txt (0x020640DC, 0x02064100, 0x02064120)

The original, the NNS G2D per-node SRT translate setter:

```
020640DC  ldr  r3, [r0]
020640E0  cmp  r3, #1
020640E4  bxne lr
020640E8  ldrh r3, [r0, #0x12]
020640EC  orr  r3, r3, #8
020640F0  strh r3, [r0, #0x12]
020640F4  strh r1, [r0, #0xc]
020640F8  strh r2, [r0, #0xe]
020640FC  bx   lr
```

The C that says exactly this:

```c
void func_020640DC(volatile struct Srt *p, s16 x, s16 y)
{
    if (p->mode != 1) return;
    p->dirty |= 8;
    p->tx = x;
    p->ty = y;
}
```

produces the same eight-instruction body with the guard folded into the
instructions instead of the branch, four bytes shorter:

```
ldr r3, [r0] / cmp r3, #1 / ldrheq r3, [r0, #0x12] / orreq r3, r3, #8 /
strheq r3, [r0, #0x12] / strheq r1, [r0, #0xc] / strheq r2, [r0, #0xe] / bx lr
```

The threshold is exactly five and was measured, not guessed: adding a sixth
store to the same block flips the output to `bxne lr` plus an unpredicated
body. Inverting the guard (`if (p->mode == 1) { ... }`), routing the early
exit through an explicit `goto`, hoisting the tested field into a local, and
spelling the compound assignment out all give the same predicated form.

Two consequences worth remembering:

- A short `bx<cond> lr` in the original is not a cue to keep rewriting the
  guard. It is a signal that the byte range will not close from plain C at
  the pinned flags, and belongs in `docs/notes/` as a measured near miss.
- `volatile` on the struct pointer is still worth trying even when it cannot
  close the range, because it is what stops the compiler rescheduling the
  guarded stores. In the case above it turns a five-instruction reordering
  difference into a single missing `bxne lr`, which is what makes the near
  miss legible at all.

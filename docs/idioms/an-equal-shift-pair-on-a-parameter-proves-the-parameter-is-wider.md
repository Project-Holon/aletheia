# An equal shift pair applied to a parameter proves the parameter is declared wider than the cast

summary: a cast to `u16` on something already declared `u16` folds away to
nothing, so a live `lsls #16` / `lsrs #16` on an argument register is positive
evidence that the parameter's declared type is `u32` (or `int`) and the source
wrote the narrowing itself; declaring the parameter `u16` costs four bytes and
a `SIZE` verdict.

Found in: `src/matched/sub_0201407C.c` (0x0201407C)

`shift-pair-with-no-matching-type-is-a-bitfield.md` reads an equal-amount pair
as a width. That rule says what the width is, but not where the cast came
from, and for a pair sitting on an incoming argument register the answer is
load bearing.

`sub_0201407C` narrows twice in a row:

```
lsls r0, r4, #0x10          /* r4 is the third argument         */
lsrs r0, r0, #0x10
adds r0, r5, r0             /* r5 is the second argument        */
lsls r0, r0, #0x10
lsrs r5, r0, #0x10
```

The second pair is the obvious one: the sum is stored back into a `u16`, so it
truncates. The first pair is the interesting one. Written with a `u16`
parameter:

```c
void *sub_0201407C(u32 heap, u16 index, u16 delta)   /* wrong */
{
    record = (u16)(index + (u16)delta);
```

the `(u16)` on `delta` is a cast of a `u16` to `u16`. The compiler proves it is
a no-op and deletes it, and the function comes out four bytes short: the
`adds` reads `r4` directly and only the outer pair survives. There is no way
to get the inner pair back by rearranging the expression, because nothing in
the source is asking for a truncation that the declared type has not already
performed.

Widening the parameter is what restores it:

```c
void *sub_0201407C(u32 heap, u16 index, u32 delta)   /* right */
```

Now `(u16)delta` genuinely discards the top half and the shift pair is
emitted. Note that this is asymmetric: `index` stays `u16`, because its own
truncation happens implicitly at the assignment into the `u16` result and
would be a no-op if written out as well.

The general form: each equal-amount shift pair in the bytes has to correspond
to exactly one narrowing that is not already implied by a declared type. Count
the pairs, then widen parameters until the counts agree. Getting it wrong is a
`SIZE` verdict rather than a `DIFF`, which makes it easy to mistake for a
missing statement rather than a wrong declaration.

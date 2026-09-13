# A const struct pointer is what lets one field load serve three out-parameters

summary: a getter that fills several `u32 *` out-parameters reloads the struct
field before every store unless the struct pointer is `const`, because a store
through an unrelated pointer may alias it; adding the qualifier removes the
reloads and is worth twelve bytes with nothing else changed.

Found in: `src/matched/unit_0200C0E8.c` (0x0200C164)

`func_0200C164` unpacks one packed byte into four out-parameters:

```
push {r3, r4}
ldrh r4, [r0, #8]
str  r4, [r1]
ldrb r1, [r0, #0xa]      /* loaded once, and used three times */
lsls r0, r1, #0x1a
lsrs r0, r0, #0x1a
str  r0, [r2]
lsls r0, r1, #0x19
lsrs r0, r0, #0x1f
str  r0, [r3]
lsls r0, r1, #0x18
lsrs r1, r0, #0x1f
ldr  r0, [sp, #8]
str  r1, [r0]
pop  {r3, r4}
bx   lr
```

Written the obvious way over a non-const pointer, every instruction is right
and there are two extra `ldrb`s:

```c
void func_0200C164(struct Blk34 *p, u32 *a, u32 *b, u32 *c, u32 *d)
{
    *a = p->unk08;
    *b = p->unk0A.f0;     /* ldrb; shift pair; str */
    *c = p->unk0A.f6;     /* ldrb again */
    *d = p->unk0A.f7;     /* ldrb again */
}
```

The reloads are correct code: `*b = ...` writes four bytes through a `u32 *`
the compiler knows nothing about, and that store is allowed to overlap the
byte at +0x0A, so the value has to be read again. Qualifying the parameter is
what tells it otherwise:

```c
void func_0200C164(const struct Blk34 *p, u32 *a, u32 *b, u32 *c, u32 *d)
```

and the function is EXACT with no other change. Nothing else in the file needs
the qualifier, because no other function both reads a field twice and stores
through a pointer in between.

Two spellings that look like they should work and do not, so that nobody
re-derives them:

* hoisting the three reads into locals before the three stores does produce
  one `ldrb`, but it also drags all three shift pairs above the stores, which
  is a different instruction order and twelve bytes wrong. The original
  interleaves shift, store, shift, store, and only the const pointer gives
  both properties at once;
* copying the bitfield container into a one-byte local struct gives one load
  and spills the local to the stack (`add r1, sp, #0` / `strb`), which is four
  bytes the original does not have.

The reverse reading is the useful one. A getter whose loads are *not* CSEd
across its own stores is evidence that its pointer argument was **not** const
in the original, and a getter whose loads are CSEd is evidence that it was.
That is a real statement about the source's prototypes, recoverable from the
bytes, and it is the only place the qualifier is visible at all: on a function
that reads a field once, `const` changes nothing.

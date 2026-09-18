# A local declared at its first use schedules its store there, and a nested block is the only spelling

summary: moving a local's declaration down to where it is first used moves its
initialising store there too, which reorders everything else in the function;
this front end rejects the mixed declaration (`expression syntax error`, even
at `-lang c99`), so the declaration has to go into a nested block instead.

Found in: `src/matched/func_0206A884.c` (0x0206A884).

The function is four calls to the same registrar and then a read-modify-write of
a flags word.  The third call passes the *address* of a one-word local, so the
local has to exist as storage:

```c
void func_0206A884(void)
{
    int v = 2;                                   /* declared at the top */

    func_0206DDA4(0x1610, g_02148B50, 0x11);
    func_0206DDA4(0x19, g_02148B98, 0xC);
    func_0206DDA4(0x10, &v, 1);
    func_0206DDA4(0x15, g_02148BC8, 0x20);
    g_02148B4C[63] = (g_02148B4C[63] & ~1u) | 2;
}
```

That compiles to 120 bytes with the initialisation at the *front*:

```
push {r3, lr}
ldr  r0, [pc, #0x58]      <- the 0x1610 pool word
mov  r3, #2
ldr  r1, [pc, #0x54]
mov  r2, #0x11
str  r3, [sp]             <- v = 2, before the first call
bl   func_0206DDA4
```

The original has `mov r3, #2` and `str r3, [sp]` between the second and the
third call, i.e. the source declared `v` where it first needed it.  Because a
declaration may not follow a statement in the same block - this front end
reports `expression syntax error` at `-lang c99`, not a warning - the only
spelling that puts the store there is a nested block:

```c
    func_0206DDA4(0x1610, g_02148B50, 0x11);
    func_0206DDA4(0x19, g_02148B98, 0xC);
    {
        int v = 2;
        func_0206DDA4(0x10, &v, 1);
    }
    func_0206DDA4(0x15, g_02148BC8, 0x20);
```

which is EXACT.  The frame is identical either way (the local has the same
stack slot and the same `push {r3, lr}`); the only thing that changed is where
the store lands in the schedule, and with it the whole 120-byte block.

Two consequences worth remembering:

- A `mov`/`str` pair that initialises a stack word in the *middle* of a
  function is not evidence of an aggregate or of a spilled temporary; it is
  evidence that the declaration is at that point in the source.  Declaring
  everything at the top of the function costs bytes and is the commonest way a
  four-call wrapper comes out four to eight bytes long.
- `-lang c99` on this front end does **not** mean C99 declarations.  A
  declaration after a statement in the same block is a hard error, so the
  spelling is a fresh `{ ... }` block, which the allocator treats as an
  ordinary scope.

# A global re-read across a call to a same-file static needs `volatile`

summary: when the intervening call is to a `static` function defined in the
same translation unit, this compiler can see that the callee never writes the
global and keeps the first load live across the call; the original reloads it,
which only reproduces by declaring the global `volatile`.

Found in: `src/matched/unit_020271F8.c` (0x020271F8)

Six checker functions in this unit each compute `g_System + 4` (the event
queue object), pass it to a trampoline, then compute `g_System + 4` again to
pass to the dispatcher:

```c
void *queue = (char *)g_System + 4;
sub_02027220(queue, value);
queue = (char *)g_System + 4;
sub_02026FB8(queue);
```

`sub_02026FB8` is an unresolved extern here, so nothing says it cannot touch
`g_System`, and the second load survives untouched. `sub_02027220` is
different: it is `static` and defined earlier in the same file, so the
compiler can inline-analyse its body, sees that it only writes through the
`dst` pointer it was already given, and concludes the reload is redundant.
With a plain

```c
extern void * const g_System;
```

the compiled second load is folded into the register the first one left
behind (`adds r0, r5, #4` instead of a fresh `ldr r0, [r5]`), 13 concrete
bytes wrong. Marking the declaration

```c
extern void * const volatile g_System;
```

is what forces the second load to happen at all, matching the original's
`ldr r0, [r5]` after the call. The `const` half is not defeated by this: the
qualifiers compose, and the object is still never written through this
translation unit's own code, only reread as if something else might write it,
which is exactly what letting a real static callee stay opaque should have
cost.

The general shape: any global reread that survives across a call whose target
is a `static` function visible in the same file is at risk of being optimised
away, in a way that a call to a genuine extern is not. `volatile` is the fix
precisely because the field really is meant to be treated as unknown to the
caller, and the qualifier says so instead of the callee's invisibility saying
so by accident.

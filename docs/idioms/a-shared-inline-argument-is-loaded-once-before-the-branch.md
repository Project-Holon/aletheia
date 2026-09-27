# An argument spelled identically in both arms of an if/else is loaded once, before the branch

summary: when both arms of an `if`/`else` call the same function with the same
expression for one argument, the compiler hoists that expression's load above
the branch and branches first, unlike an unequal-expression pair where the load
stays in its own arm.

Found in: `src/matched/func_021BC520.c` (0x021BC520)

The function is

```
0207D658(addr, p[0], p[1], p[2], 0, p[2] - 0x10)
```

with `addr` chosen by a flag. The original emits `cmp flag, #0` *first*, then
`ldr r3, [p, #8]` (the `p[2]` read), then `bne` to the else arm:

```
0000  push {r3, lr}
0002  sub  sp, #8
0004  adds r2, r1, #0
0006  cmp  r0, #0
0008  ldr  r3, [r2, #8]
000A  bne  loc_else
...
```

The natural reading, binding the common argument to a local before the branch,

```c
int v = p[2];
if (flag == 0) { f(0x04000050, p[0], p[1], p[2], 0, v - 0x10); }
else           { f(0x04001050, p[0], p[1], p[2], 0, v - 0x10); }
```

puts the `ldr` *before* the `cmp`, because the local is live from its
declaration. Removing the local and spelling `p[2]` inline in both arms makes
the compiler schedule the compare first and the shared load after it, exactly
as the original does. Both arms must spell the *same* expression; an arm that
reads a different offset keeps its own load and the hoist does not happen.

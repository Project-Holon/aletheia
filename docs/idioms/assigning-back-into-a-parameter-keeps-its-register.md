# Assigning back into a parameter keeps that parameter's register, a fresh local takes the next one

summary: when a function overwrites one of its own arguments with a later value,
the value inherits the register the argument was living in; spelling the same
thing as a new local shifts that value, and often the whole tail of the
function, one register along.

Found in: docs/notes/sub_02034D60.c.txt (0x02034D60)

sub_02034D60 passes its `id` argument to FS_LoadOverlayInfo, then classifies the
load address that comes back in the out-struct:

```
mov r2, r0            /* id, into the third argument register */
add r0, sp, #0
mov r1, #0
bl  FS_LoadOverlayInfo
ldr r2, [sp, #4]      /* the load address, back into r2 */
cmp r2, #0x2000000
```

The natural C, reading the field into a fresh local, puts it in r1 instead and
shifts every compare that follows:

```c
u32 addr;
addr = info.ram_address;      /* ldr r1, [sp, #4] */
```

Writing it back into the parameter reproduces the original exactly:

```c
id = info.ram_address;        /* ldr r2, [sp, #4] */
```

The parameter's own register is the one the compiler reaches for, because from
its point of view the same variable is simply being reassigned; a new local is a
new live range and gets the next free register. It is worth checking whenever a
function's post-call scratch value sits in an argument register that has no
business still being live: the C almost certainly reuses the argument rather
than naming something new. The same reading applies in reverse, a value in a
register no argument ever touched is evidence the source did declare a fresh
local.

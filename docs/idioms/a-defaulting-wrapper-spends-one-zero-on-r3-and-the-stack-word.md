# A defaulting wrapper spends one zero on both r3 and the stack word


summary: a five-argument callee reached through a shorter entry point compiles
to `push {r3, lr}` plus a single `mov r3, #0` that serves as both the fourth
argument and the one outgoing stack word, so the push is the stack argument's
home slot rather than a saved register; the same push followed by
`ldr ip, [sp, #8]` is always a plain five-argument forwarder.

Found in: `src/matched/func_02048F4C.c`, `src/matched/func_02048F60.c`,
`src/matched/func_02048F74.c`, `src/matched/func_02048F88.c`

## The shape

A five-argument callee reached through a three-argument entry point compiles
to five instructions, not six:

```
02048F60  push {r3, lr}
02048F64  mov  r3, #0
02048F68  str  r3, [sp]
02048F6C  bl   #0x2048d54
02048F70  pop  {r3, pc}
```

`push {r3, lr}` looks like a saved register plus the link register. It is not:
r3 is dead here, and the push exists only to open the one word of outgoing
stack area the fifth argument needs, with lr paying for the 8-byte alignment.
The single `mov r3, #0` then serves twice, as the fourth argument in its
register and as the fifth argument in the slot the push just made.

## Why it matters when writing the C

The wrapper is one statement:

```c
void *func_02048F60(u32 archive_id, u32 member, u32 heap)
{
    return func_02048D54(archive_id, member, heap, 0, 0);
}
```

Both trailing zeros must be literal constants of the same type. Spelling
either as a local, or giving one of them a different type (`NULL` against a
non-pointer parameter, say), splits the zero into two materialisations and
costs two extra bytes. Writing four arguments instead of five loses the
`str` and the `push` together, and the function comes out 12 bytes instead
of 20, which reads as a completely different function rather than a near
miss.

## The neighbouring five-argument form

The same file's next entry point forwards all five arguments:

```
02048F74  push {r3, lr}
02048F78  ldr  ip, [sp, #8]
02048F7C  str  ip, [sp]
02048F80  bl   #0x2048d00
02048F84  pop  {r3, pc}
```

`ldr ip, [sp, #8]` reaching across the two words just pushed is the tell:
the caller's own stack argument is being copied down into the callee's
outgoing area. A `push {r3, lr}` followed by a load at `[sp, #8]` is
therefore always a plain forwarder with one stack argument, never a function
that does work of its own.

## Seen at

`func_02048F4C`, `func_02048F60`, `func_02048F74` and `func_02048F88`, the
four entry points of the arm9 archive reader (`src/matched/`).

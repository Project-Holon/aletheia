# Identical loads written out in both arms are CSE'd and hoisted above the branch

summary: writing the same `*(int *)(a0 + k)` load inline in both arms of an
`if`/`else` lets mwcc common-subexpression-eliminate the pair into one load,
which the scheduler is then free to hoist between the compare and the branch;
binding the load to a local first makes the compiler sink it below the branch,
four bytes and a reordering apart.

Found in: src/matched/ov112_func_021F5424.c (0x021F5424)

The original is a two-arm dispatch on one parameter whose call argument is the
same field load in both arms:

```
021F5424  push {r3, lr}
021F5426  cmp  r1, #1
021F5428  ldr  r0, [r0, #8]      ; the single hoisted load
021F542A  bne  #0x21f5432
021F542C  bl   #0x21f626c
021F5430  pop  {r3, pc}
021F5432  bl   #0x21f6280
021F5436  pop  {r3, pc}
```

The C that produces it writes the load at each use:

```c
void func_021F5424(int a0, int a1)
{
    if (a1 == 1)
        func_021F626C(*(int *)(a0 + 8));
    else
        func_021F6280(*(int *)(a0 + 8));
}
```

The plausible rewrite

```c
    int v = *(int *)(a0 + 8);
    if (a1 == 1) func_021F626C(v); else func_021F6280(v);
```

compiles to `push`; `ldr`; `cmp`; `bne` — the load is scheduled *before* the
compare instead of between the compare and the branch — and it is four bytes
shorter because the shared value is folded differently.  The duplicated-load
spelling is the one that reaches the image: mwcc sees the two identical loads,
CSEs them, and the shared node lands in the cmp/branch gap the original has.
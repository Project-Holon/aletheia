# An early return reached by branch, not by predication, is a `goto`

summary: in ARM code a guarded `return K;` is normally predicated inline
(`movhs r0, #0` / `pophs`); when the original branches to a separate
`mov r0, K` / `pop` block at the bottom instead, the source wrote `goto`.

Found in: src/matched/sub_02030428.c (0x02030428), and the same fix in
0x02030098, 0x02030344, 0x0203046C and 0x020302A4.

This compiler will happily predicate a short early return in ARM mode. Given

```c
    if (heapId >= g_EnvModule.count) {
        g_EnvModule.error = 1;
        return 0;
    }
    g_EnvModule.error = 0;
    return sub_0202FBAC(heapId);
```

it emits the guard's whole body under the condition code and never branches:

```
    cmp   r0, r3
    movhs r0, #1
    strhhs r0, [r2, #0xe]
    movhs r0, #0
    pophs {r3, pc}
```

The original instead branches away and keeps a one-instruction exit block at
the end of the function:

```
    movhs r0, #1
    strhhs r0, [r2, #0xe]
    bhs   #0x203045c
    ...
    pop   {r3, pc}
0x203045c:
    mov   r0, #0
    pop   {r3, pc}
```

That shape is a `goto`, and only a `goto` reproduces it:

```c
    if (heapId >= g_EnvModule.count) {
        g_EnvModule.error = 1;
        goto fail;
    }
    g_EnvModule.error = 0;
    return sub_0202FBAC(heapId);

fail:
    return 0;
```

The existing note
`guards-separated-by-statements-share-an-exit-only-through-goto.md` describes
the two-guard case, where the shared exit is what gives the game away. The
single-guard case looks nothing like a shared exit, which is exactly why it is
easy to miss: there is only one early return, so the natural C is a plain
`return`, and the resulting diff is not a wrong instruction anywhere but a
two-instruction shift of everything after the guard. In a 204-byte function
(0x02030098) that reads as 118 concrete bytes differing, which looks far worse
than the one-word change it actually is.

The tell to look for before writing the C: an exit block after the function's
main `pop`, reached only by conditional branches. Every such block is a label,
not a `return`.

The inverse case is real too and appears in 0x020303D8, where one failure path
branches to the shared block and the other falls into it because the success
tail is fully predicated. There the success case must be written as
`if (ok) { ...; return v; }` falling through to the label, not as a second
`goto`-style guard, or the predication is lost.

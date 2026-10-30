# A value in r3 at a failure call is its printf argument

summary: when a variable of a long function takes r3 in the image and no source form moves it
there, look at the failure call at the end. If its message is a format string (`%d`), the
variable is the fourth argument: the allocator coalesces it with the argument register r3, and
since it is already in r3 no move is emitted.

Found in: src/game/ov019/union_msg.c UNION_MSG_SelectSubMenu (black_ja 0x0217F498).

The Japanese image kept the menu key in r3 for the whole function; our build gave it r1, and the
table pointer and jump-table temporaries rotated with it. `mwccdbg regalloc-replay` showed that
r3 needs the key coloured after its neighbours, and no change of declaration order, block local,
type, copy or added live range gave that (a graph search over added and removed interference
edges found no form either).

The message of the failure call at the end, str_ja_021809CC, is `"menu_ret=%d\n"`. The call
that matches:

```c
#if LANGUAGE == LANGUAGE_JAPANESE
    GF_PANIC_FailPrintf(str_ja_021808FC, 0x6CC, str_ja_021809CC, key);
#else
    GF_PANIC_Fail((char *)d_021807F8, 0, (char *)d_021807F8);
#endif
```

The image shows only the three pool loads into r0, r1 and r2 before the call; the fourth
argument is the key, already in r3.

How to use it: before a register search, read the strings of the failure calls in the function.
A `%` in the message means an argument the image does not show as a move.

# A call written before a goto into the shared tail is cross-jumped down to its bl

summary: when an arm of the original is only `mov r0, <arg>; b <tail>` and the tail begins
with the `bl` of the same call that another path makes with a different argument, write the
call in that arm followed by `goto` to a label placed after the other path's call; 1.1p1
cross-jumps the identical `bl` and keeps only the argument setup in the arm.

Found in: src/matched/ov016_func_021BE3E4.c (0x021BE3E4, touch in keyboard.o) and
src/matched/ov016_func_021C5A10.c (0x021C5A10, button in scenesetaplist.o)

touch ends in `exchangeBack(-1); MemKb->repeat = 0;`, and the key and button hits reach it as
`mov r0, r4; b tail+4` (the tail is `mvn r0, #0; bl exchangeBack; ...`). Writing each hit as
`exchangeBack(i); MemKb->repeat = 0; return;` repeats the zero store three times, so 1.1p1
keeps 0 in a callee-saved register and the prologue grows (`push {r4-r8}` for
`push {r3-r7}`). Routing the hit through a single `i = -1; exchangeBack(i)` tail moves the
compare into the tail instead. What the original compiled from:

```c
            if (DWCi_TPlCheck(&r)) {
                if (MemKb->push != i)
                    goto out;
                exchangeBack(i);
                goto end;
            }
    ...
out:
    exchangeBack(-1);
end:
    MemKb->repeat = 0;
```

button's case 0 (`mov r0, #7; b` onto case 1's `bl DWCi_SNDlPlay; ... DWCi_ChangeScene`)
closed the same way: `DWCi_SNDlPlay(7); goto change;` with `change:` placed before the
shared `DWCi_ChangeScene(endScene);`.

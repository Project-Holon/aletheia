# A dead beq after bne is a repeated compare of the same value

summary: `cmp r0, #7; bne L; ...; L: beq X` with no flag-setting instruction
between the `bne` and `L` is a second test of the same value whose `cmp` the
peephole dropped. The flags are still those of the first `cmp`, so the `beq`
can never be taken, but mwcc keeps it. Write the second test in the source.

Found in: `src/game/ov135/worldtrade_input.c`
(WORLDTRADE_INPUT_ClampPageChoice, Japanese target, dsi/1.1p1, Thumb).

```c
if (choice != WTMENU_BOTTOM_BTN) {
    if (p->layout == 7) {
        if (choice >= 3) {
            choice = -1;
        }
        return choice;
    } else if (p->layout != 7) {
        return choice;
    }
}
return -2;
```

The `else if` falls through to `return -2` when its test fails, so the
dropped `cmp` leaves `beq` to the -2 block. Two sequential `if`s give the same
bytes. A plain `return choice;` in place of the `else if` gives 34 bytes
without the dead `beq`.

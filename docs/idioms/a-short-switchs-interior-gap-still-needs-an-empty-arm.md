# A short switch's interior exit-valued table entry still has to be written as an empty arm

summary: the rule that an exit-valued jump-table entry between two real arms is
a gap the source never labelled holds only while the switch is still dense
enough to table; in a short switch (cases 0, 2, 3 over a range of 0..3) the
missing interior case drops the whole thing to a `cmp`/`beq` chain, and writing
`case 1:` back as an empty arm (sharing the default body) is what restores the
PC-relative table.

Found in: `src/matched/func_021A1928.c` (0x021A1928)

`empty-switch-arms-are-what-make-the-table.md` splits an exit-valued table entry
in two: one **before** the first real arm must be a source `case` label (there
would otherwise be no table to read it from), while one **between** two real
arms is a gap the source did not have. The second half is not unconditional.
It assumes the switch is already dense enough to table without that label.

`func_021A1928` dispatches on `p[0]` with real arms at 0 and 2/3, an exit-valued
entry at 1, and an ARM `addls pc, pc, r0, lsl #2` table whose four entries are

```
b  <case0 body>     /* r0 == 0 */
b  <exit>           /* r0 == 1, returns 0 */
b  <case2/3 body>   /* r0 == 2 */
b  <case2/3 body>   /* r0 == 3 */
```

Following the "interior entry is a gap" reading, the source was written with
only the real arms plus `default`:

```c
switch (p[0]) {
case 2:
case 3: return func_021A153C(p);
case 0: return func_021A1804(p);
default: return 0;
}
```

and this front end did **not** emit a table at all: three labels over the range
0..3 fell below its density threshold, so it produced a `cmp r0,#0 / beq`,
`cmp r0,#2 / beq`, `cmp r0,#3 / bne` chain instead (72 bytes, no `addls`, no
table, against the original's 76). Adding the interior label back, sharing the
default body,

```c
    case 1:
    default:
        return 0;
```

denses the labels to 0, 1, 2, 3 and restores the `addls pc, pc, r0, lsl #2`
preamble and the four-entry table byte for byte.

So the corrected reading is: an exit-valued entry between two real arms may be
a gap *only* when the remaining labels still table. When the switch comes out
as a compare chain and the original has a table, trust the table's entry count
over the gap rule and give the source a label for every entry -- including an
interior one that does nothing but reach the exit.

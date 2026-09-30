# The boundaries of a switch's jump-table run depend on the whole case-value set

summary: mwccarm builds one decision tree over all the case values and only a
leaf subtree whose values are dense and numerous enough becomes a PC-relative
table; a single case value you have not accounted for elsewhere in the switch
can move the tree's split points, so a contiguous run that tables by itself
becomes a shorter run that falls back to a compare chain. When the image has a
compare chain where you produce a second jump table, suspect a missing case
value near the run, not the run itself.

Found in: `src/matched/ov_sdk/ov175_func_021DF65C.c` (0x021DF65C)

`DWCi_HandleWSLoginError` has one arm (`errorCode -= 8`) shared by
`{1..7, 100..103, 105..108}`. Written as the semantics read, with the arm's
values grouped `case 2..7, 100..103, 105..108`, the compiler emits a **second**
jump table for the dense run 105..108:

```
sub  r2, r4, #0x69
cmp  r2, #3
addls pc, pc, r2, lsl #2
b    default
b    A ; b A ; b A ; b A
```

The image instead has a lone `cmp r4, #0x69` node and a linear range test for
106..108, and is 16 bytes shorter. The difference is not the grouping of the
105..108 labels — splitting them, reordering them and giving 105 its own body
all still table the run. The difference is that the switch's value set was
missing `case 1`.

The dense 0..7 run is a table whose entry 0 points at `default` and entries
1..7 at the same arm:

```
.hword ... 0x0082  ; case 0 -> default
.hword ... 0x00C0  ; case 1 -> arm
...
```

Adding `case 1:` to the arm makes the table correct **and** shifts the tree's
split over the upper values so 105 is a single node and 106..108 a three-value
linear chain, matching the image exactly. The run of three is below the
compiler's table threshold where the run of four was not.

The practical rule when a switch produces an extra jump table the image does
not have: recover the real arm set from the whole dispatch, including the low
end of any dense run (its table entries say which values share the arm), and
rewrite the case list with the missing values. The table/chain shape is a
consequence of the full set, not of how the labels are grouped or ordered.

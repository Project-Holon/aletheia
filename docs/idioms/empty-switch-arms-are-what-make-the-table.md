# A jump table with entries pointing at the exit needs those cases in the source, or there is no table at all

summary: mwccarm only emits the PC-relative halfword table when the case labels
it can see are dense from zero, so a switch whose real arms start at 4 has to
carry `case 0` through `case 3` as empty arms; written with only the three real
arms it becomes a `cmp`/`beq` chain, eight bytes longer and with every register
reallocated.

Found in: `src/matched/unit_020095C8.c` (0x02009698), against
`src/matched/unit_020095C8.c` (0x02009634)

`docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md` reads a table
entry that points at the function's exit as a case label the source did **not**
have. That reading is right for a gap in the middle of the range and wrong at
the bottom of it, and the two functions here are the controlled experiment,
because they are the getter and the setter over the same seven fields of the
same record, compiled in the same file.

The getter dispatches all seven values and its table has seven distinct
targets. The setter only does anything for 4, 5 and 6, and its table is

```
.hword 0x0082, 0x0082, 0x0082, 0x0082, 0x000C, 0x002E, 0x005A
```

with the first four displacements all naming the `pop` at the end. Written the
way the semantics suggest,

```c
switch (field) {
case 4: ... break;
case 5: ... break;
case 6: ... break;
}
```

this front end does not produce that table. It produces

```
cmp r2, #4
beq .case4
cmp r2, #5
beq .case5
cmp r2, #6
beq .case6
pop {r3, r4}
bx  lr
```

which is 172 bytes against the original's 164 and shares almost no register
assignment with it. Adding the four arms the table implies,

```c
case 0:
case 1:
case 2:
case 3:
    break;
case 4:
```

restores the `cmp #6` / `bhi` / `add pc` preamble, the seven-entry table and
the original's bytes.

The decision the compiler is making is about density measured from zero rather
than about the number of arms: three labels at 4, 5 and 6 are a chain, seven
labels at 0 to 6 are a table, and the four extra ones cost nothing but their
table slots. So the reading of an exit-valued entry has to be split in two:

* an exit-valued entry **between** two real arms is a gap, and the source has
  no label for it. `func_0200AE54` in `unit_0200ADB8.c` is that case;
* exit-valued entries **before** the first real arm cannot be a gap, because
  without them there would be no table to read them out of. They are empty
  `case` labels the source really wrote.

The practical rule when a switch comes out as a compare chain and the original
has a table: count the table entries, and give the source a case label for
every one of them.

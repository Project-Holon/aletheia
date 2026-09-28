# A two-node switch tree over a dense run plus one outlier fixes how many labels the run had

summary: for cases {16..38, 47}, 1.1p1 emits `cmp #38; bgt` to a lone `cmp #47`, then `subs #16; bmi` into a 16..38 table, only when the 16..38 run holds 10 or 11 labels; with 9 or fewer it is a compare chain and with 12 or more one 16..47 table. Holes and labels jump to the same exit when the arms are empty, so only the count and the endpoints are recoverable.

Found in: src/matched/ov/ov010_func_02165ECC.c (0x02165ECC)

The image dispatches `ldrh r1, [r4, #0x30]; cmp r1, #0x26; bgt X; adds r0, r1, #0;
subs r0, #0x10; bmi exit; <23-entry table>`, and X is `cmp r1, #0x2f` falling into
the exit (every arm is empty). Writing all 23 labels 16..38 plus `case 47` widens
the table to 0x10..0x2F (the range check becomes `subs; cmp #0x1f; bhi`); moving 47
into the default as `if (type == 47)` gives the right length but a single range
check. Measured on {16, 38, 47} plus k more labels from 17..37: k = 8 or 9 (10 or 11
labels in the run) builds the tree byte-exactly; fewer builds a compare chain,
more builds the wide table. The outlier side follows the same density rule: with
all 23 run labels, the outlier stays in the table up to 72 and becomes its own
tree node from 76 up.

When a switch tree's lower node goes straight to a table with only a `bmi` lower
check, try thinning the dense run before rewriting the structure.

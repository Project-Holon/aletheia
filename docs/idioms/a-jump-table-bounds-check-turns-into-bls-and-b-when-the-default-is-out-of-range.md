# A jump-table bounds check turns into `bls table; b default` when the default is out of branch range

summary: 1.1p1 writes the bounds check of a dense switch as `cmp rN, #max; bhi default`
only when the default target is inside the Thumb conditional branch range (+256 bytes).
When a draft is a few bytes too long anywhere between the check and the default target,
the check becomes `bls table; b default`. The cause is the size of the draft, not the
case labels. Fix the other residue first, then the empty labels give the image's form.

Found in: `src/matched/ov/ov206_func_021BA374.c` (0x021BA374).

The image has `cmp r0, #7; bhi end` and an 8-entry table, with cases 0, 6 and 7 pointing at
the code after the switch. The `bhi` at +0x32 reaches +0x134, which is the maximum forward
distance of a Thumb conditional branch. The draft had one case arm 4 bytes too long (an
address that the image derives once and keeps in a register). With the empty labels
`case 0: case 6: case 7: break;` the bounds check became `bls table; b end`. Without the
labels the table had 6 entries (`cmp #5`). After the case arm matched the image size, the
same empty labels gave `cmp #7; bhi end` and the function was EXACT.

How to recognise it: the `bhi` target in the image is at or near +256 bytes from the
branch. Do not try other case-label spellings: measure the size of the code between
the check and the target first.

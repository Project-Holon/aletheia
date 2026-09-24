# A long index colours apart from an int one

summary: when a loop index or table index and one neighbouring value swap
two registers at every use and no declaration order moves them, declare the
index `long` / `unsigned long` instead of int / u32: mwcc keeps long and int
as distinct types for register colouring, and the swap disappears.

Found in: src/matched/func_02051C88.c (0x02051C88), src/matched/func_0206ECE0.c (0x0206ECE0)

On ARM, long and int are both 32 bits and every instruction is the same, so
nothing in the diff points at the type; the only symptom is a same-width
register exchange that survives every declaration order, the permuter and
the other levers:

  * 0x02051C88 (1.1p1, game code): the first loop's index and the slots
    base came out ip / lr against the image's lr / ip over 13 instructions
    (19 bytes, five waves, all 720 declaration orders).  `unsigned long i;`
    in place of `u32 i;` is EXACT; `long a, b` for the compared slot
    indices is still 19.
  * 0x0206ECE0 (../2.0/sp2p2, NitroSystem g3d): the node pointer and the
    pivot index k came out r4 / r5 against the image's r5 / r4 (14 bytes,
    seven waves, 400 declaration orders).  `long k;` in place of `int k;`
    is EXACT under both 2.0 front ends; u16 / u8 k change the size.

The same fact moved 0x02048744 from 18 to 14 in wave 16 (`long i, j`), where
it swapped one pair back and exposed another (that note records the TwlSDK
s32 as `signed long`; the SDK headers are not in this tree to confirm it).
Try it on the index of a swapped pair before declaration sweeps; it is one
measurement.  It did not move 0x0206F4C8, 0x0202E1F0, 0x0200CA98,
0x0204A7A0 or 0x0202627C (wave 18), so it is a lever, not a rule.

Wave 19: it also closed 0x02031FE0 (src/matched/func_02031FE0.c, 1.1p1,
ARM), where the long value is not an index but a sum (`AB = A + B`, a record
end offset) and the swap partner was B.  There `unsigned long AB` alone moved
9 to 13 bytes (a three-register rotation), and only a declaration sweep ON
TOP of the long type (AB, pa, pb, i, A, B) reached EXACT; every earlier
720-order sweep had been with u32.  So when long moves a swap without closing
it, sweep declaration order again with the long in place.

Wave 19 (lane swaps_long): the type does not have to be on an index. In
0x0202E1F0 (1.1p1, Thumb, docs/notes/pkt_0202E1F0.c.txt) the swapped pair
was o and w, w being a stack parameter reused as the &ws pointer. `unsigned
long w` alone is still 21, and a copy `wp = (void *)w;` before loop 1 with
`void *w` is still 21; the two together put o in r6 and w in r7 as the image
has them (21 to 2 bytes). The remaining 2 bytes are the copy being folded to
&ws at its one use. The same recipe did not move 0x02048744, 0x0202173C,
0x02021848, 0x0209D7D4 or 0x0204EEC8 (their notes list the measurements).

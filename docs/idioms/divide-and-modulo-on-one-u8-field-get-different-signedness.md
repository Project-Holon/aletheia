# `x / 8` is `lsrs` but `x % 8` is the full signed sequence, in the same expression on the same `ldrb`

summary: mwccarm lowers `/` on a byte load as unsigned and `%` on the same
value as signed `int`, so a bare `lsrs #3` next to an `lsls #29` / `subs` /
`rors #29` quartet is one expression on one `u8` field; copying the field into
a `u32` local first collapses the modulo to `movs #7` / `tst` and loses bytes.

Found in: src/pending/sub_0201D854.c (0x0201D854)

gf_font.c rounds a pixel count up to whole bytes twice in a row, and each looks
like this:

```
0201D8D8  ldrb r0, [r0]          /* the u8 field */
0201D8DE  movs r1, #0x1d
0201D8E0  lsrs r3, r0, #0x1f     /* the sign bit, known zero here */
0201D8E2  lsls r2, r0, #0x1d
0201D8E4  subs r2, r2, r3
0201D8E6  rors r2, r1
0201D8E8  adds r1, r3, r2        /* r1 = x % 8, signed lowering */
0201D8EA  beq  ...               /* ... != 0 ? 1 : 0 */
0201D8F2  lsrs r0, r0, #3        /* r0 = x / 8, unsigned lowering */
0201D8F4  adds r1, r0, r1
```

The two halves disagree about the type of the same value. The division is a
bare logical shift, which is only valid for a non-negative operand, so the
compiler has used the range of the `ldrb`. The modulo is the generic signed
`int` sequence (`(x << 29) - (x >>> 31)`, rotated back, plus the sign), which
that same range information would have collapsed to `ands #7`. mwccarm simply
does not consult the range in its `%` lowering and does in its `/` lowering.

The C that reproduces it writes the field expression out on both sides, so both
operands keep the ordinary `int` promotion:

```c
f->unk7E = (u8)(f->unk74 / 8 + ((f->unk74 % 8) ? 1 : 0));
```

The single `ldrb` is then common-subexpression elimination, not a source-level
temporary. Measured on this function, holding everything else fixed:

```
f->unk74 / 8 + ((f->unk74 % 8) ? 1 : 0)   ->  the sequence above,  372 bytes, right
u32 v = f->unk74; v / 8 + ((v % 8) ? 1:0) ->  movs #7 / tst,       356 bytes, sixteen short
s32 v = f->unk74; ...                     ->  the front end rejects the unit
```

So the tell runs both ways. A `movs #7` / `tst` pair is a modulo on a value the
compiler has in an unsigned local; the `lsls #29` / `subs` / `rors #29` quartet
is the same modulo written against a field or any other plain `int` expression.
Seeing the quartet next to a plain `lsrs` is not two different values and not a
cast, it is one field read twice in one line.

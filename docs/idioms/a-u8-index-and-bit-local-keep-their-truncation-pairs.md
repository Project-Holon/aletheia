# A `u8` index and a `u8` bit number each keep their own `lsls #0x18`/`lsrs #0x18` pair

summary: a byte index and a bit number held in `u8` locals survive to the
object as two separate truncation pairs even though both are provably in
range, because each local's own conversion is emitted at its assignment; the
same values written inline in the shift expression are proved to fit and lose
the pairs.

Found in: src/matched/sub_0202F114.c (0x0202F114)

The original computes a byte index and a bit number from one `u32`, and each
gets a pair of its own:

```
0202F116  movs r3, #7
0202F118  ands r3, r1          ; bit = i & 7
0202F11A  lsls r1, r1, #0x15   ; \
0202F11C  lsls r3, r3, #0x18   ;  |  idx = (u8)(i >> 3), bit = (u8)(i & 7)
0202F11E  lsrs r1, r1, #0x18   ;  |
0202F120  lsrs r3, r3, #0x18   ; /
0202F122  movs r4, #1
0202F124  ldrb r0, [r0, r1]
0202F126  lsls r4, r3          ; mask = 1 << bit
```

```c
    u8 idx = (u8)(i >> 3);
    u8 bit = (u8)(i & 7);

    if ((p[idx] & (1 << bit)) != 0)
        return 0;
    return 1;
```

Writing the two expressions inline (`p[(i >> 3) & 0xFF] & (1 << (i & 7))`)
loses both `lsls #0x18`/`lsrs #0x18` pairs: the front end knows the masked
and shifted values are already in range and folds the conversion away, four
instructions ahead of where the original has them.  The converse also bites:
parking the mask in a third `u8` local (`u8 m = 1 << bit;`) adds a *third*
truncation pair after the shift, so the mask has to stay inline in the `&`.

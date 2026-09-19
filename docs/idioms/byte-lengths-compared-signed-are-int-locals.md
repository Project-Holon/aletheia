# A signed compare of two byte lengths means the operands are int locals

summary: `movgt`/`blt` on two values just loaded with `ldrb` means mwcc lost
their range, which only happens when they were assigned to `int` locals first;
comparing the `u8` members directly makes mwcc use the unsigned codes
(`movhi`/`blo`) instead, and the two spellings differ by four bytes with
everything else identical.

Found in: `src/matched/func_02096D10.c` (0x02096D10) and
`src/matched/func_02096DF0.c` (0x02096DF0), `pkt_02096990`

The minimum of two byte lengths, written the obvious way:

```c
    n = a->f04;                       /* u8 members, compared directly */
    if (a->f04 > b->f04)
        n = b->f04;
```
compiles to `cmp r4, r2` / `movhi lr, r2`, because a `ldrb` tells mwcc the
value is 0..255 and an unsigned comparison is then just as good. The original
reads:

```
02096D50  ldrb r4, [r0, #4]
02096D54  ldrb r2, [r1, #4]
02096D58  mov  ip, #0
02096D5C  mov  lr, r4
02096D60  cmp  r4, r2
02096D64  movgt lr, r2          <- signed
02096D68  cmp  lr, #0
02096D6C  ble  0x02096DA8       <- signed, tolerates a negative count
```

which is `movgt`, so the operands are signed-unknown. Copying both members into
`int` locals first restores that:

```c
    int la = a->f04, lb = b->f04;
    n = la;
    if (la > lb)
        n = lb;
```

The same lever explains a `volatile`d member compared against an `int` loop
index: the qualifier does not change the type, but the reloaded byte is used
from a register mwcc has no range for, so the loop test also comes out signed.

Related: `a-small-constant-is-rematerialised-off-a-zero-register.md` covers the
`mov ip, #0` that the `int i` loop counter leaves behind here.

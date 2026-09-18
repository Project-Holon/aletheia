# A u8 field read into an int counter keeps ldrb; the counter's own type decides the compare and the increment

summary: A `u8` struct field assigned to an `int` loop bound still loads
with `ldrb` but the loop compare comes out signed (`ble`/`blt`), and the
counter only gets the `lsls #0x18; lsrs #0x18` narrowing when the counter
itself is declared `u8` — a twin pair of loops over the same field can differ
by exactly those two choices.

Found in: src/matched/func_0202597C.c (and its twin src/matched/func_02025774.c)

Two functions in one packet walk the same object:

```
02025774  adds r5, r0, #0        ; p
02025778  adds r0, #0xcb
0202577A  ldrb r0, [r0]          ; u8 bound
          ...
020257A0  adds r0, r4, #1
020257A2  lsls r0, r0, #0x18     ; counter IS u8
020257A4  lsrs r4, r0, #0x18
020257AC  cmp r4, r0
020257AE  blo                    ; unsigned compare
```

```
0202597C  adds r5, r0, #0        ; p
02025980  adds r0, #0xcb
02025982  ldrb r0, [r0]          ; same u8 field
          ...
020259A8  adds r4, r4, #1        ; no narrowing: counter is int
020259B2  cmp r4, r0
020259B4  blt                    ; signed compare
```

The load is `ldrb` in both, so the field is `u8` in both and neither source
uses a `s8` — declaring the field `s8` to explain the signed compare is the
trap: it switches the load to `ldrsb` and every subsequent offset shifts. The
signed compare comes from the *counter*: `for (int i = 0; i < p->w; i++)`
promotes the `u8` field to `int`, while `for (u8 i = 0; ...)` compares
unsigned and pays for the narrowing pair on every increment.

Both loops re-read the field after the loop body's call (the callee may write
through the same pointer), so write the bound as a direct `*(u8 *)(p + 0xCA)`
or `p->w` read in the loop head, not as a local hoisted above it.

Verified with:

    python tools/match.py one --src src/matched/func_0202597C.c \
        --func func_0202597C --addr 0x0202597C --cc 1.1p1 --thumb

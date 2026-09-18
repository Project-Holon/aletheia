# A four bit field in a byte container still needs the dword shift pair, and its signedness picks `lsrs` over `asrs`

summary: `ldrb` followed by `lsls #28` / `lsrs #28` is an unsigned four bit
bitfield in a byte; the same shifts written as a mask fold to `movs #0xf` /
`ands`, and the same shifts on a plain `u8` pick `asrs` because the byte
promotes to signed `int`.

Found in: src/matched/func_02020234.c (0x02020234)

`0x02020234` narrows the byte at object +0x18 to four bits before handing it
to `func_02043B5C`:

```
ldrb r1, [r4, #0x18]
lsls r1, r1, #0x1c
lsrs r1, r1, #0x1c
blx  #0x2043b5c
```

Three spellings, three different instruction sequences, and only one of them
is the original:

```c
((u32)p[0x18] << 0x1c) >> 0x1c   /* movs r1,#0xf ; ands r1,r2      */
(p[0x18] << 0x1c) >> 0x1c        /* lsls r1,#0x1c ; asrs r1,#0x1c  */
p->lo4                           /* lsls r1,#0x1c ; lsrs r1,#0x1c  */
```

The first is the surprise: writing both shifts out by hand does not preserve
them, the optimiser proves the mask and re-materialises it as `ands`.  That is
the same finding as
docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md, one width
down: there the surviving field is 24 bits in a word, here it is 4 bits in a
byte, so the shifts are `#0x1c` rather than `#8`.

The second spelling is the one to be careful about, and it is a *different*
trap from the same family: `p[0x18]` has type `u8`, which promotes to signed
`int`, so `>> 0x1c` is an arithmetic shift and the byte comes out `asrs`.
One byte wrong, identical size, no diagnostic.  The bitfield spelling fixes
both because the extraction is generated from the field's declared width and
unsignedness together:

```c
struct Ctl {
    u8 pad[0x18];
    u8 lo4 : 4;
    u8 hi4 : 4;
};
```

The container stays a byte (`ldrb`, not `ldr`), which is what says the field
lives in a `u8` and not in a word.

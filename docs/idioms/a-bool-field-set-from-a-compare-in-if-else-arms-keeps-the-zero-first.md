# A bool field set from a compare in if/else arms keeps the zero first, the relational form puts the one first

summary: `mov rN, #0` ... `moveq rN, #1` then one `strb` is `if (f()) field = 0; else field = 1;`;
writing the same store as `field = f() == 0;` gives `mov rN, #1` / `movne rN, #0`, a ternary
`f() ? 0 : 1` materialises a second compare, and `if (f() == 0) field = 1; else field = 0;` keeps
two stores. Only the zero-first if/else collapses to the image's pair.

Found in: src/matched/ov_sdk/ov016_func_021CF80C.c (0x021CF80C, DWCi_SETTINGlSetSetting)

The original stores `MemSet->temp.ipAuto` from a `memcmp` against a 4-byte zero address:

```
bl    memcmp
cmp   r0, #0
mov   r1, #0
...
moveq r1, #1
strb  r1, [r0, #0x4f5]
```

Measured on the same function, everything else fixed:

- `ipAuto = memcmp(ip, NONE, 4) == 0;` gives `mov ip, #1` / `movne ip, #0` (2 lines out).
- `ipAuto = memcmp(ip, NONE, 4) ? 0 : 1;` and `(bool)(... == 0)` keep an extra compare (44..49 lines).
- `if (memcmp(...) == 0) ipAuto = 1; else ipAuto = 0;` keeps the arms (2 lines).
- `if (memcmp(ip, NONE, 4)) ipAuto = 0; else ipAuto = 1;` is EXACT.

The neighbouring `dnsAuto` store, a two-call conjunction, follows the same order: the image lays
the `= 0` arm out first, which is `if (memcmp(dns0) != 0 || memcmp(dns1) != 0) dnsAuto = 0; else
dnsAuto = 1;`.

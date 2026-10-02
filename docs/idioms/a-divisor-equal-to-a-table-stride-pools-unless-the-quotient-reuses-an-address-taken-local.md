# A divisor equal to a later table stride pools unless the quotient reuses an address-taken local

summary: when a `_u32_div_f` divisor equals the element stride of a table indexed
after the call, 1.1p1 hoists the constant into a callee-saved register before the
call (`movs r6, #0xc`) and reuses it for the `muls`; the image rematerialises it
after the call. Writing the quotient back into the address-taken local it came from
(`z = (z >> 3) / 12;` instead of a fresh `q`) removes the pooling, no other change.

Found in: src/matched/ov/ov021_func_021B0808.c (0x021B0808)

`func_0206DF3C(&pos, &x, &z)` returns z through a pointer; the quotient indexes
`d_021D939C[2][4]` (VecFx32, stride 12). With `q = (z >> 3) / 12;` the residue was
24 bytes (extra `movs r6, #0xc`, shifted registers). Measured inert first: divisor
spellings (12u, 12UL, sizeof, casts to u8/u16/s8, enum local, inline div helper),
types of r, row pointer, char/flat/row-struct indexing. Changing the divisor to 13
proved the pooling was the only difference. `z = (z >> 3) / 12;` is EXACT.

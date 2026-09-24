# Rule study: anonymous string literals (func_02094B8C, MSL __strtold)

## 1. What the pool words point at

`match.py one` (1.1p1 -O4,p, c99): MATCH, 3864 bytes, 15 of 17 resolved. Unresolved: +0x0EF0 ABS32 `@52`, +0x0EF4 ABS32 `@70`, both "no address: not in the symbols: block".

`match.py show --addr 0x02095A7C --size 8`: words 0x020A62E4 and 0x020A62DC. Image bytes: 0x020A62DC `NAN(\0` (then 3 NUL pad), 0x020A62E4 `INFINITY\0`. The compiled tu.o holds the same two literals (offsets 0x270, 0x280).

layout/data_objects.txt rows 585/586 list both as kind `pool`, not `string`; their only evidence is the pool word under test (0x02095A80 / 0x02095A7C).

## 2. Why `string` refuses

The blocker is only the missing name. The resolver never reaches attest_string: `@N` has no declared address. Given the address by hand, 0x020A62E4 passes `string` (previous run "NAN(" fixes it), 0x020A62DC fails `string` condition 5 (the NUL before it ends a table, not a string) but passes `sole-ref/string`. So an outside witness exists for both. What is missing is a non-circular way to get the address.

## 3. The compiled proof argument

Byte scan of all 242 loaded regions (3.94 MB): `INFINITY` occurs once (0x020A62E4), `NAN(` occurs once (0x020A62DC). The rule must take the address from the compiled literal bytes by an image-wide unique search, not from the ROM pool word (reading that word would be the circularity the honesty rule forbids). Then the resolved word is compared with the ROM word. A wrong literal gives no hit (unresolved), several hits (refused) or one hit at a different address (for example a suffix `FINITY\0`), which comes out DIFF. Only the right bytes produce the right address. It cannot be fooled.

## 4. Recommendation: add `string/anonymous`

Conditions, each a separate refusal: relocation target is a compiler-local `@N` symbol in the TU's data/rodata; its bytes (symbol extent) are one NUL-terminated printable run of at least MIN_STRING_CHARS; that byte sequence, NUL included, occurs exactly once across all loaded regions; the hit is in a data section and outside the compared range. Address = the hit, addend applied.

Selftest: positive (unique `INFINITY\0` resolves and compares EXACT); negative, literal present twice (refused, stays MATCH); negative, bytes differ from the image (no hit, refused; or unique hit elsewhere, DIFF).

Figure effect: func_02094B8C would go EXACT, 3864 bytes (the brief's +2892 does not match the function size; recheck against the coverage tool's counting). No other src/pending file mentions `anonymous` or has a MATCH entry with string literals, so it unblocks this one file only.

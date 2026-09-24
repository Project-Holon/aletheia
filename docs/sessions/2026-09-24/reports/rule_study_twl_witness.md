# Rule study: TWL callees of func_0206DC00

## 1. What the outside witness prevents

A hardened PC24 `bl` writes `(value - site - 8) >> 2`, where `value` comes from the `symbols:` line, and the result is compared against the image. The `twl` token only selects which listing to check. It never supplies the value. A wrong address always gives DIFF, and no compensating error exists. The 2026-09-23 audit says this of every class: none of them "can make wrong bytes EXACT". The only wrong answer left is semantic: an extern placed at an address that is not a callee (an interior offset, a pool word, or data read as code). The outside branch rules that out, but it is not the only way.

## 2. Comparison

`matched` is stronger, because it pins the whole function body. The fair comparison is `sole-ref/code`. It already accepts an exact traced `func_` label with the declared ISA and no referrer, for ARM9 and for overlays. Its weakness is the prologue sweep, which can label data. Both of these starts hold up:

- Each follows a `pop {...,pc}` and a pool word.
- Each opens with an lr-saving `push`.
- Each has a callback path (`blx r3` when r2 is 0) that fits the caller's DMA callback.
- Both call sites use an ARM `bl`, which matches the ARM labels.

## 3. References inside twl

None. A grep of all of asm/ finds only the sites 0x0206DCA4 and 0x0206DD40, both inside the compared range. The other hits repeat these two sites in overlapping split files. Both labels therefore come from the sweep. `sole-ref/code` needs no referrer anyway.

## 4. Recommendation

The rule: a call whose `symbols:` line carries `twl` is attested `sole-ref/code` when its address is inside the twl window and is exactly a `func_` label in asm/twl/twl.s with the declared ISA. This is the overlay `sole-ref/code` rule with the twl listing as its only candidate, added as the last fallback in attest_sole_ref().

Selftest:

- Positive: 0x027300F0 and 0x0272FEF4, `arm`, `twl`, with lo..hi = 0x0206DC00..0x0206DDA4.
- Refused:
  - an interior address (0x027300F4);
  - the pool word at 0x027300EC;
  - the ISA declared `thumb`;
  - no hint, or an `ovNNN` hint;
  - an ARM9 address (0x0206DBF4) with the `twl` token;
  - no twl.s (no key).

Figure effect: at most +404 bytes (func_0206DC00 alone), and only if it recompiles EXACT. No existing entry changes class.

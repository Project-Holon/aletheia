# Two callers of the same extern attest each other, so split the unit rather than give up on it

summary: when the only callers of an external function are inside the range
under comparison, the `label` class has no witness and the whole unit caps at
MATCH; putting those callers in different ranges makes each one the other's
outside witness and both come out EXACT.

Found in: `src/matched/unit_02008B4C.c` (0x02008B20 and 0x02008B78),
`src/matched/unit_02008FFC.c` (0x0200903C and 0x02009050)

This is a property of the harness rather than of the compiler, but it decides
where a file is cut, so it belongs with the rest of what a packet agent needs.

A file is often the only user of some helper. `sub_02008B20` and `sub_02008B78`
are the only two callers of `OS_GetOwnerRtcOffset` in `arm9_main` and in all 237
overlays; `sub_0200903C` and `sub_02009050` are the only two callers of
`sub_02008F3C`. Matched as one range, each pair attests itself out of existence:
every witness for the target address is inside the bytes being compared, the
honesty rule discards them all, and a 306-byte unit with every concrete byte
right reads

```
MATCH      translation unit @ 02008AEC
    +003A THM_CALL OS_GetOwnerRtcOffset -> unresolved: 02087D08 has no
          witness outside 02008AEC..02008C1E
```

The fix is not more evidence, it is a smaller range. Cut the file between the
two call sites. Each range then contains one of them and the other one, now
outside, is an ordinary `label` witness, and both halves are EXACT. Nothing
about the rule is bent: the evidence was always a real instruction in the image,
it just had to stop being part of what is under test.

Two constraints pull the other way and have to be checked before choosing the
cut:

* a call to a function **defined in the same range** is the `local` class and
  needs no evidence at all. Cutting a range so that a callee moves out of it can
  therefore break a site that was fine, which is what leaves `sub_02008AF0` and
  `sub_02009020` unmatched in the two files above: each is the only caller of a
  function it must be split away from.
* a reference through a pool word to a function nothing ever branches to has no
  `label` witness in the first place, and `literal` sees only the word under
  test. `sub_02009020` is that: a three-instruction tail call to an address the
  image names exactly once.

So the recipe is: list every external reference in the proposed range, count its
witnesses elsewhere in the image, and cut where the counts allow. When no cut
satisfies every site at once, leave out the one function that is over-constrained
and match the rest, rather than settling for MATCH on all of it: `csrc.py`
refuses anything that is not EXACT, so a MATCH unit contributes nothing to the
build.

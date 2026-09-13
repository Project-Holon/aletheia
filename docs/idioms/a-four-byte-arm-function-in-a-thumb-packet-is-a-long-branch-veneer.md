# A four byte ARM function inside a Thumb packet is a long branch veneer, and it cuts the translation unit in two

summary: `ldr pc, [pc, #-4]` plus a pointer word, labelled by disasm.py as an
ARM function in the middle of otherwise Thumb game code, is a linker stub for
a call the Thumb `bl` could not reach; it is not compiled from any C, so no
`tu` range may span it and the original file has to be matched as the pieces
between the stubs.

Found in: `src/matched/unit_02005430.c` (0x02005430), and the four stubs at
0x020053E4, 0x02005420, 0x02005428 and 0x02005454 in `pkt_020051D8`

`layout/worklist.json` reports `pkt_020051D8` as `isa mixed` and lists four
four-byte ARM functions among twenty-two Thumb ones. They are all the same
eight bytes:

```
	.arm
func_020053E4:
	ldr	pc, pool_020053E8           /* 020053E4  04 F0 1F E5 */
pool_020053E8:
	.word	0x0273154C                  /* 020053E8 */
```

and each is reached from exactly one `blx` in the Thumb function just before
it. That is `mwld`'s long branch veneer: the C called an extern, the compiler
emitted a Thumb `BL` with a relocation, and the linker found the target more
than 4 MB away (0x0273154C is 7.5 MB from the call at 0x020053AA) and
redirected the call to a stub it generated next to the caller.

Two consequences, and the second is the expensive one to find by hand.

**The stub forces a unit boundary.** `match.py tu` lays the object's sections
end to end and compares them with a byte range. The compiler never emitted
these eight bytes, so a range that contains them can never reproduce them, and
a packet with four of them is at most five separately matched pieces however
the original source file was divided. Sweep for them before proposing any unit
boundary: a mixed-ISA packet's boundaries are decided by the linker, not by the
source.

**Whether the stub can be attested at all depends on where its pointer lands.**
`docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md`
covers the case that works: the extern is declared at the stub's address,
marked `arm`, and the `veneer` attestation class carries it because the pointer
word names a function of a known region. Here it does not. 0x0273154C,
0x027315D0, 0x027314F0 and 0x027315C0 are inside no region of
`layout/layout.json` at all, which is the TWL-only `arm9i` module this project
does not extract, so condition 4 of `veneer_at()` refuses and the only evidence
left for the stub's address is the one `blx` that reaches it, inside the
function under test. All four callers therefore stay open, and the difference
between them and `src/matched/unit_02005794.c`, which closed, is entirely which
side of a region boundary the callee happened to be on.

The recognition rule is worth stating on its own, because `disasm.py` labels
these `func_` like any other function and the worklist counts them as work:

* `E51FF004` followed by one word, or `E59FC000 E12FFF1C` followed by one word,
  four-aligned, with no prologue and no caller other than a pool word or one
  adjacent `blx`, is a linker stub and not a decompilation target;
* a `func_` label on it is `disasm.py`'s trace succeeding, not a claim that
  somebody wrote it.

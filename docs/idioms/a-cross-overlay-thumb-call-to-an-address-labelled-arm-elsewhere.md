# An overlay's Thumb call cannot be attested if the only label for its address lives in another overlay and is ARM

summary: when an overlay `bl`s a Thumb routine whose only `func_` label
image-wide is an ARM body in a different overlay, match.py refuses to resolve
the site (`ISA conflict ... the image says arm`) and no header spelling fixes
it: the call is a Thumb `bl` in the original but the resolver can only patch it
to `blx`, so the function is a permanent DIFF unless the Thumb copy gets its own
label or an EXACT entry.

Found in: `docs/notes/ov060_func_021F39F4.c.txt` (0x021F39F4, region ov060,
call at +0x1C to 0x021BE6BC)

Overlays share address space. A call from ov060 to 0x021BE6BC is rendered
`bl 0x021BE6BC (outside this region)` because ov060's window is
0x021F36C0..0x021F3BE0; when ov060 executes, 0x021BE6BC is some Thumb routine.
The only label at that address anywhere is `func_021BE6BC` in `asm/overlays/
ov114.s`, and ov114's copy there is ARM (`src/matched/func_021BE6BC.c` has
`isa: arm`).

The original call is a Thumb `bl`:

```
	.inst.w	0xF7CAFE54	/* 021F3A10  CA F7 54 FE  bl 0x021BE6BC */
```

Match the reconstructed C and the compiled object comes out with `blx` at that
site (the interworking call for the ARM symbol the resolver knows).  Declaring
the symbol Thumb in the header does not help; it is refused outright:

```
ISA conflict for func_021BE6BC at 021BE6BC: the source declares thumb,
the image says arm (the func_021BE6BC label in ov114).
```

Adding a region token (`thumb ov060`) does not change it, because the resolver
still finds the ov114 label first.  Leaving the symbol out and letting the
address naming convention resolve it produces the same `blx` patch.  The
`label` class therefore cannot carry the site, and neither can `sole-ref/code`
(there is no Thumb `func_` start at that address), so the site either stays
wildcarded with the wrong opcode or is a concrete DIFF.

The recognition rule: a `bl` (not `blx`) whose target is outside the function's
own region, whose only image-wide label is of the opposite ISA, and with no
Thumb label in the caller's own overlay, is unfixable from C.  What would close
it is the missing witness, not more C: a `func_` label on the Thumb copy in the
right overlay's listing (then name it with that region token), or an EXACT
`layout/matched` entry for that copy (then `matched` attests it).  The
same-ISA case is the ordinary `label` path and works fine; this is only the
cross-ISA collision.

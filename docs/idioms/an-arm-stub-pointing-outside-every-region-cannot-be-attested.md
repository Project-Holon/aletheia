# An ARM link stub that points outside every region cannot be attested

summary: `E51FF004 <ptr>` / `E59FC000 E12FFF1C <ptr>` at a 4-aligned address
is the `veneer` class only when the pointer word names a *labelled* function
or an SDK symbol *inside* a region of `layout/layout.json`; several stubs in
the 0x02005xxx boot area point at 0x027004xx and 0x02730xxx, which no region
covers, so `names_known_code()` refuses them on its first condition and every
call site naming the stub caps at MATCH with all its concrete bytes right.

The six stubs in 0x020053E4..0x02006D3C are ordinary Thumb-to-ARM
interworking jumps out of one function each:

```
02005454  04 F0 1F E5  E51FF004  ldr pc, [pc, #-4]
02005458  C0 15 73 02  027315C0  .word 0x027315C0
```

A Thumb caller reaches one with `blx func_02005454`, and the linker wrote the
*distance to the stub*, not to the real callee, so the address the compared
bytes encode is the stub's own.  That is exactly the case the `veneer` class
exists for (`docs/MATCHING.md`, "The veneer class"), and it works whenever the
stub's pointer names code the trace reached:

```
02072788  E59FC000  ldr ip, [pc, #0]
0207278C  E12FFF1C  bx  ip
02072790  0208970C  .word SND_SetMasterVolume      <- inside arm9_main
```

Here it does not.  `python -c "import match; match._region_at(0x027315C0)"`
returns `None`: `layout/layout.json`'s `arm9` region is
0x02004000 + 0xA5E80 (it ends at 0x020A9E80, where the game's data begins), and
0x027004xx / 0x02730xxx are Twl main RAM beyond anything the image contains.
`names_known_code()` opens with

```python
if _region_at(target) is None:
    return False
```

so the stub is refused before the label lookup is even tried, and no source
spelling changes the outcome: the call site stays wildcarded, the entry caps
at `MATCH`, and `--suggest-split` has nothing to offer because the only
content is one function.

What this does *not* mean is that the stub is not a stub.  Its shape, its
alignment, and the fact that the Thumb caller's relocation lands on the stub's
address rather than on a function entry are all consistent with a linker
veneer; what is missing is only the second half of the evidence, that the
pointer names code the project can name.  Recognising a pointer that falls
outside every region as *itself* evidence is a change to `tools/match.py` and
belongs to the integrator, not to a packet file.

Do not burn budget re-spelling the C at such a site: the count of unresolved
sites is fixed by `layout.json`, and the `--suggest-split` census will already
tell you the same thing for free.

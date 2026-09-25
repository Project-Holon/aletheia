# Match an unlabelled callee first, and its thunks resolve as matched

summary: A pool-word offset-thunk whose callee is an unlabelled leaf in the
same overlay caps at MATCH; reproducing that leaf as its own EXACT entry makes
the thunk's ABS32 site resolve through the `matched` class, no new image
evidence needed.

Found in: src/matched/ov068_unit_021B9944.c (0x021B9944)

Several overlays carry families of compiler-generated offset thunks of the
shape

```
ldr r3, [pc, #N]      @ load the real callee from a literal pool
adds r0, #0xNN        @ adjust the incoming pointer
bx r3                 @ tail-call it
.word func_XXXXXXXX | 1
```

The thunk's only relocation is that pool word. When the callee is a leaf that
saves nothing, `disasm.py` never labels it (see
`unlabelled-leaf-functions-hide-in-word-runs.md`), so the site has no witness
outside its own range: `label` finds no label, `literal` reads ARM9 pools only,
and `sole-ref/code` refuses a non-`func_` start. The thunk is byte-correct but
stuck at MATCH.

Do not reach for a region hint on another overlapping overlay (the caller's own
window usually holds the address, and a hint would be a guess wearing evidence's
clothes). Instead, `match.py show --addr <callee> --region <same ov> --thumb`
the callee, write it as its own C function, verify it `EXACT`, and file it as a
separate entry (a region-qualified packet, e.g.
`src/matched/ov068_func_021BA018.c`). Its manifest entry is indexed by address;
because the site's `site_region` is that same overlay, `attest_matched()`'s
`_matched_overlay_ok()` picks it and the pool word resolves as `matched`. The
thunks then verify EXACT and, being contiguous, fold into one `tu` unit
(`ov068_unit_021B9944.c` covers the four at 0x021B9944..0x021B996C).

The same overlay-local reasoning applies to a thunk that tail-calls an ARM9
function through a pool word: the ARM9 target is `label`-attested (the callee
`func_0204B3B4` had three callers), so that thunk goes EXACT directly and then
attests the three ov071 offset-thunks that call it.

Only when the callee lives in a *different* overlay (0x02188D2C, 0x021897BC) and
is unlabelled there does the MATCH cap hold; the fix then belongs to whichever
lane owns that overlay, not to a guess here.

# A `func_` label can be the dead lead of a pool run, not a live function

summary: a `disasm.py` `func_` label whose first bytes happen to decode as a
saved-`lr` prologue can be the dead lead of a preceding function's literal
pool, so its extent is hundreds of bytes of `.word` data and no C ever
matches; a 300+ byte extent with zero `bl`/`blx`/`[pc` in its body is a pool
run, not an oversized function.

Found in: asm/overlays/ov102.s, ov103.s, ov104.s, ov112.s, ov175.s (stale `func_` labels)

`disasm.py` auto-labels a prologue that saves `lr` (`push {.., lr}`). Because
the listing is regenerated after earlier work, a `func_XXXXXXXX:` label can
survive at an address that is now covered by a preceding function's literal
pool: the bytes at the label happen to decode as `push {.., lr}` too, so
`listing_labels()` still reports it, but the region between this label and the
next one is a pool of `.word`s. Taking `match.py show --addr` at such a label
returns a

    <addr> <lead> push {.., lr}
    <addr+2> <lead+2> ...
    <addr+4> pool_XXXX:
    .word ...

shape. The live function before it is far longer than the gap between pool
entries, and compiling the label's four or five decoded instructions never
matches, because the original compiles them as one literal-pool table.

The diagnostic: count the regions with **zero** `bl`/`blx`/`[pc` in their body.
Those are almost never real functions: the listing computes a function's extent
as "address to the next `func_`/`sub_` label", so a pool gets attributed to the
next label and a stale label can sit in the middle of it. In the [256,512)
overlay band, ov103/ov104/ov102/ov112/ov175 all contained such stale labels
whose "function" extent was 400-500 bytes but whose emitted body was three
instructions followed by a literal pool. `match.py one` on such a candidate
reports `SIZE`/`DIFF` spanning the whole extent and no amount of C will close
it.

Guard: before writing C for an extent, confirm at least one call or pool load
appears in the body. If a 300+ byte extent shows none, it is a pool run whose
lead is dead; skip it rather than treating it as an oversized function.

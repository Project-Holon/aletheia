# A nearby absolute address is synthesized from the loaded base, not pooled

summary: When a function writes several absolute addresses that differ by a
round immediate, mwcc loads only one from the literal pool and derives the
others with `sub`/`add`; writing the accesses through a common pointer variable
instead changes the register allocation and no longer matches.

Found in: src/matched/ov016_func_021C1F64.c (0x021C1F64)

The original `func_021C1F64` sets the low two bits of five halfword registers:
`0x04001008`, `0x0400100A`, `0x04000008`, `0x0400000A` and `0x0400000C`. Its
prologue loads only two of those addresses from the literal pool
(`0x04001008` into `r3`, `0x0400000A` into `r1`) and computes the third with

```
sub r2, r3, #0x1000        @ 0x04001008 - 0x1000 == 0x04000008
```

i.e. mwcc recognised that the two absolute constants differ by a representable
immediate and preferred the one-instruction `sub` over a second pool word. The
value being stored always lands in `r0`; the long-lived derived base goes to
`r2`.

Writing the body with the raw absolute addresses is what reproduces this:

```c
((BgCnt *)0x04001008)->priority = 3;
((BgCnt *)0x0400100A)->priority = 3;
((BgCnt *)0x04000008)->priority = 3;
((BgCnt *)0x0400000A)->priority = 3;
((BgCnt *)0x0400000C)->priority = 3;
```

The tempting "tidier" spelling, routing the accesses through pointer locals,
compiles to the same semantics but a different register assignment and loses
the `sub`:

```c
BgCnt *b = (BgCnt *)0x04001008;
BgCnt *c = (BgCnt *)0x0400000A;
b[0].priority = 3; b[1].priority = 3; d = b - 0x800; ...
```

Here the derived base is materialised into `r0` and the stored value into `r2`,
the two registers swap relative to the original, and the whole function reads
`DIFF` over its `bic`/`orr`/`strh` triples even though the byte count and the
logic are identical. When a hardware-register initialiser shows a `sub`/`add`
of `#0x1000` (or another round immediate) feeding an address that is not in the
pool, spell every register as its own absolute cast and let mwcc do the
arithmetic.

The same shape made eleven sibling functions in `ov016` exact
(`func_021C2340`, `func_021C2590`, `func_021C3194`, `func_021C386C`,
`func_021C3DC8`, `func_021C41E0`, `func_021C4558`, `func_021C7D00`,
`func_021CA874`, `func_021CACA0`, `func_021CB0E4`, `func_021CDAC8`), which
differ only in the first argument passed to `func_021BD1D4`.

# A Thumb leaf's call site needs `thumb` on the symbols line, not the ARM name default

summary: when a `symbols:` block is silent, match.py reads a `func_0xADDR`
name as ARM; an unlabelled Thumb leaf (disasm never traces it because it saves
no `lr`) then fails every code class that checks ISA and the call stays
wildcarded, so declaring the true ISA is the whole fix.

Found in: src/matched/func_021EE520.c (0x021EE520),
src/matched/func_02210408.c (0x02210408),
src/matched/func_021F513C.c (0x021F513C)

The ARM9 contains many leaf functions that save no `lr`; `disasm.py` only
auto-labels a prologue that saves `lr`, so those leaves print as `.word` runs
and get no `func_` label.  A caller in an overlay that branches to one sees a
perfectly ordinary call, but because the callee has no traced label the
`label` and `sole-ref/code` classes cannot fire, and if no source was written
for it there is no `matched` entry either.

What makes this recoverable is that many of these leaves are already matched
and present in a shard: the address has an EXACT entry, compiled `-thumb`
because the shard records the truth.  `attest_matched()` refuses an entry whose
ISA differs from the source's declaration, and with no `symbols:` line the
harness infers `arm` from the `func_0xADDR` name convention.  So the verdict is
`MATCH` with "no witness outside ..." even though the witness exists.

The fix is one symbols line:

```c
 * symbols:
 *   func_0202616C  0x0202616C  thumb
```

after which the BL resolves as `matched` (or `sole-ref/code` for a leaf that is
labelled but has no other caller) and the function goes `EXACT`.  This is worth
trying first on any `MATCH` whose blocker is a `func_` call: `0202616C`,
`02021ED8`, `0200F7C0` all resolved this way, each unblocking several files.
The same tell applies to functions in an overlay with several overlapping
labels: adding the `ovNNN` token beside the ISA picks the one meant, e.g.
`func_021FC610  0x021FC610  thumb  ov135`.

# A `code` token in a `symbols:` line silently refuses the relocation

summary: the third field of a `symbols:` line is the declared kind and must be
`thumb`, `arm` or `data`; `code` is not recognised, so `read_header()` ends the
`symbols:` block there and every later relocation reports "not in the symbols:
block" and caps at `MATCH` however correct the C is.

Found in: `src/pending/func_02704BE0.c` (0x02704BE0) and the whole
pkt_0270xxxx twl packet, 2026-09-27.

A `symbols:` line's third field is the *declared kind*, and the only accepted
spellings are `thumb`, `arm` and `data` (`declared_symbols()` raises
`bad symbol kind` otherwise). It is easy to write `code` by analogy with the
`kind` column of a disassembly or with the `region` prose, and the failure is
quiet in the worst way: `read_header()`'s `SYMBOL_RE` only matches
`(thumb|arm|data)`, so a line with `code` is not recognised as a symbol line at
all. That single misspelt line *ends the `symbols:` block*, and every symbol
line after it is silently dropped — the file then reports every later
relocation as "not in the symbols: block" and caps at `MATCH` however correct
the C is.

The tell is a relocation that fails with

    no address for 'NAME': not in the symbols: block, not an address-bearing
    name, not in layout/symbols_sdk.json

even though the header plainly lists `NAME`. Fix the token to `arm`/`thumb`/
`data` and the same file resolves and can reach `EXACT`.

Related traps seen in the same twl packet:

* A TWL callee's fourth token is the region `twl`, not the ISA: the ISA is the
  third token. `func_X 0x027..... arm twl` is right; `func_X 0x027..... code
  twl` is not, and `func_X 0x027..... twl a2` (region then alignment, no kind)
  is a `bad symbols:` line.
* An ARM target is declared `arm`, never `code`. `match.py` cross-checks the
  declared ISA against the image and raises an explicit `ISA conflict` when the
  two disagree, but only *after* the name resolves; a `code` token never gets
  that far.
* A TWL address that is also an EXACT-matched neighbour becomes attestable by
  the `matched` class the moment the neighbour is filed, even though the
  `label` class still refuses it for having no outside caller. Several twl
  files that were parked at `MATCH` on a `func_02700xxxx`/`func_02701xxxx`
  callee went `EXACT` with no C change once that callee's shard landed — so
  re-run `match.py one` on a parked `MATCH` after each promotion wave before
  assuming a blocker is permanent.

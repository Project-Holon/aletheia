# Wave 19: sole-ref/code over the twl listing

Implements the recommendation of `rule_study_twl_witness.md`.

## Change

`tools/match.py` gains `attest_sole_ref_twl_code(addr, kind, region_hint)`,
tried as the last fallback in `attest_sole_ref()` after the overlay
`sole-ref/code` rule. It accepts a code site whose `symbols:` line carries the
`twl` token when the address lies inside the `twl` window of
`layout/layout.json` and is exactly a `func_` label in `asm/twl/twl.s` with
the declared ISA. No outside branch is required, which separates it from
`attest_twl_label()`. The listing path is now the module constant
`TWL_LISTING`, so the selftest can point it at a missing file. The class list
comment in `match.py` and the evidence-class section of `docs/MATCHING.md`
describe the rule and state that the twl listing is derived from a decrypted
region `delink.py` verifies before writing it (key SHA-1, BLZ stream fully
consumed, clear tail byte-identical).

## Selftest

192 cases, 0 failures (183 before, 9 new):

- accepted: 0x027300F0 and 0x0272FEF4, `arm`, `twl`, compared range
  0x0206DC00..0x0206DDA4, through `attest()`, subkind `code`;
- refused: interior 0x027300F4, pool word 0x027300EC, `thumb` declared, no
  hint, an `ov093` hint, the ARM9 address 0x0206DBF4 with `twl`, and no
  `twl.s` (listing path pointed at a missing file, label cache dropped).

With no key the positive cases run on an injected label table, as the
existing twl `label` cases do.

## func_0206DC00

`match.py one` in a fresh process: EXACT under `../2.0/sp2 -O4,p`, 14 of 14
relocations resolved, both TWL sites as `sole-ref x1`. Moved to
`src/matched/`, header status EXACT, packet line set to `pkt_0206DC00`.
`manifest --verify --shard pkt_0206DC00` twice: 1 rewritten, then 0
rewritten; the entry records `evidence: sole-ref code:0x0272FEF4,
code:0x027300F0`.

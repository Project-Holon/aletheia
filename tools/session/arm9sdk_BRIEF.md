# ARM9 SDK lane brief

Read `docs/LANES.md` and `docs/AGENT-BRIEF.md` first. This overrides them where
they differ.

## Your work

Your packet is one entry in `tools/session/arm9sdk_packets.json`. Its `list`
gives, per function: `addr`, `size`, `name` (the catalog's SDK symbol), `lib`
and `object`. Work **only** those addresses.

Order: smallest `size` first, so easy wins bank early; group consecutive
functions that share an `object` so the member is extracted once.

## Method

1. `python tools/match.py show --addr 0xADDR --region arm9` — resolves the ISA
   and shows the extent. Trust this over the catalog for ISA.
2. Extract the archive member into a scratch dir **outside the repo** (use the
   system temp dir): the member is `object`, inside the `.a` named `lib` under
   `sdk/` (e.g. `sdk/TwlSDK/lib/ARM9-TS/Rom/libos.TWL.HYB.a`). Cache it per
   member; the same object backs many of your functions.
   `tools/gcc-arm/xpack-arm-none-eabi-gcc-14.2.1-1.1/bin/arm-none-eabi-ar` to
   extract, `.../arm-none-eabi-objdump` to read it.
3. Read the member's DWARF: `--dwarf=info` gives the real arity, parameter and
   local types and their register/home locations; `--dwarf=decodedline` maps
   every instruction to its source line. Never open, read or copy the vendor
   source files the DWARF names; cite file:line metadata only.
   **Trust the DWARF, not the catalog name** — `layout/symbols_sdk.txt` has
   known bad rows. If the catalog name disagrees with the member's symbol at
   that offset, say so in your report and use the DWARF's.
4. Write C reproducing the bytes. Configuration is always the same for this
   pool: compiler `dsi/1.1p1`, flags `-O4,p`, lang `c99`, and the ISA from
   step 1.
   When the DWARF subprogram has **no `DW_TAG_variable` children** (only
   formals or none at all), the SDK original is hand-written assembly, and an
   `asm void` body is the correct and expected form. Others in
   `src/matched/arm9_sdk/` show the style.

## Files

Write `src/matched/arm9_sdk/func_XXXXXXXX.c` for an EXACT match, or
`src/pending/arm9_sdk/func_XXXXXXXX.c` for anything else. The C function is
named `func_XXXXXXXX` (address-based, so no two lanes can collide); cite the
SDK symbol in the header and in a `symbols:` block.

House header, all fields:

    /*
     * function: func_XXXXXXXX
     * address:  0xXXXXXXXX
     * packet:   pkt_XXXXXXXX
     * region:   arm9
     * compiler: 1.1p1
     * flags:    -O4,p
     * lang:     c99
     * isa:      arm
     * status:   <the verdict match.py actually gave>
     */

Never write `EXACT` on a file that is not EXACT.

## Verify

    python tools/match.py one --src <file> --func func_XXXXXXXX \
        --addr 0xXXXXXXXX --cc 1.1p1 --<arm|thumb> --region arm9 --flags=-O4,p

Iterate to `EXACT` or `EXACT*`. Otherwise leave the file in
`src/pending/arm9_sdk/` with `status: MATCH` and move on. Then:

    python tools/match.py manifest --verify --shard pkt_XXXXXXXX

## Rules

- Only your lane's addresses. Never touch `tools/`, `layout/`,
  `docs/MATCHING.md`, or another lane's files. Never delete anything.
- Scratch goes in the system temp dir, never the repo.
- No `git add`, `git commit`, `git push`.
- Report per function: address, verdict, bytes, and the evidence line. Note
  any catalog/DWARF name disagreements.

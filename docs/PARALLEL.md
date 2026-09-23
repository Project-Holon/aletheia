# Parallel decompilation

A packet agent should start at `docs/AGENT-BRIEF.md`; come here only when the brief does not answer the question.

Matching functions one at a time is serial only because the tooling was
serial. The addresses are not: `arm9_main` is 5369 functions, and once the
SDK territory is fenced off the remaining game code splits cleanly into
disjoint address runs that separate agents can work on without ever reading
each other's output.

`tools/worklist.py` draws that map. `layout/worklist.json` is the map.

## The territory

Every function in the region falls into exactly one class.

| class | meaning | who touches it |
| --- | --- | --- |
| `sdk` | the address carries an SDK symbol recovered by `tools/libmatch.py` | nobody; these arrive from hybrid library linking and are not decompilation targets |
| `runtime` | the address is listed in `layout/runtime_arm9.txt`, the mwccarm/MSL runtime helper library identified by wave 18B and linked in as hand-written assembly | nobody; not decompilable C, excluded from the open pool and the coverage denominator exactly like `sdk` |
| `matched` | covered by an entry in a `layout/matched/` shard | nobody; read only, already proved |
| `open` | everything else | one agent at a time, through a packet |

Only `open` functions end up inside packets, so a packet never contains an
address another agent or the linker already owns.

One exception to the `sdk > matched` precedence is worth knowing about.
`libmatch.py` marks a short library function with no sibling evidence as weak
(the trailing `?` column in `layout/symbols_sdk.txt`). When `match.py` has
since proved that the bytes at such an address are game code, the proof wins
and the function is classified `matched`, with the overruled library name
kept in `sdk_conflict`. The summary counts these; a rising count means
`symbols_sdk.txt` is shadowing game code and should be re-run with a stricter
threshold.

## Packets

A packet is a contiguous run of open functions. Breaks are forced where the
territory itself breaks:

- an `sdk` or `matched` function sitting between two open functions,
- more than `0x200` bytes of non-code between one function's last instruction
  and the next function's label,
- the packet reaching 30 functions or 3072 bytes of code, whichever comes
  first.

The last rule keeps a normal packet inside the 20 to 40 function and 2 to
4 KB band that one agent can carry in context. The first two rules dominate
in practice, so the sizes are bimodal: a large block of packets sits at the
size cap and a long tail of small fragments sits between SDK functions. A
fragment is a real unit of work, not a defect in the split.

Packet ids are derived from the start address (`pkt_0209CE10`) and are
stable across refreshes.

## Fields

```
id                     pkt_<start address>, stable
status                 "open" | "claimed:<agent>" | "done" | "blocked"
start, end             address range the packet owns; end is the last
                       function's extent, which is the next function label
                       anywhere in the listing
code_end               where the packet's last instruction stops; the gap
                       between code_end and end is trailing data
units, files           translation units the packet spans
function_count         functions in the packet
code_bytes             instruction bytes, the number that drives coverage
extent_bytes           end - start
isa                    "arm", "thumb" or "mixed"
data_adjacent_count    functions with a data run of 0x100 bytes or more
                       immediately before them or immediately after their
                       code; a planner should expect literal pools and
                       tables rather than clean function boundaries there
sdk_calls              SDK function names this packet's code branches to or
                       holds pointers to; the header set the C will need
external_callers       distinct functions outside the packet that branch
                       into it
external_pointer_refs  distinct functions outside the packet that hold a
                       pointer to one of its entry points
entry_points           the packet's functions that anything outside it
                       reaches; the ones whose signatures are load bearing
functions[]            addr, end, size, code, isa, unit, data_adjacent
```

The top-level `summary` carries the counts and the coverage percentage,
computed as matched code bytes over game (matched plus open) code bytes. SDK
bytes are excluded from the denominator: they are not work.

## The concurrency contract

An agent working `pkt_0209CE10` writes exactly three kinds of file, and
nothing else in the tree:

| what | where | who else touches it |
| --- | --- | --- |
| its C sources | `src/matched/*.c`, for addresses inside its packet | nobody |
| its manifest shard | `layout/matched/arm9/pkt_0209CE10.json` | nobody |
| idiom notes | `docs/idioms/<short-slug>.md`, one file per finding | nobody |

Every one of those is per packet, so two agents running at the same time
cannot produce a conflicting write. What an agent must **not** touch: another
packet's addresses, another shard, `layout/worklist.json`,
`docs/MATCHING.md`, `layout/function_starts.txt`, or anything under `asm/`,
the rest of `layout/`, or `tools/`. Those are the integrator's, and all of
them are regenerated or reviewed once per wave.

Two consequences are worth spelling out.

* **Shared prose is not a shared file.** Compiler idioms used to live in one
  section of `docs/MATCHING.md`, which made that document the second
  serialisation point after the manifest. An idiom is now one file under
  `docs/idioms/`, and `docs/MATCHING.md` carries only a generated index of
  that directory. An agent adds a file; nobody merges prose.
* **A shard id outlives its packet.** `worklist.py --refresh` dissolves a
  packet once its functions stop being open, but
  `layout/matched/arm9/pkt_0209CE10.json` keeps its name for ever, because it
  is the record of that work rather than a view of the live worklist. The id
  comes from a `packet:` line in each source file's header, so it never moves
  when the worklist changes.

## Workflow

**Orchestrator.** Reads `layout/worklist.json`, picks packets that are
`open`, and writes `claimed:<agent>` into their `status` before dispatching.
The file is emitted one packet per line with sorted keys, so two claims
written in parallel conflict only when they touch the same packet. Nothing
else in the file is the orchestrator's to edit; `worklist.py --refresh`
rewrites every derived field on the next pass.

**Agent.** Works only inside its packet's address range. It writes C into
`src/matched/`, putting its packet id in each file's header:

```c
/*
 * unit:     yes
 * address:  0x0209D728
 * packet:   pkt_0209CE10
 * ...
 */
```

That one line is what routes the entry into the agent's own shard; without it
the entry lands in `arm9/legacy.json`, which is a shared file and defeats the
point. Verification is local:

```
python tools/match.py show --addr 0x0209D728
python tools/match.py one --src src/matched/sub_0209D728.c \
    --func sub_0209D728 --addr 0x0209D728 --cc 1.1p1
python tools/match.py manifest --verify --shard pkt_0209CE10
```

The last of those is the agent's gate. It recompiles every entry of that one
shard, records the verdict each one actually gets, and writes that one file.
It reads the other shards, because the symbol map is drawn from all of them,
and writes none of them. The `sdk_calls` and `entry_points` hints in the
packet are there so the agent does not have to re-derive the packet's
interface from the listing before writing the first line.

Anything an agent learns about the compiler that cost it time goes into a new
`docs/idioms/<slug>.md`. `docs/idioms/README.md` has the format the index
generator expects.

**Integrator.** Once per wave, with no agent running:

```
python tools/match.py manifest --verify     # every shard, live verdicts
python tools/match.py selftest              # the attestation rules
python tools/match.py idioms                # regenerate the MATCHING.md index
python tools/build.py --split --pack        # the chain, byte for byte
python tools/worklist.py --refresh          # matched functions leave the pool
```

`manifest --verify` rewrites only the shards whose entries changed, so a wave
that landed three packets produces a three-file diff and the merge is a
directory union rather than a hand edit. `--refresh` dissolves packets that
shrank or whose functions changed class, reports them by name, and drops their
status rather than silently carrying a claim onto different territory. Every
other packet, claim included, survives untouched.

The integrator is also the only one who may add to
`layout/function_starts.txt` or rerun `tools/disasm.py`, because both change
the listings every agent reads.

## Commands

```
python tools/worklist.py              build layout/worklist.json
python tools/worklist.py --refresh    recompute, preserving claims
python tools/worklist.py --check      would a refresh change anything?
python tools/worklist.py --summary    coverage numbers
python tools/worklist.py --packet pkt_0209CE10
python tools/worklist.py --force      rebuild, discarding every status
```

The manifest side of the same wave:

```
python tools/match.py manifest --verify               verify and write all shards
python tools/match.py manifest --verify --shard ID    one shard, for an agent
python tools/match.py idioms                          regenerate the idiom index
python tools/match.py selftest                        the attestation rules
python tools/match.py tu --src ... --addr ... --suggest-split
                                                      where to cut a MATCH unit
```

When a range comes out `MATCH` with every concrete byte right, run
`--suggest-split` before doing anything else. It prints, per unresolved site,
how many witnesses the address has image wide and how many of them are inside
the range, and then the cuts that would leave every site a witness outside. A
site whose only witness is the call inside the function that needs it cannot
be cut free at all, and the report says so; that is the point at which the
function is left out and the rest of the range matched. See "Where to cut a
file" in `docs/MATCHING.md`.

`--refresh` is idempotent: running it twice in a row produces the same file.
The merge rule it implements is documented in full at the top of
`tools/worklist.py`.

### Tooling

`tools/fileanchors.py` harvests every `__FILE__` literal-pool anchor across
the ARM9 static image and all 237 overlays: a pool word a traced instruction
actually loads (`disasm.py`'s own `Region.pools`, not a guess from a raw
byte scan) whose value points at a NUL-terminated, all-printable string
ending in `.c` or `.cpp`. Each hit is recorded as its pool site address, the
nearest preceding function address, the region, the string's own address
and the file name, written to `layout/file_anchors.txt` in the same
addresses-and-names-only style as `layout/symbols_sdk.txt`. A full image
scan found 1022 anchors (272 in arm9_main, the rest spread thinly across
105 overlays), close to the 1018 a previous manual pass counted. `--summary`
prints counts per region and `--lookup ADDR` finds the nearest anchor at or
below an address in the same region. `worklist.py --targets` now prefers
the nearest anchor inside an open function's own packet over the older
nearby-matched-neighbour subsystem guess (a compiler-emitted attestation
beats a proximity heuristic), and `--packet` lists every anchor that falls
inside the packet's range.

`disasm.py` emits instructions the assembler cannot round-trip losslessly
as `.inst`/`.inst.n`/`.inst.w`, with the real mnemonic and operands kept
only in the trailing comment; a text scan of the mnemonic column alone
therefore misses every one of them silently. The listing bytes are
unchanged (`build.py --split --pack --no-c` still reassembles 242/242
byte-identically), but every directory of listings now also gets an
`inst_index.txt` alongside it: address, mnemonic and operands for each raw
line, gitignored with the rest of `asm/`. `disasm.scan_mnemonics(region)` is
the reader: it merges a region's ordinary listing text with its
`inst_index.txt` and yields `(addr, mnemonic, operands)` for every
instruction, raw-encoded or not, so a caller never has to special-case
`.inst` lines itself.

A function that is nothing but a pool-word load and a `bx`
(`ldr rX, [pc, #n]; bx rX; .word target`) is a tail call no `bl`/`b` scan
ever sees, because the call to it is a branch but the forward to its real
target is not
(docs/idioms/tail-call-is-a-pool-word-and-bx.md). `worklist.py` now scans
every arm9_main/arm9_itcm translation unit and all 237 overlay listings for
this exact two-instruction shape and records the inventory in
`layout/worklist.json`'s `thunks` field, printed (capped, with a pointer to
the full list) by `--summary`. The shape turns out to be a common compiler
idiom throughout the image, not limited to the half-dozen archive-id
forwarders `docs/notes/a_1_6_9_and_a_1_6_8_no_reader.c.txt` found by hand:
a full image scan found 470 thunks (292 distinct targets, 46 of them
currently open arm9_main functions). `--targets`' fan-in score now adds a
thunk's own callers to its target's count, so a function only reachable
through a forwarding stub is no longer scored as if it had none.

`match.py`'s relocation resolver only ever encoded an ARM caller's `bl` as
a same-ISA B/BL displacement, so an ARM function's direct call into a Thumb
callee (a legal interworking `blx #immediate`, e.g. 0x02091180 calling the
Thumb SVC stub at 0x02004490) stayed wildcarded and the compiler's plain
`bl` opcode byte differed from the image's `blx`, a concrete unmasked byte
outside the displacement field. `_encode_arm_branch()` now encodes
BLX(immediate) when the target is Thumb (the unconditional `1111 101H`
form, with the extra low bit of the halfword-granular displacement folded
into bit 24): verified against the real site, which reproduces the image's
0xFAFDCCC2 exactly. Three new selftest cases cover it (`python tools/match.py
selftest`, 59 cases at the time this landed).

`tools/datascan.py` audits the other direction: not whether a matched range
is really game code, but whether disasm.py's data runs in arm9_main are
really data. It rebuilds the region exactly as a real run would (same
`Analyser`, same `index_hidden_pool_words`), then re-tests every byte disasm.py
did not classify CODE against the same prologue-plus-return shape the
prologue sweep uses, ignoring why the byte is not CODE: a run a PC-relative
load claimed for an unrelated pool word can hide a real prologue the sweep
never got a chance to test, because the sweep skips anything already not
`UNK`. Pure pointer tables (every aligned word an address inside NDS main
RAM) and pure strings are excluded first; everything else is tested for an
ARM `stmfd sp!, {..., lr}`/`str lr, [sp, #-4]!`, a Thumb `push {..., lr}`, or
(only when something outside already points at the address, a bl/blx target
or a pool word's value) a no-push Thumb leaf ending in `bx lr` within 64
bytes. A hit is STRONG evidence only when a call site or a pool word points
at it and it is not itself a pool-reserved address elsewhere (which would
make it data wearing a prologue's clothes); everything else is WEAK. A full
scan of arm9_main found 81 candidates, 78 of them strong (1370 bytes, all
no-push leaves already witnessed by a call or a pool word, none yet in
`layout/function_starts.txt`) and 3 weak (192 bytes, decodable but
unwitnessed); no ARM- or Thumb-pushed candidate turned up at all. Output goes
to `layout/datascan_report.txt` (addresses and sizes only). Cross-checked
against the two known bugs in `docs/HANDOFF.md` section 6: the
`0x02010B84`/`0x02010D84` pool sites are `UNK`, never claimed by
`region.pools`, which is why they print as anonymous `.word`s (the
pool-word index misses them because nothing ever calls `_reserve_pool` on
them, not because they decode as Thumb); the mcss.c range
`0x02014D2C..0x020155A0` carries exactly the three `func_` labels
(`0x02014D2C`, `0x02014D90`, `0x02015590`) HANDOFF's tail-call-label bug
predicts. Against the 393066-byte game-code denominator
(`tools/worklist.py --summary`), the strong candidates are 0.35% and the
weak ones another 0.05%: not nothing, but nowhere near enough hidden code to
call the denominator materially wrong.

`attest_string()`'s `_printable_run_backward()` stopped a preceding run at
any byte below 0x20, so a format string ending in `\n` immediately before
the candidate (`"!![%x][%x]\n"` at 0x020A7E40, right before `"gf_standard.c"`
at 0x020A7E4C) measured a zero-length predecessor and refused to attest.
`\t`, `\n` and `\r` are now admitted inside a run (never as its terminator,
which stays NUL). `src/pending/func_0203EF5C.c` reattested EXACT and moved
to `src/matched/func_0203EF5C.c`, with its manifest entry added to
`pkt_0203EF5C`.

`disasm.py`'s literal-pool index only ever grew from a PC-relative load the
tracer actually decoded, so a pool word used exclusively by code the tracer
never reaches (a switch's case bodies after an `add pc, rN` it cannot
follow, or a leaf function with no `lr`-saving prologue tucked in the
`.word` run after another function's ordinary return) stayed an anonymous
`.word`, unusable as a `literal` witness even though the load instruction
is real. `index_hidden_pool_words()` does a second, narrowly-scoped pass
over such runs (tied to a known owning function by walking back through
any already-reserved pool words to real CODE, decoded in that owner's own
ISA) and adds any PC-relative load's target to `region.pools` when the
target is itself still unclassified and its value reads back as a pointer
into a loaded region; it never marks bytes CODE, so reassembly is
unaffected (`build.py --split --pack` stays 242/242). This recovered the
pool word at 0x02020EF4 (`item_gfx_member`'s second, previously invisible
copy, still inside `src/pending/unit_02020E60.c`'s own compared range so
it stays MATCH) and at 0x02061C3C (`func_02061B5C`'s second copy, outside
`src/matched/sub_02061C0C.c`'s own range, promoted to EXACT*). Finding real
evidence for a linker veneer's own address this way (two genuine `ldr
rX, [pc, #4]; bx rX` accessors that call through 0x02072788) also exposed
that `attest()`'s existing class order already ranks `literal` ahead of
`veneer`; the two veneer selftest cases that test range-exclusion now go
through `attest_veneer()` directly rather than `attest()`, since that
address is no longer a clean example of only having veneer-class evidence.

`compare()` claimed EXACT from literal byte equality on the whole buffer
alone, without checking that `fb.mask` was entirely hard first. A relocation
site that stays wildcarded because `resolve_relocations()` found no witness
can still be byte-equal to the image by plain coincidence (`sub_02049800`'s
call to `func_0204982C`, the first byte past its own extent, has its PC24
field pinned by adjacency rather than by any evidence class), and that used
to read as EXACT. `compare()` now additionally requires `all(fb.mask)`
before returning EXACT; a wildcarded byte that happens to match is capped
at MATCH, matching the verdicts table at the top of the file. `manifest
--verify` demoted exactly one entry image-wide, `sub_02049800` in
`pkt_0204968C`; it moved to `src/pending/sub_02049800.c` with the blocking
witness (0x0204982C, one caller, at the extent boundary) named in its
header, and its manifest entry was dropped. Two consecutive
`manifest --verify` runs afterward are byte-identical (0 rewritten both
times).

`tools/procscan.py` classifies every ARM function's return in arm9_main and
all 237 overlays into one of five epilogue shapes (`disasm.scan_mnemonics`
for the instructions, function labels in the listings for boundaries) to
surface a second known-`-proc arm7tdmi` translation unit's tell
(`pop {..., lr}` then `bx lr`, see
`docs/idioms/an-arm-epilogue-of-pop-lr-then-bx-names-a-proc-arm7tdmi-unit.md`)
before an agent burns a session discovering it function by function.
`layout/units_arm9.json` turned out to be a fixed 180-function listing-chunk
split, not real mwcc translation-unit boundaries (the known arm7tdmi library
at 0x0205429C..0x020584E0 shares its 180-function chunk with roughly 130
unrelated, arm946e-compiled functions either side of it), so the real
per-TU grouping is recovered instead as maximal address-contiguous runs of
functions that agree on hard evidence, never bridging a listing-chunk
boundary and requiring at least three same-signal non-leaf functions before
a run is trusted over the pinned default (one hand-written low-level
`stmdb`/`bx lr` routine turned up alone in an otherwise all-Thumb chunk and
is not a unit). The census is written to `layout/proc_hints.txt`
(addresses and epilogue-class counts only) with a row per recovered unit,
per overlay, and per still-open work packet, and cross-checked against
every EXACT match already on file under the default flags: all 13 arm9
units with real non-leaf EXACT evidence classify arm946e, and the one
EXACT match that falls inside the arm7tdmi-classified range is itself a
leaf function (`func_02058380`, which the idiom doc already notes matches
under either `-proc`), not a contradiction. Two units come back arm7tdmi
image-wide: the known 0x020524C8..0x020585DC library (containing the
0x0205429C..0x020584E0 range the idiom doc names) and the mwccarm/MSL
runtime helper library at 0x0209A524..0x0209D728 (wave 18B,
`docs/notes/pkt_0209BDBC_runtime_library.c.txt`), which is hand-written
assembly rather than a second mwcc-compiled arm7tdmi source file but
legitimately shares the same two-instruction return shape. No overlay
comes back non-arm946e. `tools/worklist.py --targets` and `--packet` now
read `layout/proc_hints.txt` (optional; both work fine without it) and
print the packet's inferred proc whenever it is not arm946e, so an agent
opening a packet in that range sees the right `-proc` before its first
compile instead of after a run of DIFFs.

`match.py` has a `runtime` witness class alongside `label`/`veneer`/
`literal`/`string`/`matched`/`local`: a `bl`/`blx` target listed in
`layout/runtime_arm9.txt` (the MSL/runtime.a soft-float and 64-bit integer
routines mwccarm links in) attests directly from that curated table, the
same evidentiary standing `symbols_sdk.json` gives an SDK symbol, with no
`func_` label or outside call needed. It closed `src/pending/sub_02018E34.c`
(now `src/matched/`, `pkt_02018DB4`), whose three calls to `_ll_shl` were the
only Thumb BL/BLX sites anywhere in the image that reach it, so `label`
could never have carried them regardless of a label.

The `label` class's overlay branch (`attest_overlay_label()`) now resolves
which of several address-overlapping overlays a cross-region `bl`/`blx`
means, instead of silently taking the first candidate whose listing happens
to carry a label: a fourth token on a `symbols:` line names the overlay
(`func_021D21C0  0x021D21C0  thumb  ov021`), and without one, more than one
labelled candidate is refused rather than guessed at. The three
`field_sound_system.c` pending files stay `MATCH`-capped even so: their
common callee at `0x021D21C0` sits in a span `disasm.py`'s per-overlay
tracer scored as a literal pool (nothing inside that overlay's own listing
branches to it, only ARM9 does), so none of its three candidate overlays
carries a `func_` label there at all; `manifest --verify`'s per-site report
now names the candidate overlays so this reads as a labelling gap rather
than a silent `MATCH`.

Overlay data map for `sole-ref/data` (2026-09-23): `overlay_data_structure()`
reads each overlay's own listing once, lazily, into code addresses, data
addresses, object starts (data labels and the first datum of every
`.word`/`.byte` run after code, `.byte` addresses taken from the preceding
`.org`), traced extents and the values of its `pool_` words. A `data` site
into an overlay attests when the chosen overlay (symbols-line hint, else the
overlay the function under test lives in, else the unique candidate) holds
data at an object start there, with a pool referrer outside the compared
range counting as a start; the overlay `sole-ref/self` rule carries a
single-pool table the way the ARM9 one does, reading the site's ROM word from
the region under comparison.

`sole-ref/code` for overlay labels (2026-09-23): a call into an overlay
address that exactly one chosen overlay's listing labels `func_` with the
declared ISA attests as `sole-ref/code` without an outside branch, which is
the shape of every ARM9 wrapper whose overlay callee has no other caller
(`sub_0200F734` into ov009 `0x02156460`). `attest_overlay_label()` still
refuses it as `label`; the new rule runs only after every stronger class.

matched-overlay (2026-09-23): the `matched` class already read every shard,
overlay directories included, but ignored the region. An entry in
`layout/matched/ovNNN/` now attests only when that overlay is the one meant
(hint, the caller's own overlay, or no other overlapping overlay labelling or
matching the address); ARM9 entries keep the old rule unchanged. The selftest
covers each rule with positive and negative cases (157 cases).

## Pokemon White is planned

A second build target (Pokemon White, IRAO) is planned for this tree; see
docs/ROADMAP.md. For packet agents this means: all addresses you write in
symbols: blocks and shards are addresses in the Black image; do not invent
schema fields that assume a single version; and when a function or table
smells version-specific (a version flag, an exclusive-species table), say so
in the source file header.

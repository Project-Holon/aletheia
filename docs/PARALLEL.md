# Parallel decompilation

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

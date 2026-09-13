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
| `matched` | covered by a `layout/matched.json` entry | nobody; read only, already proved |
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

## Workflow

**Orchestrator.** Reads `layout/worklist.json`, picks packets that are
`open`, and writes `claimed:<agent>` into their `status` before dispatching.
The file is emitted one packet per line with sorted keys, so two claims
written in parallel conflict only when they touch the same packet. Nothing
else in the file is the orchestrator's to edit; `worklist.py --refresh`
rewrites every derived field on the next pass.

**Agent.** Works only inside its packet's address range. It writes C into
`src/matched/`, verifies locally with

```
python tools/match.py show --addr 0x0209D728
python tools/match.py one --src src/matched/sub_0209D728.c \
    --func sub_0209D728 --addr 0x0209D728 --cc 1.1p1
```

and reports the entries it wants added to the manifest. The `sdk_calls` and
`entry_points` hints are there so the agent does not have to re-derive the
packet's interface from the listing before writing the first line.

An agent never edits another packet's addresses, and never edits
`layout/matched.json` concurrently: see below.

**Integrator.** Once per wave, merges the agents' proposed manifest entries
into `layout/matched.json`, runs the full chain (`tools/match.py manifest
--verify`, then the build), and then runs

```
python tools/worklist.py --refresh
```

so the newly matched functions leave the open pool. Packets that shrank or
whose functions changed class are dissolved and reported by name, and their
status is dropped rather than silently carried onto different territory.
Every other packet, claim included, survives the refresh untouched.

`layout/matched.json` is a single file today, so manifest writes are the one
genuinely serial step in a wave. Sharding it (one manifest fragment per
packet, concatenated by a tool at verify time) is the planned follow-up that
would remove the last serialisation point; until then the integrator owns the
file and agents propose entries rather than writing them.

## Commands

```
python tools/worklist.py              build layout/worklist.json
python tools/worklist.py --refresh    recompute, preserving claims
python tools/worklist.py --check      would a refresh change anything?
python tools/worklist.py --summary    coverage numbers
python tools/worklist.py --packet pkt_0209CE10
python tools/worklist.py --force      rebuild, discarding every status
```

`--refresh` is idempotent: running it twice in a row produces the same file.
The merge rule it implements is documented in full at the top of
`tools/worklist.py`.

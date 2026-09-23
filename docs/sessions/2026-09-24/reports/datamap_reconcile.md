# datamap reconcile: layout/data_objects.txt against a fresh tools/datamap.py run

Scope: tools/datamap.py and layout/data_objects.txt. Nothing installed; the committed file, layout/worklist.json and every shard touched are back at their HEAD content.

## 1. Classification

The committed derived section was last regenerated at 57c7d9d (2026-09-21). datamap.py's scanning logic has not changed since then (bdbbb9f only added the hand-section carry-over). A fresh run into a scratch file gives 1474 derived rows against 1506 committed. The hand-declared section comes out byte-identical.

| class | rows | meaning |
|---|---|---|
| unchanged | 470 | identical line |
| (a) referrer unit renamed only | 1004 | same address, same kind; every pool-word site the committed row cites is still a pool word with that value in the current listings. Only the unit names changed (for example 024_020730DC no longer exists as a listing file after the seed round 9/10 boundary moves), and so did the order of the six sites shown |
| (b) dropped | 32 | 29 `pool`, 3 `string` |
| (c) added | 0 | none |
| (d) evidence changed | 0 | none beyond the renames in (a) |

A textual diff files the 1004 renamed rows under (d), because the six sites shown before `(+N more)` are a different six. Compared by site address, they all belong in (a).

## 2. Dropped rows: stale, not a generator bug

Every dropped address now lies inside a traced function in the current ARM9 listings. That is why datamap.py's `in_code` filter removes them, and it is right to.

- The 29 `pool` rows: every cited pool word still exists with the same value. Each target (with the Thumb bit cleared for the 9 odd addresses) is now a `func_` label, so these words are function pointers and not data objects. The listings changed legitimately: the stale-split-file fix and the unit-boundary moves turned these starts into traced code.
- The 3 `string` rows (0x0200D290, 0x0202034A, 0x02026D58): the bytes are now instructions inside functions 0x0200D288, 0x0202032C and 0x02026D48.

Stale rows and the sources that name the address. No `symbols:` line anywhere in src/ declares one of them as `data`: every citation is a function reference.

| address | kind | citing sources |
|---|---|---|
| 0x0200D290 | string | none |
| 0x0200EC15 | pool (Thumb fn) | func_0200EBD0.c, func_0200EC14.c, unit_0200ECB4.c |
| 0x02020325 | pool (Thumb fn) | unit_02020268.c |
| 0x0202034A | string | none |
| 0x02026D58 | string | none |
| 0x02029FD1, 0x02029FE5 | pool (Thumb fn) | func_02029F6C.c, func_02029FD0.c, func_02029FE4.c |
| 0x0202AB5D | pool (Thumb fn) | func_0202AB5C.c, func_0202B544.c, func_0202B7BC.c |
| 0x0202B90D | pool (Thumb fn) | func_0202B544.c, func_0202B7EC.c, func_0202B8F4.c, func_0202B90C.c, func_0202BB40.c |
| 0x0202BB41 | pool (Thumb fn) | func_0202B7EC.c, func_0202B90C.c, func_0202BAF4.c, func_0202BB40.c |
| 0x0202F769, 0x0202F775 | pool (Thumb fn) | func_0202F768.c, func_0202F774.c, sub_0200545C.c |
| 0x020394C0 | pool (ARM fn) | func_020394C0.c, func_0203D4D0.c, func_0203D56C.c |
| 0x0203B018, 0x0203B01C | pool (ARM fn) | func_0203AFCC.c, func_0203B038.c, func_0203B390.c, func_0203B5D4.c, func_0203BA98.c, unit_0203B018.c |
| 0x0203B1B0 | pool (ARM fn) | func_0203B1B0.c, func_0203D010.c |
| 0x0203BFF0 | pool (ARM fn) | func_0203CF04.c, unit_0203BF9C.c |
| 0x0203C8E8 | pool (ARM fn) | func_0203D798.c, func_0203D7B0.c, func_0203D7BC.c, unit_0203C8A8.c |
| 0x0203DC4C | pool (ARM fn) | func_0203D8F0.c, func_0203DC4C.c, func_0203DC70.c |
| 0x02040804 | pool (ARM fn) | unit_020407E8.c |
| 0x0204BE38 | pool (ARM fn) | func_0204B0F4.c, func_0204BE38.c, func_0204C2C8.c, sub_0204B0C8.c |
| 0x02061644 | pool (ARM fn) | func_020613D8.c, func_020614D4.c, func_02061644.c |
| 0x02061B5C | pool (ARM fn) | func_02061B2C.c, func_02061B5C.c, sub_02061C0C.c |
| 0x0206DBF4 | pool (ARM fn) | func_0206DBF4.c, src/pending/func_0206DC00.c |
| 0x02073BE0 | pool (ARM fn) | func_020738C0.c, func_02073BB0.c, func_02073BE0.c |
| 0x020746C4, 0x020746D0, 0x020746DC | pool (ARM fn) | func_02074048.c, func_020746C4.c, func_020746D0.c, func_020746DC.c |
| 0x02076050 | pool (ARM fn) | func_02075FCC.c, func_02076050.c, func_02076B80.c, func_020773C4.c |
| 0x0209455C | pool (ARM fn) | func_0209455C.c |
| 0x020946D8 | pool (ARM fn) | func_020946D8.c, func_02095AA4.c, func_02095EAC.c, func_02095F40.c, func_020963F8.c |
| 0x020979BC | pool (ARM fn) | func_0209AB80.c, unit_02098B44.c |

All paths are under src/matched/ unless marked otherwise. No generator fix is needed, and datamap.py is unchanged.

## 3. Added rows

There are none. In their place I spot-checked ten random rows from class (a): in each one, the first site the regenerated row cites is a `.word <addr>` under a `pool_<site>:` label in the named unit listing (10/10).

## 4. Figure effect

The reconciled file is the fresh output with the hand section carried over verbatim. Other lanes committed while I was measuring (6e5cf61, 009b9d8), so the only clean comparison is back to back on the same tree: `worklist --refresh` then `--summary`, first with the committed file, then with the reconciled one.

- Both runs: 4389 matched, 386876 code bytes, 96.6451 percent, and sole-ref by sub-kind data 13 fn, code 63, string 7, self 155. Identical.
- The 17 shards whose JSON mentions a dropped address, verified with `manifest --verify --shard` under both files: 69 entries, identical verdicts, and no verdict changes.
- A baseline drift that is not caused by the map: under the COMMITTED file, `--verify` rewrites pkt_0204BE38 (drops its `sole-ref: code:0x0204C2C8` evidence) and pkt_02094488 (EXACT* to EXACT). This comes from the uncommitted tools/match.py in the working tree. Both files were restored.

Why the figures cannot move: match.py's sole-ref/data rule requires `in_data_section(addr)` before it looks at the map, and every dropped address is code. disasm.py reads only `range` rows, which are in the unchanged hand section.

## 5. Recommendation

Install the reconciled file as it is. None of the 32 stale rows is used as data evidence by any matched or pending file, so none of them needs to be kept while citing files are fixed. The unit renames bring the referrer names back in line with the current listing files. Scratch copy: the session scratchpad, dmrec/reconciled.txt. The equivalent is `python tools/datamap.py` on the current tree.

Process note: the session scratchpad is shared between lanes (another lane overwrote a shards.txt of mine midway). Lanes should use a subdirectory of their own.

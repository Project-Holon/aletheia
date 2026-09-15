# A unit attests only its own start address, not every function inside it

summary: the manifest records one entry per unit at the unit's start address,
so folding a labelled function into the middle of a `tu` file deletes its
manifest entry and drops any other file that depended on it as a `matched`
witness from EXACT back to MATCH; split the unit at the address someone else
needs.

Found in: `src/matched/unit_02030C44.c` and `src/matched/sub_02030BD4.c`
(0x02030BD4-0x02030CB0), witnessing `src/matched/unit_02030DA8.c`

Consolidating a clean run of `EXACT` functions into one `tu` file is the
preferred shape, but it is not free: the manifest records one entry per unit
at the unit's **start** address (plus any unlabelled followers the extent
walk discovered). A labelled function in the middle of a unit gets no entry
of its own, so it stops being an address the `matched` evidence class can
attest, and any other file whose only witness for that address was the
manifest entry drops back from `EXACT` to `MATCH`.

## The tell

The consolidation verifies `EXACT` and the shard rewrite looks healthy, but
its entry list is shorter than the function list you just folded in, and the
missing addresses are exactly the labelled interior functions:

```
shard pkt_02030BD4: 3 entr(ies)          shard pkt_02030BD4: 2 entr(ies)
  0x02030BD4  sub_02030BD4     EXACT       0x02030BD4  unit_02030BD4  EXACT
  0x02030C44  unit_02030C44    EXACT       0x02030C68  unit_02030C68  EXACT
  0x02030C68  unit_02030C68    EXACT
```

Some other file then reports the interior address as unresolved on its next
run, with no change to its own C:

```
+0034 PC24 sub_02030C44 -> unresolved: 02030C44 has no witness outside ...
```

## Worked case

0x02030BD4, 0x02030C44 and 0x02030C68 are three functions of one packet: a
free-stack refill, an allocator and a release. All three are `EXACT`, none
holds a relocation, and folding them into `unit_02030BD4.c` reproduces the
packet's whole 220-byte range in one go. It is the better-looking file.

It is also the wrong one. 0x02030C44 has exactly one caller image-wide, the
call inside `sub_02030DC8`, so `unit_02030DA8.c` has no `label` witness for
it and no cut that frees it; its only route to `EXACT` is a `matched` entry
at 0x02030C44. Folding 0x02030C44 into a unit that starts at 0x02030BD4
deletes that entry and puts the neighbouring unit back to `MATCH`.

Split at the address someone else needs: `sub_02030BD4.c` on its own, and
`unit_02030C44.c` over 0x02030C44-0x02030CB0 (which still earns its unit
shape, since 0x02030C68 is an unlabelled follower and has no entry to lose).
All three entries come back and both units stay `EXACT`.

## Rule

Before folding a run into one unit, check whether any interior function is
the sole witness for a call site elsewhere. `--suggest-split` answers the
question in the other direction (which cuts *create* witnesses); this is the
same accounting run backwards, so read its per-site witness counts before
merging, not only before splitting. A function with one caller image-wide
that is not in your range must stay at the start of whatever file holds it.

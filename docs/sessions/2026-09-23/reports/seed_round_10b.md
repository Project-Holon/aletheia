# Seed round 10b: declared data objects in disasm.py, overlay hint check on sole-ref/self

1. data_objects.txt has two sections. Rows from the line `# hand-declared rows` to the end are kept verbatim by datamap.py, which regenerates only the section above. New kind `range`: `region start range end evidence`, hand rows only. The digest table is `arm9 0x020A8BE0 range 0x020A9E64`. disasm.py marks each declared range as data before any seed is traced. A seed into a range is refused and logged as a conflict, and the range start gets a `d_` label. match.py no longer lets a `range` or `table-guess` row replace an accepted row at the same start.
2. func_020A8FE6 is gone: unit 031 went from 22 to 21 functions (-44 code bytes), it is not in `worklist --targets 80`, and the split build passes. Wave 18 (319410d) committed first and already carries the -44 in its figure and its worklist.json.
3. Hint rule (self_hint_accepted): a contested overlay hint on a sole-ref/self site is accepted only if the function loads the hinted overlay through an `overlay_id` site. An uncontested hint needs nothing. resolve_relocations decides after the overlay_id pass. Selftest: 176 cases, 0 failures (8 new, 2 of them end to end on func_02010AC4: accepted, and refused once its ov115 id is changed to ov123's).
4. Verdicts (manifest --verify, run twice): pkt_0202F9F8, pkt_02010AC4 and pkt_02010BB8 (holds func_02010C34; there is no pkt_02010C34 shard) are all EXACT. Also EXACT: pkt_020120B4, pkt_02156B70, pkt_02167358.

FIGURES 95.12 95.22 4380 (no change against wave 18)

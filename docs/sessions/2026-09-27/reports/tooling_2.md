# tooling_2 (relaunch of tooling_1 flags)

## Salvaged (uncommitted from the cut run, re-verified)

- tools/match.py: `attest_sole_ref_data` blanket pass for 0x04xxxxxx and 0x02000000..0x02008000 replaced. I/O space accepts only a register start in `IO_REGS_ARM9` (curated from GBATEK DS/DSi I/O maps, cited in the comment) with a declared alignment no wider than the register. Unloaded low RAM accepts only an outside object start, a map row outside lo..hi, or a traced label. 7 new selftests. Selftest 231/231. Line endings LF, same as HEAD.
- tools/coveragemap.py: render_arm9 no longer recolours `open` as `matched`.

## Dry run (task 1)

Every shard entry citing an address in either range was listed. Sole-ref/data hits: 0x04004006, 0x04004308, 0x0400430C (twl/twl.json, 7 entries) and 0x04004202 (twl/twl_wifi.json, 12 entries); all are documented registers and pass at align 2. `manifest --verify --force` on both shards: 0 rewritten, all statuses unchanged. The only low-RAM citation (ov021 func_021D1C8C, code:0x02006DD8) is sole-ref/code, unaffected, still EXACT*. No entry loses EXACT: match.py kept.

## Maps (task 2)

Regenerated all three SVGs. Captions equal the tools: ARM9 400,674/400,674, 12.20 pts sole-ref, SDK 19,024 of 129,144, runtime 8,964 of 8,964 in #e0b020 (worklist --summary: 0 open now, the last 14-byte function landed during this run, so no open tiles to show). Overlays 373,060/1,902,770, SDK 82,520 of 473,226, 5407/26527 fns (ovstats). TWL map unchanged. Overlay and twl renderers did not share the fault.

## Flags

- tools/datamap.py rewrote layout/data_objects.txt (evidence input); reverted to HEAD, not a map.
- tools/ovstats.py line 251 prints matched function count as "overlay game code ... functions".
- Duplicate shard: func_021605C0 in ov010/pkt_021605C0.json and pkt_ov010_021605C0.json.

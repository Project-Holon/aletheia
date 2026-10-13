# Wave procedure (aletheia, session started 2026-09-20 22:54 CET)

Target: 50 percent ARM9 game-code coverage (worklist --summary). Start: 41.91 percent, 3143 functions, commit b120797.

## Per wave
1. Pick 3 open packets from `python3 tools/worklist.py --targets 40`: prefer <= 1200 code bytes, no
   `proc` hint, no existing src/pending file for the packet (those belong to the promotions agent), not
   already in assigned.txt. Small packets can be bundled two or three per agent.
2. Launch 3 `general-purpose` agents, model sonnet, in ONE message, run_in_background false. Each gets:
   the packet id(s), the standing brief (below), and asks for a <250-word report.
3. Every 3rd wave (3, 6, 9, ...) add a 4th agent: the promotions agent (brief below).
4. Fold-in, sequentially, after all agents return:
   - `git status --short` and make sure only src/matched, src/pending, layout/matched/<pkt>.json,
     docs/idioms, docs/notes changed. Anything else: inspect, revert if a worker overstepped.
   - For every touched shard: `bash $S/verify_one.sh <id>` (fresh process) and grep its .out for any
     verdict that is not EXACT/EXACT*. A non-EXACT file in src/matched gets moved to src/pending with
     its real status. Then re-verify.
   - `python3 tools/worklist.py --refresh`; read `--summary` coverage line.
   - Build + ROM: `python3 tools/build.py --split --pack | tail -3`, then ndsrom build --override
     build/pack, then ndsrom verify; require PASS + sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5.
   - README.md percent + function count; ALWAYS `python3 tools/coveragemap.py` (both SVGs) before every commit.
   - Commit (explicit paths; message: "wave N: <n> functions exact, coverage X percent";
     NO attribution trailer of any kind, owner rule 2026-09-21), push, read origin/main back.
5. Append the wave's result line to this file under Log.

## Standing packet-agent brief (paste)
Repo the repository root. Read docs/AGENT-BRIEF.md fully once (it is the manual). Work
ONLY the packet(s) named. Foreground commands only, no background loops. Never edit layout/worklist.json,
layout/units_*.json, layout/function_starts.txt, tools/, asm/. Do not commit. File EXACT/EXACT* in
src/matched, MATCH in src/pending with the blocking class in the header, DIFF as docs/notes/*.c.txt
only. Header status must be exactly the verdict match.py printed. End with
`python3 tools/match.py manifest --verify --shard <pkt>` and report its output. Report (<250 words):
per function address -> verdict, files written, blockers, unlabelled followers noticed.

## Promotions-agent brief (paste, every 3rd wave)
Same rules. Goal: turn src/pending files into EXACT without new C where possible. Procedure: for each
pending file with `status: MATCH` or `MATCH*` (start with the ones whose header note names an
unresolved site), re-run `match.py one`/`tu` in a fresh process; if it is now EXACT (a blocker landed),
git mv it to src/matched, set status, run manifest --verify --shard. If still MATCH, run
`--suggest-split` and, when a cut is offered, split the file accordingly. Budget: 30-40 files. Report
the promoted addresses and the shards touched.

## Assigned packets
(see assigned.txt)

## Log

## Rules added by the user after wave 1
- Agents run in background (run_in_background true); fold in as each returns; stay responsive.
- Commit + push after every wave before the next starts.
- New ground only: exclude any address in docs/notes or src/pending from packet-agent targets. Promotions agent is the only one that revisits pending.
- Commit message carries exact coverage AND reproduced coverage (pending_pct.py). README keeps exact only.
- User paused waves after wave 1 ("something is odd"); do not start a wave without their go-ahead.

## Log
- wave 1 (7bfc297): 0 exact; exact 41.9090, reproduced 49.0851. Targets were documented residue. Lesson recorded.
- user go-ahead 2026-09-20 ~23:40: run waves back to back without asking; if blocked, change approach. Targeting = landscape.py tiers (tier 2 coherent untouched packets for packet agents, tier 3 for the promotions agent every wave). All agents background.
- wave 2 launched: A pkt_0202363C, B pkt_02021B6C, C pkt_0202D7D8, P promotions (11 tier-3 files).
- user 2026-09-21 ~00:30: switch wave agents to model opus (Sonnet not worth the tokens).
- user 2026-09-21: commit subject/body must show each coverage figure with its increase over the previous commit in parentheses, e.g. "exact coverage 42.04 percent (+0.13)".
- clarified: the reproduced-coverage delta reports ONLY the change in the pending component, not the exact gain again. Format: "exact coverage X percent (+a); reproduced coverage Y percent (pending part +b)".
- wave 2 (814969e): 6 exact; exact 42.0407 (+0.1317), pending part 7.1914 (+0.0153). Wave 3 launched with opus.
- user asleep from ~00:45 2026-09-21: run waves continuously, commit+push after each, resume any failed subagent via SendMessage, honour the 02:10 and 07:20 wake-ups.
- wave 3 (bd26abb): 17 exact; exact 42.5358 (+0.4951), pending part 7.2747 (+0.0833). Wave 4 launched (opus).
- user 2026-09-21: the 4th (promotions/unblock) agent runs ONLY on every 3rd wave (6, 9, 12, ...). Waves 5, 7, 8, ... are 3 packet agents only. Wave 4 kept its P agent as a one-off.
- wave 4 (ae53c37): 11 exact; exact 42.8710 (+0.3352), pending part 7.4701 (+0.1954). Wave 5 launched (3 agents, opus). Unblock targets for wave 6 P: 0x020680DC (frees 0x02069818), 0x0206EE60 (frees 0x0206EB7C, 940 B), 0x02070524/0x02070624 (free 0x02070730 then 0x02070904), 0x02070A24 (frees 0x02070B64); kept-constants pin candidates 0x02072758, 0x02071EFC; pin pair 0x0206F214+0x0206F36C.
- wave 5 (4a56d1a): 5 exact; exact 42.9769 (+0.1059), pending part 7.4702 (+0.0001). Wave 6 launched (3 packet agents + P on unblock queue).
- wave 6 (1267b5b): 6 exact; exact 43.1456 (+0.1687), pending part 7.5123 (+0.0421). Wave 7 launched (3 agents). Wave 9 P queue: 0x02050550 (frees 0x020504D8), 0x020680DC (5 B off, frees 0x02069818), 0x02070A24 (frees 0x02070B64), 0x02070524+0x02070624 (free 0x02070730 then 0x02070904), 0x0206EE60 (frees 0x0206EB7C), 0x0206F214+0x0206F36C pair, 0x020731E0/0x02073D7C/0x02075858 (free 0x02072758), proposed kept-frame tell for 0x02068E78 (owner decision).
- wave 7 (4c132bf): 8 exact; exact 43.5574 (+0.4118), pending part 7.7277 (+0.2154). One agent declined the task (relaunched, fine). Wave 8 launched (3 agents). Add to wave 9 P queue: any second caller of 0x0208A054/0x02089378 (frees 0x020731E0 then 0x02072758), 0x02073624 (frees 0x02073344), 0x020522E4 (frees 0x02052274), another reader of 0x0209FB58 (frees 0x02025EA4).
- wave 8 (8811625): 9 exact; exact 43.8484 (+0.2910), pending part 7.7277 (+0.0000). Wave 9 launched (3 packet agents + P).
- wave 9 (e78d652): 8 exact + 1 promoted; exact 44.2834 (+0.4350), pending part 7.6729 (-0.0548). Wave 10 launched (3 agents, tier-2b bundles). Wave 12 P queue: 0x020506B8 then 0x02050550 (frees 0x020504D8), 0x020508BC (frees 0x02050894), 0x02073D7C+0x02075858 (free 0x02072758), 0x02020A58/0x02020B5C (free 0x02020CA0), 0x0202AFAC/FFC/B04C (free 0x0202AF74), 0x020680DC, 0x02070A24.
- SEED FILE ITEMS for the owner (layout/function_starts.txt is the integrator's; regenerate with disasm.py arm9 --split and confirm build 242/242 afterwards):
  wrong starts: 0x0202173C and 0x02021848 (worklist says 0x0202173E / 0x0202184A; real prologue is push {r0-r3} two bytes earlier)
  unlabelled followers reported this session: 0x02070BD8 (now filed), 0x02020780, 0x02069C00, 0x02071EAC, 0x02071EFC, 0x020724E4, 0x02072524, 0x02071180, 0x02071360, 0x020713A4, 0x0206A67C, 0x0203AD74, 0x0202CE40, 0x0202CF84, 0x0202CF8C, 0x0202CF98, 0x0202CFC0, 0x0202CFEC, 0x0202D018, 0x02028748, 0x02028754, 0x020235F0, 0x02021B18, 0x02021EE4
  padding halfwords (not code): 0x02025DE6, 0x02025EA2, 0x02025F5A, 0x0201FAC2, 0x0201FB2E, 0x0201FC1A, 0x020219C2, 0x02022002
- wave 10 (3719b54): 7 exact; exact 44.5373 (+0.2539), pending part 7.6960 (+0.0231). Wave 11 launched (3 agents, Thumb bundles).
- wave 11 (e6ac5e6): 16 exact; exact 45.0103 (+0.4730), pending part 7.7356 (+0.0396). Wave 12 launched (3 packet agents + P).
- wave 12 (76ed30d): 9 exact + 1 promoted; exact 45.4688 (+0.4585), pending part 7.8014 (+0.0658). Wave 13 launched (3 agents). Wave 15 P queue: 0x0202D3D0 (29 B off, frees 0x0202D760), 0x02020A58/B5C (frees 0x02020CA0), 0x0202AFAC/FFC/B04C (free 0x0202AF74), 0x02073DFC (4 B off, frees 0x02073D7C) + 0x02075858 (free 0x02072758), 0x02013C70 pending MATCH (frees 0x02014204), second caller for 0x02005328 sites.
- wave 13 (4ec2bfb): 17 exact; exact 45.9438 (+0.4750), pending part 7.9366 (+0.1352). Wave 14 launched (3 agents). Add to wave 15 P queue: 0x02027D44/0x02027E3C (free 0x02027974, 116 B), 0x02063294 (frees 0x0204BF40), 0x02022490 (frees 0x02022518 + 0x020225B4 cycle), 0x02073624 (frees 0x02073344).
- wave 14 (d6b9a6e): 12 exact + 1 promoted; exact 46.3864 (+0.4426), pending part 8.1212 (+0.1846). Wave 15 launched (3 packet agents + P).
- wave 15 (6e0f641): 8 exact + 1 promoted; exact 46.8881 (+0.5017), pending part 8.2528 (+0.1316). Wave 16 launched (3 agents). Wave 18 P queue: 0x02063294 (13 B off, frees 0x0204BF40), 0x02063378 (5 B), 0x0206419C (1 instr), 0x02020A58 (7 B, frees 0x02020CA0), 0x02073DFC (12 B rotation, frees 0x02073D7C), 0x02022490 (frees 0x02022518+0x020225B4), 0x02027D44/E3C (free 0x02027974), 0x02095EAC (1 instr), 0x02072374 (7 B), 0x02071C14 (13 B).
- 07:xx 2026-09-21: wave 16 agents died on the session rate limit (resets 07:00) and were resumed via SendMessage. New targeting tool prescreen.py (scratchpad): parses `match.py show`, asks match.attest() per call/pool site; only functions with every site attestable go to packet agents from wave 17 on. Wave 17 plan (attestable only):
  A thumb: 0x02020D5C 0x02024838 0x0202824C 0x0202D0D4 0x0202DAA4 0x02011B8C 0x020160D4
  B arm:   0x02067BA4 0x02047CFC 0x02051C88 0x0204F428 0x02070DDC
  C arm:   0x02048744 0x02057C9C 0x02068AE8 0x0204C060 0x02042B24
- wave 16 (d59892d): 4 exact; exact 47.1256 (+0.2375), pending part 8.3916 (+0.1388). Wave 17 launched from prescreen (attestable only).
- 07:5x: removed stale generated listing asm/arm9/src/014_02035284.s (older run, not in layout/units_arm9.json; it mislabelled 0x02035D20 as thumb and broke attestation). Regenerating asm via disasm.py arm9 --split would also fix it.
- wave 18 plan (prescreen attestable, corrected parser): A thumb 0x02010068 0x0202D4A8 0x02022AD0 0x0201761C; B arm 0x02091E48 0x020454E0 0x02067080 0x02068C84; C arm 0x02081E7C (MD5 transform, 796 B, standard algorithm) + 0x02053A60 (708 B, arm7tdmi hint: flags -O4,p -proc arm7tdmi); P near-miss closers <=7 B: 0x0206419C 0x02051C88 0x02095EAC 0x0201CD10 0x02020A58 0x02072374 0x02063378. Attestable untouched pool is nearly spent after this; later waves = near-miss closers + chain unblocks + larger attestable functions.
- wave 17 (e10664b): 8 exact, 0 new parks (prescreen); exact 47.4968 (+0.3712), pending part 8.4774 (+0.0858). Wave 18 launched.
- OWNER DECISIONS pending: (1) 0x02081E7C is SHA-1 in hand-written ARM (ROR sites, pool before entry); recommend adding to layout/runtime_arm9.txt (removes 796 B from the game denominator, bookkeeping). (2) 0x02053A60 mixes v4T epilogue with v5TE smulbb: neither -proc reproduces it; note docs/notes/pkt_02053A60.c.txt. (3) proposed "kept frame" tell for 0x02068E78 (2.0 pin) still awaiting a yes/no. (4) single-pool-word data attestation class: the pending pool (8.5 points) is mostly this.
- wave 18 (53c241a): 2 exact (both closer); exact 47.5811 (+0.0843), pending part 8.5344 (+0.0570). Yield falling; wave 19 = 2 agents (closer + one packet agent).
- wave 19 (b1335fb): 2 exact + 1 promoted; exact 47.7605 (+0.1794), pending part 8.5627 (+0.0283). Wave 20 launched: two closers.
- wave 20 (e328bd8): 0 exact. Loop PAUSED 09:2x 2026-09-21 pending owner decisions; yield curve: w11 16, w13 17, w14 12, w15 8, w16 4, w17 8, w18 2, w19 2, w20 0.
- 10:1x: seeded 52 followers/corrected entries into layout/function_starts.txt (backup in scratchpad), regenerated listings (242/242 PASS), full re-verify to fixed point: 9 EXACT*->EXACT, 2 transient CCERR restored after serial re-verify, 1 genuine MATCH demotion (0x020336B8, witness for 0x020336A4 gone). Denominator +1246 B (43 new open leaf rows).
- wave 21 plan: A thumb leaves 0x0200EC98..0x02022AC4 (14); B thumb leaves 0x020235F0..0x0202D018 (18); C arm leaves 0x020336A4..0x02071C94 (9); P: corrected entries 0x02091E44 (frees 0x02092004), 0x0202173C, 0x02021848 + big attestable thumb 0x0201183C (830), 0x02016C60 (870).
- reseed integration (717afcb). Wave 21 launched (3 leaf bundles + P).
- SEED FIX for next regen: remove 0x02025772 and 0x0202597A from layout/function_starts.txt (alignment padding; real functions at 0x02025774 / 0x0202597C already labelled).
- OWNER DECISION 2026-09-21 ~11:00: sole-ref evidence class approved (data word landing on a known object boundary in the data section, recorded per site in the shard, share reported separately in the coverage line). Implementer agent launched; permuter builder agent launched in parallel; wave 21 A still running.
- SEED FIXES for next regen: 0x0201049C -> 0x02010498 (leaf really starts 4 B earlier); add followers 0x0200ECB4, 0x02021F08; remove padding seeds 0x02025772, 0x0202597A.
- tooling commit f907a87 (sole-ref + permuter). Full sole-ref promotion pass running. Wave 22 launched: two closers with the permuter.
- wave 22 (1920671): 2 exact + 5 promoted; exact 48.1322 (+0.2511), pending part 8.3571 (-0.1696). Sole-ref full pass: 1 promotion (strict boundary rule; rodata tail unlabelled). Pending split: code-only 173 files/12.7 KB, rodata-only 58/4.6 KB, mixed 44/5.1 KB, other 66/3.5 KB. Wave 23 chain agent resumed after the noon reset.
- 13:2x: data-object map agent launched (tools/datamap.py -> layout/data_objects.txt, wired into sole-ref, measurement only). User rule: no new wave until the map is done. Wave 23 C still running; 23 A/B done (0 exact, 3 new parks).
- 2026-09-21 ~15:30: sole-ref widened (86d747a); promotion pass moved 199 parked files; exact 52.25 percent (4.14 points on sole-ref/code). 2.0 front-end measurement: 1.1p1 confirmed default (2.0 agrees on 68 percent of matched code, closes nothing). Wave 24 plan (prescreen under widened class): A thumb accessors 0x0202D064 0x0202D09C 0x0202D110 0x0202D144 0x0202D178 0x0202D1AC 0x0202D1E0 + 0x02028484 0x0202E560 0x0202368C; B thumb 0x0202055C 0x020200CC 0x0201FF30 0x0200FD38 0x0200FEBC; C arm 0x02036CA8 0x02065D4C 0x02048010 0x0203A150 0x02038AE0 0x02044D88.
- promotion (3e3e1b3): 204 promoted; exact 52.4370 (+4.3048), pending part 2.3914 (-6.1094). Wave 24 launched (3 opus).
- user out from ~16:15 2026-09-21: keep waves running back to back (3 opus, prescreen targets), commit+push after every wave, run promote_fast.py every third wave (after the P/closer waves), resume any crashed agent via SendMessage. Fold-in checklist unchanged: stale-shard check, verify touched shards, refresh, README, build+ROM, commit with both figures + deltas + sole-ref line, push.
- wave 24 folded: 11 exact; exact 52.7388 (+0.3018), pending part 2.4242 (+0.0328). Wave 25 plan (prescreen): A thumb 0x02027D44 0x02027E3C (free 0x02027974) 0x0200545C 0x0201A090 0x02026A60; B arm 0x020696F4 0x0206958C 0x02064754 0x02050C30 0x0204DACC; C arm 0x02038380 0x020385C4 0x0203174C 0x02037288 0x02037478. Promotion pass due on wave 27 fold-in.
- wave 24 (43c736c) pushed. Wave 25 launched (3 opus).
- wave 25 folded: 7 exact + 1 promoted; exact 53.4147 (+0.6759), pending part 2.4242 (+0.0000). Wave 26 plan: A thumb 0x0200F83C 0x020163C4 0x02016630; B arm 0x020698F8 0x02066E30 0x02044954; C arm 0x02065DB4 0x020691E0 0x0206ECE0. Wave 27 = promotion pass at fold-in.
- wave 25 (148bd02) pushed. Wave 26 launched (3 opus).
- wave 26 (dfd0036): 0 exact; promotion pass 0. Remaining parked: 18 non-label thumb sites + 9 overlay data words. Wave 27 launched (3 opus, big attestable).
- wave 27 (50f9e48): 1 exact (0x0202368C); 27C two size-exact DIFFs. exact 53.4674 (+0.0527), pending part 2.4242 (+0). Pushed. Owner: no Co-Authored-By trailers from now on.
- 2026-09-21 16:40: owner: no Co-Authored-By trailers ever; history rewrite of the 32 older commits blocked by classifier, owner to run filter-branch themselves. Compiler research: squiddonaut/pokeblack uses dsi/1.1 -O4,p, no pins; dsi/1.1..1.3p1 identical .text to 1.1p1. dsi/1.6sp1 == 1.6sp2, sweep over 10 pending DIFF + 5 note best-sources: nothing closes, two regress. Do not retry 1.6sp. Promotion 6ad0dcc (func_02086374 became EXACT under 1.1p1). tools/coveragemap.py + docs/coverage_map.svg in README (90667f7): regenerate at every fold-in. Wave 28 launched: A thumb 0x0200FD38 0x0200FEBC 0x0200545C; B thumb 0x0201FF30 0x0202055C 0x02026A60; C arm 0x02068AE8 0x02068C84 0x020713C8.
- 2026-09-21 17:05: history rewritten (filter-branch, force-with-lease): all Co-Authored-By trailers removed from the 36 commits since b120797; every hash quoted above this line is stale, origin/main is c56dbfe. Owner plan agreed: after wave 28, family waves (family = span between consecutive __FILE__ anchors), fixed order by matched-function count desc, a family keeps its slot until blocked or closed, cycle when exhausted, re-verify all family shards each wave.
- wave 28 (1d5772f): 3 exact (0x0201FF30, 0x020713C8, 0x02071510 pinned 2.0). exact 53.7570 (+0.2619), pending part 2.4242 (+0). Two coverage maps in README. Pushed. Next: family wave 1 (clact.c, field_sound_system.c, time_icon.c).
- 2026-09-21 ~17:50 family wave 1 results: field_sound_system.c BLOCKED (4 pending capped by lone-referrer rodata objects, 1 residue 4 B); time_icon.c 0 exact, 1 new MATCH (lone-referrer tag), 3 allocator residues, span is two files (icon module | heap allocator from 0x0202FB34) -> treated as BLOCKED; clact.c pending. Owner agreed: reorder by open bytes among anchored families with matched>=15 and >=35% (families_order2.txt, frozen). Lone-referrer cap count so far: 7 sites in 2 families (4 rodata, 1 tag string, 2 bss) -> owner decision pending. Note re-verification worker running (scratchpad/notecheck). Family wave 2 = mcss.c, bmp.c, bg_sys.c (clact.c keeps a 4th slot only if it reports STILL MOVING with an exact).
- family wave 1 (95cc38c): 0 exact, +1 MATCH; pending part 2.4395 (+0.0153). Family wave 2 launched: mcss.c, bmp.c, bg_sys.c + clact.c continuation (D224 at 2 bytes).
- family wave 2 (0f29cae): 7 exact. Promotion under sole-ref/self (43d1adb): 79 files, exact 55.6272 (+1.7155), pending part 0.7082. 25 pending files labelled MATCH are DIFF today (pending_verdicts.json); pending_pct.py now requires fresh verdicts. Tree clean, all pushed. STOPPED per owner: no wave 3 until the talk.
- owner 2026-09-21: agents must write their full report to scratchpad/reports/<name>.md and hand back ONE line only (chat noise).
- seed fix + 0x0202E09C via permuter (54c5846): exact 55.6698 (+0.0426). Open owner item: disasm.py label rule needs prologue check for the mcss merge. Permuter benchmark batch running (scratchpad/perm/bench).
- 2026-09-21 21:48 owner asleep: crons at 03:10 and 08:10; standing order: keep running permuter-armed family lanes, fold in + commit + push each wave, promote now and then, whatever strategy is appropriate. Family wave 3 (permuter-armed): gf_font 6 exact, net_handle 7, printsys 1, ica_anime 0, wipe_sub resumed after sleep. Benchmark run 4: 17 rows, 0 autonomous closes in-batch, 6 moved; tool-assisted closes today: 0x0202E09C, 0x02061DFC, 0x0200A21C.
- family wave 3 (b6a2d24): 28 exact, 56.7241 (+1.0543). Wave 4 running: game_beacon (2 exact, done), billboard_act, backup_system, net_system.
- family wave 4 first set (f6fe4a3): 13 exact, 57.2611 (+0.5370). Running: musical_dist_save, app_taskmenu. symbol_save done (0 exact).
- owner 2026-09-21 22:xx: lanes must NOT spawn subagents (Agent tool forbidden in every brief).
- family wave 4 second set (fd012cf): 4 exact, 57.4834 (+0.2223). Running: g3d_system, particle, btl_setup, net_state.
- wave 4 third set + mystery_data (d8ac2e8): 19 exact, 58.1627 (+0.6793). README map caption removed (owner). Running: pms_draw.
- wave 5 first set (be620e0): 8 exact, 58.3487 (+0.1860). Running: gf_standard, net_save; launching shinka_check, touchpanel, pmsi_param, wordset.
- wave 5 second set + promotion (fe0d88e): 15 exact, 58.6095. in_data_section halfword fix promoted 8. Running: shinka_check, touchpanel, pmsi_param; launched wave 6: field_status, net, save_control, blink_palanm.
- wave 5 third set (33534de): 5 exact, 58.8626. Running wave 6: field_status, net, save_control, blink_palanm.
- 03:0x wave 6 first set (7ca1406): 6 exact, 58.9686. Rate limit hit ~02:xx, reset 03:00; net.c + 2 bundles resumed. Seed candidates: 0x0203C8E8 0x0203BFF0 0x020394C0 0x0200AD6C.
- 03:3x pseudo-families built (scratchpad/pseudo_families.txt, 99 clusters). Wave 7 launched on the top 4 clusters with matched bases. Thumb bundle still running.
- wave 6 second set (1f0394f): 4 exact, 59.0434. Wave 7 (pseudo-families) running x4.
- wave 7 first set (54e841b): 11 exact, 59.3836; reproduced crossed 60. pkt_020737C0 is a 2.0 unit. Running: 7A pkt_02052F58, 7E pkt_02051E64, 7F pkt_0206A17C.
- wave 7 second set (6285908): 9 exact, 59.6910. Running: 7A pkt_02052F58, 7G pkt_020949F4, 7H pkt_02064B68.
- wave 7 third set (3f26f43): 7 exact, exact 60.21 (60 crossed). Running: 7I pkt_02096D10, 7J pkt_020929E8, 7K pkt_02063000.
- wave 7 fourth set (29da58e): 3 exact, 60.3150. Running: 7L pkt_02071360, 7M pkt_020640DC.
- wave 7 fifth set (9ed701f): 6 exact, 60.6982. Running: 7L pkt_02071360, 7N pkt_02061D0C, 7O pkt_020611D4.
- wave 7 sixth set (b2a798d): 9 exact, 61.0886. Running: 7O pkt_020611D4, 7Q pkt_0206AF08, 7R pkt_02074A34.
- wave 7 seventh set (d9775f2): 10 exact, 61.8161. 7R done (5 exact, next fold-in). Running: 7S, 7T, 7U bundles.
- wave 7 eighth set (1fa81b0): 7 exact, 62.1972. 7S done (4 exact, next fold-in). Running: 7T, 7V, 7W.
- 08:05 overnight summary written: scratchpad/reports/overnight_2026-09-22.md (55.67 -> 62.20 exact, 25 commits). Five lanes resumed after the 08:00 reset.
- wave 7 ninth set (7355f23): 5 exact, 62.4780. Running: 7V, 7X, 7Y.
- wave 7 tenth set (03019d2): filed, 62.4780 unchanged. Running: 7Y, 7Z, 7AA.
- wave 7 eleventh set (fb4b9c7): 11 exact, 62.6706. Running: 7AA (five-cluster bundle).
- wave 7 final set (df76914): 9 exact, 63.0702. Wave 7 total 92 exact. Running: pass2 poke_tool, bg_sys, bmp.
- pass2 poke_tool/bmp (9e49e95): 63.1127. Running: pass2 bg_sys. Launching pass2 clact, mcss.
- pass2 bg_sys (350cab3): 63.3904. Running: pass2 clact, mcss.
- pass2 printsys/wipe_sub/symbol_save + HANDOFF (3ba9dbf): 63.4893. Owner: no new waves. Running: pass2 clact, mcss; final fold-in on their return.
- final fold-in (573bb40): 63.8208 exact, 64.4924 reproduced. STOPPED per owner, no lanes running.
- 2026-09-22 owner: quota reset, resume lanes (opus); SDK question answered (denominator excludes 125774 B SDK + 20556 runtime; 33 conflicts to audit; no lib/ in sdk/). Wave 8 launched x5 on the largest remaining pseudo-family remainders (scratchpad/pseudo_remaining.txt).
- sdk class + promotion (6e6dce3): 63.8484. Audit: 16 seed candidates in reports/sdk_audit.md (apply between lanes); 13 genuine SDK conflicts (owner call). Wave 8 x5 running.
- wave 8 first set (deff685): 11 exact, 65.8526 (+2.00). Running: 8A, 8C, 8D, 8E.
- wave 8 second set (86c097f): 8 exact, 66.4223. 8E done (5). Running: 8A, 8D. Owner: no wave 9 until told.
- wave 8 final (1e58f62): 17 exact, 68.3619. Wave 8 total 36 exact. STOPPED: owner says no wave 9 until told. Queued: 16 seed candidates (reports/sdk_audit.md), 13 genuine-SDK conflicts (owner call), pseudo_remaining.txt for the next wave.
- seedfix2: 14 rows seeded, 11 pending -> EXACT (promotion in flight). HANDOFF a956e24 records the wave-8 strategy. Wave 9 launched x6.
- seedfix2 + promotion (d205a88): 13 exact; denominator 390384->394940 (bookkeeping -0.74); 67.6234. Wave 9 x6 running.
- wave 9 first set (51ec6fd): 7 exact, 68.2757. Running: 9A, 9B, 9C, 9E, 9F.
- wave 9 second set (5c2e674): 6 exact, 70.2537 (70 crossed). Running: 9B, 9C, 9E, 9F.
- wave 9 third set (77c1e63): 7 exact, 71.0103. Limit hit 22:50; 9B 9C 9E resumed 22:52. Owner: no new wave after 9; crons 04:03 and 09:03 armed.
- wave 9 fourth set (f8e5a33): 3 exact, 71.1612. Running: 9C, 9E.
- wave 9 final (d7cd2db): 0 exact. Wave 9 total 27 exact + 13 seed promotions; 71.1612. STOPPED: no new wave until told. Crons 04:03, 09:03 armed (fold-in only).
- 2026-09-22 ~23:3x wave 10 launched x10 (second/third lanes on large functions; two no-sibling clusters).
- 2026-09-22 23:4x owner: new waves APPROVED while asleep ("do start new waves"). Crons re-armed 01:03/04:03/07:03 (fold in + top up to ~10 lanes) and 09:03 (fold in + overnight report + HANDOFF numbers).
- 2026-09-22 ~23:5x wave 10 first set: cf59c48, 12 exact (A pkt_020929E8: qsort + __pformatter via unit member line fix; C pkt_020737C0: 6 targets + 4 leaves), 71.57 / 72.27.
  SEED QUEUE (apply between waves, needs disasm.py --split + build checks, do not run under lanes): 0x0209455C arm (qsort), 0x02073BE0 arm, 0x020746C4 arm, 0x020746D0 arm, 0x020746DC arm (all in worklist as extent, uncounted until seeded).
- 2026-09-22 23:5x OWNER RULE: no top-ups. Lanes K and L allowed as exception. Wave 11 starts only when all 12 wave-10 lanes are done. Crons re-armed with this rule.
- 2026-09-23 00:2x wave 10 second set: 2c5cb57, 12 exact (D pkt_0206A17C all 5 incl. NitroSystem G3D bind functions, owner: SDK-class question; F's 7 sharded early), 71.97 / 72.66.
- 2026-09-23 00:3x lane F done (7 exact, already in 2c5cb57); headers committed separately. SEED QUEUE add: 0x02061644 arm (follower of func_020614D4, turns its EXACT* into EXACT). Follow-ups: func_020625D8 (pkt_020625D8) two-symbol split g_02146BB0_blk + g_02146BB0 should also unstick src/pending/func_02062474.c (wave 11 item); permuter --extent option (tool item).
- 2026-09-23 00:5x wave 10 third set: 496b617, 7 exact (E: pkt_02063000 2 + pkt_02070360 5), 72.84 / 73.54. Lanes left: B G H I J K L.
- 2026-09-23 01:2x wave 10 fourth set: cd79cde, 25 exact (B 3, I 7 incl. NNS g2d Font/CharCanvas ids, J 4, K 3, L 2, H's 6 sharded early), 75.51 / 76.23. Only G (bmp) and H (clact/ica) still running. No new wave until both report.
- 2026-09-23 01:4x wave 10 final set: d5d9e09, 8 exact (G bmp.c). WAVE 10 TOTAL: 79 exact, 71.16 -> 76.56 exact, 71.86 -> 77.28 reproduced. All 12 lanes done.
- 2026-09-23 02:3x seed round 3: 88a5b35, 9 starts, denominator 394940 -> 395472, 5529 -> 5538 fns, 76.59 / 77.31. match.py timeout 180 -> 900 s (build.py -j default was tripping it; run --arm9-image with -j 4 in background). Wave 11 launched x10.
- 2026-09-23 03:5x usage limit cut all 10 wave-11 lanes (~02:4x); resumed after reset. 01:03 cron fired: nothing to do (wave 10 folded, wave 11 already launched).
- 2026-09-23 04:0x wave 11 lane E done: 0x02081E7C is TwlSDK libmath SHA-1 compression (not the game's MD5 transform, owner decision 2026-09-19 now moot); filed as a 796-byte CodeWarrior asm body, EXACT. HELD OUT of commits (src/matched/func_02081E7C.c + layout/matched/arm9/pkt_02081E7C.json untracked) pending OWNER CALL: accept asm-bodied SDK function as game coverage, or git rm it and move the 796 B to the SDK exclusion. Also OWNER/TOOL item: 8 disasm starts (0x02082F48/F90, 0x02083028/0C0, 0x02083250/298/334/3D0) are interiors of MI_CpuCopy (752 B) and MI_CpuMove (788 B); sdk class should cover a libmatch symbol's full size or the starts be dropped: removes 1188 B from the open pool.
- 2026-09-23 04:3x wave 11 first set: 9e418e0, 13 exact (D: MSL parse_format 0x020924DC; I: 12 poke_tool.c sharded early), 77.36 / 78.08. SHA-1 asm file moved to scratchpad/heldout/ pending owner call.
- 2026-09-23 05:0x wave 11 second set: e3ccd2e, 4 exact (B), 77.55 / 78.27. foldin.sh written (refresh+ROM+maps+sharded split).
- 2026-09-23 05:3x wave 11 third set: 4d517ab, 2 exact (A), 77.76 / 78.48. Lanes left: C F G H I J.
- 2026-09-23 06:0x wave 11 fourth set: 8b348db, 8 exact (F: NNS_G2dArrangeOBJ1D; H: bg_sys 5 + g3d_system 2), 78.79 / 79.51. Lanes left: C G I J.
  SEED QUEUE add (wave 11 H): 0x020407E8 arm (leaf sub_020407E8 in unit_020407E8.c, follower of sub_02040618 -> EXACT*), 0x02040804 arm (sibling leaf).
- 2026-09-23 06:3x wave 11 fifth set: 7d9848a, 3 exact (G: mcss quad drawer 0x020155A0 1064 B; I: backup_system 2, poke_tool fully closed earlier), 79.05 / 79.77. Lanes left: C J.
- 2026-09-23 06:5x wave 11 lane C done: 0 exact (pkt_0206EB00 three ties 14/2/8 unchanged; pkt_020682DC residues 159->119, 254->238, 313->168; notes already committed). Only J left.
- 2026-09-23 07:1x wave 11 final set: 92daa84, 10 exact (J: wipe_sub 6 incl. pending sub_02022AC4 promoted, printsys 4). WAVE 11 TOTAL: 41 exact, 76.59 -> 79.75 exact, 77.31 -> 80.47 reproduced. SEED QUEUE add: 0x0200D288 arm (leaf follower of func_0200D144). Seed round 4 next (0x020407E8, 0x02040804, 0x0200D288), then wave 12.
- 2026-09-23 07:3x wave 12 launched x10 (see assigned.txt). Seed round 4 (0x020407E8, 0x02040804) applied to function_starts + disasm; builds running in background; commit after they pass. 0x0200D288 NOT seeded (no matched source filed for it).
- 2026-09-23 08:0x seed round 4 + wave 12 first set: 02748fc, 15 exact sharded early (A 3 incl. 0x02067340/1024 and 0x020643CC; H 2; I 9 incl. app_taskmenu 4, symbol_save 4), 80.92 / 81.77. Whole-image build: split 5/5 PASS + ROM sha1 identical; one compile (func_0200421A.c, first TU) timed out at 900 s under 10-lane load, recheck between waves.
- 2026-09-23 08:2x wave 12 lanes I (10 exact: symbol_save 4, app_taskmenu 4, game_data 1, leaf 0x02008450) and H (2 exact: 0x02041FF4, 0x02044F64) done; all already in 02748fc. 80% CROSSED (80.92 exact).
  SEED QUEUE (round 5): 0x02008450 thumb (leaf, filed; pool-word witness at 0x02012BDC), 0x0200EC14 thumb (follower of func_0200EBD0), 0x0200E874 thumb + 0x0200E878 thumb (followers of func_0200E7BC).
- 2026-09-23 08:4x wave 12 lane A done: 3 exact (0x02066B84, 0x02067340, 0x020643CC), all in 02748fc; 0x02067080 still open.
  OWNER FLAG (independence rule): lane A reports it took the function SHAPES for the g2d functions from the public NitroSystem decompilation (github.com/ntrtwl/NitroSystem, rev 21c8fd0), i.e. SDK library code, not the game. Owner said 2026-09-20 "dont copy from the project i still want this to be independent" (about pokeblack). Files are in 02748fc (0x02066B84, 0x02067340, 0x020643CC). Owner call: keep (SDK library reference, like the TwlSDK docs site) or rewrite. Future briefs: state the rule explicitly.
- 2026-09-23 09:0x wave 12 second set: 2c24721, 29 exact (E billboard 8, G net 7, F game_beacon+pms_draw 16, D backup_system 2), 82.96 / 83.80. Lanes left: B C J.
- 2026-09-23 09:2x OWNER: max 8 agents per wave from wave 13 on; NitroSDK decomp cross-reference allowed. Limit cut B C J at ~08:4x; resumed. 2c24721 missed its files (quoting slip), fixed in 70ecace.
- 2026-09-23 09:5x wave 12 third set: 9971411, 7 exact newly sharded (B's 2 were in 70ecace; J sharding early), 83.13 / 83.97. Lanes left: C J.
- 2026-09-23 10:1x wave 12 fourth set: 006aa60, 2 exact (J: 0x02062688 + pending 0x02062B30 promoted), 83.66 / 84.50. Only C (mcss) left.
- 2026-09-23 10:5x OWNER DECISIONS applied: d51f3f6. SHA-1 -> symbols_sdk.txt; worklist sdk_interior rule (12 labels); 13 files -> src/calib (sdk_calibration in their packet shards). Denominator 395520 -> 392516. 84.08 / 84.93.
- 2026-09-23 10:2x wave 12 lane C done: 0 exact (mcss residues 4 still DIFF). WAVE 12 TOTAL: 54 exact, 79.75 -> 84.08 (incl. denominator change). All lanes done.
- 2026-09-23 10:3x seed round 5 applied (11 rows, all covered by matched sources; 0x02050080 skipped, no file); builds in background. Wave 13 launched x8.
- 2026-09-23 10:4x OWNER: wave 13 is the LAST wave. After it: fold in, seed round if any, full HANDOFF update (numbers, decisions, lessons waves 10-13, remaining, how to continue). No wave 14.
- 2026-09-23 11:0x seed round 5: 24d8b7c, denominator 392516 -> 392810, 5551 fns, 84.10 / 84.92. Split build 5/5 + ROM identical; whole-image -j4 again 'timed out' on the first TU although it compiles alone in 0.75 s: build.py parallel wine start-up artefact, -j 1 rerun in background.
- 2026-09-23 11:1x five wave-13 lanes (A D F G H) stalled on the stream watchdog (600 s no progress) around 11:0x; resumed via SendMessage.
- 2026-09-23 11:3x wave 13 first set: ca2b4ae, 20 exact sharded (F: particle/poke_tool/pokegra/arc_tool/game_beacon 8, plus others' early shards), 84.98 / 85.80.
- 2026-09-23 11:4x wave 13 lanes F (8) and H (12) done, all in ca2b4ae. Lanes left: A B C D E G.
  SEED QUEUE (round 6, after wave 13): 0x0201A468 thumb (leaf after func_0201A3F4, tail-calls 0x02045EC0), 0x0201A48C/0x0201A4A0/0x0201A4B4 thumb (same-run tail-call leaves) — only if files exist; ov010 0x02167394 is an overlay target (evidence item, not arm9 seed).
  OWNER ASK: HANDOFF must explain the project, the wave workflow, evidence rules, tools, what works and what does not.
  SEED QUEUE add (H): 0x02076050 arm (follower of func_02075FCC, already EXACT), 0x0206DBF4 arm (12-byte leaf inside func_0206DBDC's extent; unblocks one site of pending func_0206DC00).
- 2026-09-23 12:0x wave 13 second set: 0875cab, 9 exact sharded (D backup/areaman/key 2 + others' early shards), 85.48 / 86.30. Lanes left: A B C E G.
- 2026-09-23 12:1x wave 13 lane B done (7 exact, all sharded into 0875cab). Lanes left: A C E G. Worklist item from D: pkt_020360B8 cut as 68 code bytes but is one 412-byte function (stale label 0x020360B8+68?): check between waves.
  SEED QUEUE add (B): thumb 0x02020268 0x02020298 0x020202EC 0x020202FC 0x02020314 0x02020324 0x02020344 0x02020350 (all inside unit_02020268.c); REMOVE seed 0x020202CC (bogus, function_starts line ~387).
- 2026-09-23 12:3x wave 13 third set: b3f8e19 (amended), 10 exact (G NitroSystem residues), 86.51 / 87.33. Lanes left: A C E.
- 2026-09-23 12:5x whole-image build -j 1: 242/242 PASS, whole ARM9 image PASS (the -j 4 'timeouts' were a parallel wine start-up artefact; use -j 1 for this check).
- 2026-09-23 13:0x wave 13 fourth set: 93d1ae1, lane A net families 11 exact. Lanes left: C E.
  TOOL ITEM (A): disasm.py prints the literal pools 0x02010B84..97 and 0x02010D84..97 as Thumb instructions so the pool-word index misses them (blocks two MATCH parks in net_save). Stale 'blocker' line in src/matched/func_0200F7B8.c.
- 2026-09-23 13:2x wave 13 lane C done (6 exact, all in 93d1ae1); headers committed. SEED QUEUE add: 0x0200D288 thumb (file exists now). Only E left.
- 2026-09-23 13:4x wave 13 final set: 5a0632f, lane E 4 exact. WAVE 13 TOTAL: 60 exact. All 8 lanes done. Seed round 6 next, then HANDOFF.
- 2026-09-23 14:0x seed round 6: 7c2177b. Skipped (no files): 0x0201A468/48C/4A0/4B4, 0x0206DBF4.

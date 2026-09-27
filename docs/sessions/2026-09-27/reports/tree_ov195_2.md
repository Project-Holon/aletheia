# tree_ov195_2 report

Tree: ov195 root func_022040E0, continued from tree_ov195 (about 75 open). This lane took 36 functions bottom up. Root not attempted.

EXACT, filed (33), each shard verified twice (second pass 0 rewritten), shards pkt_<addr> in layout/matched/ov195/:
fade: 022081A4 0220826C(u) 0220827C 022082DC 022083EC 02208430 022067BC; quads: 02207510 02208478 0220851C 022076A0 02206604 02206664 0220672C(u) 0220602C; particles/anim: 022086C8 0220871C 022089A4 0220878C 02208A48(u) 02208C10(u) 02208C18(u) 02208C28(u) 02208C30(u); scene: 02206274 02206108 02205C74 022063E0 0220685C 02206264(u) 0220623C 02204C24.
Levers: forwarded second argument left live in r1 (02208430, 0220826C takes (p, x)); ternary clamp for re-truncation (022082DC); `x * 0xFFFFFFFF` (022081A4); const FX_SinCosTable_ (022063E0); per-arm boolean calls (02204C24); FX_F32_TO_FX32 macro; counter bumped in body (0220685C, new idiom file).

MATCH (src/pending): 02208AB0 (0x0204784C unlabelled arm9 leaf), 0220887C (0x02051B04 unlabelled arm9 leaf). All other bytes right.
DIFF (src/pending): 02208570, one 2-byte residue (third vertex z loaded ldrsh+truncate); notes in docs/notes/pkt_02208570.c.txt.

Next lane's list: root 022040E0; 02205D50 (732, needs arm9 seeds 0x02015F50, 0x0201600C, 0x02015EE8); 02206A5C (976); 02206E2C (1764); 02207868 (2340 real state machine, 0220818C is its bl-tail); 02208570 residue.

Seeds: 0x0204784C arm (site 0x02208B3E), 0x02051B04 arm (site 0x02208954); ov195 EXACT unlabelled 0x0220826C 0x0220672C 0x02206264 0x02208A48 0x02208C10 0x02208C18 0x02208C28 0x02208C30.

Integrator: runtime_arm9.txt and docs/notes/pkt_0209BDBC_runtime_library.c.txt swap the float add/subtract names. By structure (same-sign path) and by call sites, 0x0209C95C is add (mwcc `_fadd`) and 0x0209CB8C is subtract (`_fsub`). Regenerate the idiom index. Permuter seeds used: 7301-7304.

# tree_ov208_4 (ov208)

## Tree

Parent root 0x021C3D3C (1372 B, a ten-state proc) and the roots 0x021C625C and 0x021C7860 are now EXACT. 0x021BF9B0 was mapped but not started, because the lane's context budget ran out. The near-miss redrafts (53F4, D634, 5CF0, 4F78) were not attempted.

## New EXACT (3; each shard verified twice, second pass 0 rewritten)

- 021C3D3C: the draft was byte-exact except for stack slots in states 6 and 7. Two changes closed it. First, state 6's all-stopped flag is its own local (`settled`), separate from the `done` of states 3/4, declared `done, settled, ready, idle`. Second, state 7's test is a nested `if (W(0x6b0) == 2) { if (f() == 0) ready = 1; } else ready = 1;`, which produces the image's branch-to-next.
- 021C625C (1132 B, graphics init plus a 4 x 0x28 entry table at 0x5F4): the element address is written base-first, `*(u32 *)(p + i * 4 + 0x5e4)`. The two 8-byte cell headers are one array, `hdr[2]`, because the image addresses sp+0x64 as sp+0x5c+8. The first `func_0204AC18` call takes 3 as its second argument; I had misread it as 0. The rodata table data_021C87A0 attests as sole-ref.
- 021C7860 (1160 B, soft float): the index is written as `idx = 0; if (W(0x124) == 0) idx = 1;` because both ternary spellings give the opposite polarity. In the mode-6 arms, `x = q; x += 0.5f;` keeps `_fadd(q, k)` (existing idiom). Stack locals are declared in the order they are used.

Files: src/matched/ov/ov208_func_021C3D3C.c, _021C625C.c, _021C7860.c; shards layout/matched/ov208/pkt_ov208_021C3D3C.json, _021C625C.json, _021C7860.json. `manifest --check` is clean. There is no new idiom file: every lever was already indexed.

## Next lane

1. 021BF9B0 (1112 B), a proc with the same shape as 3D3C (10 states, jump table). Its open ov208 callees are 021C0090 (164), 021C0134 (656), 021C0450 (212), 021C0544 (348), 021C0714 (44), 021C0788 (272), 021C08E8 (104), 021C0A8C (132), 021C0B10 (72), 021C0C50 (60), 021C0C8C (52), 021C10B8 (920), 021C1810 (272), 021C1AD4 (568), 021C23BC (116), 021C2458 (76), 021C24A4 (76), 021C24F0 (60), 021C252C (52). The root can be matched before its callees, as 3D3C was.
2. Fresh drafts of 021C53F4 (20 B), 021BD634 (8 B), 021C5CF0 (19 B), 021C4F78 (18 B).

## Integrator

- ov208 symbol lines need the `ov208` region token. Without it, 0x021BE844 is refused as ARM, because ov016 labels that address.
- No permuter seeds were used.

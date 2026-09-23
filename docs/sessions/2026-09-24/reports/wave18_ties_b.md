# Wave 18 lane ties_b (18F)

Per address, bytes out before -> after, verdict, what moved it:

- 0x020246C8: 1 -> 0, EXACT. Fail tail written out in the flag arm (`ok = 0; *p = 0x6A1; goto done;`). New idiom: a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.
- 0x02013528: 6 -> 0, EXACT. u16 heap-id stack parameter plus u16 in three callee prototypes (existing u16 idiom).
- 0x02025360: 21 -> 0, EXACT. Scan bound written `j < i + len`; permuter anneal seed 2101 (existing loop-bound idiom).
- 0x0202271C: 9 -> 0, EXACT under 1.1p1. Two extern names at 0x020A73D0 (same reading as func_02023F98). New idiom: a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.
- 0x0204B49C: 20 (76/80) -> 0, EXACT. `value += origin.x` compound add on the s16 parameter. New idiom: a-compound-add-to-a-narrow-parameter-keeps-the-sum-in-its-home-register.
- 0x0200E0BC: 9 -> 0, EXACT. Enum counter and enum result, `i < (u32)IDX_MAX` (existing enum idiom).
- Followers 0x020141E0 (EXACT*), 0x020141F0, 0x0200AD7C, 0x0200AD8C (EXACT*), 0x0200AD94 (EXACT*): written and filed.
- 0x0209128C: still 1 under 1.1p1. EXACT under ../2.0/sp2, ../2.0/base, ../1.2/sp4 and ../1.2/base (kept `movne`). Not filed: the pin rule needs a kept-branch tell. Needs an integrator ruling.
- Unchanged, notes appended: 0x0201DB20 15, 0x0204EEC8 58, 0x02071104 6, 0x02069BA0 6, 0x02034D60 5, 0x0201D768 66, 0x0202350C 12, 0x0209D7D4 43, 0x02011688 26, 0x0201C7D0 2 (sp2) / 37, 0x020111BC 3.

Files: src/matched/func_{020141E0,020141F0,0200AD7C,0200AD8C,0200AD94,020246C8,02013528,02025360,0202271C,0200E0BC}.c, src/matched/sub_0204B49C.c. Three idioms. Notes for every address in scope.

Shards verified twice (0 rewritten on the second pass): pkt_020141E0, pkt_020141F0, pkt_0200AD7C, pkt_0200AD8C, pkt_0200AD94, pkt_020245D4, pkt_02013528, pkt_02025360, pkt_0202271C, pkt_0204B454, pkt_0200E0BC. The five follower shards, pkt_020245D4 and func_020246C8 are already in commit 319410d.

Seeds: none new.

For the integrator: rule on 0x0209128C. The u16 heap lever may also fit 0x0201B2B0.

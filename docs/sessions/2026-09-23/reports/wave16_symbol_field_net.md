# Wave 16, symbol/field/net lane (7 families, 18 addresses)

EXACT 7 of the lane's addresses plus 1 witness leaf. MATCH 7 (evidence walls, parked). DIFF 1. Already promoted by the integrator after 16A's overlay leaves: 4.
- blink_palanm: EXACT* 0x0202ED00 (copy through dst/src = dst + 1, flag test `(t + 1)[n]` so only the n*0x28 product is shared). EXACT 0x0202EB9C under 1.1p1, no pin (notify call written in both arms of the count test; the cross-jump moves off the two func_0202ED00 calls and the register rotation goes with it).
- time_icon: EXACT 0x0202F1B4 (not an allocator tie: no gotos, every case written out, case 2's guard with the call run in both arms) plus EXACT 0x0202F47C (unlabelled 12-byte leaf, its witness, same shard). MATCH 0x0202F9F8: d_021B68D8 now resolves with an ov179 token; only the overlay ids 0x58/0xB3 remain. DIFF 0x0202FB34 unchanged at 74 (every front end, u8-index form, register/volatile step).
- poke_personal: EXACT* 0x0201B038 (`w = v; w |= (u8)(v << 4)`, truncations inside the call argument). Header docs/families/poke_personal.h written.
- savedata: EXACT 0x02033A88 (callee arity: func_02034734 takes 5 arguments; declaration order src, i, count, dst, total). Header docs/families/savedata.h written.
- net: EXACT 0x0203CBAC (call in both arms, the non-zero arm first, for both id guards; break arms per the corrected case map; `f = 0; if (..) f = 1;`; `int done`). 0x0203D8F0/0x0203AFCC resolve as sole-ref/code.
- symbol_save: 0x0200E488, 0x0200F698, 0x0200E3A4, 0x0200E3E8 already promoted (commit 59be3f7). MATCH 0x0200F234 (ov ids 0x72/0x0E), 0x0200F17C (same ids plus the three overlay callees below; ov009/ov014/ov015 tokens added).
- field_status: MATCH 0x02014878 (ov ids 0x5B/0x83), 0x020145CC, 0x0201450C, 0x02014488 (all wait on ov010 0x0215FA34/0x0215FA44).
Levers that moved residues: call in both arms (EB9C, F1B4, CBAC), callee arity (3A88), declaration order (3A88), separating a shared subexpression (ED00), an explicit copy local (B038). Permuter not needed; 2.0 sp2/sp2p2 tried on each residue, none better than 1.1p1.
DIFF notes appended: pkt_0202ED00, pkt_0202EB9C, func_0202F1B4, sub_0201B038, pkt_02033A88, pkt_0203CBAC (closures), sub_0202FB34 (DIFF; context layout and argument order match TwlSDK CRYPTO_RC4Encrypt, worth a libmatch check as SDK code).

## Integrator: seed
- 0x0202F47C thumb, src/matched/func_0202F47C.c (callee of 0x0202F1B4 at +0x58, only branch image-wide).

## Overlay callees needing evidence (address, overlay)
0x0215536C ov009, 0x02177020 ov014, 0x021798D4 ov015 (func_0200F17C); 0x0215FA34, 0x0215FA44 ov010 (field_status; their own pending files are MATCH on abs_id_14, so they need EXACT or ov010 func_ seeds). Overlay-id constants 0x72, 0x0E, 0x5B, 0x83, 0x58, 0xB3 have no evidence class.

## Shards verified (each twice, stable)
pkt_0202ED00, pkt_0202EB9C, pkt_0202F1B4 (F1B4 and F47C witness each other: first pass MATCH, second EXACT), pkt_0201B038, pkt_02033A88, pkt_0203CBAC.

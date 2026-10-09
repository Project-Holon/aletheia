# musical_dressup_sys (ov010)

Round 3 (lane r3_ov03): the greedy merge with the call-argument harmonizer was re-run; the parts below are what is left. Every part verifies byte-exact on its own.

Eight parts (was 10). The struct pass is the only blocker. Local structs with different field
sets per part: Work (dims use sizeof of another local struct), Seq (Link_02155478 vs
Link_02155C0C pointer members), Stage (Member * vs void * at +4), Member / Party / Ent / Deal
(nested renamed views Rec6_02157028, Member_02156934, Tbl, Ent_02157028), Obj and Rec (complex
members). Prototype conflicts that need these structs first: func_02155FB4, func_02155FC8,
func_02156530, func_02156710..func_02156824, func_021568A8..func_02156B74, func_02157028..func_021572E4.

Parts: musical_dressup_sys_p01.c, musical_dressup_sys_p02.c, musical_dressup_sys_p03.c, musical_dressup_sys_p04.c, musical_dressup_sys_p05.c, musical_dressup_sys_p06.c, musical_dressup_sys_p07.c, musical_dressup_sys_p08.c

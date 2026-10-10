# zukan_detail_form merge status (w12c)

3 parts left (was 4). Round 12 merged old p01 + p02 (EXACT). p01 now carries the canonical objects:
Ov208Form (0x6e4 bytes; item[4] of Ov208Mdl at 0xc stride 0x44, ents[8] of Ov208Ent, rs[9] resource ids at
0x5c0, act[4] at 0x5e4, row[4] of Ov208Row at 0x5f4 stride 0x28, tail words w694..w6e0), Ov208AnmState
(one struct for the old S_021C4E54 / Ov208Anm_021C51D4 views), Ov208Ent (gender/shiny/form named).

Remaining boundaries (p01|p02, p02|p03): p02 (old p03) and p03 (old p04) still address the form object as
u8 *p with W(o)/H(o) macros and ObjNNNNN matched-include views. Next step: change their u8 *p parameters to
struct Ov208Form *p and use the named fields (script in the lane notes; offsets as above).

Finding (w12c): converting p02's function ov208_func_021C625C and ov208_func_021C6760 to named row fields
changes the code. The image computes (p + i * 0x28) first and adds the constant 0x618 / 0x60c / 0x604 as a
register offset (pool constant), so the base p + 0x5f4 is not hoisted. p->row[i].obj makes mwcc hoist
p + 0x5f4 and use [r5, #0x24]. 625C closed with `e = (struct Ov208Form *)((u8 *)p + i * 0x28); e->row[0].x`
(needs `short x, y` in Ov208Row); 6760 and the other users of that shape (func_021C66C8, 021C68D4, 021C692C,
021C6A10, 021C6AFC, 021C6BB4, 021C6C00, 021C6D10) are not converted yet. Partial work: scratchpad
r13/w12c/p02_wip_rows.c.

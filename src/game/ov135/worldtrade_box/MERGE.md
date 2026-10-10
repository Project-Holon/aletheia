# worldtrade_box (ov135): 5 parts (was 6)

w13b (2026-10-10): one canonical Work (and canonical Entry, Ctx, State, Rec, Req, Res, Sub, IconRec, Info, ...)
now lives in worldtrade_types.h, shared with worldtrade_adapter and worldtrade_enter; every part includes it.
Old p01+p02 merged (EXACT; BoxItem/BoxMenu/BoxItems2/BoxItems3 replace the two Item/Menu copies).
Next boundary, p01 | p02 (old p03): the merge compiles after these edits and is DIFF by 11 bytes, all inside
func_021F68A4 (icon loader); the edits were: opaque tags struct Obj_021F68A4 -> struct Obj and
struct Ctx_021F6E58 -> struct Ctx, Info_p02 / IconRec_p02 / IconRec_021F5E44 -> canonical Info / IconRec,
`(u8 *)p` removed from three func_021F68A4 calls, `(Deposit *)p->ent` cast, `(u32)arc` cast. One of them
changes code; bisect them one at a time.
Later boundaries (not tried since the older notes): p04 | p05 and the u8 * vs struct pointer arguments of
func_021F8358 / func_021F875C, g_02203C00 declared two ways, tbl_02202FC4 / tbl_0220301C row structs.

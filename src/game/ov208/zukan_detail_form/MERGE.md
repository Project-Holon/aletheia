# zukan_detail_form merge status (r5 s10)

4 parts left (was 5). Round 5 closed old p01|p02: the DIFF was not in func_021C36CC or func_021C3A24
any more; the only difference was func_021C48CC, which stored the func_0204A298 result in p->arc (0x128)
where the image stores it at 0x594 (p->marc). Fixed with p->marc = (u32)func_0204A298(...).
Merged p01 is EXACT and carries the canonical struct Ov208Form (0x6e4 bytes).

Remaining boundaries (p01|p02, p02|p03, p03|p04): p02, p03 and p04 still address the form object as
u8 *p with W(o)/H(o) offset macros (about 220 uses) and per-part struct Ov208Menu/Ov208Mdl views. Merging
fails with 'illegal implicit conversion from struct Ov208Form * to unsigned char *' at the calls into
func_021C5664, func_021C580C, func_021C5D64 and others. Next step: change the u8 *p parameters of the
p02..p04 functions to struct Ov208Form *p and replace W/H/MDL by the named fields (offsets listed in
the Ov208Form block of p01), then merge. Also p01 still has hack views in func_021C4A48 (Obj10908 casts)
and the W/PW/OBJ/H macros in its first half.

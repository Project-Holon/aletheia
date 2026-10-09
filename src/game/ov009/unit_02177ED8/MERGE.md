# unit_02177ED8 (ov009)

4 part files remain (unit_02177ED8_p01.c .. p04.c, address order), each EXACT. Round 4 (r4_ov02)
joined old p03 and p04 (0x021782B4..0x02178C48) with the greedy driver; the rest does not join.

Boundaries:

- p01 | p02 and p03 | p04: g_021AB184 is viewed as struct DWCWFCUtil (field auth, G_DWCWFCUtil.h)
  in p01/p03 and as struct DWCAuthGlobal (field ctx, G_DWCAuthGlobal.h) in p02/p04. Same object,
  offset 4 (pointer to the auth work area). The work area is also viewed as DWCAuth (p01),
  DWCAuthCtx (p02, p04) and DWCAuth_02178678/DWCAuth_021783BC (p03).
- Names disagree for the same offsets: 0x1004 is "result" in p01/p03 and "error" in p02/p04;
  0x1008 is "error" in p01 and the start of a 0x1c4-byte result block in p02.

Next step: one canonical DWCAuth (stack to 0x1004, int at 0x1004, result block at 0x1008 with
returncode first, param at 0x11cc, http at 0x1314, thread at 0x1320 with id at 0x138c, mutex,
abort_flag) and one g_021AB184 struct (f0, auth, state, userid); then rerun the greedy driver.

# An if/else with a constant per arm keeps two identical calls apart

summary: mwcc 1.1p1 cross-jumps two identical calls on different paths into one call; when the
original keeps them apart, write one of them as an if/else that passes a different constant in
each arm (mwcc merges that pair into one call but not with the other path's call).

Found in: src/game/ov068/option_menu.c (OPTION_MENU_UpdateButtons), src/game/ov071/monolith_tool.c
(MONOLITH_TOOL_SLOT_SELECT_Main)

Symptom: the function comes out a few bytes short (504 against 508 in ov068) or with one branch
going to the other path's call. A second extern name for the callee made the two calls look
different and closed it, which is why both files once carried a second declaration
(`func_020061E4_2`, `func_020355D8x`).

Fix: one name, and the calls written the way the listing shows them:

  * ov068: `if (cancel) PlaySe(OPTION_SE_CANCEL); else PlaySe(OPTION_SE_CONFIRM);` in place of a
    ternary argument, and the two stores after it repeated inside both outer arms (both changes
    are needed).
  * ov071: `if (touch == 7) UI_SetInputMode(1); else UI_SetInputMode(0);` then the shared tail.

The listing looks like a ternary (one call, the argument chosen before it), so read it as an
if/else with constants when the call must not merge with a sibling path.

# A loop-body local below the CSE temps is an inline helper's local

summary: mwcc creates the locals of an expanded `static inline` helper after every declared
local of the caller. A spilled value whose slot sits below the caller's CSE temps, with the
loop registers swapped against your declaration order, is a helper local: move the loop body
into a static inline helper.

Found in: src/game/ov119/pokemontrade_save.c, POKETRADE_SAVE_ApplyTradeResult, Japanese build
(lane JP-M7).

## Symptom

The Japanese build adds one check to a loop body (language 1 and nation not 105: skip). With
the check written in place, the size matched but 20 bytes differed:

- the spilled `area` value took sp+0x14 (above the CSE temps); the image has it at sp+4, the
  lowest slot, and every earlier temp one slot higher;
- the status pointer and the nation value had their registers swapped (r6/r5 against r5/r6).

## Cause

Spill slots follow object creation order (a later object gets a lower slot). Named locals
of the caller exist before the IRO makes its CSE temps, so they sit above them. An inline
helper's parameters and locals are made at expansion, after the caller's locals, so they
get the lowest slots and the highest-numbered virtual registers, which also changes the
register ties.

## Fix

```c
static inline void POKETRADE_SAVE_RegisterWifiHistory(void *wifiHistory, void *status)
{
    u8 nation = MYSTATUS_GetNation(status);
    u8 area = MYSTATUS_GetArea(status);
    if (MYSTATUS_GetLanguage(status) == 1 && nation != 105)
        return;
    ...
}
...
for (i = 0; i < 2; i++) {
    if (list[i])
        POKETRADE_SAVE_RegisterWifiHistory(obj, list[i]);
}
```

Tell: run `mwccdbg regalloc-replay --renumber` first. If renumbering two loop locals
reproduces the register swap and declaration order does not move the slot, try a helper.

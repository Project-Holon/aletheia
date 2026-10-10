# event_field_proclink (ov010)

Round 13 (lane w13d): 12 parts -> 2. Shared types unified (Bool, Req, Work, Owner, Ctx opaque casts, S, u32 aliases), stand-in callers rewritten as typed C (func_0215F2A0, func_0215F608 table search), prototypes aligned (func_021BE8D4, func_021BE92C, func_020127A4, func_02197D3C, func_02161938 returns its argument unchanged in the id 0xF1 case, func_02161CDC).

Left: p01|p02 at 0x0216171C. An eight-byte Thumb thunk (`ldr r3, [pc]; bx r3; .word 0x020307B0`) sits between func_021616F0 and func_02161724. It is a linker veneer (gamegaps class `veneer`), so the file boundary is real; merged, the EXACT result breaks at the missing veneer.

Parts: event_field_proclink_p01.c, event_field_proclink_p02.c

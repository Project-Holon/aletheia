# A constant loaded at entry into a callee-saved register is a declaration initialiser

summary: a `mov rN, #k` into a callee-saved register among the argument set-up of the first call, for a local that is only assigned on one path later, is that local's initialiser at declaration (`u16 x = k;`), not a hoisted constant.

Found in: src/matched/WM_StartDataSharing.c (0x0209004C)

WM_StartDataSharing opens with the WMi_CheckStateEx arguments and, among them,
`mov r8, #1`. r8 is `connectedAIDs`, which the body only assigns when
`WM_GetAID() == 0`; the other path never reads it. Declaring it without an
initialiser drops the `mov` and shifts the parameter registers (aidBitmap to
r7, dataLength to r6), a whole-function diff. `u16 connectedAIDs = 1;` puts the
`mov r8, #1` back in place, after the argument moves and before the call.

The same function also passes its updated parameter straight to the next call:
`aidBitmap |= (u16)(1 << aid); dsInfo->aidBitmap = aidBitmap;
count = MATH_CountPopulation(aidBitmap);` gives `orr` then the store and the
call on the same register, where `MATH_CountPopulation(dsInfo->aidBitmap)`
re-reads the field with an extra `ldrh`.

The shape is not always an initialiser: in WM_StepDataSharing (same object) a
`mov r5, #0` at the same spot stays unexplained, see
docs/notes/pkt_020902D8.c.txt.

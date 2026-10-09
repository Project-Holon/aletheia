# tr_tool (arm9)

Parts p01, p02 (thumb, c99). Round 4 re-checked: the merge compiles, and with func_02030734 taken
as p01's prototype (u32 heapId, ..., u16 tag) every p01 function is exact. Only func_0202A4B4 (p02)
then differs: it is 1244 bytes merged against 1248 in the image, so one literal-pool word is shared
with p01's pool in a single file but is kept separate in the image. That is a literal-pool boundary
(the two parts were different object files), not a type problem. Real boundary.
Types are already compatible apart from the func_02030734 prototype (p02 uses u16 heap, u32 line).

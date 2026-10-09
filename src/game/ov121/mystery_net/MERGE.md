# Merge blockers (lane r2_13)

Parts in ../ are in address order (p01, p02, p03).

- mystery_net_p02.c (func_021DDC30, func_021DDC44) is ARM code between two Thumb parts. The header lines are complete, so this is a real ISA change. Wrapping the two functions in `#pragma thumb off` inside p01 compiles them as ARM, but the compiler then writes the Thumb bit into the literal-pool pointers that p01 holds to them (021DDC31 and 021DDC45 instead of 021DDC30 and 021DDC44): 2 bytes differ. So they stay a separate ARM file.
- p01 and p03 cannot join without p02.

# iss_3ds_sys.c (arm9)

Three parts (`_p01`..`_p03`) and one single (`func_0202B744.c`, between p01 and p02) remain.
Merging p01 + func_0202B744, func_0202B744 + p02 and p02 + p03 each give c99=DIFF: there is unmatched code in the gaps
(0202B720..0202B744 is not laid out by the merged file, and likewise 0202B8F4..0202B90C), so the merged file puts the next
function at the wrong address. Merge when the gap functions are matched.
Done in this pass: p03 and p04 merged after unifying the two local `E` entry structs (same layout).

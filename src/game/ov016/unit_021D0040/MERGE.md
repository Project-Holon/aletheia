# unit_021D0040 (ov016)

Translation unit 021D0040..021D0B44. Two parts remain:

- unit_021D0040_p01.c: DWCi_STEPlBegin through DWCi_STEPlChange (0x021D0040..0x021D05BC), holds taskBegin4.
- unit_021D0040_p02.c: func_021D0684 (0x021D0684) onward, holds taskEnd0 (func_021D06A4).

Why the two parts cannot be one file: taskBegin4 and taskEnd0 only match when
`File` and `MemStep` are declared as function-scope statics inside each function
(compiler 1.1p1 hoists the load of a non-escaping function static above the
store to the address-taken local `x`; a struct member load stays below it).
In the original TU these two names were one pair of file statics at 0x021DE64C.
In one source file each function would own a separate pair, so the second
function would address `.bss` + 8 instead of `.bss` + 0 and its literal pool
would differ (DIFF). The other functions reach the same storage through
`extern STEP_BSS step_bss` (`step_bss.file`, `step_bss.memStep`).

Fixed in this pass: struct field names `File`/`MemStep` collided with the
`#define File`/`#define MemStep` macros the merger hoists to the top of the
file, so the macros are gone and the code uses `step_bss.file` and
`step_bss.memStep` directly.

Round 3 (r3_ov04): re-tried the p01+p02 merge: still DIFF (taskEnd0), same function-static reason as above.

Round 18 (L17): merged p01+p02 with file-scope statics File and MemStep (func_021D0684 as `MemStep->task != 0`):
everything else matches except that an unused file static File is dropped by the compiler, so MemStep lands at +0
instead of +4 (one word differs at each use). A function-scope unused static is kept. Boundary unchanged.

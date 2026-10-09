# iss_3ds_sys (arm9)

2 parts left. p01 (0202B4BC..0202B8F8) merged old p01..p03 after adding 11 hidden tail-call stubs for the uncovered 12-byte code at 0202B720/72C/738 and 0202B758..7AC (each is ldr r0,[r0,#k]; ldr r3,pool; bx r3).

p01 to p02 (0202B90C): 0202B8FC and 0202B904 are two 8-byte Thumb linker veneers (ldr r3,[pc]; bx r3) with no function; 0202B8F4 and 0202B90C are the same veneer kind. This is a real file boundary (unmatched code: 0202B8FC..0202B90C).
Callee arity of the hidden stubs is unknown: each is written with one pointer argument.
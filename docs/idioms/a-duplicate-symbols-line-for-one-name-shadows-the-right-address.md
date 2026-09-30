# A duplicate `symbols:` line for one name shadows the right address

summary: two `symbols:` lines that give the SAME C identifier two different
addresses leave every call site of that name resolving to whichever address
the lookup index kept; when that address is contested across overlapping
overlays the sites all go unresolved ("2 overlays overlap this address, none
resolvable without a region hint"), and the fix is to delete the wrong line
rather than add a hint. The vendor object shows which line is wrong.

Found in: src/pending/ov_sdk/ov009_func_0216D57C.c (0x0216D57C,
DWCi_MatchProcess), wave 8, 2026-10-01

The row declared

    DWCi_HandleMatchCommandError     0x021719A4 arm
    ...
    DWCi_HandleMatchCommandError     0x021779A4 arm

0x021779A4 is a *different* function that happens to share overlay address
space (ov009 and ov014 both load there), so the name resolved to it and its
five call sites inside the row were refused: no witness outside the compared
range, and two overlays disagree about what is at the address so no
`label` evidence either. 0x021719A4 is the real target.

The authority is the vendor object, not the listing: the object's relocation
table names one address per site. `python tools/sdkobj.py 0x0216D57C
--region ov009` prints the listing with each `bl` marked

    0254  0216D7D0  bl ... ~ bl #0x21719a4  <PC24 DWCi_HandleMatchCommandError>

so the wrong line is identifiable without guessing. Deleting the 0x021779A4
line took the row from 199/204 to 204/204 resolved. A duplicate name is not a
second symbol the way a duplicated pool word is (`a-duplicated-pool-word-is-
a-second-extern-name-for-the-same-address`); here the two lines disagree about
the address, and one of them is simply wrong.

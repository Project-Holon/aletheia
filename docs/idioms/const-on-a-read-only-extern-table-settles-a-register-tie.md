# const on a read-only extern table settles a register tie that reads as allocator residue

summary: a lookup table declared `extern u16 tbl[4][4]` instead of `extern const u16 tbl[4][4]` can
leave a function at the right size with every register of the table-indexing half renamed; declaring
the table const alone can close it.

Found in: src/matched/func_0204C2C8.c (0x0204C2C8)

func_0204C2C8 (the clact.c OAM cull callback) reads two OBJ width/height tables indexed
[shape][size] twice each and passes the results to func_0204C3CC.  With the tables declared
without const it compiled to 260 bytes against 260 with 58 concrete bytes out, register names
only: the table bases in r8/lr where the image has ip/r8, the wrapped y in r0 where the image has
lr, and the late `lsl r2, r2, #0xc` of x0 scheduled before the stores instead of after.  Three
waves measured 120 declaration orders, 80 index casts, table access forms and two permuter anneals
against it, all flat.

Declaring both externs `const` (no other change) gives EXACT.  The permuter's const mutations only
touch pointer parameters, so a flat anneal says nothing about this lever.  Before calling a
same-size register reshuffle around table reads an allocator tie, check that every extern the
function only reads, tables and templates alike, is declared const.

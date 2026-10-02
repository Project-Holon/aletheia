# A row add after the key compare is an inline byte-offset argument

summary: when a table scan compares `ldrh rK, [tbl, off]` and only forms
`row = tbl + off` inside the matching branch (reusing off), the row is an
inline helper's argument written as `(u16 *)((u8 *)tbl + i * 12)`; a 2-D
subscript, `&tbl[i]` or a row local assigned in the branch all CSE the add
into the compare block. The helper's own colours then come from
`for (i = 1, p = row; ...)`: a local pointer copy set in the for header.

Found in: src/matched/ov/ov021_func_0219A1E8.c (0x0219A1E8), Thumb

Measured: the `(u8 *)` byte-offset row (in-function or as an inline
argument) keeps the add below the compare. As an inline argument it also
reproduces the entry copy of the second parameter (`adds r4, r1, #0`) and
the table in r1, but leaves row r1 / index r0 (18 bytes). A pointer copy
in the helper body (`u16 *p = row;`) gives row r0 but loses the entry copy;
the copy made in the for header (`for (i = 1, p = row; p[i] != 9; i++)`)
gives row r0, index r3, v in r4: EXACT. Return types, parameter order,
passing the start index, and while/for spellings were all inert.

# ov114 SDK wave lane U29 — the zero-pool lever (0x021CB3B4 EXACT)

`dsi/1.1p1` pools a repeated integer literal into one callee-saved register and
hoists the materialisation to the frame head, but only when the literal occurs
in the **same statement region**; it does not pool two copies that live in
distant regions of the function. This is what the row verdicts in
`ov114_sdk_u19_residues.md` call "descending vs ascending hand-out": the
literal's register is live across the branches, so it shifts every temporaries'
allocation in the block.

Measured on 0x021CB3B4 (`CRYPTOi__BN_add_word`, 224 bytes): the obvious spelling
of the negative-a path —

```
if (l > w) a->d[0] = l - w;
else { a->neg = 0; if (l < w) a->d[0] = w - l; else a->top = 0; }
```

— gives **two** zero literals in the region and compiles to 224 bytes with 46
concrete mismatches: ours materialises `mov r2,#0` per use, the object keeps one
`mov r2,#0` hoisted to +0010 and reuses it for all three sign/top stores, which
in turn pins `a->d` in r1 (not r2) and the loaded word in r0. Writing the store
out once per branch —

```
else if (l < w) { a->neg = 0; a->d[0] = w - l; }
else            { a->neg = 0; a->top = 0; }
```

— gives **three** literals, triggers the pool, and the row is byte-exact. The
same edit also fixes `l = w + a->d[i]` operand order in the ripple loop
(`l = a->d[i]; l = w + l;` emits `add r0,r0,r5`, the object emits `add r0,r5,r0`).

So: when the residue includes a re-materialised constant plus a knock-on
register shift, **raise the literal count in the region** (duplicate the shared
store into the sibling branches) before declaring it an allocator tie-break.
Folding a statement out of an if/else is what loses the pool.

Counter-case, for the file: 0x021BD7E8 (`NHTTPi_ThreadSendProc`) has the same
signature — the object's `mov r5,#0` at +000C serves three statements in three
different regions (+0078 sendBufwp=0, +0080 sendStatus=0, +0350 sendBufwp=0) —
but there is no sibling branch to duplicate into, and no spelling tried (extra
`char *commBuf_p` local from the DWARF, four declaration orders) moves the
r6/r7 chain swap. Unpooled and parked.

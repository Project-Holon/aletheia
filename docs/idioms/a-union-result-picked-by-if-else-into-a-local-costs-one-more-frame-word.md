# A union result picked by if/else into a local costs one more frame word than a direct field store

summary: when two branches each call a function that returns a one-word union
and the frame is one word larger than the plain C gives, assign both results to
a union local and store the local once after the if/else. Do not cast the
callees to other return types per call: the header prototypes stay plain.

Found in: src/game/ov093/hand_waza.c (0x021E3FC0, HAND_WAZA_PsychoShiftTransferStatus)

The original opens `push {r4-r7, lr}; sub sp, #0x1c` and both branches end in
r0, with a single `str r0, [r4, #8]` at the join. With every callee declared as
in its header (union SickCont returns, an int status getter) and

```c
if (kind == BTL_SICK_POISON && BTL_SICKCONT_IsKind1Index15(cont) != 0)
    addSick->sickCont = BTL_SICKCONT_MakeKind1Index15();
else
    addSick->sickCont = BTL_CALC_MakeDefaultSickCont(kind);
```

every byte matched except the frame (`push {r3-r7, lr}; sub sp, #0x18`). The
form below gives EXACT:

```c
union SickCont newCont;
...
if (kind == BTL_SICK_POISON && BTL_SICKCONT_IsKind1Index15(cont) != 0)
    newCont = BTL_SICKCONT_MakeKind1Index15();
else
    newCont = BTL_CALC_MakeDefaultSickCont(kind);
addSick->sickCont = newCont;
```

An earlier match got the same frame by casting the status getter to a
one-word struct return at two calls and the default-condition call to an int
return. That needed function-pointer casts, because the other callers in the
same file use the header types. The data block of the file's handler tables is
one interleaved run for all its functions, so the file is one TU and a
per-file prototype split cannot be the explanation.

The ternary form (`addSick->sickCont = c ? A() : B();`) hangs dsi/1.1p1 here.

A related case in the same file (Roost, 0x021E6994): the record was typed with
a plain u32 condition field, so the call was cast to an int return. With the
real record type (`struct HandExAddSick`, whose `sickCont` is the union) the
plain call `addSick->sickCont = BTL_SICKCONT_MakeKind2(1, 2);` is EXACT and
reserves no frame word.

# Wave 19 lane mechanisms (19Q)

I attacked each residue's mechanism with the levers lane 19O left open. One
function moved and nothing closed. 60 hand measurements (12 per function,
plus one repeat on 0x02071104) and two permuter runs of 1000 compiles.

| address | before -> after | verdict | what moved it |
|---|---|---|---|
| 0x0206F4C8 | 2 -> 2 | DIFF | Nothing. All commuted, cast-moved and s64-local spellings of the unnamed sum give 2. `+=` gives 4, the negated term 76. mwcc canonicalises the operand order. |
| 0x02071104 | 6 -> 6 | DIFF | Nothing. Inline helpers give 6 to 26, explicit copies 6 or 18, the shift term hoisted 6 or 18. Copies propagate back into one web. |
| 0x02069BA0 | 6 -> 6 | DIFF | Nothing. The argument through a temporary, the call first, and 8 as a non-literal or stored through a u8 pointer all give 6. Volatile on the acc field alone gives 14. |
| 0x0202350C | 12 -> 4 | DIFF | Store order: `obj->f30 = a4;` written before the f40/f44 stores. a4 is then live across kb, so kb leaves r1. That removes the anti-dependency that kept the a4 load below the f44 store, and the scheduler keeps the image's store order. Residue: a `movs r0,#0` / `ldrb r2` scheduler tie. The alias and type levers (int fields, const, restrict, void *, u32 array stores) all give 12. |
| 0x0202627C | 10 -> 10 | DIFF | The residue changed shape. The RMW byte read first into a local (`w = byte; cb; a; b = p->b1; ...; byte = w & ~2`) puts the flag byte in r3 and the loads in the image's order. Only zero and cb are left swapped (r2/r5). Kept as an alternative source. |

Permuter: 0x0202350C seed 3601 (no gain), 0x0202627C seed 3602 (flat at 10).

Finding: 0x0202350C's "load not hoisted over stores" was a register
anti-dependency, not aliasing. The alias levers do nothing.

Files written: wave-19 mechanisms sections in docs/notes/pkt_0206F4C8.c.txt,
docs/notes/pkt_02071104.c.txt, docs/notes/func_02069BA0.c.txt,
docs/notes/func_0202350C.c.txt (new best-source marker, 4 out) and
docs/notes/pkt_0202627C.c.txt (alternative source). Nothing was filed in src/
and no shards were verified. No idiom was written because nothing closed.

Seeds: none noticed.

Integrator: stage the five note files and this report.
0x0202350C's 4-out source is the new base for the next lane.

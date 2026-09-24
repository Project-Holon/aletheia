# Wave 20, lane 20C mcss_5

No function closed. Both notes have a dated wave-20 section with every measurement and the register-at-that-point analysis. The best sources are unchanged.

| address | before -> after | verdict | measurements |
|---|---|---|---|
| 0x02016C60 | 29 -> 29 (870/872, 1.1p1) | DIFF | 20 (sweeps counted once) |
| 0x02067080 | 2 -> 2 (704/704, ../2.0/sp2) | DIFF | 8 plus one permuter run |

0x02016C60: at the pass-2 header, r2 (base) and ip (scale) are live and nothing else is. Both add operands die (f2c in r1, k*0x30 in r0), so no value holds r0 across the pointer in either build. The difference is colouring order: the image colours the r0 temporaries before the pointer, and this build colours the pointer first. I measured 20 things, all 29, apart from load-order-only 27s in the statement sweeps:
- dead initialisers on all 35 locals
- a named p (initialised, dead defs at three points, block-scoped, split add)
- 120 header statement orders, plus 420 orders with split temporaries
- self-assignments of a0, a1 and six locals at seven points
- the w2 test forms and a q[] view
- a named pass-1 pointer
- every other dsi compiler
The permuter was not run.

0x02067080: at +0x21C, r6 (_01), ip (halfW) and r8 are dead in both builds, so our compile does not hold r6 there. The allocator takes ip whenever it is free. Reading y before the x store moves y into r6, which is right, but the dy mla result then moves from r7 to ip. The 2 bytes out stay the same. A 105-order statement sweep, dy forms, extending halfW/halfH, and the permuter (800, seed 4101, inline via a scratch MUTFUNC copy) all stayed flat at 2. To match, ip has to be unavailable to both values.

Files written: docs/notes/pkt_02016C60.c.txt, docs/notes/pkt_02066E30.c.txt (appended sections only), and this report. Nothing was filed, so no shards needed verifying. No seeds noticed. I used permuter seed 4101; 4102..4149 are unused.

Integrator: nothing to do. `git status` shows tools/permuter.py staged-modified, and that change is not from this lane.

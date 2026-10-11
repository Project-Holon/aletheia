# g3d_system (arm9)

4 parts, each ends at a linker veneer (02046C88, 02047964, 02048C4C), so a file cannot continue across it. The round 3 greedy pass confirmed: p01+p02 and p03+p04 are c99=DIFF, p02+p03 fails on struct G3dSys vs G3dSys_0.

- g_02146A5C is seen through about 13 partial views (void * in p01/p02, struct G3dSys in p03); the struct view changes register allocation in p01 (func_02046AFC, func_02046B40).
Round 15 (lane w14b): stubs at 02046C88, 02047964, 02048C4C are `void f(void) { g(); }` (EXACT). p01+p02 merged; p02|p03 stays
split (struct G3dSys vs void * clash at the merged line 2232) and p03|p04 is a DIFF.


Round 4 (r4_ov05): re-ran the greedy pass, no change. func_0217FACC is called with one argument in p04 (as in the original, r1 is not set) but defined (u32 *p, int a1) in p05; an unprototyped extern in p04 plus no prototype in p05 compiles, but the merged file also stops at unsigned int[] against const char * (line 1171) and a redeclaration. p03|p04 and p02|p03 are DIFF without a compile error.

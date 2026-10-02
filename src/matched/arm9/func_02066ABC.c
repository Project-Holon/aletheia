/*
 * unit:     no
 * function: func_02066ABC
 * address:  0x02066ABC
 * packet:   pkt_02066ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

extern unsigned char *func_02066878(unsigned int i);
int func_02066ABC(int a0, int a1, int a2){ int t0; t0 = (int)func_02066878(a0); *(int *)(((char *)(t0) + 36)) = (int)~0; *(int *)(((char *)(t0) + 40)) = (int)a1; *(int *)(((char *)(t0) + 44)) = (int)a2; return t0; }

/*
 * unit:     no
 * function: INFOWIN_Exit
 * address:  0x02024DCC
 * packet:   pkt_02024ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int INFOWIN_Exit(void){ int t0, t1, t2; if ((unsigned int)(*(int *)((char *)(0x214693C))) != (unsigned int)(0)) { t0 = func_02030EAC((int)*(int *)(((char *)(*(int *)((char *)(0x214693C))) + 36))); t1 = func_0203FB44((int)*(unsigned char *)(((char *)(*(int *)((char *)(0x214693C))) + 6)), (int)*(int *)((char *)(*(int *)((char *)(0x214693C)))), (int)(1 << 0xc)); t2 = func_020307B0((int)*(int *)((char *)(0x214693C))); *(int *)((char *)(0x214693C)) = (int)0; return 0; } else { return *(int *)((char *)(0x214693C)); } }

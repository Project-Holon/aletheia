/*
 * unit:     no
 * function: DOUBLE3DDISP_Exit
 * address:  0x0204EA0C
 * packet:   pkt_0204E8C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   GX_DisableBankForLCDC  0x02080B98  arm
 *   GX_DisableBankForSubBG  0x02080BAC  arm
 *   GX_DisableBankForSubOBJ  0x02080BC0  arm
 */

int DOUBLE3DDISP_Exit(void){ int t0, t1, t2, t3; t0 = GX_DisableBankForLCDC(); t1 = GX_DisableBankForSubBG((int)t0); t2 = GX_DisableBankForSubOBJ((int)t1); t3 = func_020307B0((int)*(int *)((char *)(0x2146A80))); *(int *)((char *)(0x2146A80)) = (int)0; return 0; }

/*
 * function: PMSI_PARAM_GetSaveWork
 * address:  0x02024148
 * packet:   pkt_02024148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 *
 * symbols:
 */
void *PMSI_PARAM_GetSaveWork(char *p){return *(void **)(p+8);}

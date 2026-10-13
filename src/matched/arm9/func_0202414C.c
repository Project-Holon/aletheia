/*
 * function: PMSI_PARAM_GetWordSave
 * address:  0x0202414C
 * packet:   pkt_0202414C
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
void *PMSI_PARAM_GetWordSave(char *p){return *(void **)(p+12);}

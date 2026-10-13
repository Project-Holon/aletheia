/*
 * function: PMSI_PARAM_SetUiInputMode
 * address:  0x02024224
 * packet:   pkt_02024224
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
 *   func_020355D8 0x020355D8 arm
 */
extern void func_020355D8(void *);
void PMSI_PARAM_SetUiInputMode(void *a,void *b) { func_020355D8(b); }

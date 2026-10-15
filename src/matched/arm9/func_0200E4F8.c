/*
 * unit:     no
 * function: MISC_SAVEDATA_GetScoreValue
 * address:  0x0200E4F8
 * packet:   pkt_0200E4B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MISC_SAVEDATA_GetAnswerMessageOffset  0x0200E488  thumb
 */

int MISC_SAVEDATA_GetScoreValue(int a0, int a1, int a2){ int t0; if ((unsigned int)(a2) == (unsigned int)(0)) {  return 0; } else { t0 = MISC_SAVEDATA_GetAnswerMessageOffset((int)(a1 + 0), (int)(a2 + 0)); return *(unsigned short *)(((char *)(((a0 + 0) + (t0 << 1))) + ((int)((0x55 << 2)) << 0))); } }

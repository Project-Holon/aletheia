/*
 * unit:     no
 * function: FIELD_SOUND_SYSTEM_UpdateFadingInAfterPop
 * address:  0x0202920C
 * packet:   pkt_0202920C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 *   FIELD_SOUND_SYSTEM_FinishRequest  0x02029364  thumb
 */

int FIELD_SOUND_SYSTEM_UpdateFadingInAfterPop(int a0, int a1, int a2, int a3){ int t0, t1, t2; t0 = GFL_USE_IsBgmFading(); if ((unsigned int)(t0) == (unsigned int)(0)) { t1 = FIELD_SOUND_SYSTEM_SetState((int)((a0 + 0) + 0), (int)1); t2 = FIELD_SOUND_SYSTEM_FinishRequest((int)((a0 + 0) + 0)); } else {  return t0; } }

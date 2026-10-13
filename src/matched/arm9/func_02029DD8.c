/*
 * unit:     no
 * function: FIELD_SOUND_SYSTEM_RestoreVolume
 * address:  0x02029DD8
 * packet:   pkt_02029DD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_3DS_SYS_SetVolume  0x0202B914  thumb
 *   FIELD_SOUND_SYSTEM_FadeVolume  0x02028A58  thumb
 */

int FIELD_SOUND_SYSTEM_RestoreVolume(int a0, int a1){ int t0 = func_0202B57C((int)(a1 + 0)); int t1 = ISS_3DS_SYS_SetVolume((int)t0, (int)0x7f); int t2 = FIELD_SOUND_SYSTEM_FadeVolume((int)((a0 + 0) + 0), (int)0x7f, (int)6); return t2; }

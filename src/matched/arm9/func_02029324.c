/*
 * unit:     no
 * function: FIELD_SOUND_SYSTEM_UpdateReplacing
 * address:  0x02029324
 * packet:   pkt_02029324
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 *   FIELD_SOUND_SYSTEM_FinishRequest  0x02029364  thumb
 *   FIELD_SOUND_SYSTEM_PlayRequestedBgmNow  0x0202945C  thumb
 */

int FIELD_SOUND_SYSTEM_UpdateReplacing(int a0, int a1, int a2, int a3){ int t0 = FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(a0); int t1 = GFL_USE_SetBgmPlayerParam((int)1); int t2 = FIELD_SOUND_SYSTEM_SetState((int)((a0 + 0) + 0), (int)2); int t3 = FIELD_SOUND_SYSTEM_FinishRequest((int)((a0 + 0) + 0)); return t3; }

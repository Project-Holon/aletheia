/*
 * function: RINGTONE_SYS_SetBgmMuted
 * address:  0x0202A02C
 * packet:   pkt_0202A02C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PLAYER_VOLUME_FADER_SetMute  0x020287A8  thumb
 *   NNS_SndPlayerSetPlayerVolume  0x02072D98  arm
 */
#include "../include/Obj15807.h"

int RINGTONE_SYS_SetBgmMuted(int a0, int a1){ int t0, t1, t2, t3, t4, t5, t6, t7, t8; if ((unsigned int)((a1 + 0)) == (unsigned int)(1)) { t0 = NNS_SndPlayerSetPlayerVolume((int)1, (int)0); t1 = NNS_SndPlayerSetPlayerVolume((int)2, (int)0); t2 = NNS_SndPlayerSetPlayerVolume((int)3, (int)0); t3 = NNS_SndPlayerSetPlayerVolume((int)4, (int)0); } else { t4 = NNS_SndPlayerSetPlayerVolume((int)1, (int)0x7f); t5 = NNS_SndPlayerSetPlayerVolume((int)2, (int)0x7f); t6 = NNS_SndPlayerSetPlayerVolume((int)3, (int)0x7f); t7 = NNS_SndPlayerSetPlayerVolume((int)4, (int)0x7f); } t8 = PLAYER_VOLUME_FADER_SetMute((int)((struct Obj15807 *)((char *)((a0 + 0))))->f8, (int)((a1 + 0) + 0)); return t8; }

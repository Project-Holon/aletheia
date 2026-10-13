/*
 * unit:     no
 * function: FIELD_SOUND_SYSTEM_DiscardRequest
 * address:  0x02029354
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_ClearRequest  0x02029348  thumb
 */
#include "../include/Obj01618.h"

int FIELD_SOUND_SYSTEM_DiscardRequest(int a0){ int t0; if ((unsigned int)(*(int *)&((struct Obj01618 *)((char *)(a0)))->f1C) != (unsigned int)(0)) { t0 = FIELD_SOUND_SYSTEM_ClearRequest((int)a0, (int)*(int *)&((struct Obj01618 *)((char *)(a0)))->f1C); } else {  return a0; } }

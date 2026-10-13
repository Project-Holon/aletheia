/*
 * function: FADE_Update
 * address:  0x0204E638
 * packet:   pkt_0204E638
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_02146A7C     0x02146A7C  data
 *   FADE_ApplyBrightness  0x0204E824  arm
 */

#include "../include/G_Run0204E720.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern struct Run0204E720 *g_02146A7C;
extern void FADE_ApplyBrightness(void);

void FADE_Update(void)
{
    if (g_02146A7C == 0) {
        return;
    }
    if ((g_02146A7C->unk00 & 0xf) == 0) {
        return;
    }
    if (g_02146A7C->unk10 != 0) {
        g_02146A7C->unk10 = g_02146A7C->unk10 - 1;
        return;
    }
    g_02146A7C->unk10 = g_02146A7C->unk14;
    g_02146A7C->unk08 = g_02146A7C->unk08 + g_02146A7C->unk18;
    if ((g_02146A7C->unk08 >= g_02146A7C->unk0c && g_02146A7C->unk18 > 0) ||
        (g_02146A7C->unk08 <= g_02146A7C->unk0c && g_02146A7C->unk18 < 0)) {
        g_02146A7C->unk08 = g_02146A7C->unk0c;
    }
    FADE_ApplyBrightness();
    if (g_02146A7C->unk08 == g_02146A7C->unk0c) {
        g_02146A7C->unk00 = 0;
    }
}

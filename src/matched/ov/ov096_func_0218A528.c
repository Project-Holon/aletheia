/*
 * function: TR_AI_ReleaseScript
 * address:  0x0218A528
 * packet:   pkt_0218A528
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   gTrAiScriptCache     0x0218A7C0  data
 */

#include "../include/G_Slot.h"

typedef unsigned char u8;

typedef struct {
    u8 id[4];
    u8 ref[4];
    void *obj[4];
} Slot;

extern struct Slot *gTrAiScriptCache;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void TR_AI_ReleaseScript(u8 *a)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (gTrAiScriptCache->id[i] == a[0x45]) {
            gTrAiScriptCache->ref[i]--;
            if (gTrAiScriptCache->ref[i] == 0) {
                gTrAiScriptCache->id[i] = 0xff;
                func_020307B0(gTrAiScriptCache->obj[i]);
                gTrAiScriptCache->obj[i] = 0;
            }
            return;
        }
    }
}

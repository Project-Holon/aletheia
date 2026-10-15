/*
 * function: ZUKAN_DETAIL_AREA_ApplyPendingEffect
 * address: 0x021BFFEC
 * packet: pkt_ov208_021BFFEC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness 0x021C239C thumb ov208
 *   ZUKAN_DETAIL_AREA_ResetBlendAlpha 0x021C2304 arm ov208
 *   ZUKAN_DETAIL_AREA_ApplyBrightness 0x021C231C thumb ov208
 *   ZUKAN_DETAIL_AREA_SetupSplitWindows 0x021C232C thumb ov208
 *   ZUKAN_DETAIL_COMMON_SetBrightnessFull 0x021BC4F4 thumb ov208
 *   ZUKAN_DETAIL_COMMON_TransferPalettes 0x021BC6BC thumb ov208
 */
#include "../include/Obj08397.h"
typedef unsigned char u8;
extern void ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(char *);
extern void ZUKAN_DETAIL_AREA_ResetBlendAlpha(char *);
extern void ZUKAN_DETAIL_AREA_ApplyBrightness(char *);
extern void ZUKAN_DETAIL_AREA_SetupSplitWindows(char *);
extern void ZUKAN_DETAIL_COMMON_SetBrightnessFull(int flag, int *p);
extern void ZUKAN_DETAIL_COMMON_TransferPalettes(char *p);
void ZUKAN_DETAIL_AREA_ApplyPendingEffect(void *unused, char *p)
{
    switch (((struct Obj08397 *)p)->f414) {
    case 1: ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(p); ZUKAN_DETAIL_AREA_ResetBlendAlpha(p); break;
    case 2: ZUKAN_DETAIL_AREA_ApplyBrightness(p); ZUKAN_DETAIL_AREA_SetupSplitWindows(p); break;
    case 3:
        ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(p);
        ZUKAN_DETAIL_AREA_ApplyBrightness(p);
        ZUKAN_DETAIL_COMMON_SetBrightnessFull(0, (int *)(((struct Obj08397 *)p)->f418));
        break;
    }
    ((struct Obj08397 *)p)->f414 = 0;
    ZUKAN_DETAIL_COMMON_TransferPalettes(((struct Obj08397 *)p)->f420);
}

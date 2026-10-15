/*
 * function: ZUKAN_DETAIL_VOICE_ApplyPendingDisplay
 * address:  0x021C2BA8
 * packet:   pkt_ov208_021C2BA8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   ZUKAN_DETAIL_COMMON_TransferPalettes  0x021BC6BC  thumb
 */
#include "../include/Obj08403.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void BG_SYS_PushTile(u32 index);
extern void ZUKAN_DETAIL_COMMON_TransferPalettes(char *p);

void ZUKAN_DETAIL_VOICE_ApplyPendingDisplay(void *unused, u8 *p)
{
    if (((struct Obj08403 *)p)->f1C != 0) {
        BG_SYS_FillScrollArea(3, 0, ((struct Obj08403 *)p)->f18 - 1);
        BG_SYS_FillScrollArea(3, 3, 0);
        BG_SYS_PushTile(3);
        ((struct Obj08403 *)p)->f1C = 0;
    }
    ZUKAN_DETAIL_COMMON_TransferPalettes(*(char * *)&((struct Obj08403 *)p)->fC8);
}

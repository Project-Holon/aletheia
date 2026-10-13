/*
 * function: POKELIST_UpdateSwapAnimation
 * address: 0x021B981C
 * packet: pkt_ov091_021B981C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PLIST_PLATE_ClearSlideTrail 0x021BB1A0 thumb ov091
 *   PLIST_PLATE_SetSlideOffset 0x021BB0C4 thumb ov091
 *   PLIST_PLATE_SetMon 0x021BB200 thumb ov091
 *   POKELIST_FinishSwap 0x021B999C thumb ov091
 *   POKEPARTY_SwapMembers 0x0201AB8C thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj01229.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PLIST_PLATE_ClearSlideTrail(int, u8 *, int);
extern void PLIST_PLATE_SetSlideOffset(u8 *p, const u8 *s, int d);
extern void PLIST_PLATE_SetMon(u8 *, u8 *, int, int);
extern void POKELIST_FinishSwap(u8 *);
struct Party;
extern u32 POKEPARTY_SwapMembers(struct Party *p, u32 i, u32 j, u32 heap);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int);
#define W(o) (*(int *)(p + (o)))
#define ROW(i) (*(u8 **)(p + (i) * 4 + 0x160))
void POKELIST_UpdateSwapAnimation(u8 *p)
{
    switch (p[0xe]) {
    case 3:
        PLIST_PLATE_ClearSlideTrail((int)p, ROW(W(0x2c)), p[0x104]);
        PLIST_PLATE_ClearSlideTrail((int)p, ROW(W(0x30)), p[0x104]);
        p[0x104]++;
        PLIST_PLATE_SetSlideOffset(p, ROW(W(0x2c)), p[0x104]);
        PLIST_PLATE_SetSlideOffset(p, ROW(W(0x30)), p[0x104]);
        if (p[0x104] >= 16) {
            POKEPARTY_SwapMembers((struct Party *)(*(int *)W(0x280)), W(0x2c), W(0x30), ((struct Obj01229 *)p)->f0);
            PLIST_PLATE_SetMon(p, ROW(W(0x2c)), (int)POKEPARTY_GetMember(*(void **)W(0x280), W(0x2c)), p[0x104]);
            PLIST_PLATE_SetMon(p, ROW(W(0x30)), (int)POKEPARTY_GetMember(*(void **)W(0x280), W(0x30)), p[0x104]);
            p[0xe] = 4;
            GFL_USE_PlaySeDefaultVolume(0x642);
        }
        break;
    case 4:
        PLIST_PLATE_ClearSlideTrail((int)p, ROW(W(0x2c)), p[0x104]);
        PLIST_PLATE_ClearSlideTrail((int)p, ROW(W(0x30)), p[0x104]);
        p[0x104]--;
        PLIST_PLATE_SetSlideOffset(p, ROW(W(0x2c)), p[0x104]);
        PLIST_PLATE_SetSlideOffset(p, ROW(W(0x30)), p[0x104]);
        if (p[0x104] == 0)
            POKELIST_FinishSwap(p);
        break;
    }
}

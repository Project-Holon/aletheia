/*
 * unit: yes
 * function: DENDOU_VIEW_StateRotate, DENDOU_VIEW_StateStartExit
 * address: 0x021DD3F4
 * packet: pkt_ov171_021DD3F4
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DENDOU_VIEW_AdvanceRotation 0x021DD774 thumb ov171
 *   DENDOU_VIEW_IsPaletteFadeBusy 0x021DCBE8 thumb ov171
 *   DENDOU_VIEW_DrawMemberInfo 0x021DDC28 thumb ov171
 *   DENDOU_VIEW_ApplyPaletteFade 0x021DCBA4 thumb ov171
 *   DENDOU_VIEW_StartWipeOut 0x021DD4D0 thumb ov171
 */
#include "../include/Obj00142.h"
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
extern int DENDOU_VIEW_AdvanceRotation(char *);
extern int DENDOU_VIEW_IsPaletteFadeBusy(u8 *p);
extern void DENDOU_VIEW_DrawMemberInfo(u8 *p);
extern void DENDOU_VIEW_ApplyPaletteFade(char *);
extern int DENDOU_VIEW_StartWipeOut(u8 *p, int value);
int DENDOU_VIEW_StateRotate(char *p)
{
    unsigned i;
    if (!DENDOU_VIEW_AdvanceRotation(p)) {
        for (i = 0; i < *(u16 *)(p + ((struct Obj00142 *)p)->fC5E * 0xbc + 0xc4); ++i)
            *(u8 *)(p + i + 0xb34) = *(u8 *)(p + i + 0xb40);
        DENDOU_VIEW_IsPaletteFadeBusy((u8 *)p);
        DENDOU_VIEW_DrawMemberInfo((u8 *)p);
        return 7;
    } else {
        for (i = 0; i < *(u16 *)(p + ((struct Obj00142 *)p)->fC5E * 0xbc + 0xc4); ++i) {
            if (*(u8 *)(p + i + 0xb3a) > *(u8 *)(p + i + 0xb40))
                --*(u8 *)(p + i + 0xb3a);
            else if (*(u8 *)(p + i + 0xb3a) < *(u8 *)(p + i + 0xb40))
                ++*(u8 *)(p + i + 0xb3a);
        }
        DENDOU_VIEW_ApplyPaletteFade(p);
        return 9;
    }
}
int DENDOU_VIEW_StateStartExit(char *p)
{
    return DENDOU_VIEW_StartWipeOut((u8 *)p, 1);
}

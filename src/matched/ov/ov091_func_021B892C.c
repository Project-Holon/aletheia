/*
 * function: POKELIST_ConfirmBattleParty
 * address:  0x021B892C
 * packet:   pkt_ov091_021B892C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The six-byte buffer is a block-scope initialised array
 * (an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six assignments sink `add r7, sp, #4` below the stores.
 *
 * symbols:
 *   PLIST_PLATE_SetSelected  0x021BAFA0  thumb  ov091
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   PLIST_PLATE_GetLabelState  0x021BB43C  thumb  ov091
 *   POKE_REGULATION_CheckSelection  0x02019E54  thumb
 *   POKELIST_ShowMessage  0x021B9788  thumb  ov091
 *   POKELIST_EndMessageToList  0x021B9E20  thumb  ov091
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   PLIST_MESSAGE_CreateWordSet  0x021BB97C  thumb  ov091
 *   PLIST_MESSAGE_SetWordSetNumber  0x021BB9EC  thumb  ov091
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb  ov091
 *   PLIST_MENU_ButtonWinSetActive  0x021BBE5C  thumb  ov091
 *   PLIST_MENU_ButtonWinSetDecide  0x021BBE68  thumb  ov091
 */
#include "../include/Obj06210.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void PLIST_PLATE_SetSelected(u8 *a, u8 *s, int k);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern int PLIST_PLATE_GetLabelState(int *p);
extern int  POKE_REGULATION_CheckSelection(u32 a0, u32 a1, u32 a2);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void POKELIST_EndMessageToList(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetNumber(int a, int b, int c, int d, unsigned char e);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void PLIST_MENU_ButtonWinSetActive(int h, int f);
extern void PLIST_MENU_ButtonWinSetDecide(int h, int f);

void POKELIST_ConfirmBattleParty(u8 *p)
{
    u8 *q;
    u8 i;
    int n;
    int r;

    q = (u8 *)((u32 *)W(0x280))[0x14 / 4];
    if (W(0x2c) != 6) {
        if ((int)W(0x2c) <= 5) {
            PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            CLACT_SetActorDrawEnable((struct Obj *)W(0x1d8), 0);
        }
        W(0x2c) = 6;
    }
    ((u32 *)W(0x280))[0x3c / 4] = 6;
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 6; i++) {
            n = PLIST_PLATE_GetLabelState((int *)(*(int *)(p + i * 4 + 0x160)));
            if (n <= 5) {
                buf[n] = i + 1;
            }
        }
        r = POKE_REGULATION_CheckSelection((u32)q, *(u32 *)W(0x280), (u32)buf);
    }
    if (q[2] > p[0x105]) {
        POKELIST_ShowMessage(p, q[2] + 0x56, 1, (int)POKELIST_EndMessageToList);
        GFL_USE_PlaySeDefaultVolume(0x557);
        return;
    }
    if (q[3] < p[0x105]) {
        POKELIST_ShowMessage(p, q[3] + 0x5c, 1, (int)POKELIST_EndMessageToList);
        GFL_USE_PlaySeDefaultVolume(0x557);
        return;
    }
    if (r == 1) {
        PLIST_MESSAGE_CreateWordSet((u16 *)p, W(0x150));
        PLIST_MESSAGE_SetWordSetNumber((int)p, W(0x150), 0, ((struct Obj06210 *)q)->f6, 3);
        POKELIST_ShowMessage(p, 0x92, 1, (int)POKELIST_EndMessageToList);
        GFL_USE_PlaySeDefaultVolume(0x557);
        PLIST_MESSAGE_DestroyWordSet(p, W(0x150));
        return;
    }
    if (r == 7) {
        POKELIST_ShowMessage(p, 0x94, 1, (int)POKELIST_EndMessageToList);
        GFL_USE_PlaySeDefaultVolume(0x557);
        return;
    }
    PLIST_MENU_ButtonWinSetActive(W(0x10c), 0);
    PLIST_MENU_ButtonWinSetDecide(W(0x108), 1);
    p[0xc] = 0xc;
    ((u32 *)W(0x280))[0x3c / 4] = 6;
    ((u32 *)W(0x280))[0x40 / 4] = 0;
    W(0x118) = 1;
    GFL_USE_PlaySeDefaultVolume(0x54c);
}

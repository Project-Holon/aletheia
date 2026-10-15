/*
 * function: BOX2_SEQ_StateSwapMenuE
 * address: 0x021E7D64
 * packet: pkt_ov170_021E7D64
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_UI_OpenListPack 0x021EF57C thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb ov170
 *   BOX2_MAIN_SetHandSlots 0x021DF110 thumb ov170
 *   BOX2_UI_PutTopBarThenClose 0x021EF6A8 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_MAIN_UpdateWindowMove 0x021E01A8 thumb ov170
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_SEQ_SetSlotActorMode 0x021ECB60 thumb ov170
 *   BOX2_SEQ_PrintMessageE 0x021EBBBC thumb ov170
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23918.h"
#include "../include/Obj23919.h"
#include "../include/Obj23920.h"
#include "../include/Obj23921.h"
#include "../include/Obj23922.h"
#include "../include/Obj23923.h"
#include "../include/Obj23924.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
extern void BOX2_SEQ_SetWindow9(u8 *, int, int);
extern void BOX2_SEQ_ShowWindowObject(char *, int);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***, unsigned short, int, unsigned, unsigned);
extern void BOX2_MAIN_SetHandSlots(char *p, int b);
extern void BOX2_UI_PutTopBarThenClose(struct WinMgr *mgr);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int BOX2_MAIN_UpdateWindowMove(char *p);
extern void BOX2_UI_MoveCursor(char **, int, int);
extern void BOX2_UI_ToggleSlotPair(char *, int);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_SEQ_SetSlotActorMode(char *, int, int);
extern void BOX2_SEQ_PrintMessageE(char *p, int b);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
int BOX2_SEQ_StateSwapMenuE(u8 *p)
{
    switch (((struct Obj23918 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 4, 0);
        BOX2_SEQ_SetWindow9(p, 14, 0);
        BOX2_SEQ_ShowWindowObject(*(char * *)&((struct Obj00000 *)p)->f2C, 24);
        BOX2_MAIN_RefreshCursorBox((char *)p);
        BOX2_UI_OpenListPack(*(struct WinMgr * *)&((struct Obj23919 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f74);
        (((struct Obj23920 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 85);
    case 1:
        ((struct Obj23921 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA174 = BOX2_MAIN_GetPartyValueAt((void ***)p, p[22], p[20], 11, 0);
        BOX2_MAIN_SetHandSlots((char *)p, ((struct Obj23922 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA174);
        BOX2_UI_PutTopBarThenClose(*(struct WinMgr * *)&((struct Obj23923 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f74);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((struct Obj23924 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)((int (*)(u8 *))BOX2_MAIN_UpdateWindowMove), 85);
    case 2:
        BOX2_UI_MoveCursor((char **)p, 9, 0);
        BOX2_UI_ToggleSlotPair(*(char * *)&((struct Obj00000 *)p)->f2C, 0);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_SetSlotActors((char *)p, 2, 1);
        BOX2_SEQ_SetSlotActorMode(*(char * *)&((struct Obj00000 *)p)->f2C, p[22], 0);
        BOX2_SEQ_PrintMessageE((char *)p, 24);
        return BOX2_SEQ_ReturnAfterClear((char *)p, 86);
    }
    return 85;
}

/*
 * function: BOX2_SEQ_StateMoveItemE
 * address: 0x021E8024
 * packet: pkt_ov170_021E8024
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb ov170
 *   BOX2_UI_OpenListPack 0x021EF57C thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_SEQ_SetSlotActorMode 0x021ECB60 thumb ov170
 *   BOX2_MAIN_HasOtherTradable 0x021DD694 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_PrintMonName 0x021EBBC8 thumb ov170
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb ov170
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   BOX2_SEQ_OpenYesNo 0x021E8FE8 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23928.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct WinMgr;
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
extern void BOX2_SEQ_SetWindow9(unsigned char *p, int a, int b);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *, int, int);
extern int BOX2_MAIN_IsWindowMoving(char *);
extern void BOX2_SEQ_SetSlotActors(char *, int, int);
extern void BOX2_SEQ_SetSlotActorMode(char *, int, int);
extern int BOX2_MAIN_HasOtherTradable(void ***, unsigned);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void BOX2_SEQ_PrintMonName(u8 *, unsigned, int);
extern int BOX2_SEQ_ReturnAfterClear(char *, int);
extern void *POKEPARTY_GetMember(void *, unsigned);
extern unsigned POKE_TOOL_GetPartyValue(void *, unsigned, unsigned);
extern unsigned FILE_UTIL_Check136C(u16);
extern void BOX2_SEQ_PrintPrompt(u8 *, int, int, int);
extern void BOX2_UI_ToggleSlotPair(char *, int);
extern int BOX2_MAIN_GetMonAt(void ***, int, unsigned);
extern unsigned POKE_TOOL_GetBoxValue(void *, unsigned, unsigned);
extern int BOX2_SEQ_OpenYesNo(u8 *, int);
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
int BOX2_SEQ_StateMoveItemE(char *p)
{
    unsigned slot;
    switch (S) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable(W, 4, 0);
        BOX2_SEQ_SetWindow9((unsigned char *)p, 14, 0);
        BOX2_UI_OpenListPack(*(struct WinMgr **)(W + 0x74));
        S++;
        return BOX2_SEQ_SetSeqThird(p, (int)BOX2_MAIN_IsWindowMoving, 0x59);
    case 1:
        if (((struct Obj00000 *)p)->f16 >= 30) {
            BOX2_SEQ_SetSlotActors(p, 2, 1);
            BOX2_SEQ_SetSlotActorMode(W, ((struct Obj00000 *)p)->f16, 0);
            slot = ((struct Obj00000 *)p)->f16 - 30;
            if (BOX2_MAIN_HasOtherTradable((void ***)p, slot) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x557);
                BOX2_SEQ_PrintMonName((u8 *)p, 6, 24);
                *(u8 *)(W + 0xA170) = 1;
                ((struct Obj00000 *)p)->f28 = 14;
                return BOX2_SEQ_ReturnAfterClear(p, 6);
            }
            if (FILE_UTIL_Check136C(POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(((struct Obj23928 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8, slot), 6, 0)) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x557);
                BOX2_SEQ_PrintPrompt((u8 *)p, 0, 5, 24);
                *(u8 *)(W + 0xA170) = 1;
                ((struct Obj00000 *)p)->f28 = 14;
                return BOX2_SEQ_ReturnAfterClear(p, 6);
            }
        } else {
            BOX2_UI_ToggleSlotPair(W, 0);
            BOX2_SEQ_SetSlotActors(p, 1, 1);
            BOX2_SEQ_SetSlotActorMode(W, ((struct Obj00000 *)p)->f16, 0);
        }
        if (POKE_TOOL_GetBoxValue((void *)BOX2_MAIN_GetMonAt((void ***)p, ((struct Obj00000 *)p)->f14, ((struct Obj00000 *)p)->f16), 0x4c, 0) != 0) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_PrintMonName((u8 *)p, 3, 24);
            *(u8 *)(W + 0xA170) = 1;
            ((struct Obj00000 *)p)->f28 = 14;
            return BOX2_SEQ_ReturnAfterClear(p, 6);
        }
        BOX2_SEQ_PrintMonName((u8 *)p, 0, 24);
        return BOX2_SEQ_ReturnAfterClear(p, BOX2_SEQ_OpenYesNo((u8 *)p, 1));
    }
    return 0x59;
}

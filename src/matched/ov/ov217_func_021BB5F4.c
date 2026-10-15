/*
 * function: RESEARCH_LIST_UpdateSaveExit
 * address: 0x021BB5F4
 * packet: pkt_ov217_021BB5F4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BB910 retains supplied r1=13 through its forwarding chain.
 * symbols:
 *   RESEARCH_LIST_GetSubState 0x021BB98C thumb ov217
 *   RESEARCH_LIST_FindSaveIndex 0x021BBC50 thumb ov217
 *   RESEARCH_LIST_ShiftTextLeft 0x021BBE7C thumb ov217
 *   RESEARCH_LIST_StoreSaveValues 0x021BBCB0 thumb ov217
 *   RESEARCH_LIST_GetSelectedIndex 0x021BC6E4 thumb ov217
 *   RESEARCH_LIST_ShiftTextRight 0x021BBDF0 thumb ov217
 *   RESEARCH_LIST_UpdateEntryActor 0x021BC014 thumb ov217
 *   RESEARCH_LIST_SetOamEnabled 0x021BC72C thumb ov217
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   RESEARCH_LIST_IncSubState 0x021BB990 thumb ov217
 *   RESEARCH_LIST_FadeOut 0x021BC490 thumb ov217
 *   RESEARCH_LIST_IsFadeDone 0x021BC4A0 thumb ov217
 *   RESEARCH_LIST_HideEntryPalette 0x021BC50C thumb ov217
 *   RESEARCH_LIST_IsPaletteFadeDone 0x021BC55C thumb ov217
 *   RESEARCH_LIST_SetCommandReady 0x021BB91C thumb ov217
 *   RESEARCH_LIST_PushCommand 0x021BB910 thumb ov217
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
extern unsigned RESEARCH_LIST_GetSubState(void *);
extern u8 RESEARCH_LIST_FindSaveIndex(u8 *);
extern void RESEARCH_LIST_ShiftTextLeft(unsigned int object, unsigned int slot);
extern void RESEARCH_LIST_StoreSaveValues(u8 *);
extern unsigned RESEARCH_LIST_GetSelectedIndex(void *);
extern void RESEARCH_LIST_ShiftTextRight(unsigned int object, unsigned int slot);
extern void RESEARCH_LIST_UpdateEntryActor(u8 *);
extern void RESEARCH_LIST_SetOamEnabled(u8 *, unsigned, u8 *);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void RESEARCH_LIST_IncSubState(void *);
extern void RESEARCH_LIST_FadeOut(void);
extern int RESEARCH_LIST_IsFadeDone(void);
extern void RESEARCH_LIST_HideEntryPalette(char *p);
extern unsigned RESEARCH_LIST_IsPaletteFadeDone(unsigned);
extern void RESEARCH_LIST_SetCommandReady(void *);
extern void RESEARCH_LIST_PushCommand(u8 *, unsigned);
void RESEARCH_LIST_UpdateSaveExit(u8 *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        RESEARCH_LIST_ShiftTextLeft((unsigned int)p, RESEARCH_LIST_FindSaveIndex(p));
        RESEARCH_LIST_StoreSaveValues(p);
        RESEARCH_LIST_ShiftTextRight((unsigned int)p, RESEARCH_LIST_GetSelectedIndex(p));
        RESEARCH_LIST_UpdateEntryActor(p);
        RESEARCH_LIST_SetOamEnabled(p, 3, (u8 *)1);
        GFL_USE_PlaySeDefaultVolume(1898);
        RESEARCH_LIST_IncSubState(p);
        break;
    case 1:
        if (((struct Obj00025 *)p)->f24 >= 60) {
            RESEARCH_LIST_FadeOut();
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 2:
        if (RESEARCH_LIST_IsFadeDone()) {
            RESEARCH_LIST_HideEntryPalette((char *)p);
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 3:
        if (RESEARCH_LIST_IsPaletteFadeDone((unsigned)p)) {
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand(p, 13);
        }
        break;
    }
}

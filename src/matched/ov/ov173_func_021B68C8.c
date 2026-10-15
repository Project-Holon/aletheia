/*
 * function: POKE_SUMMARY_MAIN_HandleInput
 * address: 0x021B68C8
 * packet: pkt_ov173_021B68C8
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKE_SUMMARY_ACTOR_ShowTextKind1Or4 0x021B817C thumb ov173
 *   POKE_SUMMARY_ACTOR_IsTaskMenuOpen 0x021B7F50 thumb ov173
 *   POKE_SUMMARY_ACTOR_ConfirmDecideById 0x021B80EC thumb ov173
 *   POKE_SUMMARY_ACTOR_OpenDecideWin 0x021B80A4 thumb ov173
 *   POKE_SUMMARY_ACTOR_ToggleTaskMenu 0x021B7EB0 thumb ov173
 *   POKE_SUMMARY_ACTOR_ConfirmDecide 0x021B80C4 thumb ov173
 *   POKE_SUMMARY_MAIN_GetRecordWord 0x021B7438 thumb ov173
 *   POKE_SUMMARY_MAIN_DrawMoveDetail 0x021B71C4 thumb ov173
 *   POKE_SUMMARY_MAIN_RedrawMoveList 0x021B70D8 thumb ov173
 *   POKE_SUMMARY_ACTOR_UpdateScrollArrows 0x021B7F64 thumb ov173
 *   POKE_SUMMARY_ACTOR_SetScrollAnim 0x021B7FD0 thumb ov173
 */
#include "../include/Obj00362.h"
#include "../include/Obj24153.h"
#include "../include/Obj24154.h"
#include "../include/Obj24155.h"
#include "../include/Obj24156.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *);
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int POKE_SUMMARY_ACTOR_ShowTextKind1Or4(char *p);
extern int POKE_SUMMARY_ACTOR_IsTaskMenuOpen(char *);
extern int POKE_SUMMARY_ACTOR_ConfirmDecideById(char *,u16);
extern int POKE_SUMMARY_ACTOR_OpenDecideWin(char *,u16);
extern void POKE_SUMMARY_ACTOR_ToggleTaskMenu(char *,int);
extern int POKE_SUMMARY_ACTOR_ConfirmDecide(u8 *p, u16 n);
extern u16 POKE_SUMMARY_MAIN_GetRecordWord(char **);
extern void POKE_SUMMARY_MAIN_DrawMoveDetail(char *,int);
extern void POKE_SUMMARY_MAIN_RedrawMoveList(char *);
extern void POKE_SUMMARY_ACTOR_UpdateScrollArrows(char *);
extern void POKE_SUMMARY_ACTOR_SetScrollAnim(u8 *,int);
int POKE_SUMMARY_MAIN_HandleInput(char *p)
{
    u32 v;
    ((struct Obj00362 *)p)->f1CC=CURSOR_MOVE_GetCurrent(*(struct Sound * *)&((struct Obj00362 *)p)->f1C8);
    v=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj00362 *)p)->f1C8);
    switch(v) {
    case 0:case 1:case 2:case 3:
        if(TOUCHPANEL_GetTrg()==0) {
            if(((struct Obj24153 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16+v < ((struct Obj00362 *)p)->f1B8) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                return POKE_SUMMARY_ACTOR_ShowTextKind1Or4(p);
            }
        } else {
            if(((struct Obj24154 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16+v < ((struct Obj00362 *)p)->f1B8)
                GFL_USE_PlaySeDefaultVolume(0x54c);
        }
        break;
    case 4:case 5:break;
    case 6:case 8:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if(POKE_SUMMARY_ACTOR_IsTaskMenuOpen(p)) return POKE_SUMMARY_ACTOR_ConfirmDecideById(p,14);
        else return POKE_SUMMARY_ACTOR_OpenDecideWin(p,14);
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,0);
        return POKE_SUMMARY_ACTOR_OpenDecideWin(p,14);
    case 7:
        if(POKE_SUMMARY_ACTOR_IsTaskMenuOpen(p)) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return POKE_SUMMARY_ACTOR_ConfirmDecide((u8 *)p,15);
        }
        break;
    case -8:
        if(((struct Obj24155 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16!=0) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            --((struct Obj24156 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16;
            POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
            POKE_SUMMARY_MAIN_RedrawMoveList(p);
            POKE_SUMMARY_ACTOR_UpdateScrollArrows(p);
            POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)p,-1);
        }
        break;
    case -4:case -3:case -1:break;
    }
    return 1;
}

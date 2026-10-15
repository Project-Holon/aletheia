/*
 * function: POKE_SUMMARY_MAIN_Update
 * address: 0x021B6174
 * packet: pkt_ov173_021B6174
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final 2 bytes are alignment padding
 * symbols:
 *   POKE_SUMMARY_MAIN_WaitWipe 0x021B68B0 thumb ov173
 *   POKE_SUMMARY_MAIN_HandleInput 0x021B68C8 thumb ov173
 *   POKE_SUMMARY_MAIN_UpdateText 0x021B69F8 thumb ov173
 *   POKE_SUMMARY_MAIN_OpenMenu 0x021B6A64 thumb ov173
 *   POKE_SUMMARY_MAIN_UpdateMenu 0x021B6AAC thumb ov173
 *   POKE_SUMMARY_MAIN_ApplyMove 0x021B6B0C thumb ov173
 *   POKE_SUMMARY_MAIN_ShowTextKind6 0x021B6B54 thumb ov173
 *   POKE_SUMMARY_MAIN_ShowMoveText 0x021B6B6C thumb ov173
 *   POKE_SUMMARY_MAIN_StartWipe 0x021B6BA0 thumb ov173
 *   POKE_SUMMARY_ACTOR_StartWipe 0x021B7B60 thumb ov173
 *   POKE_SUMMARY_ACTOR_StartProc 0x021B7B8C thumb ov173
 *   POKE_SUMMARY_ACTOR_StartNetRestart 0x021B7C00 thumb ov173
 *   POKE_SUMMARY_ACTOR_WaitDecide 0x021B8110 thumb ov173
 *   POKE_SUMMARY_ACTOR_ShowTextKind2 0x021B815C thumb ov173
 *   POKE_SUMMARY_ACTOR_ShowTextKind1Or4 0x021B817C thumb ov173
 *   POKE_SUMMARY_MAIN_UpdateTaskMenu 0x021B6390 thumb ov173
 *   CLACT_DrawSystem 0x0204A600 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj06564.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Tcbl;
extern int POKE_SUMMARY_MAIN_WaitWipe(int *p);
extern int POKE_SUMMARY_MAIN_HandleInput(char *p);
extern int POKE_SUMMARY_MAIN_UpdateText(char *p);
extern int POKE_SUMMARY_MAIN_OpenMenu(u8 *p);
extern int POKE_SUMMARY_MAIN_UpdateMenu(u8 *p);
extern int POKE_SUMMARY_MAIN_ApplyMove(char **p);
extern int POKE_SUMMARY_MAIN_ShowTextKind6(int *p);
extern int POKE_SUMMARY_MAIN_ShowMoveText(char *p);
extern int POKE_SUMMARY_MAIN_StartWipe(char *p);
extern int POKE_SUMMARY_ACTOR_StartWipe(u8 *p);
extern int POKE_SUMMARY_ACTOR_StartProc(char *p);
extern int POKE_SUMMARY_ACTOR_StartNetRestart(void *);
extern int POKE_SUMMARY_ACTOR_WaitDecide(u8 *p);
extern int POKE_SUMMARY_ACTOR_ShowTextKind2(char *p);
extern int POKE_SUMMARY_ACTOR_ShowTextKind1Or4(char *p);
extern void POKE_SUMMARY_MAIN_UpdateTaskMenu(int *p);
extern void CLACT_DrawSystem(void);
extern void TCBL_Main(struct Tcbl *p);
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
int POKE_SUMMARY_MAIN_Update(void *unused0,u32 *state,void *unused2,u8 *p)
{
    switch(*state) {
    case 0: *state=POKE_SUMMARY_MAIN_WaitWipe((int *)p);break;
    case 1: *state=POKE_SUMMARY_MAIN_HandleInput((char *)p);break;
    case 2: *state=POKE_SUMMARY_MAIN_UpdateText((char *)p);break;
    case 3: *state=POKE_SUMMARY_MAIN_OpenMenu(p);break;
    case 4: *state=POKE_SUMMARY_MAIN_UpdateMenu(p);break;
    case 5: *state=POKE_SUMMARY_MAIN_ApplyMove((char **)p);break;
    case 6: *state=POKE_SUMMARY_MAIN_ShowTextKind6((int *)p);break;
    case 7: *state=POKE_SUMMARY_MAIN_ShowMoveText((char *)p);break;
    case 8: *state=POKE_SUMMARY_MAIN_StartWipe((char *)p);break;
    case 9: return 1;
    case 10: *state=POKE_SUMMARY_ACTOR_StartWipe(p);break;
    case 11: *state=POKE_SUMMARY_ACTOR_StartProc((char *)p);return 0;
    case 12: *state=POKE_SUMMARY_ACTOR_StartNetRestart(p);return 0;
    case 13: *state=POKE_SUMMARY_ACTOR_WaitDecide(p);break;
    case 14: *state=POKE_SUMMARY_ACTOR_ShowTextKind2((char *)p);break;
    case 15: *state=POKE_SUMMARY_ACTOR_ShowTextKind1Or4((char *)p);break;
    }
    POKE_SUMMARY_MAIN_UpdateTaskMenu((int *)p);
    CLACT_DrawSystem();
    TCBL_Main(((struct Obj06564 *)p)->f64);
    PRINTSYS_QUE_Main(((struct Obj06564 *)p)->f218);
    return 0;
}

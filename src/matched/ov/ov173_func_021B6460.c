/*
 * function: POKE_SUMMARY_MAIN_ExitScreen
 * address: 0x021B6460
 * packet: pkt_ov173_021B6460
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_SUMMARY_MAIN_DeleteTaskMenu 0x021B6348 thumb ov173
 *   POKE_SUMMARY_ACTOR_UpdateSound 0x021B7C7C thumb ov173
 *   POKE_SUMMARY_MAIN_DeleteMoveList 0x021B71B8 thumb ov173
 *   POKE_SUMMARY_MAIN_DeleteBmpWindows 0x021B6828 thumb ov173
 *   POKE_SUMMARY_MAIN_DeleteMsgWindow 0x021B6794 thumb ov173
 *   POKE_SUMMARY_MAIN_ExitDisplay 0x021B6678 thumb ov173
 *   POKE_SUMMARY_MAIN_DeleteText 0x021B688C thumb ov173
 *   POKE_SUMMARY_ACTOR_DeleteSystem 0x021B7694 thumb ov173
 *   func_02030EAC 0x02030EAC arm
 */
#include "../include/Obj00362.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void POKE_SUMMARY_MAIN_DeleteTaskMenu(u8 *);
extern int POKE_SUMMARY_ACTOR_UpdateSound(int *);
extern void POKE_SUMMARY_MAIN_DeleteMoveList(char *);
extern void POKE_SUMMARY_MAIN_DeleteBmpWindows(char *);
extern int POKE_SUMMARY_MAIN_DeleteMsgWindow(int *);
extern void POKE_SUMMARY_MAIN_ExitDisplay(void);
extern void POKE_SUMMARY_MAIN_DeleteText(char *);
extern void POKE_SUMMARY_ACTOR_DeleteSystem(u8 *p);
struct Node;
extern void func_02030EAC(struct Node *n);
void POKE_SUMMARY_MAIN_ExitScreen(char *p) { POKE_SUMMARY_MAIN_DeleteTaskMenu((u8 *)p); POKE_SUMMARY_ACTOR_UpdateSound((int *)p); POKE_SUMMARY_MAIN_DeleteMoveList(p); POKE_SUMMARY_MAIN_DeleteBmpWindows(p); POKE_SUMMARY_MAIN_DeleteMsgWindow((int *)p); POKE_SUMMARY_MAIN_ExitDisplay(); POKE_SUMMARY_MAIN_DeleteText(p); POKE_SUMMARY_ACTOR_DeleteSystem((u8 *)p); func_02030EAC(((struct Obj00362 *)p)->f68); }

/*
 * function: COMM_BTL_DEMO_MAIN_UpdateRowContext
 * address: 0x021BA30C
 * packet: pkt_ov213_021BA30C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   COMM_BTL_DEMO_MAIN_UpdateRowDelay 0x021BA14C thumb ov213
 *   COMM_BTL_DEMO_MAIN_HasVisibleActors 0x021B9E80 thumb ov213
 *   COMM_BTL_DEMO_MAIN_RefreshRowText 0x021BA2E0 thumb ov213
 */
#include "../include/Obj08419.h"
extern void COMM_BTL_DEMO_MAIN_UpdateRowDelay(char *,unsigned),COMM_BTL_DEMO_MAIN_RefreshRowText(char *);extern int COMM_BTL_DEMO_MAIN_HasVisibleActors(unsigned);
void COMM_BTL_DEMO_MAIN_UpdateRowContext(char *p,unsigned limit){COMM_BTL_DEMO_MAIN_UpdateRowDelay(p+32,limit);if(COMM_BTL_DEMO_MAIN_HasVisibleActors(((struct Obj08419 *)p)->f10))COMM_BTL_DEMO_MAIN_RefreshRowText(p);(((struct Obj08419 *)p)->f50)++;}

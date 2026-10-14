/*
 * function: GURU2_MAIN_StateWaitBranch
 * address: 0x021DED88
 * packet: pkt_ov137_021DED88
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_IsAbortVoted 0x021E1974 thumb ov137
 *   GURU2_MAIN_CountContinueVotes 0x021E1954 thumb ov137
 */
#include "../include/Obj06536.h"
typedef unsigned short u16;
extern int GURU2_MAIN_IsAbortVoted(char *);
extern int GURU2_MAIN_CountContinueVotes(char *);
int GURU2_MAIN_StateWaitBranch(char *p) {if(GURU2_MAIN_IsAbortVoted(p)==1)((struct Obj06536 *)p)->f0=45;else if(((struct Obj06536 *)p)->f30==GURU2_MAIN_CountContinueVotes(p))((struct Obj06536 *)p)->f0=16;return 0;}

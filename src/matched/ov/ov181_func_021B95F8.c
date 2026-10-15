/*
 * function: STAFF_ROLL_RunState
 * address: 0x021B95F8
 * packet: pkt_ov181_021B95F8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STAFF_ROLL_UpdateInput 0x021BA318 thumb ov181
 *   STAFF_ROLL_PrintNextRow 0x021B9C80 thumb ov181
 *   STAFF_ROLL_Draw3d 0x021B9F40 thumb ov181
 *   d_021BAB70 0x021BAB70 data a4
 */
#include "../include/Obj14406.h"
extern void STAFF_ROLL_UpdateInput(unsigned char *),STAFF_ROLL_PrintNextRow(char *),STAFF_ROLL_Draw3d(char *);
extern int (*const d_021BAB70[])(char *);
int STAFF_ROLL_RunState(char *p){STAFF_ROLL_UpdateInput((unsigned char *)p);((struct Obj14406 *)p)->f2E8=d_021BAB70[*(unsigned *)(p+0x2e8)](p);if(((struct Obj14406 *)p)->f2E8==5)return 0;STAFF_ROLL_PrintNextRow(p);STAFF_ROLL_Draw3d(p);return 1;}

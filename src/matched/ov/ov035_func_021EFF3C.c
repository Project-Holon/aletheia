/*
 * function: C_GEAR_POWER_ONOFF_Update
 * address: 0x021EFF3C
 * packet: pkt_ov035_021EFF3C
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sPowerOnOffTable 0x021F0640 data ov035 a4
 *   FIELD_SUBSCREEN_SetPanelResult 0x021A0FA0 thumb ov021
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj02409.h"
extern int (*sPowerOnOffTable[])(char *);
typedef unsigned int   u32;
struct PrintSys;
extern void FIELD_SUBSCREEN_SetPanelResult(int *p, int v);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
void C_GEAR_POWER_ONOFF_Update(char *p, int a1) { if(((struct Obj02409 *)p)->f4E==0) { if(sPowerOnOffTable[*(unsigned short *)(p+0x48)](p)) { FIELD_SUBSCREEN_SetPanelResult(((struct Obj02409 *)p)->fC,14); ((struct Obj02409 *)p)->f4E=1; } } PRINTSYS_QUE_Main(((struct Obj02409 *)p)->f3C); }

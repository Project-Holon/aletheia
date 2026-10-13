/*
 * function: C_GEAR_POWER_ONOFF_ExitScreen
 * address: 0x021EFFD4
 * packet: pkt_ov035_021EFFD4
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_SUBSCREEN_ResumeField 0x021A0FB4 thumb ov021
 *   C_GEAR_POWER_ONOFF_ExitWindows 0x021F0218 thumb ov035
 *   C_GEAR_POWER_ONOFF_DeleteTaskMenuRes 0x021F015C thumb ov035
 *   C_GEAR_POWER_ONOFF_ExitBgs 0x021F0100 thumb ov035
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 */
#include "../include/Obj05127.h"
typedef unsigned int   u32;
struct PrintSys;
struct Rec;
extern void FIELD_SUBSCREEN_ResumeField(u32 *p, u32 a);
extern void C_GEAR_POWER_ONOFF_ExitWindows(char *);
extern void C_GEAR_POWER_ONOFF_DeleteTaskMenuRes(char *);
extern void C_GEAR_POWER_ONOFF_ExitBgs(char *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
void C_GEAR_POWER_ONOFF_ExitScreen(char *p) { FIELD_SUBSCREEN_ResumeField(((struct Obj05127 *)p)->fC,((struct Obj05127 *)p)->f0); C_GEAR_POWER_ONOFF_ExitWindows(p); C_GEAR_POWER_ONOFF_DeleteTaskMenuRes(p); C_GEAR_POWER_ONOFF_ExitBgs(p); PRINTSYS_QUE_Clear(((struct Obj05127 *)p)->f3C); PRINTSYS_QUE_Delete(((struct Obj05127 *)p)->f3C); MSGDATA_Delete(((struct Obj05127 *)p)->f38); GF_FONT_Delete(((struct Obj05127 *)p)->f34); }

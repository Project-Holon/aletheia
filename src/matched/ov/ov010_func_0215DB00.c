/*
 * function: SCRCMD_MUSICAL_SelectPartyMon
 * address: 0x0215DB00
 * packet: pkt_ov010_0215DB00
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   EVENT_POKE_STATUS_CreatePokeSelectStatusEvent 0x0215A168 thumb ov010
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 */
typedef unsigned short u16;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *EVENT_POKE_STATUS_CreatePokeSelectStatusEvent(int a, int b, int c);
extern void SCRIPT_SYS_CallEvent(void *,void *);
int SCRCMD_MUSICAL_SelectPartyMon(void *a,void *b)
{
 int x = (int)SCRIPT_WORK_ReadWorkPointer(a,b);
 int y = (int)SCRIPT_WORK_ReadWorkPointer(a,b);
 void *p = SCRCMD_WORK_GetScriptWork(b);
 SCRIPT_SYS_CallEvent(p,EVENT_POKE_STATUS_CreatePokeSelectStatusEvent((int)SCRCMD_WORK_GetGameSystem(b),x,y));
 return 1;
}

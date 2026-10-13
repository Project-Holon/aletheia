/*
 * function: FLD_FACEUP_ScrCmdWaitEnd
 * address: 0x02164994
 * packet: pkt_ov010_02164994
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   func_020122C0 0x020122C0 thumb
 *   FLD_FACEUP_EndEvent 0x021649E8 thumb ov010
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Desc;
extern struct Desc *func_020122C0(void *,void *,void *,u32);
extern int FLD_FACEUP_EndEvent(void *,int *);
extern void SCRIPT_SYS_CallEvent(void *,void *);
int FLD_FACEUP_ScrCmdWaitEnd(void *a,void *b){void *v=SCRCMD_WORK_GetScriptWork(b);void *t=func_020122C0(SCRCMD_WORK_GetGameSystem(b),0,(void *)FLD_FACEUP_EndEvent,0);if(t==0)return 1;SCRIPT_SYS_CallEvent(v,t);return 1;}

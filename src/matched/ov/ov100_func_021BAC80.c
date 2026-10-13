/*
 * function: IRCBATTLEMATCH_StepStartChangeover
 * address: 0x021BAC80
 * packet: pkt_ov100_021BAC80
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 0x021799C0 is the ov015 Thumb callback setter, while ov009
 *   holds unrelated interior ARM instructions at the overlapping address.
 * symbols:
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_021799C0 0x021799C0 thumb ov015
 *   IRCBATTLEMATCH_IsCompatibleGameKind 0x021BAAEC thumb ov100
 *   GFL_NET_StartChangeoverEx 0x0203D060 arm
 *   IRCBATTLEMATCH_CollectMacAddresses 0x021B9FBC thumb ov100
 *   IRCBATTLEMATCH_OnChangeoverResult 0x021B9FF4 thumb ov100
 *   IRCBATTLEMATCH_OnChangeoverConnected 0x021B9848 thumb ov100
 *   IRCBATTLEMATCH_StepWaitSession 0x021BB270 thumb ov100
 */
#include "../include/Obj22085.h"
extern int GFL_NET_GetRunState(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021799C0(int a);
extern int IRCBATTLEMATCH_IsCompatibleGameKind(int a, int b);
extern void GFL_NET_StartChangeoverEx(u32 a, u32 b, u32 c);
extern void IRCBATTLEMATCH_CollectMacAddresses(int a);
extern void IRCBATTLEMATCH_OnChangeoverResult(int a, int b);
extern void IRCBATTLEMATCH_OnChangeoverConnected(int a);
extern void IRCBATTLEMATCH_StepWaitSession(int p);
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
void IRCBATTLEMATCH_StepStartChangeover(int a) {
 if(GFL_NET_GetRunState()==1) {
  switch(((struct Obj22085 *)a)->f24C) { case 9: case 10: func_021799C0((int)IRCBATTLEMATCH_IsCompatibleGameKind); break; }
  GFL_NET_StartChangeoverEx((u32)IRCBATTLEMATCH_CollectMacAddresses,(u32)IRCBATTLEMATCH_OnChangeoverResult,(u32)IRCBATTLEMATCH_OnChangeoverConnected);
  IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepWaitSession);
 }
}

/*
 * function: IRCBATTLEMATCH_CollectMacAddresses
 * address: 0x021B9FBC
 * packet: pkt_ov100_021B9FBC
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: larger state-store follower 0x021B9FF4 is filed separately.
 * symbols:
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GFL_NET_IRC_WIRELESS_GetMacAddress 0x0203D0B8 arm
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepRegisterCommands 0x021B9F80 thumb ov100
 */
typedef unsigned int   u32;
extern u32 GFL_NET_IsParentAid(void);
extern void GFL_NET_IRC_WIRELESS_GetMacAddress(void *,int);
typedef unsigned char  u8;
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StepRegisterCommands(unsigned a);
void IRCBATTLEMATCH_CollectMacAddresses(int a) {
 if(GFL_NET_IsParentAid()!=0) {
  char *p;
  int i=0;
  p=(char *)(a+0x260);
  for(;i<4;i++) GFL_NET_IRC_WIRELESS_GetMacAddress(p+i*6,i);
 }
 IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepRegisterCommands);
}

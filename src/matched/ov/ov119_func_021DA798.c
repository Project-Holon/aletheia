/*
 * function: func_021DA798
 * address: 0x021DA798
 * packet: pkt_ov119_021DA798
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   POKETRADE_NEGO_CheckCancelTouch 0x021DD24C thumb ov119
 *   POKETRADE_NEGO_CloseCancelMenu 0x021DD294 thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DA76C 0x021DA76C thumb ov119
 *   func_021DAEF0 0x021DAEF0 thumb ov119
 */
#include "../include/Obj08055.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Link;
struct MsgBank;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int POKETRADE_PROC_IsNetSession(void *);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern int POKETRADE_NEGO_CheckCancelTouch(char *p);
extern void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void func_021DA76C(void *);
extern void func_021DAEF0(char *p);
void func_021DA798(char *p) {
 int i, j, v;
 unsigned char a, b;
 i = GFL_NET_GetHandleNetID((struct Link *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()));
 j = 1 - i;
 if(POKETRADE_PROC_IsNetSession(p) && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),27,8)==0) {
  POKETRADE_NEGO_CheckCancelTouch(p);
  return;
 }
 POKETRADE_NEGO_CloseCancelMenu(p,1,1);
 a = (p+i)[0x11e0];
 if(a==2 && ((unsigned char *)(p+j))[0x11e0]==2) {
  if(POKETRADE_PROC_IsNetSession(p)) GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),13,8);
  POKETRADE_PROC_SetStep(p,(int)func_021DA76C);
  return;
 }
 b = (p+j)[0x11e0];
 if(b==5) v=0x61;
 else if(a==5) v=0x62;
 else if(b==7) v=0x63;
 else if(a==7) v=0x64;
 else if(b==8) v=0x64;
 else if(a==8) v=0x63;
 else if(b==9) v=0x61;
 else if(a==9) v=0x65;
 else if(b==6) v=0x61;
 else if(a==6) v=0x6f;
 else if(b==3) v=0x61;
 else if(a==3) v=0x66;
 MSGDATA_ReadString((struct MsgBank *)(((struct Obj08055 *)p)->f720),v,(void *)(((struct Obj08055 *)p)->f738));
 POKETRADE_SAVE_OpenMessageWindowTop(p);
 p[0x11e0]=0;
 p[0x11e1]=0;
 POKETRADE_PROC_SetStep(p,(int)func_021DAEF0);
}

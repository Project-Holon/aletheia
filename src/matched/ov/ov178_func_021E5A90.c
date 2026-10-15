/*
 * function: PARTY_STATUS_NetSync2
 * address: 0x021E5A90
 * packet: pkt_ov178_021E5A90
 * region: ov178
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   LIVEBATTLEMATCH_IRC_SendSaveData 0x0217E258 thumb ov176
 *   LIVEBATTLEMATCH_IRC_RecvSaveData 0x0217E298 thumb ov176
 *   LIVEBATTLEMATCH_IRC_NoOp 0x0217E074 thumb ov176
 */
typedef unsigned int   u32;
struct Entry;
extern u32 func_0200FB24(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,u32,u32);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,u32,u32);
extern int LIVEBATTLEMATCH_IRC_SendSaveData(int unused, int arg);
typedef unsigned char  u8;
extern int LIVEBATTLEMATCH_IRC_RecvSaveData(u8 *p, const void *q);
extern void LIVEBATTLEMATCH_IRC_NoOp(void *);
unsigned PARTY_STATUS_NetSync2(void **d,unsigned *c,unsigned *state)
{
 if(func_0200FB24()!=0){GFL_NET_ERR_RequestScreen();c[2]=2;return 1;}
 switch(*state) {
 case 0:++*state;break;
 case 1:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x11,0x1F);++*state;break;
 case 2:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x11,0x1F)!=0)++*state;break;
 case 3:if(LIVEBATTLEMATCH_IRC_SendSaveData((int)(*d),c[3])!=0)++*state;break;
 case 4:if(LIVEBATTLEMATCH_IRC_RecvSaveData(*d,(const void *)c[4])!=0)++*state;break;
 case 5:return 1;
 }
 LIVEBATTLEMATCH_IRC_NoOp(*d);return 0;
}

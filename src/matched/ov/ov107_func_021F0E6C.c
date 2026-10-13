/*
 * function: func_021F0E6C
 * address: 0x021F0E6C
 * packet: pkt_ov107_021F0E6C
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the epilogue.
 * symbols:
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsNegotiationDone 0x020399B8 arm
 *   GFL_NET_IsHandleReady 0x0203D394 arm
 *   func_02039CB4 0x02039CB4 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_021F11F0 0x021F11F0 thumb ov107
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Link;
extern int GFL_NET_HANDLE_CheckNegotiation(void);extern void *GFL_NET_HANDLE_GetCurrentHandle(void);extern int GFL_NET_HANDLE_IsNegotiationDone(void *);extern int GFL_NET_IsHandleReady(void *);extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);extern void GFL_NET_SetLoginOption(int);extern int func_021F11F0(void *,u8,u32);
typedef struct {u32 f00,f04,f08,f0C;} State;
void func_021F0E6C(State *p){switch(p->f04){case 0:break;case 1:if(GFL_NET_HANDLE_CheckNegotiation()==1)p->f04=2;break;case 2:if(GFL_NET_HANDLE_IsNegotiationDone(GFL_NET_HANDLE_GetCurrentHandle())==1)p->f04=3;break;case 3:if(GFL_NET_IsHandleReady(GFL_NET_HANDLE_GetCurrentHandle())==1){p->f04=6;GFL_NET_SetLoginOption(1);}break;case 4:if(func_02039CB4(GFL_NET_HANDLE_GetCurrentHandle(),64,4)==1){p->f04=5;GFL_NET_SetLoginOption(0);}break;case 5:case 6:default:break;}
if(p->f0C!=p->f08&&p->f08!=0){if(func_021F11F0(p,10,p->f08)==1)p->f0C=p->f08;}}

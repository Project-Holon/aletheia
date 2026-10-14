/*
 * function: POKETRADE_NEGO_StepSendCancelReply
 * address: 0x021DDDB8
 * packet: pkt_ov119_021DDDB8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_021DD080 0x021DD080 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepResolveReplies 0x021DDBF0 thumb ov119
 */

typedef unsigned short u16;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_021DD080(void *a, void *b, void *c);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepResolveReplies(char *p);

void POKETRADE_NEGO_StepSendCancelReply(unsigned char *p)
{
    unsigned char v=14;
    if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,(u32)(&v))) {
        func_021DD080(GFL_NET_HANDLE_GetCurrentHandle(),(void *)29,p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepResolveReplies);
    }
}

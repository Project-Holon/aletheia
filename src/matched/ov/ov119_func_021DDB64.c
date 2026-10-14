/*
 * function: POKETRADE_NEGO_StepSendSync25
 * address: 0x021DDB64
 * packet: pkt_ov119_021DDB64
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   func_021DD080 0x021DD080 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepWaitSync25 0x021DDB10 thumb ov119
 */

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern void func_021DD080(void *a, void *b, void *c);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepWaitSync25(unsigned char *p);

void POKETRADE_NEGO_StepSendSync25(unsigned char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle();
    if(POKETRADE_SAVE_IsMessagePrintDone((char *)p)) {
        func_021DD080((void *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()),(void *)25,p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitSync25);
    }
}

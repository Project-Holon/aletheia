/*
 * function: BTL_SERVER_StepShiftPrompt
 * address:  0x021BAE60
 * packet:   pkt_ov093_021BAE60
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_SendCommand  0x021BB718  thumb  ov093
 *   BTL_SERVER_SendCommandData  0x021BB724  thumb  ov093
 *   BTL_SERVER_AreRepliesReady  0x021BB798  thumb  ov093
 *   BTL_SERVER_ClearReplies  0x021BB7D0  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   BTL_ADAPTER_GetSendBuffer  0x021EEB64  thumb  ov093
 *   BTL_SERVER_FLOW_RunEscapeFromLead  0x021BC360  thumb  ov093
 *   BTL_SERVER_SetHandler  0x021BABEC  thumb  ov093
 *   BTL_SERVER_StepRequestPokeChange  0x021BAEF8  thumb  ov093
 */
#include "../include/Obj06222.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct QW;
extern void BTL_SERVER_SendCommand(int a, int b);
extern void BTL_SERVER_SendCommandData(u8 *p, int a, int b, int c);
extern int BTL_SERVER_AreRepliesReady(u8 *);
extern void BTL_SERVER_ClearReplies(const u8 *p);
extern u8 func_021B8FF4(u8 *);
extern u32 BTL_ADAPTER_GetSendBuffer(struct QW *p, u32 *out);
extern int BTL_SERVER_FLOW_RunEscapeFromLead(u8 *p);
extern void BTL_SERVER_SetHandler(int *p, void *f);
extern int BTL_SERVER_StepRequestPokeChange(u8 *, int *);

int BTL_SERVER_StepShiftPrompt(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        BTL_SERVER_SendCommand((int)p, 7);
        (*s)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(p) != 0) {
            u8 idx = func_021B8FF4(*(u8 * *)&((struct Obj06222 *)p)->fC);
            int *q;

            BTL_SERVER_ClearReplies(p);
            if (*((u8 *)BTL_ADAPTER_GetSendBuffer((struct QW *)(*(u32 *)(p + 0x14 + idx * 12)), 0)) == 0) {
                BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepRequestPokeChange);
            } else {
                ((struct Obj06222 *)p)->f48 = BTL_SERVER_FLOW_RunEscapeFromLead((u8 *)(((struct Obj06222 *)p)->f44));
                q = *(int * *)&((struct Obj06222 *)p)->fCB0;
                BTL_SERVER_SendCommandData(p, 8, (int)(q + 2), *q);
                (*s)++;
            }
        }
        break;
    case 2:
        if (BTL_SERVER_AreRepliesReady(p) != 0) {
            BTL_SERVER_ClearReplies(p);
            if (((struct Obj06222 *)p)->f48 != 0)
                return 1;
            BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepRequestPokeChange);
        }
        break;
    }
    return 0;
}

/*
 * function: BTL_SERVER_StepSendRecording
 * address:  0x021BB208
 * packet:   pkt_ov093_021BB208
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_REC_MakeResetPacket  0x021EE9A4  thumb  ov093
 *   BTL_SERVER_SendCommandData  0x021BB724  thumb  ov093
 *   BTL_SERVER_SendCommand  0x021BB718  thumb  ov093
 *   BTL_SERVER_AreRepliesReady  0x021BB798  thumb  ov093
 *   BTL_SERVER_ClearReplies  0x021BB7D0  thumb  ov093
 *   func_021C84D8  0x021C84D8  thumb  ov093
 *   func_021B916C  0x021B916C  thumb  ov093
 *   BTL_SERVER_SetHandler  0x021BABEC  thumb  ov093
 *   BTL_SERVER_StepSelectEnding  0x021BB280  thumb  ov093
 */
#include "../include/Obj13292.h"

typedef unsigned char u8;

extern u8 *BTL_REC_MakeResetPacket(u8 *p, unsigned int *out);
typedef unsigned int   u32;
extern void BTL_SERVER_SendCommandData(u8 *p, int a, int b, int c);
extern void BTL_SERVER_SendCommand(int a, int b);
extern int BTL_SERVER_AreRepliesReady(u8 *);
extern void BTL_SERVER_ClearReplies(const u8 *p);
extern int func_021C84D8(u8 *p);
extern void func_021B916C(u8 *p, u32 x);
extern void BTL_SERVER_SetHandler(int *p, void *f);
extern int BTL_SERVER_StepSelectEnding(u8 *);

int BTL_SERVER_StepSendRecording(u8 *p, int *s)
{
    int n;

    switch (*s) {
    case 0: {
        u8 *r = BTL_REC_MakeResetPacket(p + 0x68, (unsigned int *)(&n));
        BTL_SERVER_SendCommandData(p, 0xa, (int)r, n);
        (*s)++;
        break;
    }
    case 1:
        if (BTL_SERVER_AreRepliesReady(p) != 0) {
            BTL_SERVER_ClearReplies(p);
            BTL_SERVER_SendCommand((int)p, 0x10);
            (*s)++;
        }
        break;
    case 2:
        if (BTL_SERVER_AreRepliesReady(p) != 0) {
            BTL_SERVER_ClearReplies(p);
            func_021B916C((u8 *)(((struct Obj13292 *)p)->fC), func_021C84D8((u8 *)(((struct Obj13292 *)p)->f44)));
            BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSelectEnding);
        }
        break;
    }
    return 0;
}

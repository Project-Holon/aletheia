/*
 * function: BTL_SERVER_StepStart
 * address:  0x021BAC04
 * packet:   pkt_ov093_021BAC04
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_SendCommand  0x021BB718  thumb  ov093
 *   BTL_SERVER_AreRepliesReady  0x021BB798  thumb  ov093
 *   BTL_SERVER_ClearReplies  0x021BB7D0  thumb  ov093
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   BTL_SERVER_FLOW_RunBattleStart  0x021BBB60  thumb  ov093
 *   BTL_SERVER_SendSkipPacket  0x021BB5FC  thumb  ov093
 *   BTL_SERVER_SetHandler  0x021BABEC  thumb  ov093
 *   BTL_SERVER_GotoSelectCommands  0x021BABF4  thumb  ov093
 *   BTL_SERVER_SendCommandData  0x021BB724  thumb  ov093
 *   BTL_SERVER_StepSelectEnding  0x021BB280  thumb  ov093
 */
#include "../include/Obj09946.h"

extern void BTL_SERVER_SendCommand(int a, int b);
extern int BTL_SERVER_AreRepliesReady(unsigned char *p);
extern void BTL_SERVER_ClearReplies(const unsigned char *p);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern int BTL_SERVER_FLOW_RunBattleStart(unsigned char *p);
extern int BTL_SERVER_SendSkipPacket(unsigned char *p, int b);
extern void BTL_SERVER_SetHandler(int *p, void *f);
extern void BTL_SERVER_GotoSelectCommands(void *);
extern void BTL_SERVER_SendCommandData(unsigned char *p, int a, int b, int c);
typedef unsigned char  u8;
extern int BTL_SERVER_StepSelectEnding(u8 *p);

int BTL_SERVER_StepStart(char *p, int *st)
{
    int *q;

    switch (*st) {
    case 0:
        BTL_SERVER_SendCommand((int)p, 1);
        (*st)++;
    case 1:
        if (BTL_SERVER_AreRepliesReady((unsigned char *)p)) {
            BTL_SERVER_ClearReplies((const unsigned char *)p);
            if (BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj09946 *)p)->fC) != (void *)4) {
                BTL_SERVER_SendSkipPacket((unsigned char *)p, BTL_SERVER_FLOW_RunBattleStart((unsigned char *)(((struct Obj09946 *)p)->f44)));
                (*st)++;
            } else {
                BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSelectEnding);
            }
        }
        break;
    case 2:
        if (BTL_SERVER_AreRepliesReady((unsigned char *)p)) {
            BTL_SERVER_ClearReplies((const unsigned char *)p);
            (*st)++;
        }
        break;
    case 3:
        q = *(int * *)&((struct Obj09946 *)p)->fCB0;
        BTL_SERVER_SendCommandData((unsigned char *)p, 8, (int)(q + 2), *q);
        (*st)++;
        break;
    case 4:
        if (BTL_SERVER_AreRepliesReady((unsigned char *)p)) {
            BTL_SERVER_ClearReplies((const unsigned char *)p);
            BTL_SERVER_GotoSelectCommands(p);
        }
        break;
    }
    return 0;
}

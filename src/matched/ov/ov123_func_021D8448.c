/*
 * function: GSYNC_STATE_StatePrintErrorMessage
 * address: 0x021D8448
 * packet: pkt_ov123_021D8448
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MESSAGE_PrintDefault 0x021D5AB0 thumb ov123
 *   GSYNC_MESSAGE_PrintStream 0x021D56FC thumb ov123
 *   GSYNC_MESSAGE_PrintId 0x021D5950 thumb ov123
 *   GSYNC_MESSAGE_PrintInWindow 0x021D5960 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitInputPrintNext 0x021D840C thumb ov123
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
#include "../include/Obj06467.h"
#include "../include/Obj22968.h"
typedef unsigned char u8;
extern u8 *GAME_DATA_GetMyStatus(void *p);
typedef unsigned int   u32;
struct Sub0200852CObj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern void GSYNC_MESSAGE_PrintDefault(u8 *, int);
extern void GSYNC_MESSAGE_PrintStream(char *, int);
extern int GSYNC_MESSAGE_PrintId(u8 *p, int x);
extern void GSYNC_MESSAGE_PrintInWindow(char *, int, int);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitInputPrintNext(char *p);
void GSYNC_STATE_StatePrintErrorMessage(char *p)
{
    GSYNC_MESSAGE_PrintDefault(*(u8 * *)&((struct Obj06467 *)p)->f18, func_0200853C((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(((struct Obj22968 *)(*(char * *)&((struct Obj06467 *)p)->f20))->f4)));
    GSYNC_MESSAGE_PrintStream(*(char * *)&((struct Obj06467 *)p)->f18, 1);
    GSYNC_MESSAGE_PrintId((u8 *)(*(char * *)&((struct Obj06467 *)p)->f18), 47);
    GSYNC_MESSAGE_PrintInWindow(*(char * *)&((struct Obj06467 *)p)->f18, 7, 14);
    GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateWaitInputPrintNext, 0x6b7);
}

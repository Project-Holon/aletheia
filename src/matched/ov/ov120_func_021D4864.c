/*
 * function: GTSNEGO_DISP_WaitNegotiation
 * address: 0x021D4864
 * packet: pkt_ov120_021D4864
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_UpdatePrintStream 0x021D7AF4 thumb ov120
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_02009EA8 0x02009EA8 thumb
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_SendHandshake 0x021D4808 thumb ov120
 *   GAME_DATA_GetTradeHistory  0x02012F14  thumb  arm9
 *   GREETING_SAVEDATA_GetSentence  0x0200E6FC  thumb  arm9
 */
#include "../include/Obj02831.h"
#include "../include/Obj13929.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Rec0200E6FC;
struct Sub02009D9CObj;
extern int GTSNEGO_MSG_UpdatePrintStream(char *p);
extern int GFL_NET_GetRunState(void);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
extern void *func_0200E6E8(u32 a);
extern void GREETING_SAVEDATA_GetSentence(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void *GAME_DATA_GetTradeHistory(void **h);
extern u32 func_02009EA8(const struct Sub02009D9CObj *obj);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_SendHandshake(int *a);
void GTSNEGO_DISP_WaitNegotiation(u8 *p)
{
    u8 *q;
    int value;
    if (GTSNEGO_MSG_UpdatePrintStream((char *)(((struct Obj02831 *)p)->f40))) {
        if (GFL_NET_GetRunState() == 0) {
            GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_SendHandshake, 0x2fe);
            return;
        }
        if (((struct Obj02831 *)p)->f14 > 0) {
            ((struct Obj02831 *)p)->f14 = ((struct Obj02831 *)p)->f14 - 1;
            return;
        }
        if (GFL_NET_HANDLE_GetNegotiationNum() == 2) {
            q = *(u8 * *)&((struct Obj02831 *)p)->f48;
            value = (int)func_0200E6E8(((struct Obj02831 *)p)->f30);
            ((struct Obj13929 *)q)->f4 = ((struct Obj02831 *)p)->f144;
            ((struct Obj13929 *)q)->f8 = ((struct Obj02831 *)p)->f13C;
            GREETING_SAVEDATA_GetSentence((struct Rec0200E6FC *)value, 0, (struct Rec0200E6FC *)(p + 0x168));
            ((struct Obj02831 *)p)->f170 = func_02009EA8(GAME_DATA_GetTradeHistory((void **)(((struct Obj02831 *)p)->f2C)));
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x22);
            GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_SendHandshake, 0x314);
        }
    }
}

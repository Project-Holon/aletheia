/*
 * function: func_021DA1E4
 * address:  0x021DA1E4
 * packet:   pkt_021DA1E4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_RAP_StartMatchWithFilter  0x0215580C  thumb
 *   GFL_NET_STATE_WifiEnterRandomMatch  0x0203C304  arm
 *   DWC_RAP_SetVchatEnabled  0x02156BC4  thumb
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *   GFL_NET_STATE_GetWifiState  0x0203C3EC  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02039338  0x02039338  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   GFL_NET_HANDLE_GetNegotiationNum  0x020399EC  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_021DA384  0x021DA384  thumb
 *   func_021DA390  0x021DA390  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203D378  0x0203D378  arm
 *
 * Matchmaking step (state at +0x40): 0 starts the search with the evaluation callback, then waits for the match, the peer handshake (with a 3600-tick timeout counted at +0x1a4) and the link check; returns 1 when done, 2 on a fatal error and 0 while still running.
 */
#include "../include/Obj00839.h"

typedef unsigned long u32;

extern int DWC_RAP_StartMatchWithFilter(char *filter, int n, void *cb, char *obj);
extern u32 GFL_NET_STATE_WifiEnterRandomMatch(void);
extern void DWC_RAP_SetVchatEnabled(int v);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern int GFL_NET_STATE_GetWifiState(void);
typedef unsigned short u16;
extern u32 GFL_NET_STATE_GetError(void);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void func_0203D7BC(u8 a0);
extern u16 func_02039338(void);
extern int func_02039ACC(void);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *h, unsigned int a, unsigned int b);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern unsigned int func_02039CB4(struct Link *h, unsigned int a, unsigned int b);
extern void func_021DA384(char *obj);
extern int func_021DA390(char *obj);
extern void GFL_NET_STATE_SetWifiError(void);
extern void GFL_NET_STATE_ClearErrorMode(void);
extern void func_0200FBA0(void);
extern u32 func_0203D378(void);

int func_021DA1E4(char *obj)
{
    switch (((struct Obj00839 *)obj)->f40) {
    case 0:
        if (DWC_RAP_StartMatchWithFilter(obj + 0x44, 2, ((struct Obj00839 *)obj)->f1218, obj)) {
            GFL_NET_STATE_WifiEnterRandomMatch();
            DWC_RAP_SetVchatEnabled(0);
            ((struct Obj00839 *)obj)->f40 = 1;
        } else {
            GFL_NET_STATE_WifiDisconnect(1);
            return 2;
        }
        break;
    case 1:
        ((struct Obj00839 *)obj)->f40 = 2;
        break;
    case 2:
        switch (GFL_NET_STATE_GetWifiState()) {
        case 0:
            if ((u32)(*(u32 *)(GFL_NET_STATE_GetError() + 0xc) - 0x3f0) > 1)
                break;
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
            break;
        case 1:
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 3;
            GFL_NET_SetAutoExit(1);
            func_0203D7BC(1);
            break;
        default:
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
            break;
        }
        break;
    case 3:
        if (func_02039338()) {
            if (func_02039ACC())
                ((struct Obj00839 *)obj)->f40 = 4;
            if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
                func_021DA384(obj);
                ((struct Obj00839 *)obj)->f40 = 7;
            }
        } else {
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 5;
        }
        break;
    case 4:
        func_02039C68((struct Link *)func_020399A8(), 0xf, 0x24);
        ((struct Obj00839 *)obj)->f1A4 = 0;
        ((struct Obj00839 *)obj)->f40 = 6;
        break;
    case 5:
        if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
        } else if (GFL_NET_HANDLE_GetNegotiationNum() && func_02039ACC()) {
            func_02039C68((struct Link *)func_020399A8(), 0xf, 0x24);
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 6;
        }
        break;
    case 6:
        if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
        } else if (func_02039CB4((struct Link *)func_020399A8(), 0xf, 0x24)) {
            ((struct Obj00839 *)obj)->f40 = 8;
        }
        break;
    case 7:
        if (func_021DA390(obj)) {
            if ((u32)(*(u32 *)(GFL_NET_STATE_GetError() + 0xc) - 0x3f0) <= 1) {
                GFL_NET_STATE_SetWifiError();
                GFL_NET_STATE_ClearErrorMode();
                func_0200FBA0();
                GFL_NET_STATE_WifiDisconnect(1);
            }
            return 2;
        }
        break;
    case 8:
        func_0203D378();
        return 1;
    }
    return 0;
}

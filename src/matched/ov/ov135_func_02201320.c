/*
 * function: WORLDTRADE_SERVER_WaitNameCheck
 * address: 0x02201320
 * packet: pkt_ov135_02201320
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_CheckProfanityProcess 0x0217BC90 arm ov009
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_Delete 0x02045808 arm
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   GFL_NET_STATE_ClearErrorMode 0x0203C968 arm
 */
#include "../include/Obj05420.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int DWC_CheckProfanityProcess(void);
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_0200FBB0(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_ClearErrorMode(void);
int WORLDTRADE_SERVER_WaitNameCheck(u8 *p)
{
    int done;
    int positive;
    u16 *dst;
    void *bank;
    void *str;
    u16 *text;
    int i;
    done = DWC_CheckProfanityProcess() == 2;
    if (done) positive = ((struct Obj05420 *)p)->f1320 > 0;
    if (done) {
        if (positive) {
            dst = (u16 *)(p + 0x1f4);
            bank = func_02045B38(0, 2, 0x51, 0x48);
            str = func_02045EC0(bank, 0xf);
            MSGDATA_Delete(bank);
            text = STRBUF_GetChars(str);
            for (i = 0; i < 7 && (u32)i < STRBUF_GetLength(str); i++) dst[i] = text[i];
            dst[i] = STRBUF_GetEosChar();
            STRBUF_Delete(str);
        }
        ((struct Obj05420 *)p)->f28 = ((struct Obj05420 *)p)->fE10;
    } else {
        if ((((struct Obj05420 *)p)->fF8C)++ == 0xe10) {
            ((struct Obj05420 *)p)->f38 = -5;
            ((struct Obj05420 *)p)->f28 = 0x2b;
            func_0200FBB0();
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
        }
    }
    return 2;
}

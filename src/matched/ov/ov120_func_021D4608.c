/*
 * function: GTSNEGO_DISP_ConfirmStatus
 * address: 0x021D4608
 * packet: pkt_ov120_021D4608
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_CheckProfanityProcess 0x0217BC90 arm ov009
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_ShowTradeConfirm 0x021D4584 thumb ov120
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb  arm9
 *   MET_TRAINERS_Insert  0x0200ED54  thumb  arm9
 */
#include "../include/Obj08076.h"
#include "../include/Obj22823.h"
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
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
struct L0200ED54;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
extern struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i);
extern void MYSTATUS_Copy(void *src, void *dst);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *MET_TRAINERS_GetFromSave(void *p);
extern void MET_TRAINERS_Insert(struct L0200ED54 *l, u32 val);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_ShowTradeConfirm(u8 *p);
void GTSNEGO_DISP_ConfirmStatus(u8 *p)
{
    int ready = 0;
    int value = ((struct Obj22823 *)(*(u8 * *)&((struct Obj08076 *)p)->f48))->f18;
    int active;
    void *message;
    void *text;
    int result;
    active = DWC_CheckProfanityProcess() == 2;
    if (active)
        ready = ((struct Obj08076 *)p)->f1A8 > 0;
    if (active) {
        if (ready) {
            message = func_02045B38(0, 2, 0x51, 0x1f);
            text = func_02045EC0(message, 15);
            MSGDATA_Delete(message);
            func_020084E4((u16 *)value, text);
            STRBUF_Delete(text);
        }
        MYSTATUS_Copy((void *)value, GAME_DATA_GetMyStatusPlayer((struct Sub24 *)(((struct Obj08076 *)p)->f2C), 1 - GFL_NET_SYSTEM_GetCurrentAid()));
        result = func_02008530((const struct Sub0200852CObj *)value);
        MET_TRAINERS_Insert(MET_TRAINERS_GetFromSave((void *)(((struct Obj08076 *)p)->f30)), result);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)((void (*)(int))GTSNEGO_DISP_ShowTradeConfirm), 0x283);
    }
}

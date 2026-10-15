/*
 * function: WIFI_BSUBWAY_StatusCheckMessage
 * address: 0x021D6C50
 * packet: pkt_ov116_021D6C50
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the epilogue.
 * symbols:
 *   DWC_CheckProfanityProcess 0x0217BC90 arm ov009
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj13862.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int DWC_CheckProfanityProcess(void);
typedef unsigned int   u32;
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void STRBUF_Delete(struct U16Vec *vec);
int WIFI_BSUBWAY_StatusCheckMessage(u8 *p,unsigned heap) {
    int flag,ready;
    void *bank,*str;
    flag = DWC_CheckProfanityProcess()==2;
    if(flag) ready = ((struct Obj13862 *)p)->f210>0;
    if(flag==0) return 0;
    if(flag==1 && ready==1) {
        bank = func_02045B38(0,2,0x51,heap);
        str = func_02045EC0(bank,15);
        MSGDATA_Delete(bank);
        func_020084E4((u16 *)((struct Obj13862 *)p)->f218,str);
        STRBUF_Delete(str);
        return 2;
    }
    return 1;
}

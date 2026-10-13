/*
 * function: SCRCMD_PROC_FLD_BuildItemListFromRange
 * address:  0x021B3A64
 * packet:   pkt_ov021_021B3A64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_PROC_FLD_BuildItemListFromRange 0x021B3A64 thumb
 *   func_02045B38 0x02045B38 arm
 *   FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries 0x02186670 thumb ov020
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   SCRCMD_PROC_FLD_SetItemSlot 0x021B385C thumb ov021
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj00037.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries(char *base, char *out, u16 *cnt, int n, u16 id);
extern void *BMP_MENUWORK_Create(int, int);
extern void SCRCMD_PROC_FLD_SetItemSlot(char *p, int idx, int mode, int val, int arg);
struct Slot;
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 MSGDATA_Delete(struct Rec *rec);

void SCRCMD_PROC_FLD_BuildItemListFromRange(char *p, int i)
{
    int k = 0;
    void *q = func_02045B38(0, 2, 54, ((struct Obj00037 *)p)->f4);

    FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries(((struct Obj00037 *)p)->f1C, p + 32, (u16 *)(p + 352), i - 247, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f180 = BMP_MENUWORK_Create(((struct Obj00037 *)p)->f160 + 1, ((struct Obj00037 *)p)->f4);
    for (; k < ((struct Obj00037 *)p)->f160; k++) {
        SCRCMD_PROC_FLD_SetItemSlot(p, k, ((struct Obj00037 *)p)->f162, *(u16 *)(p + 32 + k * 8), (int)q);
    }
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + k * 8), (u32)(((struct Obj00037 *)p)->f188), 11, -2, ((struct Obj00037 *)p)->f4);
    MSGDATA_Delete(q);
}

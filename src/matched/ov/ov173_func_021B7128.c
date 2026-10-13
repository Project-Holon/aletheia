/*
 * function: func_021B7128
 * address: 0x021B7128
 * packet: pkt_ov173_021B7128
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6FB4 0x021B6FB4 thumb ov173
 *   func_021B70D8 0x021B70D8 thumb ov173
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   func_02045B38 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj00180.h"
#include "../include/Obj24162.h"
#include "../include/Obj24164.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct ScanContext;
struct Slot;
extern u32 func_021B6FB4(struct ScanContext *p);
extern void func_021B70D8(char *);
extern void *BMP_MENUWORK_Create(u32, u32);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
void func_021B7128(char *p)
{
    u32 i;
    u16 move;
    void *bank;
    ((struct Obj00180 *)p)->f1B8 = func_021B6FB4((struct ScanContext *)p);
    ((struct Obj00180 *)p)->f58 = BMP_MENUWORK_Create(((struct Obj00180 *)p)->f1B8, 0x4f);
    i = 0;
    bank = func_02045B38(0, 2, 0xcb, 0x4f);
    for (; i < ((struct Obj00180 *)p)->f1B8; i++) {
        move = ((u16 *)((struct Obj24162 *)(*(char * *)&((struct Obj00180 *)p)->f0))->f10)[i];
        if (move != 0xffff) {
            BMP_MENUWORK_AddMsgItem(((struct Obj00180 *)p)->f58, (u32)bank, move, move, 0x4f);
        } else {
            BMP_MENUWORK_AddMsgItem(((struct Obj00180 *)p)->f58, *(u32 *)&((struct Obj00180 *)p)->f44, 0x20, -2, 0x4f);
            break;
        }
    }
    MSGDATA_Delete(bank);
    ((struct Obj00180 *)p)->f1BB = 0;
    ((struct Obj00180 *)p)->f1BC = ((struct Obj24164 *)(*(char * *)&((struct Obj00180 *)p)->f0))->f14;
    func_021B70D8(p);
}

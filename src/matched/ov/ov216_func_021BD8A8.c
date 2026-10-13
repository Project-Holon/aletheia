/*
 * function: func_021BD8A8
 * address: 0x021BD8A8
 * packet: pkt_ov216_021BD8A8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021BD948 0x021BD948 thumb ov216
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   GAME_BEACON_ACCESSOR_TableRingGet 0x02165AC4 thumb ov010
 *   func_021BD174 0x021BD174 thumb ov216
 */
#include "../include/Obj00051.h"
#include "../include/Obj05556.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Tcbl;
struct TcblNode;
struct S02030FB4;
struct Queue;
struct Rec;
extern struct TcblNode *TCBL_AddTask(struct Tcbl *, void (*)(struct TcblNode *, void *), u32, u32);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern void MI_CpuFill8(void *, int, int);
extern void func_021BD948(struct TcblNode *task, char *work);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern int GAME_BEACON_ACCESSOR_TableRingGet(struct Queue *, struct Rec *, u16 *, int);
extern void func_021BD174(char *p, void *record, u16 unused, u8 slot);
void func_021BD8A8(char *owner, int direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj00051 *)owner)->f18, (void (*)(struct TcblNode *, void *))func_021BD948, 24, 0));
    MI_CpuFill8(work, 0, 24);
    ((struct Obj05556 *)work)->f4 = direction;
    if (direction == 0) {
        ((struct Obj05556 *)work)->f3 = ((struct Obj00051 *)owner)->f30 + 1;
        TOUCHBAR_SetButtonEnabled(((struct Obj00051 *)owner)->f124, 3, 0);
    } else {
        ((struct Obj05556 *)work)->f3 = ((struct Obj00051 *)owner)->f30 - 1;
        TOUCHBAR_SetButtonEnabled(((struct Obj00051 *)owner)->f124, 2, 0);
    }
    TOUCHBAR_SetButtonEnabled(((struct Obj00051 *)owner)->f124, 1, 0);
    GAME_BEACON_ACCESSOR_TableRingGet(*(struct Queue * *)&((struct Obj00051 *)owner)->f24, *(struct Rec * *)&((struct Obj00051 *)owner)->f28, (u16 *)(owner + 0x2c), *(u8 *)(owner + 0x31 + ((struct Obj05556 *)work)->f3));
    func_021BD174(owner, ((struct Obj00051 *)owner)->f28, ((struct Obj00051 *)owner)->f2C, ((struct Obj00051 *)owner)->f2E ^ 1);
    *(char * *)&((struct Obj05556 *)work)->f10 = owner;
    *(int * *)&((struct Obj05556 *)work)->f14 = counter;
    ++*counter;
}

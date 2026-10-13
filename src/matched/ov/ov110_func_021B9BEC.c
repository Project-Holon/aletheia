/*
 * function: PMS_INPUT_VIEW_StartTask
 * address: 0x021B9BEC
 * packet: pkt_ov110_021B9BEC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pointer arithmetic for the slot test, integer arithmetic for its store, keeps only the index offset live across the call.
 * symbols:
 *   gPmsInputViewTaskTable 0x021C3B94 data a4
 *   gPmsInputViewHeapSite 0x021C3C20 data ov110 a1
 *   func_02030734 0x02030734 arm
 *   PMS_INPUT_GetTasks 0x021BF7D0 thumb ov110
 *   func_02030DA8 0x02030DA8 arm
 */
#include "../include/Obj10264.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 entries[35]; } CallbackTable;
typedef struct { u8 *owner; u32 field4, field8; int id, slot, state; } Context;
extern const CallbackTable gPmsInputViewTaskTable;
extern const char gPmsInputViewHeapSite[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 PMS_INPUT_GetTasks(u8 *);
extern void *func_02030DA8(u32, u32, void *, int);
void PMS_INPUT_VIEW_StartTask(u8 *p, int id) {
    CallbackTable table;
    int i;
    Context *q;
    table = gPmsInputViewTaskTable;
    if (id >= 35) return;
    q = func_02030734(42, 24, 0, gPmsInputViewHeapSite, 493);
    if (!q) return;
    q->state = 0;
    q->id = id;
    q->owner = (u8 *)p;
    q->field4 = *(u32 *)&((struct Obj10264 *)p)->f18;
    q->field8 = ((struct Obj10264 *)p)->f1C;
    for (i=0; i<4; ++i) {
        if (!*(void **)(p+i*4+8)) {
            q->slot = i;
            *(void **)((u32)p+i*4+8) = func_02030DA8(PMS_INPUT_GetTasks(*(u8 * *)&((struct Obj10264 *)p)->f18), table.entries[id], q, 1);
            return;
        }
    }
}

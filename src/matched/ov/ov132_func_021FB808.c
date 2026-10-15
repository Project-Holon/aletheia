/*
 * function: SCRIPT_COMMAND_CmdStartShake
 * address: 0x021FB808
 * packet: pkt_ov132_021FB808
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: task allocation is 32 bytes; the product local reproduces count-first multiply scheduling.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   SCRIPT_COMMAND_GetActorMask 0x021FB1F4 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   func_02030734 0x02030734 arm
 *   STA_ACT_SCRIPT_AddTask 0x021FADA0 thumb ov132
 *   SCRIPT_COMMAND_TaskShake 0x021FB8CC thumb ov132
 *   d_021FDD00 0x021FDD00 data a1
 */
#include "../include/Obj04517.h"
#include "../include/Obj08165.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct TaskData { void *context; int tick, duration, count; void *slot; int amplitude; void *owner; void *task; } TaskData;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int SCRIPT_COMMAND_GetActorMask(char *, int);
extern void *STA_ACTING_GetActorSystem(char *p);
extern void *STA_ACTING_GetActor(char *p, u32 i);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *STA_ACT_SCRIPT_AddTask(char *p, u32 fn, u32 arg, u32 key);
extern void SCRIPT_COMMAND_TaskShake(int unused, char *p);
extern const char d_021FDD00[];
int SCRIPT_COMMAND_CmdStartShake(int unused, char *p)
{
    char *obj;
    int mask, wait, amplitude, duration, count;
    u8 i;
    TaskData *data;
    obj = *(char * *)&((struct Obj04517 *)p)->f0;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct Obj04517 *)p)->f4));
    duration = VM_GetU32(((struct Obj04517 *)p)->f4);
    count = VM_GetU32(((struct Obj04517 *)p)->f4);
    amplitude = VM_GetU32(((struct Obj04517 *)p)->f4);
    wait = VM_GetU32(((struct Obj04517 *)p)->f4);
    STA_ACTING_GetActorSystem(((struct Obj08165 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            data = func_02030734(((struct Obj08165 *)obj)->f0, 0x20, 0, d_021FDD00, 0x443);
            data->owner = obj;
            data->slot = STA_ACTING_GetActor(((struct Obj08165 *)obj)->f34, i);
            data->amplitude = amplitude;
            data->context = ((struct Obj08165 *)obj)->f34;
            data->tick = 0;
            data->duration = duration;
            data->count = count;
            data->task = STA_ACT_SCRIPT_AddTask(obj, (u32)SCRIPT_COMMAND_TaskShake, (u32)data, 10);
        }
    }
    if (wait == 1) {
        int product;
        product = count;
        product *= duration;
        ((struct Obj04517 *)p)->f14 = product;
        return 1;
    }
    return 0;
}

/*
 * function: func_021FB808
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
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_02030734 0x02030734 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FB8CC 0x021FB8CC thumb ov132
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
extern int func_021FB1F4(char *, int);
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_021FADA0(char *p, u32 fn, u32 arg, u32 key);
extern void func_021FB8CC(int unused, char *p);
extern const char d_021FDD00[];
int func_021FB808(int unused, char *p)
{
    char *obj;
    int mask, wait, amplitude, duration, count;
    u8 i;
    TaskData *data;
    obj = *(char * *)&((struct Obj04517 *)p)->f0;
    mask = func_021FB1F4(p, VM_GetU32(((struct Obj04517 *)p)->f4));
    duration = VM_GetU32(((struct Obj04517 *)p)->f4);
    count = VM_GetU32(((struct Obj04517 *)p)->f4);
    amplitude = VM_GetU32(((struct Obj04517 *)p)->f4);
    wait = VM_GetU32(((struct Obj04517 *)p)->f4);
    func_021F9DA0(((struct Obj08165 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            data = func_02030734(((struct Obj08165 *)obj)->f0, 0x20, 0, d_021FDD00, 0x443);
            data->owner = obj;
            data->slot = func_021F9DA4(((struct Obj08165 *)obj)->f34, i);
            data->amplitude = amplitude;
            data->context = ((struct Obj08165 *)obj)->f34;
            data->tick = 0;
            data->duration = duration;
            data->count = count;
            data->task = func_021FADA0(obj, (u32)func_021FB8CC, (u32)data, 10);
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

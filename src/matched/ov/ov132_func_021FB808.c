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
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_02030734 0x02030734 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FB8CC 0x021FB8CC thumb ov132
 *   d_021FDD00 0x021FDD00 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct TaskData { void *context; int tick, duration, count; void *slot; int amplitude; void *owner; void *task; } TaskData;
extern int func_0201134C(void *);
extern int func_021FB1F4(char *, int);
extern void *func_021F9DA0(void *);
extern void *func_021F9DA4(void *, int);
extern void *func_02030734(u16, u32, int, const void *, u16);
extern void *func_021FADA0(void *, void (*)(int, TaskData *), TaskData *, int);
extern void func_021FB8CC(int, TaskData *);
extern const char d_021FDD00[];
int func_021FB808(int unused, char *p)
{
    char *obj;
    int mask, wait, amplitude, duration, count;
    u8 i;
    TaskData *data;
    obj = *(char **)p;
    mask = func_021FB1F4(p, func_0201134C(*(void **)(p + 4)));
    duration = func_0201134C(*(void **)(p + 4));
    count = func_0201134C(*(void **)(p + 4));
    amplitude = func_0201134C(*(void **)(p + 4));
    wait = func_0201134C(*(void **)(p + 4));
    func_021F9DA0(*(void **)(obj + 0x34));
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            data = func_02030734(*(u16 *)obj, 0x20, 0, d_021FDD00, 0x443);
            data->owner = obj;
            data->slot = func_021F9DA4(*(void **)(obj + 0x34), i);
            data->amplitude = amplitude;
            data->context = *(void **)(obj + 0x34);
            data->tick = 0;
            data->duration = duration;
            data->count = count;
            data->task = func_021FADA0(obj, func_021FB8CC, data, 10);
        }
    }
    if (wait == 1) {
        int product;
        product = count;
        product *= duration;
        *(u16 *)(p + 0x14) = product;
        return 1;
    }
    return 0;
}

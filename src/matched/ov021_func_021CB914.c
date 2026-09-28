/*
 * function: func_021CB914
 * address:  0x021CB914
 * packet:   pkt_ov021_021CB914
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Starts the task 0x021CB8AC with a one-word work area holding the owner.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021CB8AC  0x021CB8AC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef int (*TaskFn)(void *task, int *state, void *work);

extern void *func_020122C0(void *a, u32 b, TaskFn fn, u32 size);
extern void *func_020124E8(void *task);
extern int func_021CB8AC(void *task, int *state, void *work);

void *func_021CB914(void *a, u32 owner)
{
    void *task = func_020122C0(a, 0, (TaskFn)func_021CB8AC, 4);
    *(u32 *)func_020124E8(task) = owner;
    return task;
}

/*
 * function: BSUBWAY_SCR_CreateCommShutdownTask
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
 *   BSUBWAY_SCR_CommShutdownMain  0x021CB8AC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef int (*TaskFn)(void *task, int *state, void *work);

struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int BSUBWAY_SCR_CommShutdownMain(void *task, int *state, void *work);

void *BSUBWAY_SCR_CreateCommShutdownTask(void *a, u32 owner)
{
    void *task = func_020122C0(a, 0, (TaskFn)BSUBWAY_SCR_CommShutdownMain, 4);
    *(u32 *)func_020124E8(task) = owner;
    return task;
}

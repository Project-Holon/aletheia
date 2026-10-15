/*
 * function: BSUBWAY_SCR_CreateYesNoMenuTask
 * address:  0x021CB9BC
 * packet:   pkt_ov021_021CB9BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Starts the task 0x021CB934 with a four-word work area.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   BSUBWAY_SCR_YesNoMenuMain  0x021CB934  thumb
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
extern int BSUBWAY_SCR_YesNoMenuMain(void *task, int *state, void *work);

void *BSUBWAY_SCR_CreateYesNoMenuTask(void *a, u32 owner, u32 result, u32 arg)
{
    void *task = func_020122C0(a, 0, (TaskFn)BSUBWAY_SCR_YesNoMenuMain, 0x10);
    u32 *w = func_020124E8(task);

    w[0] = owner;
    w[1] = result;
    w[3] = arg;
    return task;
}

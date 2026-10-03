/*
 * function: func_02159204
 * address: 0x02159204
 * packet: pkt_ov010_02159204
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_021591B4 0x021591B4 thumb ov010
 */
typedef unsigned int u32;
typedef struct TaskWork { void *system; void *vm; void *owner; int c; int idx; int n; } TaskWork;
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021591B4(int, int, TaskWork *);
void *func_02159204(void *vm)
{
    void *owner = func_0215A5F4(vm);
    void *system = func_0215A5DC(vm);
    void *task = func_020122C0(system, 0, (void *)func_021591B4, sizeof(TaskWork));
    TaskWork *p = func_020124E8(task);
    p->system = system;
    p->vm = vm;
    p->owner = owner;
    p->idx = 0;
    p->c = 0;
    p->n = 15;
    return task;
}

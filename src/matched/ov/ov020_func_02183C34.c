/*
 * function: func_02183C34
 * address: 0x02183C34
 * packet: pkt_ov020_02183C34
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02183B90 0x02183B90 thumb ov020
 */
typedef struct { void *owner; void *input; } Work;
typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_02183B90(int a, int *state, int *p);
void *func_02183C34(void *owner, void *input)
{
    void *task;
    Work *w;
    task = func_020122C0(owner, 0, (void *)func_02183B90, sizeof(Work));
    w = func_020124E8(task);
    w->owner = owner;
    w->input = input;
    return task;
}

/*
 * function: func_0218571C
 * address: 0x0218571C
 * packet: pkt_ov020_0218571C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02012914 0x02012914 thumb
 *   func_02159FA8 0x02159FA8 thumb ov010
 *   func_02185694 0x02185694 thumb ov020
 */
typedef struct { void *owner; void *object; unsigned char payload[0x1c]; } Work;
typedef unsigned short u16;
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u16 func_02012914(const struct BigObj *p);
extern void func_02159FA8(int a, int b);
extern void func_02185694(void);
void *func_0218571C(void *owner)
{
    void *task;
    Work *w;
    func_020120F4(owner);
    task = func_020122C0(owner, 0, (void *)func_02185694, sizeof(Work));
    w = func_020124E8(task);
    w->owner = owner;
    w->object = func_020120F4(owner);
    func_02159FA8(func_02012914(w->object), (int)w->payload);
    return task;
}

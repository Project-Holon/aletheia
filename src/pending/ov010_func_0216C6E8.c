/*
 * function: func_0216C6E8
 * address:  0x0216C6E8
 * packet:   pkt_ov010_0216C6E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020457B0  0x020457B0  arm
 *   sub_02045B38   0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0202435C  0x0202435C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_021B09D8  0x021B09D8  thumb
 *   func_021B09EC  0x021B09EC  thumb
 *   func_0219129C  0x0219129C  thumb  ov021
 *   func_0216C680  0x0216C680  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Npc {
    u16 name;           /* 0x00 */
    u16 msg;            /* 0x02 */
    u8 pad04[0x120 - 0x04];
} Npc;

typedef struct Data {
    u8 pad00[0xA0];
    Npc npcs[1];        /* 0xA0 */
} Data;

typedef struct Spawn {
    void *sys;          /* 0x00 */
    u8 pad04[4];
    VecFx32 pos;        /* 0x08 */
    void *obj;          /* 0x14 */
    void *name;         /* 0x18 */
    u16 id;             /* 0x1C */
} Spawn;

typedef u32 (*TaskFn)(void *task, u32 *state, Spawn *work);

extern void *func_020120F4(void *sys);
extern void *func_0201210C(void *sys);
extern void *func_02188C54(void *proc);
extern void *func_020122C0(void *a, u32 b, TaskFn fn, u32 size);
extern Spawn *func_020124E8(void *task);
extern void *func_020457B0(u32 size, u32 heap);
extern void *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(void *bank, u32 index, void *buf);
extern void func_02045C04(void *bank);
extern void *func_0202435C(const u16 *src, u32 heap);
extern void *func_02012964(void *ctx);
extern void *func_0216DE94(void *p, u16 id);
extern void func_0216D88C(void *actor, VecFx32 *out);
extern void *func_02188C58(void *proc);
extern u32 func_0218EC2C(void *m);
extern void func_021B09D8(VecFx32 *pos, VecFx32 *ofs, u32 a, void *m, u8 dir);
extern void func_021B09EC(u8 dir, u32 *a, u32 *b);
extern void *func_0219129C(void *x, u32 a, VecFx32 *pos, void *name, u32 c, u32 b);
extern u32 func_0216C680(void *task, u32 *state, Spawn *work);

void *func_0216C6E8(Data *d, void *sys, u32 idx, u16 id, u8 dir)
{
    VecFx32 ofs;
    u32 a;
    u32 b;
    void *ctx;
    void *proc;
    void *x;
    void *task;
    Spawn *t;
    void *bank;
    void *m;
    u16 n;

    ctx = func_020120F4(sys);
    proc = func_0201210C(sys);
    x = func_02188C54(proc);
    task = func_020122C0(sys, 0, func_0216C680, 0xD8);
    t = func_020124E8(task);
    t->sys = sys;
    t->id = id;
    if (d->npcs[idx].name == 0xFFFF) {
        t->name = func_020457B0(0x300, 4);
        bank = sub_02045B38(0, 2, 0xB8, 4);
        n = d->npcs[idx].msg;
        if (n >= 0x3AE)
            n = 0;
        func_02045CAC(bank, n, t->name);
        func_02045C04(bank);
    } else {
        t->name = func_0202435C(&d->npcs[idx].name, 4);
    }
    func_0216D88C(func_0216DE94(func_02012964(ctx), t->id), &t->pos);
    m = func_02188C58(proc);
    func_021B09D8(&t->pos, &ofs, func_0218EC2C(m), m, dir);
    t->pos.x += ofs.x;
    t->pos.y += ofs.y;
    t->pos.z += ofs.z;
    func_021B09EC(dir, &a, &b);
    t->obj = func_0219129C(x, a, &t->pos, t->name, 0, b);
    return task;
}

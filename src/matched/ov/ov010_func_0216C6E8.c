/*
 * function: func_0216C6E8
 * address:  0x0216C6E8
 * packet:   pkt_ov010_0216C6E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker: ARM9 0x02045CAC at +0080 has no outside witness. integrator-owned
 * unit_02045C44.c omits func_02045CAC from function:. Singleton TU split
 * leaves this caller OUT. No overlay leaves filed.
 * blocker: C below copied from ov122_func_021D5004.c, previously verified
 * EXACT 344 bytes through the ov070 blocker evidence; not recompiled here.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * lever: task, ctx, x, proc declaration order restores pointer spill slots.
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

typedef struct Spawn {
    void *sys;          /* 0x00 */
    u8 pad04[4];
    VecFx32 pos;        /* 0x08 */
    void *obj;          /* 0x14 */
    void *name;         /* 0x18 */
    u16 id;             /* 0x1C */
} Spawn;

typedef u32 (*TaskFn)(void *task, u32 *state, Spawn *work);

struct Actor;
struct Ctx;
struct Desc;
struct MsgBank;
struct Obj;
struct Rec;
struct U16Vec;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
struct BigObj;
struct Ent;
extern u32 func_02188C54(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_0202435C(void *slots, unsigned int heap);
extern u32 func_02012964(const struct BigObj *p);
extern void *func_0216DE94(void *p, u32 id);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void *func_02188C58(void *proc);
extern u32 func_0218EC2C(u8 *p);
extern void func_021B09D8(VecFx32 *pos, VecFx32 *ofs, u32 a, void *m, u8 dir);
extern void func_021B09EC(u8 dir, u32 *a, u32 *b);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern int func_0216C680(int a, int *st, int *o, u32 a3);

void *func_0216C6E8(u8 *d, void *sys, u32 idx, u16 id, u8 dir)
{
    VecFx32 ofs;
    u32 a;
    u32 b;
    void *task;
    void *ctx;
    void *x;
    void *proc;
    Spawn *t;
    void *bank;
    void *m;
    u16 n;

    ctx = func_020120F4(sys);
    proc = func_0201210C(sys);
    x = (void *)func_02188C54(proc);
    task = func_020122C0(sys, 0, func_0216C680, 0xD8);
    t = func_020124E8(task);
    t->sys = sys;
    t->id = id;
    if (*(u16 *)((u32)d + 0xA0 + idx * 0x120) == 0xFFFF) {
        t->name = func_020457B0(0x300, 4);
        bank = sub_02045B38(0, 2, 0xB8, 4);
        n = *(u16 *)((u32)d + 0xA2 + idx * 0x120);
        if (n >= 0x3AE)
            n = 0;
        func_02045CAC(bank, n, t->name);
        func_02045C04(bank);
    } else {
        t->name = func_0202435C((u16 *)((u32)d + 0xA0 + idx * 0x120), 4);
    }
    func_0216D88C(func_0216DE94((void *)func_02012964(ctx), t->id), &t->pos);
    m = func_02188C58(proc);
    func_021B09D8(&t->pos, &ofs, func_0218EC2C(m), m, dir);
    t->pos.x += ofs.x;
    t->pos.y += ofs.y;
    t->pos.z += ofs.z;
    func_021B09EC(dir, &a, &b);
    t->obj = func_0219129C(x, a, (u32)(&t->pos), (u32)t->name, 0, b);
    return task;
}

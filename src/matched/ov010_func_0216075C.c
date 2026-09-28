/*
 * function: func_0216075C
 * address:  0x0216075C
 * packet:   pkt_ov010_0216075C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the 0x74-byte task that runs func_021607E0 and initialises it
 * from the owner.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02160A28  0x02160A28  thumb  ov010
 *   func_02164480  0x02164480  thumb  ov010
 *   func_0215E840  0x0215E840  thumb  ov010
 *   func_021607E0  0x021607E0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Owner {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0c;            /* 0x0C */
    u8 pad10[4];
    u32 f14;            /* 0x14 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
} Owner;

typedef struct Task {
    u16 id;             /* 0x00 */
    u8 pad02[2];
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 f0c;            /* 0x0C */
    u32 state;          /* 0x10 */
    void *handle;       /* 0x14 */
    Owner *owner;       /* 0x18 */
    u8 pad1C[4];
    u8 rect[0x14];      /* 0x20 */
    u8 flags[0x18];     /* 0x34 */
    u8 info[0x14];      /* 0x4C */
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u8 pad64[4];
    u32 f68;            /* 0x68 */
    u8 pad6C[8];
} Task;

extern void *func_020122C0(void *a, void *b, void (*fn)(void *), u32 size);
extern Task *func_020124E8(void *h);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_02160A28(void *r, u32 tag, u32 x, u32 y, u32 w, u32 h);
extern void func_02164480(void *f, void *a, void *b);
extern void func_0215E840(void *p, void *out);
extern void func_021607E0(void *t);

void *func_0216075C(Owner *o, u16 id)
{
    void *h;
    Task *t;

    h = func_020122C0(o->f00, o->f08, func_021607E0, sizeof(Task));
    t = func_020124E8(h);
    MI_CpuFill8(t, 0, sizeof(Task));
    t->id = id;
    t->owner = o;
    t->state = 4;
    t->handle = h;
    t->f04 = o->f0c;
    t->f08 = o->f0c;
    t->f0c = o->f0c;
    t->f60 = 0;
    t->f62 = 0;
    t->f68 = 0;
    func_02160A28(t->rect, (u32)t->owner, t->owner->f14, t->owner->f18, t->owner->f1c, t->owner->f20);
    func_02164480(t->flags, t->owner->f00, t->owner->f04);
    func_0215E840(t->owner->f04, t->info);
    return h;
}

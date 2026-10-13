/*
 * function: EVENT_SHORTCUT_MENU_CreateProcEvent
 * address:  0x0216075C
 * packet:   pkt_ov010_0216075C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the 0x74-byte task that runs EVENT_SHORTCUT_MENU_ProcEventMain and initialises it
 * from the owner.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   EVENT_SHORTCUT_MENU_InitHooks  0x02160A28  thumb  ov010
 *   func_02164480  0x02164480  thumb  ov010
 *   MOVE_POKEMON_InitSkillInfo  0x0215E840  thumb  ov010
 *   EVENT_SHORTCUT_MENU_ProcEventMain  0x021607E0  thumb  ov010
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

struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
struct Flags;
struct Info;
struct Rect;
extern void EVENT_SHORTCUT_MENU_InitHooks(struct Rect *r, u32 tag, u32 x, u32 y, u32 w, u32 h);
extern void func_02164480(struct Flags *f, void *a, void *b);
extern void MOVE_POKEMON_InitSkillInfo(void *field, struct Info *out);
extern int EVENT_SHORTCUT_MENU_ProcEventMain(void *evt, u32 *state, struct Task *t);

void *EVENT_SHORTCUT_MENU_CreateProcEvent(Owner *o, u16 id)
{
    void *h;
    Task *t;

    h = func_020122C0(o->f00, o->f08, EVENT_SHORTCUT_MENU_ProcEventMain, sizeof(Task));
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
    EVENT_SHORTCUT_MENU_InitHooks((struct Rect *)t->rect, (u32)t->owner, t->owner->f14, t->owner->f18, t->owner->f1c, t->owner->f20);
    func_02164480((struct Flags *)t->flags, t->owner->f00, t->owner->f04);
    MOVE_POKEMON_InitSkillInfo(t->owner->f04, (struct Info *)t->info);
    return h;
}

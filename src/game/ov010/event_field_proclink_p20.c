/*
 * file:     event_field_proclink_p20.c
 * unit:     yes
 * function: func_02161070, func_0216117C
 * address:  0x02161070
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012134  0x02012134  thumb
 *   func_02029DBC  0x02029DBC  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_0216F7BC  0x0216F7BC  thumb  ov010
 */
struct BigObj;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct MenuCtx {
    void *sys;          /* 0x00 */
    u8 pad04[0x24];
    u32 mode;           /* 0x28 */
    u32 slot;           /* 0x2C */
} MenuCtx;

typedef struct MenuWork {
    u8 pad00[0xC];
    u32 next;           /* 0x0C */
    u8 pad10[8];
    MenuCtx *ctx;       /* 0x18 */
    u8 pad1C[0x4C];
    u32 f68;            /* 0x68 */
} MenuWork;

typedef struct MenuSel {
    u8 pad00[0x2C];
    u32 f2c;            /* 0x2C */
    u8 pad30[4];
    u32 item;           /* 0x34 */
    u32 arg;            /* 0x38 */
} MenuSel;

extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0202136C(u16 v);
extern u16 *func_020127A4();
extern u32 func_02012A30(const struct BigObj *p);
extern u32 func_02012134(u32 *p);
extern void func_02029DBC(u8 *a, u32 b);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u32 id);
extern int *func_0216F7BC();
int func_02161070(MenuWork *w, MenuSel *sel);
void func_0216117C(int *a0, int a1);


/*
 * Menu selection dispatch: maps the chosen item (sel->item) to the next
 * state, either a sub-mode (w->ctx->mode, answer 3) or a follow-up
 * screen (w->next, answer 4).
 *
 * Levers (2026-09-28 tree_ov010_4): the arms in the image's block order
 * (not case order), and the party fetch in case 18 as its own statement
 * so w->ctx is reloaded after the calls.
 */
int func_02161070(MenuWork *w, MenuSel *sel)
{
    void *party;

    switch (sel->item) {
    case 0:
        return 1;
    case 1:
        if (sel->f2c == 2) {
            w->next = 0;
            return 4;
        }
        return 0;
    case 12:
        w->next = 0;
        return 4;
    case 10:
    case 11:
        w->ctx->mode = 0;
        return 3;
    case 13:
        w->ctx->mode = 1;
        return 3;
    case 15:
        w->ctx->mode = 3;
        return 3;
    case 16:
        w->ctx->mode = 4;
        return 3;
    case 14:
        w->ctx->mode = 2;
        return 3;
    case 8:
        w->next = 8;
        return 4;
    case 7:
        w->next = 7;
        return 4;
    case 17:
        w->next = 11;
        return 4;
    case 19:
        w->next = 9;
        return 4;
    case 18:
        party = func_02012934(func_020120F4(w->ctx->sys));
        if (func_02017E1C(func_0201AB28(party, w->ctx->slot), 6, 0) != 0)
            w->next = 0;
        else
            w->next = 9;
        w->f68 = 2;
        return 4;
    case 20:
        w->ctx->mode = 5;
        return 3;
    case 2:
        if (func_0202136C(sel->arg) == 1)
            w->f68 = 0;
        w->next = 0;
        return 4;
    }
    w->next = 0;
    return 4;
}


void func_0216117C(int *a0, int a1)
{
    void *h = func_020120F4((const struct Ctx *)*(int *)a0[6]);
    u32 v = *func_020127A4(h);
    int f = 1;
    int s;
    int *r;

    s = func_02012A30(h);
    func_02029DBC((u8 *)s, func_02012134((u32 *)(*(int *)a0[6])));
    if (func_02013CC8(v) != 0 || (int)func_02013CE0((u16)v) != 0) {
        f = 0;
    }
    r = func_0216F7BC(h, 4, f);
    if (a1 != -1) {
        r[5] = a1;
    }
}

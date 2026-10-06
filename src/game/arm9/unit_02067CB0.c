/*
 * file:     unit_02067CB0.c
 * unit:     yes
 * function: func_02067CB0, func_02067D14
 * address:  0x02067CB0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02148B48  0x02148B48  data
 *   func_02067998 0x02067998  arm
 *   func_02067340 0x02067340  arm
 */
struct Hooks;
struct List;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef void (*CB)(void *, u32);

struct Inner02067D14 {
    u8 pad_00[0x10];
    u32 field_10;                      /* 0x10 */
    u32 mode;                          /* 0x14 */
    CB callback_18;                    /* 0x18 */
    CB callback_1c;                    /* 0x1c */
};

struct Struct02067CB0 {
    struct Inner02067D14 *inner;       /* 0x00 */
    u8 pad_04[0x0c];
    u32 unk10;                         /* 0x10 */
    u8 pad_14[0x14];
    u32 unk28;                         /* 0x28 */
    u32 unk2c;                         /* 0x2c */
    u32 flag_30;                       /* 0x30 */
};

extern void func_02067998(struct Hooks *h, struct List *lst);
extern void func_02067340(struct Inner02067D14 *a1, u32 a2);
void func_02067CB0(void);
void func_02067D14(u32 arg0);
extern struct Struct02067CB0 *g_02148B48;


void func_02067CB0(void)
{
    struct Struct02067CB0 *p = g_02148B48;

    if (p->inner->mode == 0) {
        volatile u32 *reg = (volatile u32 *)0x04000440;
        reg[0] = 0;
        reg[2] = 1;
        reg[0] = 1;
    } else {
        p->unk10 = 0;
        g_02148B48->unk2c = 0;
        g_02148B48->unk28 = 0;
    }
    g_02148B48 = 0;
}


/*
 * blocked:  MATCH, byte-exact, 180 bytes. Two call targets have no witness outside this
 *           function's own range: 0x02067998 and 0x02067340, each called from nowhere else
 *           in the image. It turns EXACT the moment either gets an entry of its own.
 */
void func_02067D14(u32 arg0)
{
    struct Struct02067CB0 *st = g_02148B48;
    struct Inner02067D14 *in = st->inner;

    if (in->field_10 == 0) {
        return;
    }

    st->flag_30 = 1;

    if (in->callback_18 != 0) {
        in->callback_18(g_02148B48, arg0);
    }

    if (g_02148B48->flag_30 != 0) {
        switch (in->mode) {
        case 0:
            func_02067998((struct Hooks *)in, (struct List *)arg0);
            break;
        case 1:
        case 2:
            func_02067340(in, arg0);
            break;
        case 3:
            break;
        }
    }

    if (in->callback_1c != 0) {
        in->callback_1c(g_02148B48, arg0);
    }
}

/*
 * function: NNSi_G2dOamSoftEmuRender
 * address:  0x02067D14
 * packet:   pkt_02067BA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocked:  MATCH, byte-exact, 180 bytes. Two call targets have no witness outside this
 *           function's own range: 0x02067998 and 0x02067340, each called from nowhere else
 *           in the image. It turns EXACT the moment either gets an entry of its own.
 * symbols:
 *   sOamSoftEmuContext    0x02148B48  data
 *   func_02067998 0x02067998  arm
 *   func_02067340 0x02067340  arm
 */

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

struct Struct02067D14 {
    struct Inner02067D14 *inner;       /* 0x00 */
    u8 pad_04[0x2c];
    u32 flag_30;                       /* 0x30 */
};

extern struct Struct02067D14 *sOamSoftEmuContext;
struct Hooks;
struct List;
extern void func_02067998(struct Hooks *h, struct List *lst);
extern void func_02067340(struct Inner02067D14 *a1, u32 a2);

void NNSi_G2dOamSoftEmuRender(u32 arg0)
{
    struct Struct02067D14 *st = sOamSoftEmuContext;
    struct Inner02067D14 *in = st->inner;

    if (in->field_10 == 0) {
        return;
    }

    st->flag_30 = 1;

    if (in->callback_18 != 0) {
        in->callback_18(sOamSoftEmuContext, arg0);
    }

    if (sOamSoftEmuContext->flag_30 != 0) {
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
        in->callback_1c(sOamSoftEmuContext, arg0);
    }
}

/*
 * function: NNS_G2dRndCoreDrawCell
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
 *   sRndCoreInstance    0x02148B48  data
 *   NNSi_G2dDrawCellToSurface3D 0x02067998  arm
 *   NNSi_G2dDrawCellToSurface2D 0x02067340  arm
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

extern struct Struct02067D14 *sRndCoreInstance;
struct Hooks;
struct List;
extern void NNSi_G2dDrawCellToSurface3D(struct Hooks *h, struct List *lst);
extern void NNSi_G2dDrawCellToSurface2D(struct Inner02067D14 *a1, u32 a2);

void NNS_G2dRndCoreDrawCell(u32 arg0)
{
    struct Struct02067D14 *st = sRndCoreInstance;
    struct Inner02067D14 *in = st->inner;

    if (in->field_10 == 0) {
        return;
    }

    st->flag_30 = 1;

    if (in->callback_18 != 0) {
        in->callback_18(sRndCoreInstance, arg0);
    }

    if (sRndCoreInstance->flag_30 != 0) {
        switch (in->mode) {
        case 0:
            NNSi_G2dDrawCellToSurface3D((struct Hooks *)in, (struct List *)arg0);
            break;
        case 1:
        case 2:
            NNSi_G2dDrawCellToSurface2D(in, arg0);
            break;
        case 3:
            break;
        }
    }

    if (in->callback_1c != 0) {
        in->callback_1c(sRndCoreInstance, arg0);
    }
}

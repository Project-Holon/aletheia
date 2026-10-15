/*
 * function: BG_SYS_CommitScroll
 * address:  0x02041B94
 * packet:   pkt_02041B94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   GFL_NET_SetIrcParams  0x0203D814  arm
 *   BUTTON_MAN_RotScaleMtx22  0x02051E74  arm
 *   func_0207D59C  0x0207D59C  arm
 *
 * The per-frame scroll/affine flush for the whole BG system: eight
 * independent blocks, one per layer, each guarded by its own bit of the
 * dirty mask at +0x04 of the singleton (the mask unit_02041F28 ORs
 * (1 << layer) into after every register write).  Nothing loops; all eight
 * blocks are written out, which is why the function is 848 bytes of almost
 * entirely repeated code.
 *
 * Layers 0, 1, 4 and 5 have only the plain path: pack scroll_x (+0x14) and
 * scroll_y (+0x18) into one word, low 9 bits and bits 16..24, and store it
 * to the layer's BGxOFS pair.  Layer 1 additionally tail-calls
 * GFL_NET_SetIrcParams with that same scroll pair.
 *
 * Layers 2, 3, 6 and 7 are affine-capable and first read the record's +0x1c
 * flag: zero takes the same plain path, non-zero builds a 16-byte matrix on
 * the stack with BUTTON_MAN_RotScaleMtx22 and hands it to func_0207D59C along with the
 * layer's affine register block.
 *
 * THREE DECLARATIONS CARRY THE FUNCTION, all three established by this pass
 * (it was untouched before):
 *
 *  1. THE RECORD REACHES PAST ITS OWN STRIDE.  The stride is 0x2c, but the
 *     affine arms read two words at slot-relative +0x2c and +0x30 -- for
 *     layer 2 those are the absolute offsets 0x84 and 0x88, which lie in the
 *     head of layer 3's record.  Declaring the record as exactly 0x2c bytes
 *     and indexing an array of them cannot express that, so the record is
 *     declared out to +0x34 and the array indexing is done explicitly with a
 *     0x2c byte stride (the SLOT macro).  The image's constant offsets, with
 *     no `mla` anywhere, are what show the indices are all compile-time.
 *
 *  2. THE MATRIX IS 16 BYTES, NOT 32.  The four stack temporaries sit at
 *     sp+0x38, +0x28, +0x18 and +0x08: a stride of 0x10.  With a 32-byte
 *     matrix the frame comes out `sub sp, #0x88` instead of `#0x48`.
 *
 *  3. func_0207D59C TAKES THE AFFINE PAIR IN r2/r3 AND THE SCROLL PAIR ON
 *     THE STACK.  That is arguments 3 and 4 being +0x2c/+0x30 and arguments
 *     5 and 6 being scroll_x/scroll_y, not the other way round.  The
 *     reversed order compiles and is the same size; it differs only in which
 *     two values are spilled to [sp] and [sp,#4], which is how the diff
 *     names it.
 *
 * GFL_NET_SetIrcParams's parameter list is also pinned here: it takes the scroll
 * pair (two u32), which the image shows as the two loads of +0x40/+0x44
 * immediately before the `bl`.  A void declaration leaves those two loads
 * with no reason to exist and loses them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BG_SYS_CommitScroll.c \
 *       --func BG_SYS_CommitScroll --addr 0x02041B94 --arm --cc 1.1p1
 */


typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* One layer record.  The stride is 0x2c, but the affine arms reach two
 * words PAST that stride, into the head of the next record: 0x84/0x88 for
 * layer 2 are slot-relative +0x2c/+0x30.  The declaration therefore runs to
 * +0x34 and the array is indexed by a 0x2c-byte stride explicitly, which is
 * what the `mla`-free constant offsets in the image show. */
struct BgSlot {
    u8  pad_00[0x14];
    u32 scroll_x;   /* +0x14 */
    u32 scroll_y;   /* +0x18 */
    u8  flag_1c;    /* +0x1c */
    u8  pad_1d[3];
    u16 aff_20;     /* +0x20 */
    u16 pad_22;
    u32 aff_24;     /* +0x24 */
    u32 aff_28;     /* +0x28 */
    u32 aff_2c;     /* +0x2c, first word of the NEXT record */
    u32 aff_30;     /* +0x30 */
};

struct BgSys { u8 raw[0x1d0]; };

#define SLOT(i) (*(struct BgSlot *)((u8 *)g_02146A44 + (i) * 0x2c))

struct Mtx { u32 w[4]; };

extern struct BgSys *g_02146A44;
extern void GFL_NET_SetIrcParams(u32 x, u32 y);
struct Mtx22;
extern void BUTTON_MAN_RotScaleMtx22(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void func_0207D59C(void *reg, struct Mtx *m, u32 a, u32 b, u32 x, u32 y);

#define W(a) (*(volatile u32 *)(a))

void BG_SYS_CommitScroll(void)
{
    u32 m  = 0x1ff;
    u32 hm = m << 16;

    if ((*(u16 *)((u8 *)g_02146A44 + 4)) & 0x01) {
        W(0x04000010) = (SLOT(0).scroll_x & m)
                      | (hm & (SLOT(0).scroll_y << 16));
    }
    if ((*(u16 *)((u8 *)g_02146A44 + 4)) & 0x02) {
        W(0x04000014) = (SLOT(1).scroll_x & m)
                      | (hm & (SLOT(1).scroll_y << 16));
        GFL_NET_SetIrcParams(SLOT(1).scroll_x,
                      SLOT(1).scroll_y);
    }
    if ((*(u16 *)((u8 *)g_02146A44 + 4)) & 0x04) {
        if (SLOT(2).flag_1c == 0) {
            W(0x04000018) = (SLOT(2).scroll_x & m)
                          | (hm & (SLOT(2).scroll_y << 16));
        } else {
            struct Mtx t;
            BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)(&t), SLOT(2).aff_20,
                          (const void *)SLOT(2).aff_24,
                          (const void *)SLOT(2).aff_28, 2);
            func_0207D59C((void *)0x04000020, &t,
                          SLOT(2).aff_2c, SLOT(2).aff_30,
                          SLOT(2).scroll_x, SLOT(2).scroll_y);
        }
    }
    if ((*(u16 *)((u8 *)g_02146A44 + 4)) & 0x08) {
        if (SLOT(3).flag_1c == 0) {
            W(0x0400001c) = (SLOT(3).scroll_x & m)
                          | (hm & (SLOT(3).scroll_y << 16));
        } else {
            struct Mtx t;
            BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)(&t), SLOT(3).aff_20,
                          (const void *)SLOT(3).aff_24,
                          (const void *)SLOT(3).aff_28, 2);
            func_0207D59C((void *)0x04000030, &t,
                          SLOT(3).aff_2c, SLOT(3).aff_30,
                          SLOT(3).scroll_x, SLOT(3).scroll_y);
        }
    }
    if ((*(u16 *)((u8 *)g_02146A44 + 4)) & 0x10) {
        W(0x04001010) = (SLOT(4).scroll_x & m)
                      | (hm & (SLOT(4).scroll_y << 16));
    }
    if ((*(u16 *)((u8 *)g_02146A44 + 4)) & 0x20) {
        W(0x04001014) = (SLOT(5).scroll_x & m)
                      | (hm & (SLOT(5).scroll_y << 16));
    }
    if ((*(u16 *)((u8 *)g_02146A44 + 4)) & 0x40) {
        if (SLOT(6).flag_1c == 0) {
            W(0x04001018) = (SLOT(6).scroll_x & m)
                          | (hm & (SLOT(6).scroll_y << 16));
        } else {
            struct Mtx t;
            BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)(&t), SLOT(6).aff_20,
                          (const void *)SLOT(6).aff_24,
                          (const void *)SLOT(6).aff_28, 2);
            func_0207D59C((void *)0x04001020, &t,
                          SLOT(6).aff_2c, SLOT(6).aff_30,
                          SLOT(6).scroll_x, SLOT(6).scroll_y);
        }
    }
    if ((*(u16 *)((u8 *)g_02146A44 + 4)) & 0x80) {
        if (SLOT(7).flag_1c == 0) {
            W(0x0400101c) = (SLOT(7).scroll_x & m)
                          | (hm & (SLOT(7).scroll_y << 16));
        } else {
            struct Mtx t;
            BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)(&t), SLOT(7).aff_20,
                          (const void *)SLOT(7).aff_24,
                          (const void *)SLOT(7).aff_28, 2);
            func_0207D59C((void *)0x04001030, &t,
                          SLOT(7).aff_2c, SLOT(7).aff_30,
                          SLOT(7).scroll_x, SLOT(7).scroll_y);
        }
    }
}

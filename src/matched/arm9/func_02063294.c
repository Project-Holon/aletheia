/*
 * function: func_02063294
 * address:  0x02063294
 * packet:   pkt_02063000
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Writes one OAM entry (attr0/attr1/attr2) into the next free slot of a
 * reserved span of bank g_02146BC8[win->bank]'s OAM shadow (+0x100), and,
 * when the entry is affine (rsMode bit 0) and mode != 0xFFFE, stamps the
 * affine parameter index into attr1 bits 9-13.  Returns 1, or 0 when the
 * span is full.
 *
 * WHAT CLOSED IT (wave 10), after 16 hand spellings at 13 bytes out:
 *  1. The permuter's split-assign(ptr): `ptr = g_02146BC8; ptr = ptr +
 *     win->bank * 0x540;` -- two statements on ONE variable -- coalesces the
 *     mla's addend with its destination (image `mla ip, r4, r3, ip`), which
 *     the one-expression spelling never does.  The "mla destination is not
 *     source-addressable" wall of cluster_02063000.h was a declarations
 *     question here.  (13 -> 7 bytes out.)
 *  2. The attribute read-modify-write is the SDK GXOamAttr bitfield union:
 *     `if (dst->rsMode & 1) dst->rsParam = mode;`.  The shift pair
 *     (<<22, >>30) is the 2-bit rsMode field at bits 8-9 and the 0x3E000000
 *     mask is the 5-bit rsParam at bits 25-29; the explicit shift/mask
 *     spelling puts the loaded word and the test in swapped registers.
 *     (7 -> 0.)
 * dsi/1.1p1 is 220 bytes (it predicates the count block): the ../2.0/sp2
 * "kept branches" pin, as for the rest of the cluster.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02063294.c
 *       --func func_02063294 --addr 0x02063294 --arm --cc ../2.0/sp2
 *
 * symbols:
 *   g_02146BC8  0x02146BC8  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    union {
        u32 attr01;
        struct {
            u32 y:8;
            u32 rsMode:2;
            u32 objMode:2;
            u32 mosaic:1;
            u32 colorMode:1;
            u32 shape:2;
            u32 x:9;
            u32 rsParam:5;
            u32 size:2;
        };
        struct { u16 attr0; u16 attr1; };
    };
    u16 attr2;
    u16 _3;
} GXOamAttr;
struct Win02063294 { u32 bank; u16 min_oam; u16 max_oam; u16 cur_oam; };
extern u8 g_02146BC8[];

u32 func_02063294(struct Win02063294 *win, GXOamAttr *src, u32 mode)
{
    u16 max_oam = win->max_oam;
    u16 cur_oam = *(volatile u16 *)&win->cur_oam;
    u32 valid = 0;
    u32 count;
    u32 ge;
    u8 *ptr;
    u32 idx;
    if (!((int)cur_oam > (int)max_oam + 1)) {
        if (win->min_oam <= max_oam) valid = 1;
    }
    if (valid == 0) count = 0;
    else count = (u16)(max_oam - cur_oam + 1);
    if (count >= 1) ge = 1; else ge = 0;
    if (ge == 0) goto fail;
    ptr = g_02146BC8;
    ptr = ptr + win->bank * 0x540;
    idx = win->cur_oam;
    ptr = ptr + 0x100;
    {
        GXOamAttr *dst = (GXOamAttr *)(ptr + idx * 8);
        dst->attr0 = src->attr0;
        dst->attr1 = src->attr1;
        dst->attr2 = src->attr2;
        if (mode != 0xFFFE) {
            if (dst->rsMode & 1) {
                dst->rsParam = mode;
            }
        }
    }
    win->cur_oam = win->cur_oam + 1;
    return 1;
fail:
    return 0;
}

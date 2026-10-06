/*
 * file:     pokeparty_p11.c
 * unit:     yes
 * function: func_0201CAC8, func_0201CC34, func_0201CCE4
 * address:  0x0201CAC8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201D26C  0x0201D26C  thumb
 *   func_020437DC  0x020437DC  arm
 */
struct Bmp;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

struct PrintCtx {
    s16   unk00;
    s16   unk02;
    s32   unk04 : 10;
    u32   unk04b : 22;
    u16   unk08;
    u16   unk0A;
    u16   unk0C;
    u16   unk0E;
    void *unk10;
    void *unk14;
    void *unk18;
};

typedef signed char s8;

extern void func_0201DD78(u32 a, u32 b, u32 c);
extern u32 func_0201D26C(u16 *p, void *font, u32 spacing, u16 **next);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201CD10(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6,
                          u32 a7, u32 a8, u16 a9, u16 a10, u32 a11);
u16 *func_0201CC34(u16 *a0, u16 *a1);
void func_0201CCE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u16 a10);


/*
 * printsys.c: applies one 0xF000 control block whose code byte is 0xBD -- the
 * "set colour / align line" family -- and steps the cursor past the block.
 * Called from exactly one place image-wide, 0x0201C9D0 inside func_0201C974,
 * which is why func_0201C974 resolved that call `sole-ref/code` until this
 * file existed; it is `matched` now.
 *
 * The dispatch is a DENSE switch on a 7-entry PC-relative halfword table at
 * +0x30..+0x3D, so cases 0..6 must ALL be written, including `case 6:` which
 * is empty and shares the default's exit
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md and
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  Without the
 * empty case 6 the bound check is `cmp r1, #5` and the table has six entries.
 *
 * Two spellings the bytes pin:
 *
 *  1. The switch selector is `((u32)(u8)p[1] << 16) >> 16`, TWO stacked
 *     narrowings: the original has `lsls #0x18 / lsrs #0x18` (the byte) and
 *     then `lsls #0x10 / lsrs #0x10` (a u16) before the bound check.  Written
 *     as a plain `(u8)p[1]` into a `u16` local the second pair folds away and
 *     the function is four bytes short.  Two nested inlined accessors, one
 *     returning u8 and one u16.
 *
 *  2. The 5/5/5 pack in case 0 is `(b & 0x1F) | (((r << 27) >> 17) |
 *     ((g << 27) >> 22))`, i.e. RED shifts to bit 10 and GREEN to bit 5.  The
 *     reversed grouping is size-exact and eight bytes out; the order of the
 *     two `lsls #0x1b` operands in the image names which byte is which
 *     (docs/idioms/commutative-operand-order-names-the-temporary.md).
 *
 * Also corrected against docs/families/printsys.h as it stood: the measuring
 * arms (cases 2 and 3) hand func_020437DC the handle at PrintCtx+0x14, not
 * +0x18; +0x18 is the renderer hook func_0201C974 calls through.  And
 * PrintCtx+0x04 is a SIGNED 10-BIT BITFIELD (`lsls #0x16 / asrs #0x16`), not
 * a u32 flag word -- the same fact src/matched/func_0201C974.c records.
 *
 * Case order in the source is 0, 1, 3, 2, 4, 5, 6: the table's displacements
 * put case 3's body (0x0201CB7E) before case 2's (0x0201CBB6), and this
 * compiler emits switch arms in source order.
 */
u16 *func_0201CAC8(struct PrintCtx *c, u16 *p)
{
    u32 arg;
    u16 v = *p;
    u32 k;

    if (v == 0xF000) {
        k = ((u32)(u8)p[1] << 16) >> 16;
    } else {
        k = 0xFFFF;
    }

    switch (k) {
    case 0: {
        u32 r, g, b;
        r = (u8)((v == 0xF000) ? p[3] : 0);
        g = (u8)((v == 0xF000) ? p[4] : 0);
        arg = (u8)((v == 0xF000) ? p[5] : 0);
        func_0201DD78(r, g, arg);
        c->unk0E = (u16)((arg & 0x1F) | (((r << 27) >> 17) | ((g << 27) >> 22)));
        break;
    }
    case 1: {
        u16 t = c->unk0C;
        func_0201DD78((u8)((t >> 10) & 0x1F), (u8)((t >> 5) & 0x1F), (u8)(t & 0x1F));
        break;
    }
    case 3: {
        s32 w = func_020437DC(c->unk14);
        s32 x0 = (s32)(w - c->unk04);
        u32 adv;
        u32 n = 0;
        adv = (u32)func_0201D26C(p, c->unk10, 0, 0);
        {
            u32 nn = 0;
            if (*p == 0xF000) {
                nn = p[3];
            }
            c->unk00 = (s16)(c->unk04 + (x0 - (s32)adv) - 1 - (s32)nn);
        }
        break;
    }
    case 2: {
        s32 w = func_020437DC(c->unk14);
        s32 x0 = (s32)(w - c->unk04);
        s32 adv = func_0201D26C(p, c->unk10, 0, 0);
        if (adv < x0) {
            c->unk00 = (s16)(c->unk04 + (x0 - adv) / 2);
        } else {
            c->unk00 = (s16)c->unk04;
        }
        break;
    }
    case 4: {
        u32 d = (v == 0xF000) ? p[3] : 0;
        c->unk00 = (s16)(c->unk00 + (s16)d);
        break;
    }
    case 5: {
        u32 d = (v == 0xF000) ? p[3] : 0;
        c->unk00 = (s16)d;
        break;
    }
    case 6:
        break;
    default:
        break;
    }

    if (*p == 0xF000) {
        p = (u16 *)((u8 *)(p + 3) + p[2] * 2);
    }
    return p;
}


u16 *func_0201CC34(u16 *a0, u16 *a1)
{
    u16 t;
    u8 b;
    u8 m;
    int x;

    if (a1[0] == 0xF000) {
        t = (u16)(a1[1] & 0xFF);
    } else {
        t = 0xFFFF;
    }
    if (t == 0) {
        b = (u8)((a1[0] == 0xF000) ? a1[3] : 0);
        if (b == 0xFF) {
            func_0201DD78((u8)((a0[7] >> 10) & 0x1F), (u8)((a0[7] >> 5) & 0x1F),
                          (u8)(a0[7] & 0x1F));
        } else {
            int x1;
            int x2;
            x = b * 2;
            m = (u8)(a0[6] & 0x1F);
            x2 = x + 2;
            x1 = x + 1;
            func_0201DD78((u8)x1, (u8)x2, m);
            a0[7] = (u16)((((u8)x1 & 0x1F) << 10) | (((u8)x2 & 0x1F) << 5)
                          | (m & 0x1F));
        }
    }
    if (a1[0] == 0xF000) return (u16 *)((char *)a1 + 6 + a1[2] * 2);
    return a1;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201CCE4.c \
 *       --func func_0201CCE4 --addr 0x0201CCE4 --cc 1.1p1 --thumb
 */
void func_0201CCE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u32 a7,
                   u32 a8, u16 a9, u16 a10)
{
    func_0201CD10(a0, a1, a2, a3, a5, a6, a7, a8, a9, a10, 0);
}

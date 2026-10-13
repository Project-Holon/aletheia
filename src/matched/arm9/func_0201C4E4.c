/*
 * function: PRINTSYS_QUE_Main
 * address:  0x0201C4E4
 * packet:   pkt_0201C4E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = (u8 *)ps;` before `base = (u8 *)ps + 0x18;`). Game code has no
 * line table, so these were stand-ins. The plain single assignment gives
 * EXACT in --lang c99 and --lang c: the output bytes do not change. Older
 * text in this header that asks for the double assignment is superseded.
 *
 * symbols:
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   GF_FONT_IsTextColorDifferent  0x0201DE18  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_020870D0  0x020870D0  arm
 *   PRINTSYS_PrintStep  0x0201C974  thumb
 *   func_0201D7C4  0x0201D7C4  thumb
 *
 * printsys.c: the per-frame print pump.  Bumps the frame counter at +6,
 * saves the current text colour, applies the head request's colour when its
 * 4-bit kind is 0 or 2, then runs glyphs through PRINTSYS_PrintStep until the
 * string ends or the tick budget at +8 (func_020870D0 is OS_GetTick) runs
 * out.  On string end it pops the request (func_0201D7C4) and moves the
 * glyph cursor to the next record's text in the byte ring at +0x18,
 * wrapping twice at the ring size.  Restores the colour and reports idle.
 *
 * The last five bytes closed on the SHAPE OF THE INLINE WRAP HELPER: it
 * copies its parameter into a named local, conditionally zeroes the local
 * and returns it (`u16 r = o; if (r >= size) r = 0; return r;`).  The
 * early-return spelling (`if (o >= size) return 0; return o;`) truncates
 * `off + 0x1C` in place and hoists the ring-size load between the two
 * shifts; the named-local spelling keeps the image's
 * `lsls r0, r7 / lsrs r1, r0 / ldrh r0, [r5, #4]` order.  History in
 * docs/notes/PRINTSYS_QUE_Main.c.txt.
 */

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;
typedef signed int          s32;

struct Rec {
    u32 unk00;
    u32 pad04a : 20;
    s32 kind   : 4;
    u32 pad04b : 8;
    u32 pad08;
    u16 pad0C;
    u16 unk0E;
};

struct PrintSys {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8  unk06;
    u8  unk07lo : 4;
    u8  unk07hi : 4;
    u64 unk08;
    struct Rec *unk10;
    u16 *unk14;
    u8  buf[4];
};

extern void  GF_FONT_GetTextColor(u8 *r, u8 *g, u8 *b);
extern u32   GF_FONT_IsTextColorDifferent(u32 r, u32 g, u32 b);
extern void  GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern u64   func_020870D0(void);
struct PrintCtx;
extern u16 *PRINTSYS_PrintStep(struct PrintCtx *c, u16 *p, u32 f);
extern void *func_0201D7C4(struct PrintSys *p, void *q);

static inline u16 Wrap(struct PrintSys *ps, u16 o)
{
    u16 r = o;

    if (r >= ps->unk04)
        r = 0;
    return r;
}

u32 PRINTSYS_QUE_Main(struct PrintSys *ps)
{
    u16 cap;
    u8  col[3];
    u32 stop;
    u16 saved;
    u32 rr;
    u32 bb;
    u8 *base;
    u32 r;
    u32 g;
    u32 b;
    u32 go;
    u32 gg;
    u32 off;
    u16 o;
    u64 t0;

    stop = 0;
    ps->unk06 = (u8)(ps->unk06 + 1);
    if (ps->unk10 == 0) {
        return 1;
    }
    GF_FONT_GetTextColor(&col[2], &col[1], &col[0]);
    saved = (u16)(((col[2] & 0x1F) << 10) | ((col[1] & 0x1F) << 5) |
                  (col[0] & 0x1F));
    go = 0;
    if (ps->unk10->kind == 0 || ps->unk10->kind == 2) {
        r = (u8)((ps->unk10->unk0E >> 10) & 0x1F);
        g = (u8)((ps->unk10->unk0E >> 5) & 0x1F);
        b = (u8)(ps->unk10->unk0E & 0x1F);
        go = 1;
    }
    if (go != 0) {
        if (GF_FONT_IsTextColorDifferent(r, g, b) != 0) {
            GF_FONT_SetTextColor(r, g, b);
        }
    }
    t0 = func_020870D0();
    if (ps->unk10 != 0) {
        base = (u8 *)ps + 0x18;
        do {
            if (ps->unk10->kind == 1) {
                rr = (u8)((ps->unk10->unk0E >> 10) & 0x1F);
                gg = (u8)((ps->unk10->unk0E >> 5) & 0x1F);
                bb = (u8)(ps->unk10->unk0E & 0x1F);
                if (GF_FONT_IsTextColorDifferent(rr, gg, bb) != 0) {
                    GF_FONT_SetTextColor(rr, gg, bb);
                }
                ps->unk10->kind = 2;
            }
            while (ps->unk14[0] != 0xFFFF) {
                ps->unk14 = PRINTSYS_PrintStep((struct PrintCtx *)ps->unk10, ps->unk14, 1);
                if (func_020870D0() - t0 > ps->unk08) {
                    stop = 1;
                    break;
                }
            }
            if (ps->unk14[0] == 0xFFFF) {
                off = (u16)((u8 *)ps->unk10 - base);
                ps->unk10 = func_0201D7C4(ps, ps->unk10);
                if (ps->unk10 != 0) {
                    o = Wrap(ps, off + 0x1C);
                    o = Wrap(ps, o + 4);
                    ps->unk14 = (u16 *)((u8 *)ps + 0x18 + o);
                }
            }
        } while (stop == 0 && ps->unk10 != 0);
    }
    GF_FONT_SetTextColor((u8)((saved >> 10) & 0x1F), (u8)((saved >> 5) & 0x1F),
                  (u8)(saved & 0x1F));
    if (ps->unk10 != 0) {
        ps->unk02 = (u16)((u8 *)ps->unk14 - ((u8 *)ps + 0x18));
        return 0;
    }
    ps->unk00 = 0;
    ps->unk02 = ps->unk04;
    ps->unk07lo = 0;
    return 1;
}


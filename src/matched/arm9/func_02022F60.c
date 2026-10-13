/*
 * function: WIPE_SUB_LineMaskHBlank
 * address:  0x02022F60
 * packet:   pkt_02022F60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The per-scanline window programmer of the wipe family (1284 bytes with
 * both literal pools; no relocations at all, every pool word is a
 * hardware register address or a mask).  It reads VCOUNT, steps to the
 * next line (wrapping at 0xC0) and, for one or both of the two 0x184-byte
 * halves of the object, sets the outside-window plane mask (0x3F on a
 * clear row, 0x20 on a set one) and then the window-0 or window-1 inside
 * mask (chosen by the half's +0x180 word) on the MAIN engine when the
 * byte at +0x309 is 0 and on the SUB engine otherwise.
 *
 * Four facts closed it (the 2026-09-21 note was 140 bytes short):
 *  - The +0x309 arms are NOT identical: the zero arm writes the main
 *    engine's WININ/WINOUT at 0x04000048/0x0400004A, reached as
 *    0x04000004 + 0x44/0x46 off the already-loaded DISPSTAT address, and
 *    the other arm the sub engine's 0x04001048/0x0400104A.  With both
 *    arms spelled the same mwcc cross-jumps them, which was the whole
 *    deficit.
 *  - The +0x309 byte is read BEFORE the +0x180 word at every WININ
 *    leaf, so the engine is bound to a local ahead of the window test.
 *  - The second half's base is a NAMED local `h = &p->h[1]`: passed
 *    inline, mwcc folds p + 0x184 + n + 0xC0 into one offset and the
 *    +0x180 word into p + 0x304; the image materialises p + 0x184 once.
 *  - The body is wrapped in `if (n < 0xC0)`, which lets the exit branch
 *    reuse a leaf's branch island (`bge` to 0x02022FE6) instead of a
 *    blt/b pair; and the window-1 mask is `~0x3F00` (pool word
 *    0xFFFFC0FF), not 0xC0FF.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define REG_VCOUNT    (*(volatile u16 *)0x04000006)
#define REG_DISPSTAT  (*(volatile u16 *)0x04000004)
#define REG_WININ     (*(volatile u16 *)0x04000048)
#define REG_WINOUT    (*(volatile u16 *)0x0400004A)
#define REG_DB_WININ  (*(volatile u16 *)0x04001048)
#define REG_DB_WINOUT (*(volatile u16 *)0x0400104A)

struct Half {
    u8  pad[0xC0];
    u8  rows[0xC0];
    u32 wnd;
};

struct S {
    struct Half h[2];
    u8 mode;
    u8 eng;
};


#define LEAF(REG, MASK, VAL, EFF)            \
    if (REG_DISPSTAT & 2) {                  \
        v = (REG & MASK) | (VAL);            \
        REG = v | EFF;                       \
    }

#define SET_OUT(eng, wnd)                                        \
    if ((eng) == 0) { LEAF(REG_WINOUT, ~0x3F, wnd, 0x20) }       \
    else { LEAF(REG_DB_WINOUT, ~0x3F, wnd, 0x20) }

#define SET_IN(eng, which, wnd)                                          \
    e = (eng);                                                           \
    if ((which) == 0) {                                                  \
        if (e == 0) { LEAF(REG_WININ, ~0x3F, wnd, 0x20) }            \
        else { LEAF(REG_DB_WININ, ~0x3F, wnd, 0x20) }                    \
    } else {                                                             \
        if (e == 0) { LEAF(REG_WININ, ~0x3F00, (wnd) << 8, 0x2000) }  \
        else { LEAF(REG_DB_WININ, ~0x3F00, (wnd) << 8, 0x2000) }          \
    }

static inline void Apply(struct S *p, struct Half *h, int n)
{
    int v;
    int e;

    if (h->rows[n] == 0) {
        SET_OUT(p->eng, 0x3F)
        SET_IN(p->eng, h->wnd, 0x20)
    } else {
        SET_OUT(p->eng, 0x20)
        SET_IN(p->eng, h->wnd, 0x3F)
    }
}

void WIPE_SUB_LineMaskHBlank(struct S *p)
{
    int n;
    struct Half *h;

    n = REG_VCOUNT;
    if (n < 0xC0) {
        n = n + 1;
        if (n > 0xBF)
            n -= 0xC0;

        if (p->mode == 1) {
            Apply(p, &p->h[0], n);
        } else {
            Apply(p, &p->h[0], n);
            h = &p->h[1];
            Apply(p, h, n);
        }
    }
}

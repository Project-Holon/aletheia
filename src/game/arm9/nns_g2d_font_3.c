/*
 * file:     nns_g2d_font_3.c
 * unit:     yes
 * function: func_020698F8, func_02069AC4
 * address:  0x020698F8
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NNS_G2dFindBinaryBlock  0x02062B64  arm
 *   func_02088234  0x02088234  arm
 */
struct NitroFileHeader;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef int BOOL;

typedef struct {
    u32 sig;
    u16 unk04;
    u16 ver;
    u32 unk08;
    u16 off0C;
    u16 cnt0E;
} Res;

typedef signed int s32;

typedef struct {
    u32 sig;
    u32 size;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
} Section;

extern void *NNS_G2dFindBinaryBlock(struct NitroFileHeader *file, u32 signature);
extern void func_02088234(void);
u32 func_020698F8(Res *res, void **out);
void func_02069AC4(Res *base);


static inline BOOL IsNftr(const Res *r)
{
    if (r != 0 && r->sig == 0x4e465452u)
        return 1;
    return 0;
}


static inline BOOL VerAtLeast(const Res *r, u16 v)
{
    if (r != 0 && r->ver >= v)
        return 1;
    return 0;
}


static inline BOOL IsValid(const Res *r, u16 v)
{
    return r != 0 ? (IsNftr(r) && VerAtLeast(r, v)) : 0;
}


/*
 * NFTR font-resource open (docs/families/cluster_020694D8.h): validate the
 * resource against version 0x0102, then 0x0101, else assert 0x0100 and mark
 * it legacy; relocate the section table, find 'FINF', hand back payload + 8,
 * and for a legacy resource clear byte 7 of the FINF's +8 pointee.
 *
 * Closed wave 12.  The six doubly-normalised guards are three INLINE helper
 * levels, and the leaf helpers are written as `if (cond) return 1; return 0;`
 * -- the only spelling that materialises the `&&` value (moveq #1 / beq /
 * mov #0) instead of merging it into the caller's branch.  The caller's `&&`
 * then normalises it (movne #1 / moveq #0) and tests it; the outer
 * `r != 0 ? ... : 0` is the leading null test whose false value is the r4
 * zero.  `return r && cond;` in the leaves merges into control flow (256
 * bytes); `if (r == 0) return 0; return cond;` gives movhs/movlo (122 out).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020698F8.c \
 *       --func func_020698F8 --addr 0x020698F8 --arm --cc ../2.0/sp2
 *   EXACT, 460 bytes, 3 of 3 relocation sites resolved.
 *   ../2.0/sp2p2: EXACT as well; dsi/1.1p1: 452 bytes, DIFF.
 */
u32 func_020698F8(Res *res, void **out)
{
    BOOL legacy = 0;
    u8 *finf;

    if (!IsValid(res, 0x102) && !IsValid(res, 0x101)) {
        if (!IsValid(res, 0x100))
            func_02088234();
        legacy = 1;
    }
    func_02069AC4(res);
    finf = NNS_G2dFindBinaryBlock((struct NitroFileHeader *)res, 0x46494e46u);
    if (finf == 0) {
        *out = 0;
        return 0;
    }
    *out = finf + 8;
    if (legacy)
        (*(u8 **)((u8 *)*out + 8))[7] = 0;
    return 1;
}


/*
 * Relocate the section table of an NFTR-style font resource loaded at `base`:
 * the u16 at +0x0C is the byte offset of the first section header and the u16
 * at +0x0E the section count; each header carries its own FourCC at +0 and its
 * own size at +4, which is the stride to the next one.
 *
 * Per-signature fixups, all "add `base` to a stored file offset":
 *   'FINF'  +0x10 unconditionally, then +0x14 and +0x18 if non-zero
 *   'CWDH'  +0x0C if non-zero
 *   'CMAP'  +0x10 if non-zero
 *   'CGLP'  nothing -- an EMPTY arm whose target is the default exit.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md). The
 * original keeps the dead `cmp r5, lr` at 0x02069B00 (e155000e), the left
 * leaf of the four-way search tree, immediately before the unconditional
 * `b 0x02069B74` to the default exit. dsi/1.1p1 -O4,p folds that compare
 * away because the CGLP arm and the default share a target, giving 216
 * bytes against the original's 220, with every other byte identical and
 * shifted by exactly those four. Empty-arm, `default:`-fallthrough,
 * `continue` and `goto` spellings all fold the same way under 1.1p1.
 * ../2.0/sp2 keeps the compare: 220 bytes, 0 mismatches.
 */
void func_02069AC4(Res *base)
{
    Section *s;
    s32 i;
    s32 n;
    u32 v;

    s = (Section *)((u8 *)base + base->off0C);
    i = 0;
    n = base->cnt0E;
    if (n <= 0) return;
    do {
        switch (s->sig) {
        case 0x46494e46:
            s->unk10 = s->unk10 + (u32)base;
            v = s->unk14;
            if (v != 0) s->unk14 = v + (u32)base;
            v = s->unk18;
            if (v != 0) s->unk18 = v + (u32)base;
            break;
        case 0x43574448:
            v = s->unk0C;
            if (v != 0) s->unk0C = v + (u32)base;
            break;
        case 0x434d4150:
            v = s->unk10;
            if (v != 0) s->unk10 = v + (u32)base;
            break;
        case 0x43474c50:
            break;
        }
        i++;
        s = (Section *)((u8 *)s + s->size);
    } while (i < (s32)base->cnt0E);
}

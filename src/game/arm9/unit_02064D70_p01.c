/*
 * file:     unit_02064D70_p01.c
 * unit:     yes
 * function: func_02064D70, func_02064E3C
 * address:  0x02064D70
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
 *   g_02147B88   0x02147B88  data
 *   g_02147B98   0x02147B98  data
 *   g_02147D18   0x02147D18  data
 *   g_02147D28   0x02147D28  data
 *   g_02147D2C   0x02147D2C  data
 *   g_02148018   0x02148018  data
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u16  count;
    u8   pad_02[2];
    u8  *entries;      /* +0x04 */
} Tab;

typedef struct {
    Tab  *f00;
    u8    pad_04[4];
    u32   f08;
    u8   *f0c;
} S;

struct B8802064E3C {
    u8  pad_00[4];
    u32 unk_04;
    u8  pad_08[4];
    u32 unk_0c;
};

struct Blk02064E3C {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
};

void func_02064D70(S *p, int (*fn)(void *, void *, void *, int), void *ctx);
void func_02064E3C(void);
extern struct B8802064E3C g_02147B88;
extern u32 g_02147B98[];
extern struct Blk02064E3C g_02147D18[];
extern u8 g_02147D28[];
extern u8 g_02147D2C[];
extern struct Blk02064E3C g_02148018[];


/*
 * Name-record walker, the 0x5c / 0x28 stride pair of the cluster_02064B68
 * bank family.  A table with a u16 count at +0x00 and an 8-byte-record array
 * at +0x04: mode 1 hands the callback a pointer into the 0x5c-record array
 * indexed by the record's HIGH BYTE, every other mode the first word of the
 * 0x28-record array.  The callback gets (ctx, record, value, index) and a
 * zero return stops the walk.  This is a `void` function whose early exit is
 * a bare `return;`: an `int` return materialises a value and changes both
 * epilogues.
 *
 * Two levers closed the 4-byte residue docs/notes/func_02064D70.c.txt
 * records, and both are worth keeping:
 *
 *   The high-byte extract.  The image is three instructions,
 *   `and r2, r2, #0xff00` / `lsl r2, r2, #8` / `lsr ip, r2, #0x10`, and the
 *   note measured five spellings (`f >> 8`, `(u8)(f >> 8)`,
 *   `((f >> 8) & 0xff)`, `(f & 0xff00) >> 8`, f as u16 and as u32) that all
 *   fold to the single shift, which is the four bytes it was short.  The
 *   spelling that keeps all three is the mask assigned into a u16 and then
 *   shifted through u32: `(u32)((x & 0xff00) << 8) >> 16`.  The mask must be
 *   NARROWED to u16 before the pair, which is what makes the `lsl #8` survive
 *   instead of folding with the `lsr`.
 *
 *   Declaration order.  `i` must be declared FIRST, before `tab` and `n`;
 *   the note's register rotation (tab -> r8, count -> sb, i -> r7 in the
 *   image against r7/r8/sb in the compile) is entirely that, per
 *   docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *   The permuter named both levers: decl-order(i<->n), decl-order(i<->tab)
 *   and expand(f), 18 concrete bytes out -> 0.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02064D70.c \
 *       --func func_02064D70 --addr 0x02064D70 --arm --cc 1.1p1
 */
void func_02064D70(S *p, int (*fn)(void *, void *, void *, int), void *ctx)
{
    u16  i;
    Tab *tab = p->f00;
    u16  n   = tab->count;

    if (p->f08 == 1) {
        u8 *base = p->f0c;

        for (i = 0; i < n; i++) {
            if (fn(ctx, tab->entries + i * 8,
                   base + ((u32)((*(u16 *)(tab->entries + i * 8 + 6) & 0xff00) << 8) >> 16) * 0x5c,
                   i) == 0)
                return;
        }
    } else {
        u8 *base = p->f0c;

        for (i = 0; i < n; i++) {
            if (fn(ctx, tab->entries + i * 8,
                   *(void **)(base + i * 0x28), i) == 0)
                return;
        }
    }
}


/*
 * Initialises one 0x18-byte slot of the renderer's per-slot tables, selected by
 * g_02147B88's +0xC field: either the two words at 0x02147D28 / 0x02147D2C are
 * cleared, or the six words of the template at 0x02147D18 are built
 * (0x1000, 0, 0, 0x1000, 0, 0) and copied whole into 0x02148018, which is the
 * 24-byte aggregate assignment the `ldm`/`stm` pair reproduces.  The slot's
 * entry in the u32 table at 0x02147B98 is cleared either way.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064E3C.c \
 *       --func func_02064E3C --addr 0x02064E3C --arm --cc 1.1p1
 */
void func_02064E3C(void)
{
    u32 i = g_02147B88.unk_0c;

    if (g_02147B88.unk_04 != 0) {
        *(u32 *)&g_02147D28[i * 0x18] = 0;
        *(u32 *)&g_02147D2C[i * 0x18] = 0;
    } else {
        struct Blk02064E3C *s = &g_02147D18[i];

        s->unk_00 = 0x1000;
        s->unk_04 = 0;
        s->unk_08 = 0;
        s->unk_0c = 0x1000;
        s->unk_10 = 0;
        s->unk_14 = 0;
        g_02148018[i] = *s;
    }

    g_02147B98[i] = 0;
}

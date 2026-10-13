/*
 * function: CLACT_ExitResources
 * address:  0x0204D8AC
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Was blocked at MATCH: all 264 concrete bytes were correct and the two PC24
 * sites at +0x00E0 and +0x00E8, both calls to VMAN_Delete, had no witness
 * of any class (those two calls were its only branch references image
 * wide).  Unblocked by src/matched/VMAN_Delete.c, now a `matched` witness.
 *
 * symbols:
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   CLACT_FreeCharacterTable  0x0204DC64  arm
 *   CLACT_FreePaletteTable  0x0204E010  arm
 *   CLACT_FreeCellAnimTable  0x0204E0C4  arm
 *   VMAN_Delete  0x020345DC  arm
 *
 * The inverse of src/pending/CLACT_InitResources.c: release every live entry of the
 * three parallel tables, then the tables themselves and the two heaps, and
 * NULL all five pointers.  This block is the tail of the singleton, at
 * +0x104, which is why the three per-entry finalisers take a bare index and
 * find the table through the global themselves (src/matched/CLACT_ReleaseCharacter.c,
 * CLACT_ReleasePalette.c and CLACT_ReleaseCellAnim.c).
 *
 * The liveness tests are the same three fields those finalisers write: the
 * one-bit field at bit 31 of +0x3c of the 0x40-byte record, the whole word at
 * +0x10 of the 0x14-byte record, and the one-bit field at bit 31 of +0x14 of
 * the 0x18-byte record.  Bit 31 reads as a bare `lsrs #0x1f` with no mask,
 * which is the bitfield tell
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * Every loop re-reads both its bound and its table base, because the
 * finaliser it calls is opaque and may store to the singleton.  The two
 * non-power-of-two strides become `mla` against a register-held 0x14 and
 * 0x18; only the 0x40 stride folds into `add r0, r0, r4, lsl #6`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_ExitResources.c \
 *       --func CLACT_ExitResources --addr 0x0204D8AC --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RecC {
    u8  pad_00[0x3c];
    u32 unk_3c_0  : 1;
    u32 unk_3c_1  : 30;
    u32 unk_3c_31 : 1;
};

struct RecA {
    u8  pad_00[0x14];
    u32 unk_14_0  : 31;
    u32 unk_14_31 : 1;
};

struct RecB {
    u8  pad_00[0x10];
    u32 unk_10;
};

struct Res {
    void        *tiles;      /* 0x00 */
    void        *palettes;   /* 0x04 */
    struct RecC *cell;       /* 0x08 */
    struct RecA *anim;       /* 0x0c */
    struct RecB *pattern;    /* 0x10 */
    u16          n_cell;     /* 0x14 */
    u16          n_anim;     /* 0x16 */
    u16          n_pattern;  /* 0x18 */
};

extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
struct Struct020345DC;
extern void CLACT_FreeCharacterTable(void *ptr);
extern void CLACT_FreePaletteTable(void *ptr);
extern void CLACT_FreeCellAnimTable(void *ptr);
extern void VMAN_Delete(struct Struct020345DC *obj);

void CLACT_ExitResources(struct Res *res)
{
    u32 i;

    for (i = 0; i < res->n_cell; i++) {
        if (res->cell[i].unk_3c_31 == 0) {
            func_0204A8D4(i);
        }
    }

    for (i = 0; i < res->n_pattern; i++) {
        if (res->pattern[i].unk_10 == 0) {
            func_0204AFD8(i);
        }
    }

    for (i = 0; i < res->n_anim; i++) {
        if (res->anim[i].unk_14_31 == 0) {
            func_0204ADA4(i);
        }
    }

    CLACT_FreeCharacterTable(res->cell);
    CLACT_FreePaletteTable(res->anim);
    CLACT_FreeCellAnimTable(res->pattern);
    VMAN_Delete(res->palettes);
    VMAN_Delete(res->tiles);

    res->tiles    = 0;
    res->palettes = 0;
    res->cell     = 0;
    res->anim     = 0;
    res->pattern  = 0;
}

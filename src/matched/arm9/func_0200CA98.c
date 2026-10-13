/*
 * function: ZUKAN_SAVE_UpdateViewFlags
 * address:  0x0200CA98
 * packet:   pkt_0200CA98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The bitmap maintenance of "musical_dist_save.c" (block 0x37): for a
 * species id listed in the {id, count} form table it clears the species'
 * run of form bits in the two nine-byte form rows at +0x30E and +0x317,
 * clamps the caller's form index to the species' count and sets that one
 * form bit in the row `alt` picks; then, for every species, it clears the
 * id's bit in the four 0x54-byte rows at +0x1AC and sets it in the row
 * chosen by (sel, alt), with the same six-arm shape as ZUKAN_SAVE_SetSeenGenderFlag.
 *
 * Written from the start (wave 20, lane musical_fresh) after five lanes
 * iterated on one inherited source and stopped at 89 bytes out; see
 * docs/notes/pkt_0200CA98.c.txt.  Two things closed it:
 *
 *  - The bit operations are four inline helpers on a u16 index, two plain
 *    ones for the flat form index and two that decrement the 1-based
 *    species id first (the `subs #1` / `lsls #0x10` / `lsrs #0x10` on the
 *    id, with no narrowing of id itself because it arrives as u16).  The
 *    inlining is what puts x>>3, 1<<(x&7) and the 0xFF mask into shared
 *    values: the tail's bit and byte offset are computed once, before the
 *    clear loop, and reused by all six set arms.
 *  - Every row argument is passed through an explicit `(u8 *)` cast.  With
 *    the bare array (`p->unk1AC[i]`, which decays to the same type) the
 *    optimizer reassociates the address as (p + off) + K and keeps K in a
 *    register; the cast keeps p + K as one operand, so p + 0x30E / p + 0x317
 *    are hoisted out of the form loop and p + 0x1AC out of the clear loop,
 *    as the image does.  That also moves p off the register file onto the
 *    stack, which was the tail's register rotation.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/ZUKAN_SAVE_UpdateViewFlags.c \
 *       --func ZUKAN_SAVE_UpdateViewFlags --addr 0x0200CA98
 *   -> EXACT (392 bytes, both table literals resolved)
 *
 * symbols:
 *   sZukanFormTable  0x0209DE4C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk37 {
    u32 unk00;
    u32 unk04;
    u8  unk008[0x54];
    u8  unk05C[4][0x54];
    u8  unk1AC[4][0x54];
    u8  unk2FC[4][9];
    u8  unk320[0x1B0];
    u32 unk4D0;
};

struct FormCount {
    u16 unk00;
    u16 unk02;
};

extern const struct FormCount sZukanFormTable[];

static inline void FormSetBit(u8 *a, u16 no)
{
    a[no >> 3] |= (u8)(1 << (no & 7));
}

static inline void FormResetBit(u8 *a, u16 no)
{
    a[no >> 3] &= (u8)((1 << (no & 7)) ^ 0xFF);
}

static inline void SetBit(u8 *a, u16 no)
{
    no--;
    a[no >> 3] |= (u8)(1 << (no & 7));
}

static inline void ResetBit(u8 *a, u16 no)
{
    no--;
    a[no >> 3] &= (u8)((1 << (no & 7)) ^ 0xFF);
}

void ZUKAN_SAVE_UpdateViewFlags(struct Blk37 *p, u16 id, u32 sel, u32 alt, u32 form)
{
    u32 i;
    u32 j;
    u32 off;

    off = 0;
    i = 0;
    do {
        if (id == sZukanFormTable[i].unk00) {
            for (j = 0; j < sZukanFormTable[i].unk02; j++) {
                FormResetBit((u8 *)p->unk2FC[2], off + j);
                FormResetBit((u8 *)p->unk2FC[3], off + j);
            }
            if (form >= sZukanFormTable[i].unk02) {
                form = 0;
            }
            if (alt == 1) {
                FormSetBit((u8 *)p->unk2FC[3], off + form);
            } else {
                FormSetBit((u8 *)p->unk2FC[2], off + form);
            }
            break;
        }
        off += sZukanFormTable[i].unk02;
        i++;
    } while (sZukanFormTable[i].unk00 != 0);

    for (i = 0; i < 4; i++) {
        ResetBit((u8 *)p->unk1AC[i], id);
    }
    if (sel == 0) {
        if (alt == 1) {
            SetBit((u8 *)p->unk1AC[2], id);
        } else {
            SetBit((u8 *)p->unk1AC[0], id);
        }
    } else if (sel == 1) {
        if (alt == 1) {
            SetBit((u8 *)p->unk1AC[3], id);
        } else {
            SetBit((u8 *)p->unk1AC[1], id);
        }
    } else {
        if (alt == 1) {
            SetBit((u8 *)p->unk1AC[2], id);
        } else {
            SetBit((u8 *)p->unk1AC[0], id);
        }
    }
}

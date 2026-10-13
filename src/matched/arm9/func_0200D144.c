/*
 * function: ZUKAN_SAVE_HasSeenGenderForm
 * address:  0x0200D144
 * packet:   pkt_0200D144
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The five-way reader over the bitmaps ZUKAN_SAVE_SetSeenGenderFlag/ZUKAN_SAVE_SetSeenFormFlag write
 * (decode in docs/notes/pkt_0200D144.c.txt).  EXACT* only because the
 * 16-byte leaf that follows it, ZUKAN_SAVE_GetSpindaPersonality, has no label; that leaf is
 * filed as its own witness, src/matched/ZUKAN_SAVE_GetSpindaPersonality.c.
 *
 * Closed in wave 13: the two-row tests of the last two arms go through the
 * species-bit helper `TestSpecies(row, id)` (it forms `u16 x = id - 1`
 * itself, as in ZUKAN_SAVE_GetViewGenderAndForm and ZUKAN_SAVE_IsSeen), joined by `||`.  Each
 * inlined copy has its own `x`, so the image's second `adds r0, r5, r1`
 * (p + off formed again for the +0xB0 row) comes out, which no open-coded
 * spelling reached (it was 2 bytes short or 2 long, never right).  The
 * single-row arms keep the open-coded `r = 1; if (!bit) r = 0; return r;`
 * shape that gives their shared `bne` tail.
 *
 * symbols:
 *   ZUKAN_SAVE_IsInvalidSpecies  0x0200C720  thumb
 *   ZUKAN_SAVE_GetFormBitBase  0x0200C7C0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 ZUKAN_SAVE_IsInvalidSpecies(u32 id);
extern u32 ZUKAN_SAVE_GetFormBitBase(u16 id);

static inline u32 TestSpecies(const u8 *row, u32 id)
{
    u16 x = id - 1;
    return row[x >> 3] & (1 << (x & 7));
}

u32 ZUKAN_SAVE_HasSeenGenderForm(u8 *p, u16 id, u32 sel, u32 alt, u32 form)
{
    u32 res;
    s32 x;
    u32 m;
    u32 r;

    if (ZUKAN_SAVE_IsInvalidSpecies(id) != 0) {
        return (u32)-1;
    }
    res = ZUKAN_SAVE_GetFormBitBase(id);
    if (res != (u32)-1) {
        x = (u16)(res + form);
        m = 1 << (x & 7);
        r = 1;
        if (((p + alt * 9 + (x >> 3))[0x2FC] & m) == 0) {
            r = 0;
        }
        return r;
    }
    if (sel == 0) {
        if (alt == 1) {
            x = (u16)(id - 1);
            m = 1 << (x & 7);
            r = 1;
            if (((p + (x >> 3))[0x104] & m) == 0) {
                r = 0;
            }
            return r;
        }
        x = (u16)(id - 1);
        m = 1 << (x & 7);
        r = 1;
        if (((p + (x >> 3))[0x5C] & m) == 0) {
            r = 0;
        }
        return r;
    }
    if (sel == 1) {
        if (alt == 1) {
            x = (u16)(id - 1);
            m = 1 << (x & 7);
            r = 1;
            if (((p + (x >> 3))[0x158] & m) == 0) {
                r = 0;
            }
            return r;
        }
        x = (u16)(id - 1);
        m = 1 << (x & 7);
        r = 1;
        if (((p + (x >> 3))[0xB0] & m) == 0) {
            r = 0;
        }
        return r;
    }
    if (alt == 1) {
        if (TestSpecies(p + 0x104, id) || TestSpecies(p + 0x158, id)) {
            goto oneA;
        }
        goto zero;
oneA:
        return 1;
    }
    if (TestSpecies(p + 0x5C, id) || TestSpecies(p + 0xB0, id)) {
        goto oneB;
    }
    goto zero;
oneB:
    return 1;
zero:
    return 0;
}



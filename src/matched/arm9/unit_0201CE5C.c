/*
 * unit:     yes
 * address:  0x0201CE5C
 * packet:   pkt_0201CE5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PRINTSYS_PrintStreamShortWait, PRINTSYS_PrintStreamSetSpeed, PRINTSYS_PrintStreamResetSpeed, PRINTSYS_PrintStreamIsOverrideSpeed
 *
 * Four more operations on the object src/matched/unit_0201CDF4.c works on,
 * continuing its run of single-bit edits of the flag byte at +0x22: this
 * range sets bit 4 and bit 3, clears bit 3, and reads bit 3 back.
 *
 * PRINTSYS_PrintStreamShortWait lowers a level-like byte at +0x1E and, when the new value is
 * zero, replaces the pair at +0x1C/+0x1D through PRINTSYS_PrintStreamSetSpeed with whatever
 * MSG_SPEED_GetWaitForSpeed(2) returns.  PRINTSYS_PrintStreamResetSpeed is the undo: it clears the bit and
 * restores the pair from the backup at +0x18/+0x19.
 *
 * PRINTSYS_PrintStreamIsOverrideSpeed is an unlabelled follower, eight bytes with no prologue.  It
 * reads bit 3 as a `lsls #0x1C` / `lsrs #0x1F` pair, which is the bitfield
 * extraction shape of
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md rather than
 * the `lsrs #3` / `ands #1` a shift and mask would give.
 *
 * The bit read has to be cast to u32 before the shift pair: on the promoted
 * `int` the right shift is an `asrs` and the one byte is wrong.
 *
 * Every one of the four reaches the flag byte through two independent
 * `((u8 *)p)[0x22]` expressions, the same spelling unit_0201CDF4.c needs, so
 * the load address and the store address are computed separately.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CE5C.c \
 *       --addr 0x0201CE5C --thumb
 *
 * symbols:
 *   PRINTSYS_SplitWait  0x0201CDF4  thumb
 *   MSG_SPEED_GetWaitForSpeed  0x02013080  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef int           s32;

struct Rec {
    u8 pad00[0x18];
    u8 unk18;
    u8 unk19;
    u8 pad1A[2];
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 pad1F[3];
    u8 unk22;
};

extern signed char MSG_SPEED_GetWaitForSpeed(u32 idx);
extern void PRINTSYS_SplitWait(s32 v, u8 *out);

void PRINTSYS_PrintStreamSetSpeed(struct Rec *p, s32 v);

void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v)
{
    if (v < p->unk1E) {
        p->unk1E = (u8)v;
        if (v == 0) {
            PRINTSYS_PrintStreamSetSpeed(p, MSG_SPEED_GetWaitForSpeed(2));
            ((u8 *)p)[0x22] = 0x10u | ((u8 *)p)[0x22];
        }
    }
}

void PRINTSYS_PrintStreamSetSpeed(struct Rec *p, s32 v)
{
    u8 tmp[2];

    PRINTSYS_SplitWait(v, tmp);
    p->unk1D = tmp[1];
    p->unk1C = tmp[0];
    ((u8 *)p)[0x22] = 8u | ((u8 *)p)[0x22];
}

void PRINTSYS_PrintStreamResetSpeed(struct Rec *p)
{
    ((u8 *)p)[0x22] = ((u8 *)p)[0x22] & ~8u;
    p->unk1D = p->unk19;
    p->unk1C = p->unk18;
}

u32 PRINTSYS_PrintStreamIsOverrideSpeed(struct Rec *p)
{
    return ((u32)((u8 *)p)[0x22] << 28) >> 31;
}

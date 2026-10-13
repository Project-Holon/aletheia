/*
 * function: BSUBWAY_SCR_DrawTrainerNo
 * address:  0x021CBD90
 * packet:   pkt_ov021_021CBD90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks a battle-subway trainer id: the fixed boss ids on the boss round, otherwise a random id from the per-round range table of the line (normal or super, early or late stages).
 *
 * Each table arm calls the random-range helper with the table address cast to
 * an integer. A shared `const Range *tbl` local is a named variable and takes
 * the first callee-saved register (r4) ahead of the scaled index and the span;
 * per-arm calls leave the base as a short-lived load that colours after them
 * (r6, with round*4 in r4 and span in r5), and the arms' identical tails are
 * cross-jumped into one block. The integer base keeps `tbl + off` then `+2`
 * for hi instead of folding the field offset into a second pool word
 * (d_X + 2), and loads the base before the index shift. 0x0209C0A4 is
 * _s32_div_f, so the u16 % u16 modulo is signed (int promotion).
 *
 * symbols:
 *   func_021CBF98  0x021CBF98  thumb  ov021
 *   _s32_div_f  0x0209C0A4  arm
 *   d_021DB3D0  0x021DB3D0  data
 *   d_021DB3D8  0x021DB3D8  data
 *   d_021DB3E4  0x021DB3E4  data
 *   d_021DB3F4  0x021DB3F4  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 lo;
    u16 hi;
} Range;

extern u16 func_021CBF98(void *ctx);
extern const Range d_021DB3D0[];
extern const Range d_021DB3D8[];
extern const Range d_021DB3E4[];
extern const Range d_021DB3F4[];

static inline u16 RandInRange(void *ctx, u32 tbl, u32 round)
{
    u16 span = ((const Range *)(tbl + round * 4))->hi - ((const Range *)(tbl + round * 4))->lo + 1;
    return func_021CBF98(ctx) % span + ((const Range *)(tbl + round * 4))->lo;
}

u16 BSUBWAY_SCR_DrawTrainerNo(void *ctx, u32 round, u32 stage, u32 line, u8 alt)
{
    int super;
    int boss;
    u16 id;

    id = 0;
    super = 0;
    boss = -1;

    switch (line) {
    case 5:
    case 6:
    case 7:
    case 8:
        super = 1;
        break;
    }

    if (stage == 6) {
        if (!super) {
            if (round == 2)
                boss = 0;
        } else {
            if (round == 6)
                boss = 1;
        }
    }

    if (boss != -1) {
        switch (line) {
        case 0:
        case 5:
            if (boss == 0)
                id = 0x132;
            else if (boss == 1)
                id = 0x133;
            break;
        case 1:
        case 6:
            if (boss == 0)
                id = 0x134;
            else if (boss == 1)
                id = 0x135;
            break;
        case 2:
        case 3:
        case 7:
        case 8:
            if (boss == 0) {
                if (alt == 0)
                    id = 0x137;
                else
                    id = 0x136;
            } else if (boss == 1) {
                if (alt == 0)
                    id = 0x139;
                else
                    id = 0x138;
            }
            break;
        }
    } else if (!super) {
        if (round >= 3)
            goto end;
        if (stage < 6) {
            id = RandInRange(ctx, (u32)d_021DB3D8, round);
            goto end;
        }
        if (round >= 2)
            goto end;
        id = RandInRange(ctx, (u32)d_021DB3D0, round);
    } else {
        if (round >= 4)
            goto rnd;
        if (stage < 6) {
            id = RandInRange(ctx, (u32)d_021DB3E4, round);
            goto end;
        }
        id = RandInRange(ctx, (u32)d_021DB3F4, round);
        goto end;
rnd:
        id = func_021CBF98(ctx) % 100 + 200;
    }
end:
    return id;
}

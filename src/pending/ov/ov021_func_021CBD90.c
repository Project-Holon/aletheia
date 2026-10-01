/*
 * function: func_021CBD90
 * address:  0x021CBD90
 * packet:   pkt_ov021_021CBD90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Picks a battle-subway trainer id: the fixed boss ids on the boss round, otherwise a random id from the per-round range table of the line (normal or super, early or late stages).
 *
 * 2026-10-01: 103 bytes out. Control flow, prologue order and the id/super/boss
 * colours (r3/r1/r2) are right. Left: the image keeps tbl in r6 (stage's register,
 * dead by then), round*4 in r4 and span in r5; here tbl takes r4, so the super
 * branch's stage<6 choice is if-converted into a preload of tbl (ldr C; cmp; blo;
 * ldr D) instead of the image's two-arm form, and every later branch shifts by
 * two bytes. Declaration order, block scoping of tbl/span, a ternary and an
 * inline span expression do not move tbl off r4.
 *
 * symbols:
 *   func_021CBF98  0x021CBF98  thumb  ov021
 *   _u32_div_f  0x0209C0A4  arm
 *   d_021DB3D0  0x021DB3D0  data  ov021
 *   d_021DB3D8  0x021DB3D8  data  ov021
 *   d_021DB3E4  0x021DB3E4  data  ov021
 *   d_021DB3F4  0x021DB3F4  data  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 lo;
    u16 hi;
} Range;

extern u32 func_021CBF98(void *ctx);
extern const Range d_021DB3D0[];
extern const Range d_021DB3D8[];
extern const Range d_021DB3E4[];
extern const Range d_021DB3F4[];

u16 func_021CBD90(void *ctx, u32 round, u32 stage, u32 line, u8 alt)
{
    int super;
    int boss;
    u16 id;
    const Range *tbl;
    u16 span;

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
    } else {
        if (!super) {
            if (round >= 3)
                goto end;
            if (stage < 6) {
                tbl = d_021DB3D8;
            } else {
                if (round >= 2)
                    goto end;
                tbl = d_021DB3D0;
            }
        } else {
            if (round >= 4)
                goto rnd;
            if (stage < 6)
                tbl = d_021DB3E4;
            else
                tbl = d_021DB3F4;
        }
        span = tbl[round].hi - tbl[round].lo + 1;
        id = func_021CBF98(ctx) % span + tbl[round].lo;
        goto end;
rnd:
        id = func_021CBF98(ctx) % 100 + 200;
    }
end:
    return id;
}

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
 * 2026-10-01 (lane A2-18): also inert: tbl += round then tbl->lo/hi, a
 * u16 table with [round*2] indexing, the (u16) span cast inline, lo + rand %
 * span order, `if (stage >= 6)` arm order, tbl initialised to 0, a local
 * copy of stage. The image colours round*4 and span before tbl, so tbl takes
 * stage's freed r6; no source shape tried changes that colouring order.
 * 2026-10-02 (share-A relaunch): fixed the arithmetic types. 0x0209C0A4 is
 * _s32_div_f (see src/matched/arm9/func_0200E27C.c), so the modulo is signed:
 * func_021CBF98 returns u16 (its matched file) and u16 % u16 promotes to int.
 * Same bytes, but the source now says what the image does. The tbl colour is
 * unchanged. Every variant keeps the instruction stream and gives tbl r4,
 * round*4 r5, span r6. Inert: arms as gotos to calc, nested `if (round < N)`
 * arms, else-if/else rnd structures (no if-conversion but still r4), do/while(0)
 * with breaks, returns instead of goto end, the random part as a static inline
 * (with gotos or returns), split per-branch tbl/span locals with calc copies
 * (cross-jumped back into one), span as u32/int with the cast at the def,
 * hi/lo in six expression orders, a named rand() result (u16/u32/int), u32/u8 *
 * tbl with byte offsets, a named off local (single and double assigned), dead
 * initialisers for span/off, `register`, self-assignments of tbl/stage/round/
 * span/line/ctx at five points, dead reads `if (x) {}`, a copy of tbl/round/ctx at
 * calc, the tables as file statics, function statics, one struct or one array
 * with offsets, narrow param types, super/boss/id types, and all dsi versions
 * 1.1 to 1.3 (same code). Moves tbl but breaks other bytes: reusing stage as the
 * table cursor (the whole variable then takes r4, line drops to r3), a use of
 * span after the division (round*4 r4, tbl r5, span r6), a redundant second
 * stage test. Closest shape: `tbl = &tbl_X[round]` in each arm with tbl->hi/lo
 * at calc is 328 bytes with every branch exact (9 bytes out). There the arms load
 * the base into r1 and calc keeps the row pointer base+off in r4. The image keeps
 * the base (r6) and round*4 (r4) apart, which is the tbl[round] form.
 *
 * symbols:
 *   func_021CBF98  0x021CBF98  thumb  ov021
 *   _s32_div_f  0x0209C0A4  arm
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

extern u16 func_021CBF98(void *ctx);
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

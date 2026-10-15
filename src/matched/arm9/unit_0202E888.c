/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202E888
 * packet:   pkt_0202E770
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: COMM_PLAYER_SUPPORT_GetSeasonFromClock, COMM_PLAYER_SUPPORT_NextSeason, COMM_PLAYER_SUPPORT_PrevSeason, COMM_PLAYER_SUPPORT_SetSeason
 *
 * symbols:
 *   GF_STANDARD_SetField00_F4E4  0x0203F4E4  arm
 *   GAME_DATA_SetSeason  0x0201298C  thumb
 *
 * Four small date helpers. COMM_PLAYER_SUPPORT_GetSeasonFromClock asks the ARM clock getter for a
 * 0x10-byte record and reduces its second word to a two-bit value;
 * COMM_PLAYER_SUPPORT_NextSeason and COMM_PLAYER_SUPPORT_PrevSeason step that value forwards and backwards
 * around the same four-element cycle.
 *
 * The `lsrs #0x1F` / `lsls #0x1E` / `subs` / `rors #0x1E` quartet in the
 * two steppers is a signed `% 4` and nothing else: `& 3` is a two
 * instruction `movs`/`ands`, which is exactly what COMM_PLAYER_SUPPORT_GetSeasonFromClock uses at
 * the top, and `/ 4` carries a different rounding correction. Both
 * spellings appear four instructions apart in the same 80 bytes, so the
 * pair of them pins the signedness of each operand independently.
 *
 * The `lsls #0x18` / `lsrs #0x18` at the end of all three is the `(u8)`
 * return type.
 *
 * COMM_PLAYER_SUPPORT_SetSeason is a twelve byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) that narrows its
 * second argument to `u8` on the way through. It nearly cost the file a
 * cut: the pool word at 0x0202E8D4 is the only occurrence of 0x0201298D
 * anywhere in the image, 0x0201298C carries no `func_` label, and the
 * pool word is inside this range, so the `literal` class has nothing and
 * no cut can reach further since the range cannot be smaller than that
 * one function. The `matched` class covers it instead: 0x0201298C is
 * already an EXACT manifest entry from earlier work, and that witness is
 * a compilation rather than a byte of this range.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202E888.c \
 *       --addr 0x0202E888 --thumb
 */

typedef unsigned char u8;
typedef signed int    s32;

struct Date0202E888 {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
};

struct RtcDate;
extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);
extern u8 GAME_DATA_SetSeason(s32 a, u8 b);

u8 COMM_PLAYER_SUPPORT_GetSeasonFromClock(void)
{
    struct Date0202E888 d;

    GF_STANDARD_SetField00_F4E4((struct RtcDate *)(&d));
    return (u8)((d.unk04 - 1) & 3);
}

u8 COMM_PLAYER_SUPPORT_NextSeason(u8 x)
{
    return (u8)((x + 1) % 4);
}

u8 COMM_PLAYER_SUPPORT_PrevSeason(s32 x)
{
    return (u8)((x + 3) % 4);
}

u8 COMM_PLAYER_SUPPORT_SetSeason(s32 a, s32 b)
{
    return GAME_DATA_SetSeason(a, (u8)b);
}

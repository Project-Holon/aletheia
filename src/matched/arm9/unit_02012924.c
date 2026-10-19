/*
 * unit:     yes
 * address:  0x02012924
 * packet:   pkt_02012924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GAME_DATA_GetMapMatrix, GAME_DATA_GetMyItem, GAME_DATA_GetMyParty, GAME_DATA_GetBoxManager,
 *           GAME_DATA_GetMyStatus, GAME_DATA_GetMyStatusPlayer, GAME_DATA_GetBagCursor, GAME_DATA_GetOccupyInfo,
 *           GAME_DATA_GetEventWork, GAME_DATA_GetFieldWork, GAME_DATA_GetMusicalWork, GAME_DATA_GetSeason,
 *           GAME_DATA_SetSeason, GAME_DATA_GetWeatherId, GAME_DATA_SetWeatherId, GAME_DATA_GetSubscreenType,
 *           GAME_DATA_SetSubscreenType, GAME_DATA_GetFieldMenuCursor, GAME_DATA_SetFieldMenuCursor, GAME_DATA_SetWalkCountEnabled,
 *           GAME_DATA_ResetWalkCount, GAME_DATA_IncWalkCount, GAME_DATA_IsWalkCountEnabled, GAME_DATA_GetBgmInfo,
 *           GAME_DATA_GetFieldGimmick, GAME_DATA_GetLastBattleResult, GAME_DATA_SetLastBattleResult, GAME_DATA_GetItemUseWork,
 *           GAME_DATA_InitPlayerWork, GAME_DATA_SetPlayerPosition, GAME_DATA_GetPlayerPosition, GAME_DATA_SetPlayerRail,
 *           GAME_DATA_GetPlayerRail, GAME_DATA_SetPlayerMoveForm, GAME_DATA_GetPlayerMoveForm, GAME_DATA_SetPlayerZoneId,
 *           GAME_DATA_GetPlayerZoneId, GAME_DATA_SetPlayerDirection, GAME_DATA_GetPlayerDirection
 *
 * symbols:
 *   GAME_DATA_GetMyPlayerWork         0x020127A4  thumb
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record GAME_DATA_GetMyStatusPlayer indexes, and GAME_DATA_InitPlayerWork
 *    onwards are its constructor and accessors.  GAME_DATA_InitPlayerWork is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    GAME_DATA_SetPlayerRail copies whole) and a five-field view.
 *
 * GAME_DATA_IncWalkCount is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because GAME_DATA_SetPlayerDirectionType cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 *GAME_DATA_GetMyPlayerWork(void *p);

struct Vec12 {
    u32 x;
    u32 y;
    u32 z;
};

struct H4 {
    u16 v[4];
};

union U10 {
    struct H4 all;
    struct {
        u16 a;
        u8  b;
        u8  c;
        u16 d;
        u16 e;
    } f;
};

struct Rec44 {
    u16 unk00;
    u16 unk02;
    struct Vec12 unk04;
    union U10 unk10;
    u16 unk18;
    u8  unk1A;
    u8  unk1B;
    u16 unk1C;
    u8  unk1E[0x12];
    u32 unk30;
    u8  unk34[6];
    u8  unk3A;
    u8  unk3B;
    u8  unk3C;
    u8  unk3D;
    u8  unk3E[2];
    u32 unk40;
};

struct Sub24 {
    u8 unk00[0x24];
    struct Rec44 unk24[8];
};

struct BigObj {
    u8  unk000[0x18C];
    u32 unk18C;
    void *unk190;
    void *unk194;
    u32 unk198;
    u32 unk19C;
    u32 unk1A0;
    u32 unk1A4;
    u32 unk1A8;
    u32 unk1AC;
    u32 unk1B0;
    u32 unk1B4;
    u32 unk1B8;
    u32 unk1BC;
    u8  unk1C0[4];
    u8  unk1C4;
    u8  unk1C5;
    u8  unk1C6;
    u8  unk1C7;
    u8  unk1C8;
    u8  unk1C9;
    u8  unk1CA;
    u8  unk1CB;
    u8  unk1CC;
    u8  unk1CD;
    u8  unk1CE;
    u8  unk1CF;
    u8  unk1D0[0x414];
    u32 unk5E4;
    u8  unk5E8[0xA4];
    u32 unk68C;
    u32 unk690;
};

u32 GAME_DATA_GetMapMatrix(const struct BigObj *p)
{
    return p->unk18C;
}

void *GAME_DATA_GetMyItem(const struct BigObj *p)
{
    return p->unk190;
}

void *GAME_DATA_GetMyParty(const struct BigObj *p)
{
    return p->unk194;
}

u32 GAME_DATA_GetBoxManager(const struct BigObj *p)
{
    return p->unk19C;
}

u8 *GAME_DATA_GetMyStatus(void *p)
{
    return GAME_DATA_GetMyPlayerWork(p) + 0x20;
}

struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i)
{
    return &p->unk24[i];
}

u32 GAME_DATA_GetBagCursor(const struct BigObj *p)
{
    return p->unk1A4;
}

u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p)
{
    return p->unk1A8;
}

u32 GAME_DATA_GetEventWork(const struct BigObj *p)
{
    return p->unk1AC;
}

u32 GAME_DATA_GetFieldWork(const struct BigObj *p)
{
    return p->unk1B0;
}

u32 GAME_DATA_GetMusicalWork(const struct BigObj *p)
{
    return p->unk690;
}

u8 GAME_DATA_GetSeason(const struct BigObj *p)
{
    return p->unk1C4;
}

void GAME_DATA_SetSeason(struct BigObj *p, u8 v)
{
    p->unk1C4 = v;
}

u8 GAME_DATA_GetWeatherId(const struct BigObj *p)
{
    return p->unk1C5;
}

void GAME_DATA_SetWeatherId(struct BigObj *p, u8 v)
{
    p->unk1C5 = v;
}

u8 GAME_DATA_GetSubscreenType(const struct BigObj *p)
{
    return p->unk1C6;
}

void GAME_DATA_SetSubscreenType(struct BigObj *p, u32 v)
{
    p->unk1C6 = v;
}

u8 GAME_DATA_GetFieldMenuCursor(const struct BigObj *p)
{
    return p->unk1C7;
}

void GAME_DATA_SetFieldMenuCursor(struct BigObj *p, u8 v)
{
    p->unk1C7 = v;
}

void GAME_DATA_SetWalkCountEnabled(struct BigObj *p, u8 v)
{
    p->unk1C9 = v;
    if (v != 0) {
        p->unk1C8 = 0;
    }
}

void GAME_DATA_ResetWalkCount(struct BigObj *p)
{
    p->unk1C8 = 0;
}

u8 GAME_DATA_IncWalkCount(struct BigObj *p)
{
    if (p->unk1C9 != 0) {
        return p->unk1C8++;
    }
    return 0;
}

u8 GAME_DATA_IsWalkCountEnabled(const struct BigObj *p)
{
    return p->unk1C9;
}

u32 GAME_DATA_GetBgmInfo(const struct BigObj *p)
{
    return p->unk1B4;
}

u32 GAME_DATA_GetFieldGimmick(const struct BigObj *p)
{
    return p->unk5E4;
}

u32 GAME_DATA_GetLastBattleResult(const struct BigObj *p)
{
    return p->unk1BC;
}

void GAME_DATA_SetLastBattleResult(struct BigObj *p, u32 v)
{
    p->unk1BC = v;
}

u32 GAME_DATA_GetItemUseWork(const struct BigObj *p)
{
    return p->unk68C;
}

void GAME_DATA_InitPlayerWork(struct Rec44 *p)
{
    p->unk3D = 0;
    p->unk3A = 0;
    p->unk00 = 0;
    p->unk04.x = 0;
    p->unk04.y = 0;
    p->unk04.z = 0;
    p->unk18 = 0;
    p->unk1B = 0;
    p->unk30 = 0;
    p->unk10.f.b = 0;
    p->unk10.f.c = 0;
    p->unk10.f.a = 0;
    p->unk10.f.e = 0;
    p->unk10.f.d = 0;
    p->unk1C = 0xFFFF;
}

void GAME_DATA_SetPlayerPosition(struct Rec44 *p, const struct Vec12 *src)
{
    p->unk04 = *src;
}

struct Vec12 *GAME_DATA_GetPlayerPosition(struct Rec44 *p)
{
    return &p->unk04;
}

void GAME_DATA_SetPlayerRail(struct Rec44 *p, const struct H4 *src)
{
    p->unk10.all = *src;
}

struct H4 *GAME_DATA_GetPlayerRail(struct Rec44 *p)
{
    return &p->unk10.all;
}

void GAME_DATA_SetPlayerMoveForm(struct Rec44 *p, u8 v)
{
    p->unk1B = v;
}

u8 GAME_DATA_GetPlayerMoveForm(const struct Rec44 *p)
{
    return p->unk1B;
}

struct Rec44 *GAME_DATA_SetPlayerZoneId(struct Rec44 *p, u16 v)
{
    p->unk00 = v;
    return p;
}

u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p)
{
    return p->unk00;
}

void GAME_DATA_SetPlayerDirection(struct Rec44 *p, int v)
{
    p->unk18 = v;
}

u16 GAME_DATA_GetPlayerDirection(const struct Rec44 *p)
{
    return p->unk18;
}

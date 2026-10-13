/*
 * unit:     yes
 * address:  0x020120F0
 * packet:   pkt_02011EC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GAMESYSTEM_GetProcStatus, GAMESYSTEM_GetGameData, GAMESYSTEM_GetMyPlayerWork, GAMESYSTEM_GetEvent,
 *           GAMESYSTEM_SetEvent, GAMESYSTEM_GetFieldMap, GAMESYSTEM_SetFieldMap, GAMESYSTEM_IsFieldMapExist,
 *           GAMESYSTEM_SetFieldMapState, GAMESYSTEM_GetFieldMapState, GAMESYSTEM_GetIssSystem, GAMESYSTEM_GetGameComm,
 *           GAMESYSTEM_SetCommBlocked, GAMESYSTEM_IsCommBlocked, GAMESYSTEM_GetAlwaysNetFlag
 *
 * symbols:
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_IsConfigFlagSet  0x02012BB0  thumb
 *
 * 104 bytes, 0x020120F0..0x02012158, 15 functions, none of which carries a
 * label: every one of them is a two- or three-instruction accessor on a
 * 0x34-byte context record, and the whole run arrives in the listing as .word
 * data between two literal pools.
 *
 * The size of the record is not a guess: GAMESYSTEM_GetWorkSize is
 * `movs r0, #0x34; bx lr`, its sizeof getter, and it is matched in
 * src/matched/unit_02011F24.c against the same declaration.  The two byte
 * fields at +0x30 and +0x32 cost an `adds r0, #0x30` each because the Thumb
 * `strb` immediate only reaches +31, which is
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md and not a pointer in the
 * source.
 *
 * GAMESYSTEM_GetMyPlayerWork and GAMESYSTEM_GetAlwaysNetFlag are tail calls through pool words: the
 * first hands +0x1C to GAME_DATA_GetMyPlayerWork and the second to GAME_DATA_IsConfigFlagSet, and
 * both are ABS32 against a Thumb target, so the pool word is odd.
 *
 * 0x02012158, 12 bytes, is a third tail call of the same shape and is a near
 * miss.  Its pool word holds 0x02012BC9, and GAME_DATA_SetConfigFlag has no label in the
 * listing (it has no register-saving prologue) and no other reference anywhere
 * in the image, so neither the `label` nor the `literal` class has a witness
 * outside the twelve bytes under test.  Every concrete byte reproduces from
 *
 *     void GAMESYSTEM_SetAlwaysNetFlag(const struct Ctx *p, u32 v)
 *     {
 *         GAME_DATA_SetConfigFlag(p->unk1C, v);
 *     }
 *
 * Evidence class: literal, 0 witnesses outside.  It closes with the same event
 * that closes 0x02012BC8 itself; see src/matched/unit_02012AE4.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020120F0.c \
 *       --addr 0x020120F0 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
struct SaveBlock;
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u32 GAME_DATA_IsConfigFlagSet(const struct BigObj *p);

struct Ctx {
    u8    unk00[0xC];
    u32   unk0C;
    u8    unk10[8];
    u32   unk18;
    void *unk1C;
    void *unk20;
    u32   unk24;
    u32   unk28;
    u32   unk2C;
    u8    unk30;
    u8    unk31;
    u8    unk32;
    u8    unk33;
};

u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p)
{
    return p->unk0C;
}

void *GAMESYSTEM_GetGameData(const struct Ctx *p)
{
    return p->unk1C;
}

u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p)
{
    return GAME_DATA_GetMyPlayerWork(p->unk1C);
}

u32 GAMESYSTEM_GetEvent(const struct Ctx *p)
{
    return p->unk18;
}

void GAMESYSTEM_SetEvent(struct Ctx *p, u32 v)
{
    p->unk18 = v;
}

void *GAMESYSTEM_GetFieldMap(const struct Ctx *p)
{
    return p->unk20;
}

void GAMESYSTEM_SetFieldMap(struct Ctx *p, void *v)
{
    p->unk20 = v;
}

u32 GAMESYSTEM_IsFieldMapExist(const struct Ctx *p)
{
    if (p->unk20 != 0) {
        return 1;
    }
    return 0;
}

void GAMESYSTEM_SetFieldMapState(struct Ctx *p, u32 v)
{
    p->unk30 = v;
}

u8 GAMESYSTEM_GetFieldMapState(const struct Ctx *p)
{
    return p->unk30;
}

u32 GAMESYSTEM_GetIssSystem(const struct Ctx *p)
{
    return p->unk2C;
}

u32 GAMESYSTEM_GetGameComm(const struct Ctx *p)
{
    return p->unk24;
}

void GAMESYSTEM_SetCommBlocked(struct Ctx *p, u32 v)
{
    p->unk32 = v;
}

u8 GAMESYSTEM_IsCommBlocked(const struct Ctx *p)
{
    return p->unk32;
}

u32 GAMESYSTEM_GetAlwaysNetFlag(const struct Ctx *p)
{
    return GAME_DATA_IsConfigFlagSet(p->unk1C);
}

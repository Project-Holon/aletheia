/*
 * unit:     yes
 * address:  0x0201283C
 * packet:   pkt_020122B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GAME_DATA_GetWifiList, GAME_DATA_GetEventData, GAME_DATA_GetStartLocation, GAME_DATA_SetStartLocation,
 *           GAME_DATA_GetEntranceLocation, GAME_DATA_SetEntranceLocation, GAME_DATA_GetSpecialLocation, GAME_DATA_SetSpecialLocation,
 *           GAME_DATA_GetEscapeLocation, GAME_DATA_SetEscapeLocation, GAME_DATA_GetWarpLocation, GAME_DATA_SetWarpLocation,
 *           GAME_DATA_SetWarpId
 *
 * symbols:
 *   func_02008850  0x02008850  thumb
 *
 * 214 bytes, 0x0201283C..0x02012914, 13 functions, five of them labelled.  It
 * abuts src/matched/unit_02012924.c at the far end, across the one function
 * the cut below moved out.
 *
 * Four pointer fields at +0x160, +0x164, +0x168 and +0x16C and one inline
 * record at +0x170 all hold the same 28-byte thing, and each has a getter and
 * a setter.  28 bytes is three `ldm`/`stm` pairs plus a trailing `ldr`/`str`,
 * which is docs/idioms/aggregate-assignment-is-ldm-stm.md; the record has to
 * be declared four-aligned (u32 v[7], not u8 v[28]) or the copy becomes a
 * byte loop.  The four pointer setters write through the pointer
 * (`*p->unk160 = *src`) and the fifth writes the inline record
 * (`p->unk170 = *src`), which is the difference between the `ldr r2, [r0, r1]`
 * and the `adds r2, r0, r1` that opens each.
 *
 * The file is cut at 0x02012914 rather than at 0x02012924, which is where the
 * next file starts, because GAME_DATA_SetWarpId and GAME_DATA_GetSituationWarpId are the only two
 * callers of func_02008850 in the image: one range holding both leaves the
 * `label` class no witness and the whole unit reads MATCH with every concrete
 * byte right.  Split, each is the other's outside witness and both are EXACT.
 * That is docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md, and
 * the other half is src/matched/unit_02012914.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201283C.c \
 *       --addr 0x0201283C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_02008850(void *p);

struct Rec1C {
    u32 v[7];
};

struct BigObj {
    u8  unk000[0x158];
    u32 unk158;
    u32 unk15C;
    struct Rec1C *unk160;
    struct Rec1C *unk164;
    struct Rec1C *unk168;
    struct Rec1C *unk16C;
    struct Rec1C unk170;
    u8  unk18C[0x14];
    u32 unk1A0;
};

u32 GAME_DATA_GetWifiList(const struct BigObj *p)
{
    return p->unk1A0;
}

u32 GAME_DATA_GetEventData(const struct BigObj *p)
{
    return p->unk158;
}

struct Rec1C *GAME_DATA_GetStartLocation(const struct BigObj *p)
{
    return p->unk160;
}

void GAME_DATA_SetStartLocation(struct BigObj *p, const struct Rec1C *src)
{
    *p->unk160 = *src;
}

struct Rec1C *GAME_DATA_GetEntranceLocation(const struct BigObj *p)
{
    return p->unk164;
}

void GAME_DATA_SetEntranceLocation(struct BigObj *p, const struct Rec1C *src)
{
    *p->unk164 = *src;
}

struct Rec1C *GAME_DATA_GetSpecialLocation(const struct BigObj *p)
{
    return p->unk168;
}

void GAME_DATA_SetSpecialLocation(struct BigObj *p, const struct Rec1C *src)
{
    *p->unk168 = *src;
}

struct Rec1C *GAME_DATA_GetEscapeLocation(const struct BigObj *p)
{
    return p->unk16C;
}

void GAME_DATA_SetEscapeLocation(struct BigObj *p, const struct Rec1C *src)
{
    *p->unk16C = *src;
}

struct Rec1C *GAME_DATA_GetWarpLocation(struct BigObj *p)
{
    return &p->unk170;
}

void GAME_DATA_SetWarpLocation(struct BigObj *p, const struct Rec1C *src)
{
    p->unk170 = *src;
}

void GAME_DATA_SetWarpId(const struct BigObj *p, u16 v)
{
    *func_02008850((void *)p->unk15C) = v;
}

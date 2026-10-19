/*
 * unit:     yes
 * address:  0x02019B58
 * packet:   pkt_02019B58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_SetDefaultName, POKE_TOOL_SetNameFromSpecies, POKE_TOOL_LoadExpTable, POKE_TOOL_GetExpValue,
 *           POKE_TOOL_GetPlateType
 *
 * The first five of the seven functions between POKE_TOOL_IsDefaultName and the cache
 * helper at 0x02019C54.  The range stops at 0x02019C38 on purpose: the two
 * functions after it, POKE_TOOL_GetBoxSubstruct and POKE_TOOL_GetPersonalData, each reach a data
 * object through a pool word that is the object's only reference in the whole
 * image (0x0209E3A4 at 0x02019C50 and 0x02146274 at 0x02019C78), so the
 * `literal` class has no outside witness for either and both cap at MATCH
 * however they are written.  Cutting in front of them leaves these five
 * clean.
 *
 * POKE_TOOL_SetDefaultName reaches POKE_TOOL_CastToBoxParam, which src/matched/unit_020185F0.c
 * proves is an empty `bx lr`, and then calls POKE_TOOL_SetNameFromSpecies with whatever r0
 * holds, with no register saved across the first call.  That only compiles
 * from a declaration in which POKE_TOOL_CastToBoxParam returns a value, so this unit
 * declares it `void *POKE_TOOL_CastToBoxParam(void)` and passes the result straight on;
 * declaring it `void` the way unit_020185F0.c does forces a callee-saved
 * register and a four byte longer prologue.  The two declarations disagree,
 * and the image cannot say which one the original header carried, because an
 * empty function's return value is unobservable.
 *
 * POKE_TOOL_LoadExpTable is docs/idioms/tail-call-is-a-pool-word-and-bx.md: it permutes
 * three arguments into an ARM callee at 0x02048F4C and has no prologue at all.
 *
 * POKE_TOOL_GetPlateType is the plate-to-type table of ids 0xAE and 0xAF of
 * POKE_TOOL_GetBoxValueRaw: sixteen consecutive item ids from 0x12A map to sixteen type
 * ids and everything else to 0.  The switch value arrives as a pool word
 * rather than a `subs` immediate only because 0x12A does not fit the eight bit
 * form, so it is an ordinary constant and not the linker symbol of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * VERSION SENSITIVITY: POKE_TOOL_GetPlateType's sixteen case labels are item ids and
 * its sixteen results are type ids, and POKE_TOOL_SetNameFromSpecies passes id 5 (species)
 * and id 0x74 (the name) of the record.  None of them is a version flag and
 * there is no exclusive-species table here, but the item ids 0x12A..0x139 are
 * content numbering and are the values to re-read first for a White build.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019B58.c \
 *       --addr 0x02019B58 --thumb
 *
 * symbols:
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   gSpeciesNameBank       0x020A7370  data
 *   gNameBuf       0x021462F0  data
 *   gExpTableBuf       0x02146398  data
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *POKE_TOOL_CastToBoxParam(void);
extern u32   POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern void  POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);
struct MsgData;
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern void  ARC_TOOL_ReadMember(void *a, u32 b, u32 c);

extern void *gSpeciesNameBank;
extern u16   gNameBuf[];
extern u32   gExpTableBuf[];

void POKE_TOOL_SetNameFromSpecies(void *p);
void POKE_TOOL_LoadExpTable(u32 a, void *b);

void POKE_TOOL_SetDefaultName(void *p)
{
    POKE_TOOL_SetNameFromSpecies(POKE_TOOL_CastToBoxParam());
}

void POKE_TOOL_SetNameFromSpecies(void *p)
{
    u32 s = POKE_TOOL_GetBoxValue(p, 5, 0);

    MSGDATA_ReadUnits(gSpeciesNameBank, s, gNameBuf, 0x20);
    POKE_TOOL_SetBoxValue(p, 0x74, (u32)gNameBuf);
}

void POKE_TOOL_LoadExpTable(u32 a, void *b)
{
    ARC_TOOL_ReadMember(b, 0x11, a);
}

u32 POKE_TOOL_GetExpValue(u32 a, u32 i)
{
    POKE_TOOL_LoadExpTable(a, gExpTableBuf);
    return gExpTableBuf[i];
}

u32 POKE_TOOL_GetPlateType(u32 item)
{
    switch (item) {
    case 0x12A: return 9;
    case 0x12B: return 10;
    case 0x12C: return 12;
    case 0x12D: return 11;
    case 0x12E: return 14;
    case 0x12F: return 1;
    case 0x130: return 3;
    case 0x131: return 4;
    case 0x132: return 2;
    case 0x133: return 13;
    case 0x134: return 6;
    case 0x135: return 5;
    case 0x136: return 7;
    case 0x137: return 15;
    case 0x138: return 16;
    case 0x139: return 8;
    }
    return 0;
}

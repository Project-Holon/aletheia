/*
 * function: FIELD_EVENT_CHECK_CheckStepEvents
 * address:  0x0218A9B0
 * packet:   pkt_ov021_0218A9B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field step handler: runs the step-triggered checks in order (FIELD_EVENT_CHECK_CheckStepEncount,
 * the 128-step counter, milestones, egg hatching, the save flag message) and
 * returns the first non-zero result. Flags come from the u32 bitfield at
 * 0x3C.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELD_EVENT_CHECK_CheckStepEncount  0x0218AC84  thumb
 *   FIELD_EVENT_CHECK_UpdateWalkFriendship  0x0218AB9C  thumb
 *   FIELD_EVENT_CHECK_CheckZoneStepMessage  0x0218AC08  thumb
 *   FIELD_EVENT_CHECK_CheckEggHatch  0x0218AB50  thumb
 *   FIELD_EVENT_CHECK_CheckMovePokemonCooldown  0x0218AC4C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ctx9B0 {
    char pad00[0x08];
    void *f8;
    char pad0C[0x04];
    u16 f10;
    char pad12[0x2A];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
};

extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int FIELD_EVENT_CHECK_CheckStepEncount(u8 *pos, void *msg, void *sys);
extern void FIELD_EVENT_CHECK_UpdateWalkFriendship(void *sys, u8 *pos);
extern int FIELD_EVENT_CHECK_CheckZoneStepMessage(void *msg, u8 *pos, u16 id);
extern int FIELD_EVENT_CHECK_CheckEggHatch(void *p, u8 *pos, void *msg, void *sys);
extern int FIELD_EVENT_CHECK_CheckMovePokemonCooldown(u8 *pos, void *msg, void *sys);

int FIELD_EVENT_CHECK_CheckStepEvents(struct Ctx9B0 *p, u8 *pos)
{
    void *msg;
    void *sys;
    int r;

    FIELDMAP_GetHeapId(pos);
    msg = FIELDMAP_GetGameSystem(pos);
    sys = GAMESYSTEM_GetGameData(msg);
    if (p->b2 || p->b9) {
        r = FIELD_EVENT_CHECK_CheckStepEncount(pos, msg, sys);
        if (r != 0)
            return r;
    }
    if (!p->b2)
        return 0;
    FIELD_EVENT_CHECK_UpdateWalkFriendship(p->f8, pos);
    r = FIELD_EVENT_CHECK_CheckZoneStepMessage(msg, pos, p->f10);
    if (r != 0)
        return r;
    r = FIELD_EVENT_CHECK_CheckEggHatch(p, pos, msg, sys);
    if (r != 0)
        return r;
    r = FIELD_EVENT_CHECK_CheckMovePokemonCooldown(pos, msg, sys);
    if (r == 0)
        return 0;
    return r;
}

/*
 * function: FIELD_EVENT_CHECK_UpdateWalkFriendship
 * address:  0x0218AB9C
 * packet:   pkt_ov021_0218AB9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Bumps a 7-bit counter in the save block; when it wraps, calls NATSUKI_CalcWalk
 * on every party member with the two coordinates read from the position
 * object.
 *
 * symbols:
 *   func_02008978  0x02008978  thumb
 *   func_02008980  0x02008980  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   NATSUKI_CalcWalk  0x0201B7EC  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Big;
struct BigObj;
struct Sub02008828Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 func_02008978(const struct Sub02008828Obj *obj);
extern void func_02008980(struct Sub02008828Obj *obj, u16 value);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void NATSUKI_CalcWalk(void *mon, int a, int b);

void FIELD_EVENT_CHECK_UpdateWalkFriendship(void *sys, u8 *pos)
{
    void *save = func_02008854(GAME_DATA_GetSaveControl(sys));
    int wrapped = 0;
    u16 count = func_02008978(save) + 1;

    if (count >= 0x80) {
        count = 0;
        wrapped = 1;
    }
    func_02008980(save, count);
    if (wrapped) {
        void *party = GAME_DATA_GetMyParty(sys);
        int a;
        int b;
        int n;
        int i;

        a = FIELDMAP_GetZoneId(pos);
        b = FIELDMAP_GetHeapId(pos);
        n = POKEPARTY_GetCount(party);
        for (i = 0; i < n; i++)
            NATSUKI_CalcWalk(POKEPARTY_GetMember(party, i), a, b);
    }
}

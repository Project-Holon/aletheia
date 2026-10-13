/*
 * function: TRIAL_HOUSE_GetRecordSlotsState
 * address:  0x021D1028
 * packet:   pkt_ov021_021D1028
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200E8F8(void *sys);

int TRIAL_HOUSE_GetRecordSlotsState(const struct Ctx *a0)
{
    u8 *p = func_0200E8F8(GAME_DATA_GetSaveControl((struct Big *)GAMESYSTEM_GetGameData(a0)));

    if (p[0] != 0) {
        if (p[0x14] != 0) {
            return 3;
        }
        return 1;
    }
    if (p[0x14] != 0) {
        return 2;
    }
    return 0;
}

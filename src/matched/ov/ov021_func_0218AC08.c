/*
 * function: FIELD_EVENT_CHECK_CheckZoneStepMessage
 * address:  0x0218AC08
 * packet:   pkt_ov021_0218AC08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When func_02013FFC accepts the id, shows the milestone message
 * (SCRCMD_ShowStepMilestoneMessage) and increments the save block counter; returns the message
 * result.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02013FFC  0x02013FFC  thumb
 *   SCRCMD_ShowStepMilestoneMessage  0x021D220C  thumb
 *   func_02008990  0x02008990  thumb
 *   func_02008988  0x02008988  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Big;
struct Ctx;
struct Sub02008828Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u32 func_02013FFC(u32 id);
extern int SCRCMD_ShowStepMilestoneMessage(void *msg, u8 *pos);
extern u16 func_02008990(const struct Sub02008828Obj *obj);
extern void func_02008988(struct Sub02008828Obj *obj, u16 value);

int FIELD_EVENT_CHECK_CheckZoneStepMessage(void *msg, u8 *pos, u16 id)
{
    void *save = func_02008854(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(msg)));
    int r = 0;

    if (func_02013FFC(id)) {
        r = SCRCMD_ShowStepMilestoneMessage(msg, pos);
        func_02008988(save, func_02008990(save) + 1);
    }
    return r;
}

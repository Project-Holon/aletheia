/*
 * function: SCRCMD_ShowStepMilestoneMessage
 * address:  0x021D220C
 * packet:   pkt_ov021_021D220C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Shows the milestone message for the counter read from the save block when
 * it equals one of the five table entries at 0x021DD6BC, or message 0x28E1
 * once it passes 500; returns 0 otherwise.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008990  0x02008990  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   gStepMilestoneTable  0x021DD6BC  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Milestone {
    u16 count;
    u16 msg;
};

extern const struct Milestone gStepMilestoneTable[5];

struct Big;
struct Ctx;
struct Sub02008828Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 func_02008990(const struct Sub02008828Obj *obj);
extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);

int SCRCMD_ShowStepMilestoneMessage(void *msg, u8 *pos)
{
    u16 n = func_02008990(func_02008854(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(msg))));
    u32 i;

    for (i = 0; i < 5; i++) {
        if (n == gStepMilestoneTable[i].count)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)msg, gStepMilestoneTable[i].msg, 0, FIELDMAP_GetHeapId(pos));
    }
    if (n > 500)
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)msg, 0x28E1, 0, FIELDMAP_GetHeapId(pos));
    return 0;
}

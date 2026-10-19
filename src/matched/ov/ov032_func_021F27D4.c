/*
 * function: BEACON_VIEW_InitWorkFromSave
 * address:  0x021F27D4
 * packet:   pkt_ov032_021F27D4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  label/matched. Every concrete byte is right; three call sites stay
 *           wildcarded because their targets are unlabelled arm9 leaves with no
 *           caller outside this range (the integrator's, inside arm9). Each was verified
 *           EXACT with `one --thumb` and no --region:
 *             0x020275A8  u32 BEACON_STATUS_GetLog(u32 a) { return a; }
 *             0x020275AC  u8 BEACON_STATUS_GetViewTop(u8 *p) { return p[0xb0e]; }
 *             0x02010F7C  u32 GPOWER_LoadPowerTable(u32 heap)
 *                         { return ARC_TOOL_LoadMember(0x26, 0, heap); }
 *                         (ARC_TOOL_LoadMember 0x02048F60 arm, a tail call)
 *           Once those three are matched in arm9, this file is EXACT as it stands.
 *           The min of p[0x7b] and 4 must be an if/else of two stores: the
 *           ternary inverts the branch (blo for bhs; b).
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/BEACON_STATUS_GetLog,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 *
 * symbols:
 *   BEACON_VIEW_InitWorkFromSave  0x021F27D4  thumb
 *   GAME_DATA_GetItemUseWork  0x02012A54  thumb
 *   BEACON_STATUS_GetLog  0x020275A8  thumb
 *   GAME_BEACON_ACCESSOR_TableGetCount  0x02165B04  thumb  ov010
 *   BEACON_STATUS_GetViewTop  0x020275AC  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   INTRUDE_GetMonolithLevel  0x0200BF10  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   MISC_GetFromSave  0x0200C0E8  thumb
 *   MISC_GetThanksCount  0x0200C1DC  thumb
 *   func_02008730  0x02008730  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008554  0x02008554  thumb
 *   GAME_BEACON_ACCESSOR_AllocTable  0x02165B2C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_AllocInfo  0x02165B10  thumb  ov010
 *   GPOWER_LoadPowerTable  0x02010F7C  thumb
 *   BEACON_VIEW_CountDifferingRecords  0x021F0684  thumb  ov032
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct BigObj;
struct Blk34;
struct Ctx;
struct Rec1B0;
struct Sub0200852CObj;
extern u32 GAME_DATA_GetItemUseWork(const struct BigObj *p);
extern u32 BEACON_STATUS_GetLog(u32 a);
extern u8 GAME_BEACON_ACCESSOR_TableGetCount(u8 *q);
extern u8 BEACON_STATUS_GetViewTop(u8 *p);
extern signed char MSG_SPEED_GetWait(void);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *INTRUDE_GetFromSave(void *sys);
extern u8 INTRUDE_GetMonolithLevel(struct Rec1B0 *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern void *MISC_GetFromSave(void *sys);
extern u32 MISC_GetThanksCount(struct Blk34 *p);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 *GAME_BEACON_ACCESSOR_AllocTable(u32 heap);
extern u8 *GAME_BEACON_ACCESSOR_AllocInfo(u32 heap);
extern void *GPOWER_LoadPowerTable(u32 heap);
extern void BEACON_VIEW_CountDifferingRecords(u8 *p, u8 *a, u8 *b);

void BEACON_VIEW_InitWorkFromSave(u8 *p)
{
    u32 sv;
    u32 s2;

    *(u32 *)(p + 0x34) = GAME_DATA_GetItemUseWork((const struct BigObj *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x3c) = BEACON_STATUS_GetLog(*(u32 *)(p + 0x34));
    p[0x7b] = GAME_BEACON_ACCESSOR_TableGetCount((u8 *)(*(u32 *)(p + 0x3c)));
    p[0x7c] = BEACON_STATUS_GetViewTop((u8 *)(*(u32 *)(p + 0x34)));
    if (p[0x7b] < 4)
        p[0x7d] = p[0x7b];
    else
        p[0x7d] = 4;
    p[0x7f] = 0x30;
    p[0x78] = MSG_SPEED_GetWait();
    sv = (u32)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x28) = INTRUDE_GetMonolithLevel((struct Rec1B0 *)INTRUDE_GetFromSave((void *)sv));
    *(u32 *)(p + 0x1c) = GAMESYSTEM_GetGameComm((const struct Ctx *)(*(u32 *)p));
    *(u32 *)(p + 0x20) = GAME_DATA_GetWifiList((const struct BigObj *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x18) = (u32)GAME_DATA_GetMyItem((const struct BigObj *)(*(u32 *)(p + 4)));
    *(u32 *)(p + 0x14) = (u32)MISC_GetFromSave((void *)sv);
    *(u32 *)(p + 0x2d4) = MISC_GetThanksCount((struct Blk34 *)(*(u32 *)(p + 0x14)));
    s2 = (u32)func_02008730((void *)sv);
    *(u32 *)(p + 0x2c) = (u16)func_02008530((const struct Sub0200852CObj *)s2);
    p[0x30] = func_02008550((const struct Sub0200852CObj *)s2);
    p[0x31] = func_02008554((const struct Sub0200852CObj *)s2);
    p[0x32] = 0x15;
    *(u32 *)(p + 0x38) = (u32)GAME_BEACON_ACCESSOR_AllocTable(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x40) = (u32)GAME_BEACON_ACCESSOR_AllocInfo(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x44) = (u32)GAME_BEACON_ACCESSOR_AllocInfo(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x4c) = (u32)GAME_BEACON_ACCESSOR_AllocInfo(*(u16 *)(p + 0x98));
    *(u32 *)(p + 0x24) = (u32)GPOWER_LoadPowerTable(*(u16 *)(p + 0x98));
    BEACON_VIEW_CountDifferingRecords(p, p + 0x58, p + 0x59);
}

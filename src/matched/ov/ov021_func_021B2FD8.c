/*
 * function: SCRCMD_SHOP_StartShop
 * address:  0x021B2FD8
 * packet:   pkt_ov021_021B2FD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetUserWorkPtr  0x02158FB4  thumb  ov010
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   func_02030734  0x02030734  arm
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_020071CC  0x020071CC  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_PROC_FLD_StepShopTask  0x021B3158  thumb  ov021
 *   GAME_BEACON_SEARCH_SetFacilityEnter  0x021655D4  thumb  ov010
 *   d_021DE210     0x021DE210  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Work {
    u8  state;
    u8  sub;
    u8  b2;
    u8  b3;
    u32 f04;
    u8  f08;
    u8  pad09[3];
    u16 f0C;
    u16 pad0E;
    u32 f10;
    u32 f14;
    void *f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Work;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Big;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetUserWorkPtr(void *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u8 *GAME_DATA_GetSecondUnionInfo(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 FIELD_MSGBG_GetFont(u8 *p);
extern void *GAME_DATA_GetMiscSave(int *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_PROC_FLD_StepShopTask(u32 a, u32 b);
extern void GAME_BEACON_SEARCH_SetFacilityEnter(void);
extern u8 d_021DE210[];

int SCRCMD_SHOP_StartShop(u32 a, u32 b)
{
    u32 v;
    void *t;
    u32 s;
    void *x;
    Work **slot;
    u32 y;
    u32 z;
    Work *w;

    v = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    t = SCRCMD_WORK_GetGameSystem((void *)b);
    s = (u32)GAMESYSTEM_GetGameData(t);
    x = GAMESYSTEM_GetFieldMap((void *)t);
    slot = SCRIPT_WORK_GetUserWorkPtr(SCRCMD_WORK_GetScriptWork((void *)b));
    y = FIELDMAP_GetMsgBg(x);
    z = (u32)GAME_DATA_GetSecondUnionInfo((void *)s);
    w = func_02030734(4, 0x214, 1, (const char *)d_021DE210, 0xFC);
    *slot = w;
    w->f10 = FIELD_MSGBG_GetFont((u8 *)y);
    w->f14 = (u32)GAME_DATA_GetMiscSave((int *)s);
    w->f0C = 0x15;
    w->f18 = GAME_DATA_GetMyItem((const struct BigObj *)s);
    w->f20 = (u32)func_020071CC((struct Sub020071CCCtrl *)GAME_DATA_GetSaveControl((struct Big *)s), 0x3a);
    w->f1C = (u32)GAME_DATA_GetTrainerRecord((int *)s);
    w->f24 = z;
    switch (v) {
    case 0xFF:
        w->b2 = v;
        break;
    case 0xFE:
        w->b2 = v;
        break;
    case 0xFD:
        w->b2 = v;
        break;
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    case 0xFB:
        w->b2 = v;
        break;
    default:
        w->b2 = (u8)v;
        w->b3 = (u8)v;
        break;
    }
    VM_SetWait((char *)a, (int)SCRCMD_PROC_FLD_StepShopTask);
    if (v != 0xFE && v != 0xFD) {
        GAME_BEACON_SEARCH_SetFacilityEnter();
    }
    return 1;
}

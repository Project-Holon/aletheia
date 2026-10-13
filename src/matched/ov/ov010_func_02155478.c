/*
 * function: func_02155478
 * address:  0x02155478
 * packet:   pkt_ov010_02155478
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ov010 main sequence: a 28-state machine over *seq that loads the
 * sub-overlays (21, 100, 119, 195, 101, 8, 93) as child procs, sets up the
 * party/slot records at +0x8c through MUSICAL_EVENT_BuildParty/MUSICAL_EVENT_BindParticipantSlots/
 * MUSICAL_EVENT_UpdateFriendRecords, runs the fade and wireless-sync waits, and tears
 * everything down in states 21 to 23.
 *
 * Byte-correct (1388 bytes, every concrete byte), 97 of 97 relocations
 * resolved. 2026-10-05 (wave D9): EXACT. The six proc-data words got the
 * token of the overlay that holds each one on its `data` symbols line
 * (ov021, ov100, ov093, ov119, ov195, ov101), each an overlay this function
 * loads. Source unchanged.
 * Shape levers that closed it (they also settled the ctx/seq register
 * swap): case 18 writes the fe4 = 0 / (*seq)++ tail in both arms;
 * case 19 writes (*seq)++ in both arms; state 10 writes the
 * GFL_USE_CancelChangeAndPlayBgm call in each arm.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   GFL_NET_ERR_ShowSimpleScreen  0x0200F83C  thumb
 *   func_0200FA84  0x0200FA84  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   BTL_SETUP_Create  0x02013090  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetupCommDouble  0x020137C0  thumb
 *   BTL_SETUP_SetupCommTriple  0x02013864  thumb
 *   BTL_SETUP_SetupCommRotation  0x02013894  thumb
 *   BTL_SETUP_SetupCommMulti  0x020137F0  thumb
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   BTL_SETUP_SetParty  0x02013128  thumb
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   BTL_SETUP_Delete  0x020130B4  thumb
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   EVENT_BATTLE_REC_SAVE_Start  0x021550A0  thumb  ov008
 *   MUSICAL_EVENT_BuildParty  0x0215518C  thumb  ov010
 *   MUSICAL_EVENT_TrimAllPartiesToThree  0x02155224  thumb  ov010
 *   MUSICAL_EVENT_UpdateFriendRecords  0x02155244  thumb  ov010
 *   MUSICAL_EVENT_BindParticipantSlots  0x02155328  thumb  ov010
 *   func_02155A4C  0x02155A4C  thumb  ov010
 *   func_02155A6C  0x02155A6C  thumb  ov010
 *   ov008_id       0x00000008  data
 *   ov021_id       0x00000015  data
 *   ov093_id       0x0000005D  data
 *   ov100_id       0x00000064  data
 *   ov101_id       0x00000065  data
 *   ov119_id       0x00000077  data
 *   ov195_id       0x000000C3  data
 *   d_021D3FE8     0x021D3FE8  data  ov021
 *   d_021BB6A4     0x021BB6A4  data  ov100
 *   d_021F03C4     0x021F03C4  data  ov093
 *   d_021E75D8     0x021E75D8  data  ov119
 *   d_02172700     0x02172700  data  a1
 *   d_02208C40     0x02208C40  data  ov195
 *   d_021B74AC     0x021B74AC  data  ov101
 *   d_0216FEE0     0x0216FEE0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile u16 vu16;

typedef struct { u32 v[4]; } Tbl4;

struct Info {
    u8 pad00[4];
    u32 f04;
    u8 pad08[0x1a];
    u8 f22;
};

struct Req {
    u32 f00;
    u32 f04;
    u16 f08;
    u8 b0a;
    u8 b0b;
    u32 f0c;
    u32 f10;
};

struct Arg {
    struct Info *info;
    void *slots;
    u32 flag;
};

struct Ctx {
    void *f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    struct Req *f28;
    u8 pad2c[0x0c];
    void *f38;
    void *f3c[4];
    u32 f4c;
    u32 f50;
    u32 f54;
    int f58;
    void *f5c;
    u32 f60;
    void *f64;
    void *f68[4];
    u8 b78[4];
    u32 f7c;
    u8 b80[8];
    struct Info *f88;
    u8 slot[0x40];
    u32 fcc;
    u32 fd0;
    u32 fd4;
    u32 fd8;
    u32 fdc;
    void *fe0;
    u32 fe4;
};

extern u8 ov008_id[];
extern u8 ov021_id[];
extern u8 ov093_id[];
extern u8 ov100_id[];
extern u8 ov101_id[];
extern u8 ov119_id[];
extern u8 ov195_id[];
extern u8 d_021D3FE8[];
extern u8 d_021BB6A4[];
extern u8 d_021F03C4[];
extern u8 d_021E75D8[];
extern const char d_02172700[];
extern u8 d_02208C40[];
extern u8 d_021B74AC[];
extern const Tbl4 d_0216FEE0;

typedef signed int     s32;
struct Desc;
struct Entry;
struct Evt;
struct IcaAnime;
struct Link;
struct ZoneData;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
extern u32 func_02039CB4(struct Link *p, u32 lo, u32 hi);
extern u32 func_0200FB24(void);
extern u32 func_0200FBB0(void);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern void func_0200FA84(void);
extern void func_0200FBA0(void);
extern void *BTL_SETUP_Create(u32 heap);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern void BTL_SETUP_SetupCommSingle(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetupCommDouble(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetupCommTriple(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetupCommRotation(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetupCommMulti(u32 p0, u32 p1, u32 p2, u32 p3, u8 p4, u16 p5);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void BTL_SETUP_SetParty(void *p, void *src, int i);
extern void BTL_SETUP_AllocRecordBuffer(struct ZoneData *o, u32 heap);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u16 b);
extern int BTL_SETUP_Delete(int a0);
extern u32 GFL_NET_IsParentAid(void);
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int GFL_NET_GetRunState(void);
extern int GFL_NET_Exit(int a0);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *w);
extern void GFL_NET_IRC_WIRELESS_Exit(void);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *EVENT_BATTLE_REC_SAVE_Start(void *a, const int *p);
extern void MUSICAL_EVENT_BuildParty(int mode, struct Ctx *ctx);
extern void MUSICAL_EVENT_TrimAllPartiesToThree(struct Ctx *ctx);
extern void MUSICAL_EVENT_UpdateFriendRecords(struct Ctx *ctx, void *party);
extern void MUSICAL_EVENT_BindParticipantSlots(struct Ctx *ctx, void *party);
extern void func_02155A4C(struct Ctx *ctx);
extern void func_02155A6C(struct Ctx *ctx);

int func_02155478(void *proc, int *seq, struct Ctx *ctx)
{
    Tbl4 tbl;
    struct Arg arg;
    void *w;
    void *h;
    struct Req *req;

    w = ctx->f00;
    h = GAMESYSTEM_GetFieldMap(w);
    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(proc, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut(w, (int)h, 0, 0));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(proc, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)w, (int)h));
        *seq = 2;
        break;
    case 2:
        GAMESYSTEM_CallProc(w, (u32)ov021_id, d_021D3FE8, ctx);
        (*seq)++;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus(w) == 0) {
            if (ctx->f50 == 8) {
                *seq = 24;
            } else if (ctx->f50 == 12) {
                *seq = 21;
            } else {
                (*seq)++;
            }
        }
        break;
    case 4:
        (*seq)++;
        break;
    case 5:
        MUSICAL_EVENT_BuildParty(ctx->f58, ctx);
        ctx->f60 = ctx->f04;
        ctx->f64 = ctx->f38;
        ctx->f68[0] = ctx->f3c[0];
        ctx->f68[1] = ctx->f3c[1];
        ctx->f68[2] = ctx->f3c[2];
        ctx->f68[3] = ctx->f3c[3];
        ctx->f7c = ctx->f50;
        GAMESYSTEM_CallProc(w, (u32)ov100_id, d_021BB6A4, &ctx->f60);
        (*seq)++;
        break;
    case 6:
        if (GAMESYSTEM_GetProcStatus(w) == 0) {
            ctx->f50 = ctx->f7c;
            switch (ctx->f50) {
            case 7:
                *seq = 20;
                break;
            case 12:
                *seq = 20;
                break;
            case 13:
                *seq = 2;
                break;
            case 6:
                ctx->f10 = 0;
                *seq = 13;
                break;
            default:
                *seq = 7;
                break;
            }
        }
        break;
    case 7:
        func_02034AC4((u32)ov093_id);
        GFL_NET_COMMAND_AddCommandTable(0x100, (u32)d_021F03C4, 9, 0);
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x6e, 12);
        (*seq)++;
        break;
    case 8:
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x6e, 12))
            (*seq)++;
        if (func_0200FB24()) {
            if (func_0200FBB0() == 1)
                GFL_NET_ERR_ShowSimpleScreen();
            else
                func_0200FA84();
            func_02034A5C((u32)ov093_id);
            *seq = 20;
        }
        break;
    case 9:
        ctx->f88 = BTL_SETUP_Create(4);
        ctx->fe0 = GAME_DATA_GetTrainerRecord((int *)ctx->f04);
        ctx->fd8 = 0;
        switch (ctx->f50) {
        case 0:
            break;
        case 1:
            ctx->fd0 = 1;
            ctx->fd4 = 2;
            BTL_SETUP_SetupCommSingle((u32)ctx->f88, ctx->f04, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 2:
            ctx->fd0 = 1;
            ctx->fd4 = 6;
            BTL_SETUP_SetupCommDouble((u32)ctx->f88, ctx->f04, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 3:
            ctx->fd0 = 1;
            ctx->fd4 = 10;
            BTL_SETUP_SetupCommTriple((u32)ctx->f88, ctx->f04, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 4:
            ctx->fd0 = 1;
            ctx->fd4 = 14;
            BTL_SETUP_SetupCommRotation((u32)ctx->f88, ctx->f04, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 5:
            tbl = d_0216FEE0;
            ctx->fd0 = 3;
            ctx->fd4 = 18;
            BTL_SETUP_SetupCommMulti((u32)ctx->f88, ctx->f04, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1,
                          tbl.v[ctx->b78[GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())]], 4);
            ctx->f88->f22 = 1;
            ctx->f88->f04 = 1;
            MUSICAL_EVENT_TrimAllPartiesToThree(ctx);
            break;
        }
        BTL_SETUP_SetParty(ctx->f88, ctx->f38, 0);
        BTL_SETUP_AllocRecordBuffer((struct ZoneData *)ctx->f88, 1);
        ctx->f54 = GFL_USE_GetBgmNo();
        GFL_USE_CancelChangeAndStopBgm();
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 10, 12);
        (*seq)++;
        break;
    case 10:
        if (func_0200FB24()) {
            BTL_SETUP_Delete((int)ctx->f88);
            ctx->f88 = 0;
            if (func_0200FBB0() == 1)
                GFL_NET_ERR_ShowSimpleScreen();
            else
                func_0200FA84();
            func_02034A5C((u32)ov093_id);
            *seq = 20;
        } else if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 10, 12)) {
            if (GFL_NET_IsParentAid())
                GFL_USE_CancelChangeAndPlayBgm(0x48B, 0xFFFF);
            else
                GFL_USE_CancelChangeAndPlayBgm(0x48C, 0xFFFF);
            (*seq)++;
        }
        break;
    case 11:
        MUSICAL_EVENT_BindParticipantSlots(ctx, w);
        func_02034A5C((u32)ov093_id);
        arg.info = ctx->f88;
        arg.slots = ctx->slot;
        arg.flag = 1;
        GAME_EVENT_CallEvent(proc, (struct Evt **)GAME_EVENT_CreateOverlayEvent(w, (u32)ov008_id, (void *)EVENT_BATTLE_REC_SAVE_Start, (u32)(&arg)));
        (*seq)++;
        break;
    case 12:
        if (GAMESYSTEM_GetProcStatus(w) == 0) {
            MUSICAL_EVENT_UpdateFriendRecords(ctx, GAMESYSTEM_GetGameData(w));
            BTL_SETUP_Delete((int)ctx->f88);
            ctx->f88 = 0;
            GFL_USE_CancelChangeAndStopBgm();
            func_02155A6C(ctx);
            *seq = 17;
        }
        break;
    case 13:
        ctx->f1c = ctx->f04;
        ctx->f24 = (u32)ctx->f38;
        GAMESYSTEM_CallProc(w, (u32)ov119_id, d_021E75D8, &ctx->f08);
        (*seq)++;
        break;
    case 14:
        if (GAMESYSTEM_GetProcStatus(w) == 0) {
            if (ctx->f10 == 1)
                *seq = 15;
            else
                *seq = 17;
        }
        break;
    case 15:
        req = func_02030734(4, 0x14, 0, d_02172700, 0x219);
        req->f00 = ctx->f04;
        req->f04 = ctx->f24;
        req->f08 = ctx->f14;
        req->b0a = 0;
        req->b0b = ctx->f18;
        req->f0c = 1;
        req->f10 = 0;
        ctx->f28 = req;
        GAMESYSTEM_CallProc(w, (u32)ov195_id, d_02208C40, req);
        (*seq)++;
        break;
    case 16:
        if (GAMESYSTEM_GetProcStatus(w) == 0) {
            func_020307B0(ctx->f28);
            ctx->f10 = 1;
            *seq = 13;
        }
        break;
    case 17:
        if (GFL_NET_GetRunState() && func_0200FB24() == 0)
            func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xdc, 12);
        (*seq)++;
        break;
    case 18:
        if (GFL_NET_GetRunState() && func_0200FB24() == 0) {
            if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xdc, 12) == 0)
                break;
            ctx->fe4 = 0;
            (*seq)++;
        } else {
            ctx->fe4 = 0;
            (*seq)++;
        }
        break;
    case 19:
        if (GFL_NET_GetRunState()) {
            ctx->fe4++;
            if (ctx->fe4 < 60)
                break;
            GFL_NET_Exit(0);
            (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 20:
        if (GFL_NET_GetRunState() == 0) {
            func_0200FBA0();
            *seq = 21;
        }
        break;
    case 21:
        func_02155A6C(ctx);
        GAME_EVENT_CallEvent(proc, FIELD_STATUS_CreateFieldOpenEvent(w));
        (*seq)++;
        break;
    case 22:
        GAME_EVENT_CallEvent(proc, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn(w, (int)h, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 23:
        GFL_NET_IRC_WIRELESS_Exit();
        func_02155A4C(ctx);
        return 1;
    case 24:
        (*seq)++;
        break;
    case 25:
        (*seq)++;
        break;
    case 26:
        ctx->f5c = ctx->f00;
        GAMESYSTEM_CallProc(w, (u32)ov101_id, d_021B74AC, &ctx->f5c);
        (*seq)++;
        break;
    case 27:
        if (GAMESYSTEM_GetProcStatus(w) == 0) {
            *(vu16 *)0x04000304 |= 0x8000;
            *seq = 20;
        }
        break;
    }
    return 0;
}
